/* lib/snprintf.c - snprintf/vsnprintf for AIX 1.3 / MetaWare High C R2.2g
 *
 * AIX 1.3 libc does not provide snprintf or vsnprintf.  Implement both
 * using vsprintf into a stack-allocated scratch buffer, then copy at most
 * size-1 bytes into the caller's buffer and NUL-terminate.
 *
 * The scratch buffer (SNPRINTF_SCRATCH) must be larger than the longest
 * string that vsprintf will ever produce from any call site in bsd-games.
 * 4096 bytes is safe for all current uses.
 */

#include "/usr/include/stdio.h"
#include "/usr/include/stdarg.h"
#include "/usr/include/string.h"

#ifndef HAVE_snprintf

#define SNPRINTF_SCRATCH 4096

int
vsnprintf(buf, size, fmt, ap)
	char *buf;
	size_t size;
	const char *fmt;
	va_list ap;
{
	char tmp[SNPRINTF_SCRATCH];
	int r;

	r = vsprintf(tmp, fmt, ap);
	if (r < 0) {
		if (size > 0)
			buf[0] = '\0';
		return r;
	}
	if (size == 0)
		return r;
	if ((size_t)r >= size) {
		memcpy(buf, tmp, size - 1);
		buf[size - 1] = '\0';
	} else {
		memcpy(buf, tmp, (size_t)r + 1);
	}
	return r;
}

int
snprintf(buf, size, fmt)
	char *buf;
	size_t size;
	const char *fmt;
{
	va_list ap;
	int r;

	va_start(ap, fmt);
	r = vsnprintf(buf, size, fmt, ap);
	va_end(ap);
	return r;
}

#endif /* !HAVE_snprintf */
