/* include/sys/types.h - bsd-games wrapper for <sys/types.h>
 *
 * AIX 1.3 sys/types.h does not define u_intN_t types.  Add them here.
 * On i386 (32-bit): unsigned int = 32 bits, unsigned short = 16 bits,
 * unsigned char = 8 bits, unsigned long = 32 bits.
 */
#ifndef _BSD_GAMES_SYS_TYPES_H
#define _BSD_GAMES_SYS_TYPES_H

#include <sys/cdefs.h>
#include "/usr/include/sys/types.h"

#ifndef _UINT8_T
#define _UINT8_T
typedef unsigned char  u_int8_t;
#endif

#ifndef _UINT16_T
#define _UINT16_T
typedef unsigned short u_int16_t;
#endif

#ifndef _UINT32_T
#define _UINT32_T
typedef unsigned int   u_int32_t;
#endif

#ifndef _UINT64_T
#define _UINT64_T
typedef unsigned long  u_int64_t;  /* 32-bit on i386 -- only low 32 used */
#endif

/* C89 has no bool keyword; typedef it as int for code that uses bool. */
#ifndef bool
typedef int bool;
#endif

#endif /* _BSD_GAMES_SYS_TYPES_H */
