/*
 * include/paths.h - bsd-games stub for AIX 1.2
 *
 * BSD <paths.h> standard system paths.  Only the subset actually used by
 * the games is defined here; add entries as needed.
 */
#ifndef _PATHS_H_BSDGAMES
#define _PATHS_H_BSDGAMES

#define _PATH_BSHELL	"/bin/sh"
#define _PATH_CSHELL	"/bin/csh"
#define _PATH_DEVNULL	"/dev/null"
#define _PATH_TTY	"/dev/tty"
#define _PATH_TMP	"/tmp/"
#define _PATH_UTMP	"/etc/utmp"
#define _PATH_WTMP	"/etc/wtmp"
#define _PATH_UTMPX	"/etc/utmpx"
#define _PATH_SOCKETS	"/tmp/.sockets"

#endif /* _PATHS_H_BSDGAMES */
