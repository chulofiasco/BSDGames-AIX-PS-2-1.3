/* include/fcntl.h - bsd-games wrapper for <fcntl.h>.
 *
 * AIX 1.2 has /usr/include/fcntl.h but it may not define O_RDONLY
 * via sys/file.h.  This wrapper pulls in the system header and
 * provides fallback definitions for the O_* flags used by bsd-games.
 */
#ifndef _BSDGAMES_FCNTL_H_
#define _BSDGAMES_FCNTL_H_

#include "/usr/include/fcntl.h"

/* Fallbacks in case the system header omits these */
#ifndef O_RDONLY
#define O_RDONLY	0
#endif
#ifndef O_WRONLY
#define O_WRONLY	1
#endif
#ifndef O_RDWR
#define O_RDWR		2
#endif
#ifndef O_CREAT
#define O_CREAT		0400
#endif
#ifndef O_TRUNC
#define O_TRUNC		01000
#endif
#ifndef O_APPEND
#define O_APPEND	010
#endif

#endif /* _BSDGAMES_FCNTL_H_ */
