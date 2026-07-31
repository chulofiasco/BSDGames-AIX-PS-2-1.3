/* sys/endian.h - bsd-games compatibility with NetBSD <sys/endian.h> (not
 * a complete emulation).
 *
 * Copyright (c) 1999 Joseph Samuel Myers.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* AIX 1.2 on PS/2 (x86) is little-endian; use ntohs/ntohl */
#include <sys/types.h>
#include <netinet/in.h>

#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN	1234
#endif
#ifndef BIG_ENDIAN
#define BIG_ENDIAN	4321
#endif
#ifndef BYTE_ORDER
#define BYTE_ORDER	LITTLE_ENDIAN	/* IBM PS/2 is x86 little-endian */
#endif

#ifndef be16toh
#define be16toh(x)	((unsigned short)ntohs((unsigned short)(x)))
#endif
#ifndef htobe16
#define htobe16(x)	((unsigned short)htons((unsigned short)(x)))
#endif
#ifndef be32toh
#define be32toh(x)	((unsigned long)ntohl((unsigned long)(x)))
#endif
#ifndef htobe32
#define htobe32(x)	((unsigned long)htonl((unsigned long)(x)))
#endif
#ifndef BE16TOH
#define BE16TOH(x)	((x) = be16toh(x))
#endif
#ifndef HTOBE16
#define HTOBE16(x)	((x) = htobe16(x))
#endif
#ifndef BE32TOH
#define BE32TOH(x)	((x) = be32toh(x))
#endif
#ifndef HTOBE32
#define HTOBE32(x)	((x) = htobe32(x))
#endif
#ifndef be64toh
#define be64toh(x)	((unsigned long)ntohl((unsigned long)(x)))
#endif
#ifndef htobe64
#define htobe64(x)	((unsigned long)htonl((unsigned long)(x)))
#endif
/* BE64TOH: u_int64_t is unsigned long (32-bit) on AIX 1.2; same as BE32TOH */
#ifndef BE64TOH
#define BE64TOH(x)	((x) = be64toh(x))
#endif
