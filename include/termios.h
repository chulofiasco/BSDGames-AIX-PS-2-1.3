/* termios.h - bsd-games wrapper for <termios.h>.
 *
 * Copyright (c) 1998, 2000 Joseph Samuel Myers.
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

/*
 * /usr/include/termios.h contains an intentional error-trap:
 *
 *   #include <sys/ioctl.h>         <- includes sys/termio.h -> defines _h_TERMIO
 *   #if defined(_h_TERMIO) && !defined(_POSIX_SOURCE)
 *   <<<< Use only one termioX.h file >>>>   <- MetaWare can't parse <<
 *   #endif
 *
 * Strategy:
 *   1. Pre-include <sys/ioctl.h> via normal angle-bracket path so MetaWare
 *      handles it cleanly and struct winsize / struct _Winsize are defined.
 *      The include guard then makes the re-include inside termios.h a no-op.
 *   2. Define _POSIX_SOURCE so the #if condition becomes false, skipping
 *      the <<<<>>>> trap.  Restore _POSIX_SOURCE afterwards.
 */
#include <sys/ioctl.h>

/*
 * When _POSIX_SOURCE is defined, /usr/include/termios.h uses
 * "struct _Winsize" for the c_winsize member instead of "struct winsize".
 * sys/ioctl.h only defines the latter; provide the former as an alias.
 */
#ifndef _bsdgames_Winsize_defined
#define _bsdgames_Winsize_defined
struct _Winsize {
	unsigned short	ws_row;
	unsigned short	ws_col;
	unsigned short	ws_xpixel;
	unsigned short	ws_ypixel;
};
#endif

#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE
#define _BSDGAMES_UNDEF_POSIX
#endif
#include "/usr/include/termios.h"
#ifdef _BSDGAMES_UNDEF_POSIX
#undef _POSIX_SOURCE
#undef _BSDGAMES_UNDEF_POSIX
#endif

#include <sys/ttydefaults.h>

/* Output flags that _POSIX_SOURCE may exclude from the system termios.h */
#ifndef ONLCR
#define ONLCR  0000004	/* map NL to CR-NL on output */
#endif
