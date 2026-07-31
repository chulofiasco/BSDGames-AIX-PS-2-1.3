# BSDGames — IBM AIX 1.3.0 PS/2 Port

A complete, fully verified port of the NetBSD BSDGames suite (37 text, board, card, and strategy games & data utilities) to IBM AIX 1.3.0 for PS/2.

---

## 🎯 Scope

* **Scope**: Porting, building, verifying, and installing **37 BSD games and utilities** (`adventure`, `atc`, `backgammon`, `banner`, `battlestar`, `bcd`, `boggle`, `caesar`, `canfield`, `countmail`, `cribbage`, `dm`, `factor`, `fish`, `fortune`, `gomoku`, `hack`, `hangman`, `hunt`, `mille`, `monop`, `morse`, `number`, `phantasia`, `pig`, `pom`, `ppt`, `primes`, `quiz`, `rain`, `random`, `robots`, `sail`, `snake`, `tetris`, `trek`, `wargames`, `worm`, `worms`, `wtf`, `wump`).
* **C++ Exclusion Note**: `dab` (Dots and Boxes) is written in ISO C++98 (`.cc` files) and is excluded by default (`bsd_games_cfg_no_build_dirs="dab"` in `config.params`) due to the lack of a native C++ compiler on AIX 1.3.

---

## 🖥️ Target Platform & Hardware

* **Operating System**: IBM AIX 1.3.0 for PS/2 (i386 architecture)
* **Hostname**: `dirtbike`
* **Hardware System**: IBM PS/2 Model 90
* **Processor / Complex**: Intel Pentium 66 MHz (Type 4 Q Complex)
* **Memory**: 64 MB ECC Memory
* **Graphics / Video**: XGA 1 MB / Image Adapter/A 3 MB
* **Storage**: IBM Micro Channel SCSI Controller w/ 2 MB Cache

---

## 🛠️ Build & Runtime Environment

* **Compiler**: MetaWare High C Compiler R2.2g
* **Make Utility**: Native AIX System V `make`
* **Shell Environment**: Vintage Bourne shell `/bin/sh`
* **Terminal & Curses**: AIX 1.3 System V `libcurses` / `termcap`
* **Compilation Status**: **0 Compiler Warnings**, **0 Linker Errors**
* **Test Verification**: **100% PASS** on automated test suite (`make check`)

---

## ⚡ Quick Start

### 1. Build & Test as Regular User:
```sh
./configure
make
make check
```

### 2. Install System-Wide as `root`:
```sh
su
make install
```

---

## 📖 Porting Reference

For detailed architectural rules, XCOFF relocation ordering fixes, K&R parameter reconciliation details, and per-game port notes, see **[PORTING-AIX13.md](PORTING-AIX13.md)**.
