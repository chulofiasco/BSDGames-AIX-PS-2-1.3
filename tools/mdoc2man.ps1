# mdoc2man.ps1 - Convert BSD mdoc man pages to traditional Unix man macros
# For AIX 1.3 nroff compatibility (mdoc macro package not available)
#
# Usage:
#   .\tools\mdoc2man.ps1           - convert all .6 and .6.in files in tree
#   .\tools\mdoc2man.ps1 -File path\to\file.6  - convert single file
#   .\tools\mdoc2man.ps1 -Preview  - show what would be converted, no changes
#
# Files that already have .TH headers are left unchanged (already traditional).
# All edits are in-place with LF line endings, no BOM.

param(
    [string]$File    = "",
    [switch]$Preview
)

$ErrorActionPreference = 'Stop'
$root = Split-Path $PSScriptRoot -Parent

# ---------------------------------------------------------------------------
# Expand a sequence of mdoc token arguments (e.g. args to .Op, .It key, etc.)
# Returns a plain troff string with \fB/\fI markup.
# ---------------------------------------------------------------------------
function Expand-Tokens {
    param([string[]]$toks, [string]$nm)
    $out = ""
    $i = 0
    while ($i -lt $toks.Count) {
        $t = $toks[$i]
        switch ($t) {
            'Fl'  { $i++
                    if ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]') {
                        $out += "\fB\-$($toks[$i])\fP "; $i++
                    } else { $out += "\fB\-\fP " }
                  }
            'Ar'  { $i++
                    if ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]') {
                        $out += "\fI$($toks[$i])\fP "; $i++
                    } else { $out += "\fIfile\fP " }
                  }
            'Nm'  { $i++
                    if ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]') {
                        $out += "\fB$($toks[$i])\fP "; $i++
                    } else { $out += "\fB$nm\fP " }
                  }
            { $_ -in 'Cm','Ic','Li','Sy','Ev' } {
                    $i++
                    if ($i -lt $toks.Count) { $out += "\fB$($toks[$i])\fP "; $i++ }
                  }
            { $_ -in 'Em','Pa' } {
                    $i++
                    if ($i -lt $toks.Count) { $out += "\fI$($toks[$i])\fP "; $i++ }
                  }
            'Tn'  { $i++
                    if ($i -lt $toks.Count) { $out += "$($toks[$i]) "; $i++ }
                  }
            'No'  { $i++ }
            'Ux'  { $out += "UNIX "; $i++ }
            'Nx'  { $i++
                    if ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]') {
                        $out += "NetBSD $($toks[$i]) "; $i++
                    } else { $out += "NetBSD " }
                  }
            'Xr'  { $i++
                    $xn = if ($i -lt $toks.Count) { $toks[$i++] } else { "" }
                    $xs = if ($i -lt $toks.Count) { $toks[$i++] } else { "" }
                    $out += "$xn($xs) "
                  }
            'Dq'  { $out += '"'; $i++
                    while ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]$') {
                        $out += $toks[$i++] + " "
                    }
                    $out = $out.TrimEnd() + '" '
                  }
            'Sq'  { $out += "'"; $i++
                    while ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]$') {
                        $out += $toks[$i++] + " "
                    }
                    $out = $out.TrimEnd() + "' "
                  }
            'Pq'  { $out += "("; $i++
                    while ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]$') {
                        $out += $toks[$i++] + " "
                    }
                    $out = $out.TrimEnd() + ") "
                  }
            'Aq'  { $out += "<"; $i++
                    while ($i -lt $toks.Count -and $toks[$i] -cnotmatch '^[A-Z][a-z]$') {
                        $out += $toks[$i++] + " "
                    }
                    $out = $out.TrimEnd() + "> "
                  }
            '|'   { $out = $out.TrimEnd() + " | "; $i++ }
            ','   { $out = $out.TrimEnd() + ", "; $i++ }
            '.'   { $out = $out.TrimEnd() + ". "; $i++ }
            ';'   { $out = $out.TrimEnd() + "; "; $i++ }
            default { $out += "$t "; $i++ }
        }
    }
    return $out.TrimEnd()
}

function Convert-Op {
    param([string[]]$toks, [string]$nm)
    if ($toks.Count -eq 0) { return "" }
    return "[$(Expand-Tokens $toks $nm)]"
}

# ---------------------------------------------------------------------------
# Convert a whole mdoc file; returns array of output lines.
# ---------------------------------------------------------------------------
function Convert-MdocFile {
    param([string[]]$src, [string]$filename)

    $out = [System.Collections.Generic.List[string]]::new()
    $n   = $src.Count

    # --- Pass 1: collect .Dd / .Dt ---
    $ddDate = ""; $dtName = ""; $dtSect = ""
    for ($i = 0; $i -lt [Math]::Min($n, 80); $i++) {
        $l = $src[$i].TrimEnd()
        if     ($l -match '^\.Dd\s+(.+)$')             { $ddDate = $matches[1].Trim() }
        elseif ($l -match '^\.Dt\s+(\S+)\s+(\S+)')     { $dtName = $matches[1]; $dtSect = $matches[2] }
    }
    $nmDefault = if ($dtName) { $dtName.ToLower() } else {
        [System.IO.Path]::GetFileNameWithoutExtension($filename) -replace '\..*',''
    }

    $out.Add(".TH $dtName $dtSect `"$ddDate`"")

    # --- Pass 2: line-by-line conversion ---
    $section       = ""
    $nameNames     = [System.Collections.Generic.List[string]]::new()
    $namePurpose   = ""
    $nameEmitted   = $false
    $listStack     = [System.Collections.Generic.Stack[string]]::new()
    $inLiteral     = $false
    $synopsisFirst = $true

    for ($i = 0; $i -lt $n; $i++) {
        $l = $src[$i].TrimEnd()

        # Skip header macros already used
        if ($l -match '^\.Dd\b|^\.Dt\b|^\.Os\b|^\.UC\b') { continue }

        # Comments â€” pass through unchanged
        if ($l -match '^\.\\\"') { $out.Add($l); continue }

        # ---- Section headings (.Sh) ----
        if ($l -match '^\.Sh\s+(.+)$') {
            $section = $matches[1].Trim().ToUpper()

            # Flush buffered NAME section before moving on
            if ($nameNames.Count -gt 0 -and -not $nameEmitted) {
                $out.Add(".SH NAME")
                $nameStr = ($nameNames -join ", ")
                $nameOut = if ($namePurpose) { "$nameStr \- $namePurpose" } else { $nameStr }
                $out.Add($nameOut)
                $nameEmitted = $true
            }
            $out.Add(".SH $section")
            $synopsisFirst = $true
            continue
        }

        if ($l -match '^\.Ss\s+(.+)$') { $out.Add(".SS $($matches[1].Trim())"); continue }

        # ---- Buffer NAME section content ----
        if ($section -eq "NAME") {
            if ($l -match '^\.Nm\s*(.*)$') {
                $nm = $matches[1].Trim().TrimEnd(',').Trim()
                $nameNames.Add($(if ($nm) { $nm } else { $nmDefault }))
                continue
            }
            if ($l -match '^\.Nd\s+(.+)$') { $namePurpose = $matches[1].Trim(); continue }
            if ($l -match '^\s*$')          { continue }
            # Any other text in NAME â€” append to purpose
            $namePurpose += " " + $l.Trim()
            continue
        }

        # ---- SYNOPSIS section ----
        if ($section -eq "SYNOPSIS") {
            if ($l -match '^\.Nm\s*(.*)$') {
                $nm = $matches[1].Trim(); if (-not $nm) { $nm = $nmDefault }
                if ($synopsisFirst) { $out.Add(".B $nm"); $synopsisFirst = $false }
                else                { $out.Add(".br"); $out.Add(".B $nm") }
                continue
            }
            if ($l -match '^\.Op\s*(.*)$') {
                $rest = $matches[1].Trim()
                $toks = if ($rest) { $rest -split '\s+' } else { @() }
                $opStr = Convert-Op $toks $nmDefault
                $out.Add($opStr)
                continue
            }
            if ($l -match '^\.Oo\b') { $out.Add("["); continue }
            if ($l -match '^\.Oc\b') { $out.Add("]"); continue }
            if ($l -match '^\.Ar\s+(.+)$') { $out.Add("\fI$($matches[1].Trim())\fP"); continue }
            if ($l -match '^\.Fl\s+(.+)$') { $out.Add("\fB\-$($matches[1].Trim())\fP"); continue }
            if ($l -match '^\.Cm\s+(.+)$') { $out.Add("\fB$($matches[1].Trim())\fP"); continue }
        }

        # ---- Paragraph ----
        if ($l -match '^\.Pp\s*$') { $out.Add(".PP"); continue }

        # ---- List begin ----
        if ($l -match '^\.Bl\s+(.*)$') {
            $args  = $matches[1]
            $ltype = switch -Regex ($args) {
                '-tag'    { "tag" }
                '-bullet' { "bullet" }
                '-enum'   { "enum" }
                '-column' { "col" }
                default   { "item" }
            }
            $listStack.Push($ltype)
            continue
        }

        # ---- List end ----
        if ($l -match '^\.El\s*$') {
            if ($listStack.Count -gt 0) { $listStack.Pop() | Out-Null }
            $out.Add(".PP")
            continue
        }

        # ---- List item ----
        if ($l -match '^\.It\s*(.*)$') {
            $itarg = $matches[1].Trim()
            $ltype = if ($listStack.Count -gt 0) { $listStack.Peek() } else { "item" }
            switch ($ltype) {
                "tag"    {
                    $out.Add(".TP")
                    if ($itarg) { $out.Add((Expand-Tokens ($itarg -split '\s+') $nmDefault)) }
                }
                "bullet" { $out.Add(".IP \(bu") }
                "enum"   { $out.Add(".IP") }
                default  {
                    $out.Add(".IP")
                    if ($itarg) { $out.Add((Expand-Tokens ($itarg -split '\s+') $nmDefault)) }
                }
            }
            continue
        }

        # ---- Literal display blocks ----
        if ($l -match '^\.Bd\s+.*(literal|unfilled)') {
            $inLiteral = $true; $out.Add(".nf"); continue
        }
        if ($l -match '^\.Bd\b') { $out.Add(".PP"); continue }
        if ($l -match '^\.Ed\b') {
            if ($inLiteral) { $out.Add(".fi"); $inLiteral = $false }
            else            { $out.Add(".PP") }
            continue
        }

        # ---- .Bf / .Ef (font blocks) â€” ignore framing, keep content ----
        if ($l -match '^\.Bf\b|^\.Ef\b') { continue }

        # ---- Indented literal line ----
        if ($l -match '^\.Dl\s+(.+)$') {
            $out.Add(".RS")
            $out.Add((Expand-Tokens ($matches[1].Trim() -split '\s+') $nmDefault))
            $out.Add(".RE")
            continue
        }

        # ---- References ----
        if ($l -match '^\.Rs\b') { $out.Add(".PP"); continue }
        if ($l -match '^\.Re\b') { continue }

        # ---- Author ----
        if ($l -match '^\.An\s+(.+)$') { $out.Add($matches[1].Trim()); continue }

        # ---- Two-character mdoc macros ----
        if ($l -match '^\.([A-Z][a-z])\s*(.*)$') {
            $mac  = $matches[1]
            $rest = $matches[2].Trim()
            $toks = if ($rest) { $rest -split '\s+' } else { @() }

            switch ($mac) {
                'Nm' {
                    $nm = if ($toks.Count -gt 0 -and $toks[0] -cnotmatch '^[,.]$') {
                        $toks[0] } else { $nmDefault }
                    $out.Add(".B $nm")
                }
                'Ar' { $out.Add("\fI$rest\fP") }
                'Fl' { $out.Add("\fB\-$rest\fP") }
                'Cm' { $out.Add("\fB$rest\fP") }
                'Ic' { $out.Add("\fB$rest\fP") }
                'Li' { $out.Add("\fB$rest\fP") }
                'Em' { $out.Add("\fI$rest\fP") }
                'Pa' { $out.Add("\fI$rest\fP") }
                'Ev' { $out.Add("\fB$rest\fP") }
                'Sy' { $out.Add("\fB$rest\fP") }
                'Tn' { if ($rest) { $out.Add($rest) } }
                'Ux' { $out.Add("UNIX") }
                'Nx' { $out.Add("NetBSD $rest".TrimEnd()) }
                'No' { if ($rest) { $out.Add($rest) } }
                'Op' { $out.Add((Convert-Op $toks $nmDefault)) }
                'Oo' { $out.Add("[") }
                'Oc' { $out.Add("]") }
                'Xr' {
                    $xn = if ($toks.Count -gt 0) { $toks[0] } else { "" }
                    $xs = if ($toks.Count -gt 1) { $toks[1] } else { "" }
                    $tr = if ($toks.Count -gt 2) { " " + ($toks[2..($toks.Count-1)] -join " ") } else { "" }
                    $out.Add("$xn($xs)$tr")
                }
                'Dq' { $out.Add("`"$rest`"") }
                'Sq' { $out.Add("'$rest'") }
                'Pq' { $out.Add("($rest)") }
                'Aq' { $out.Add("<$rest>") }
                'Sx' { $out.Add($rest) }
                'Ss' { $out.Add(".SS $rest") }
                default {
                    # Unknown mdoc â€” comment it out and emit any text
                    $out.Add('.' + "'`"'" + " mdoc: .$mac $rest")
                    if ($rest) { $out.Add($rest) }
                }
            }
            continue
        }

        # ---- Pass-through: plain text, low-level troff, blank lines ----
        $l = [regex]::Replace($l, [regex]::Escape('\' + '&'), '')
        $out.Add($l)
    }

    # Safety flush â€” emit NAME if we somehow never hit another .Sh
    if ($nameNames.Count -gt 0 -and -not $nameEmitted) {
        $out.Add(".SH NAME")
        $nfin = if ($namePurpose) { ($nameNames -join ", ") + " \- $namePurpose" } else { $nameNames -join ", " }
        $out.Add($nfin)
    }

    return ,$out
}

# ---------------------------------------------------------------------------
# Process a single file in-place
# ---------------------------------------------------------------------------
function Process-File {
    param([string]$path)

    $bytes   = [System.IO.File]::ReadAllBytes($path)
    $content = [System.Text.Encoding]::ASCII.GetString($bytes)
    $lines   = $content -split "\r?\n"

    # Classify: look for .Dd (mdoc) or .TH (traditional) in first 40 lines
    $isMdoc = $false; $isTrad = $false
    for ($i = 0; $i -lt [Math]::Min($lines.Count, 80); $i++) {
        if ($lines[$i] -match '^\.Dd\b') { $isMdoc = $true;  break }
        if ($lines[$i] -match '^\.TH\b') { $isTrad = $true;  break }
    }

    if ($isTrad) {
        Write-Host "  SKIP (already .TH): $path" -ForegroundColor DarkGray
        return
    }
    if (-not $isMdoc) {
        Write-Host "  SKIP (no header found): $path" -ForegroundColor DarkGray
        return
    }

    if ($Preview) {
        Write-Host "  WOULD CONVERT: $path" -ForegroundColor Yellow
        return
    }

    $outLines = Convert-MdocFile $lines ([System.IO.Path]::GetFileName($path))

    $newContent = ($outLines -join "`n") + "`n"
    $utf8NoBom  = [System.Text.UTF8Encoding]::new($false)
    [System.IO.File]::WriteAllText($path, $newContent, $utf8NoBom)
    Write-Host "  CONVERTED: $path" -ForegroundColor Green
}

# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
if ($File) {
    Process-File $File
} else {
    $files = Get-ChildItem -Recurse -Path $root -Include "*.6","*.6.in" |
             Where-Object { $_.FullName -notmatch 'aix_man_samples' }
    Write-Host "Found $($files.Count) candidate files in $root"
    foreach ($f in $files) { Process-File $f.FullName }
}
Write-Host "Done."
