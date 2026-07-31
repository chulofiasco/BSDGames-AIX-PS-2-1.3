/*	$NetBSD: bsd.h,v 1.4 2003/06/11 12:00:22 wiz Exp $	*/

/*
 * Copyright (c) 1983-2003, Regents of the University of California.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 * + Redistributions of source code must retain the above copyright 
 *   notice, this list of conditions and the following disclaimer.
 * + Redistributions in binary form must reproduce the above copyright 
 *   notice, this list of conditions and the following disclaimer in the 
 *   documentation and/or other materials provided with the distribution.
 * + Neither the name of the University of California, San Francisco nor 
 *   the names of its contributors may be used to endorse or promote 
 *   products derived from this software without specific prior written 
 *   permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

# if defined(BSD_RELEASE) && BSD_RELEASE >= 43
# define	BROADCAST
# define	SYSLOG_43
# endif
# if defined(BSD_RELEASE) && BSD_RELEASE == 42
# define	SYSLOG_42
# endif

/* AIX 1.2 has no getifaddrs()/freeifaddrs(); disable broadcast discovery.
 * Users may specify the hunt server explicitly with -h hostname. */
#undef BROADCAST

/* Fixed-width integer types: AIX 1.2 has no <stdint.h> or <inttypes.h>.
 * On i386 with MetaWare High C: int=32-bit, short=16-bit, char=8-bit. */
#ifndef _BSDGAMES_INT32_T
#define _BSDGAMES_INT32_T
typedef int             int32_t;
typedef unsigned int    u_int32_t;
typedef unsigned int    uint32_t;
typedef short           int16_t;
typedef unsigned short  u_int16_t;
typedef unsigned short  uint16_t;
typedef unsigned char   u_int8_t;
typedef unsigned char   uint8_t;
#endif
