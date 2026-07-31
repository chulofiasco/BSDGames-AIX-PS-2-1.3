/* pthread.h - stub for AIX 1.2 (no pthreads; single-threaded games only).
 * Provides no-op mutex operations so malloc.c compiles unchanged.
 */
#ifndef _BSDGAMES_PTHREAD_H
#define _BSDGAMES_PTHREAD_H

typedef int pthread_mutex_t;
#define PTHREAD_MUTEX_INITIALIZER 0
#define pthread_mutex_lock(m)   (0)
#define pthread_mutex_unlock(m) (0)

#endif /* _BSDGAMES_PTHREAD_H */