/*
 * include/ctype.h - bsd-games standalone ctype for AIX 1.2
 *
 * AIX 1.2 ctype.h has two paths: when _MBCS is defined (MetaWare default)
 * it uses _MB_ctab, which requires NLchar.h / mbcs.h.  With _POSIX_SOURCE
 * also set only ctab.h is pulled in, which lacks the NLchar type → syntax
 * errors.  Bypass the whole mess with our own macros on top of _ctype[],
 * the same table the non-MBCS path uses.
 */
#ifndef _h_CTYPE_BSDGAMES
#define _h_CTYPE_BSDGAMES

/* Bit masks - must match AIX libc _ctype[] table */
#define _U   01     /* upper case */
#define _L   02     /* lower case */
#define _N   04     /* numeric    */
#define _S   010    /* space      */
#define _P   020    /* punctuation */
#define _C   040    /* control    */
#define _B   0100   /* blank      */
#define _X   0200   /* hex digit  */

extern char _ctype[];

#define isalpha(c)   ((_ctype+1)[(c)]&(_U|_L))
#define isupper(c)   ((_ctype+1)[(c)]&_U)
#define islower(c)   ((_ctype+1)[(c)]&_L)
#define isdigit(c)   ((_ctype+1)[(c)]&_N)
#define isxdigit(c)  ((_ctype+1)[(c)]&(_N|_X))
#define isalnum(c)   ((_ctype+1)[(c)]&(_U|_L|_N))
#define isspace(c)   ((_ctype+1)[(c)]&_S)
#define ispunct(c)   ((_ctype+1)[(c)]&_P)
#define isprint(c)   ((_ctype+1)[(c)]&(_P|_U|_L|_N|_B))
#define isgraph(c)   ((_ctype+1)[(c)]&(_P|_U|_L|_N))
#define iscntrl(c)   ((_ctype+1)[(c)]&_C)
#define isascii(c)   (!((c)&~0177))
#define isblank(c)   ((c) == ' ' || (c) == '\t')
#define _toupper(c)  ((c)-'a'+'A')
#define _tolower(c)  ((c)-'A'+'a')
#define toascii(c)   ((c)&0177)

#endif /* _h_CTYPE_BSDGAMES */
