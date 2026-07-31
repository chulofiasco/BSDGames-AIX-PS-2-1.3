/*
 * lib/flock.c - BSD flock() emulation using POSIX lockf() for AIX 1.2
 *
 * lockf() on AIX 1.2 SVR2 only supports exclusive locks; LOCK_SH is
 * silently promoted to exclusive.  LOCK_NB maps to F_TLOCK (non-blocking).
 */
#include <sys/file.h>
#include <unistd.h>

int
flock(fd, op)
	int fd;
	int op;
{
	int cmd;

	if (op & LOCK_UN)
		cmd = F_ULOCK;
	else if (op & LOCK_NB)
		cmd = F_TLOCK;
	else
		cmd = F_LOCK;

	return lockf(fd, cmd, (long)0);
}
