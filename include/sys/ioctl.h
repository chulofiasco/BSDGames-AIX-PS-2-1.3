/*
 * include/sys/ioctl.h - wrapper for AIX 1.3 /usr/include/sys/ioctl.h
 *
 * AIX defines:
 *      #define CTRL(c)  ('c'&037)
 *
 * This is an old SVR2 Reiser-preprocessor idiom meant to be called with a
 * bare letter: CTRL(L).  The Reiser cpp substituted 'c' -> 'L' inside the
 * character constant to yield 'L'&037 = 12.
 *
 * MetaWare High C (ANSI) treats 'c' as a single pp-token and does NOT
 * substitute inside it.  However, when the argument is itself a character
 * constant ('L'), MetaWare splits the body apostrophes from the substituted
 * token, producing ''L'' which it re-tokenises as an empty char constant
 * followed by L'' (a wide-char-literal prefix + empty literal), causing the
 * parse error:  unexpected symbol: '<WCHAR>:L'''
 *
 * Fix: after letting the system header define everything it needs, uncondi-
 * tionally replace CTRL with the portable ANSI form.
 */
#ifndef _BSDGAMES_SYS_IOCTL_H
#define _BSDGAMES_SYS_IOCTL_H

#include "/usr/include/sys/ioctl.h"

#undef  CTRL
#define CTRL(x) ((x) & 037)

#endif /* _BSDGAMES_SYS_IOCTL_H */
