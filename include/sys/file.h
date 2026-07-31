/*
 * include/sys/file.h - bsd-games stub for AIX 1.2
 *
 * BSD flock() constants and declaration.
 * AIX 1.2 does not have flock(); see lib/flock.c for the implementation
 * built on top of lockf().
 */
#ifndef _SYS_FILE_H_BSDGAMES
#define _SYS_FILE_H_BSDGAMES

#define LOCK_SH  1	/* shared lock */
#define LOCK_EX  2	/* exclusive lock */
#define LOCK_NB  4	/* non-blocking (OR'd with LOCK_SH or LOCK_EX) */
#define LOCK_UN  8	/* unlock */

extern int flock(int, int);

#endif /* _SYS_FILE_H_BSDGAMES */
