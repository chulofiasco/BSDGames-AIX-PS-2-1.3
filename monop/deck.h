/*	$NetBSD: deck.h,v 1.6 2003/08/07 09:37:27 agc Exp $	*/

/*
 * Copyright (c) 1980, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)deck.h	8.1 (Berkeley) 5/31/93
 */

#include <sys/types.h>

#define	bool	char

/* AIX 1.2: no u_int64_t; card file offsets fit in 32 bits */
#ifndef _U_INT64_T
typedef unsigned long u_int64_t;
#define _U_INT64_T
#endif
/* AIX 1.2: no int32_t in sys/types.h */
#ifndef _INT32_T
typedef int int32_t;
#define _INT32_T
#endif

#define	CC_D	deck[0]
#define	CH_D	deck[1]

struct dk_st {			/* deck description structure		*/
	int	num_cards;		/* number of cards in deck	*/
	int	last_card;		/* number of last card picked	*/
	bool	gojf_used;		/* set if gojf card out of deck	*/
	u_int64_t	*offsets;	/* offsets for start of cards	*/
};

typedef struct dk_st	DECK;
