/* lib/err.c - BSD err/warn functions for AIX 1.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

extern const char *getprogname(void);

static void
print_progname(void)
{
	const char *prog = getprogname();
	if (prog != NULL && *prog != '\0')
		fprintf(stderr, "%s: ", prog);
}

void
vwarnx(fmt, ap)
	const char *fmt;
	va_list ap;
{
	print_progname();
	if (fmt != NULL)
		vfprintf(stderr, fmt, ap);
	fputc('\n', stderr);
}

void
vwarn(fmt, ap)
	const char *fmt;
	va_list ap;
{
	int e = errno;
	print_progname();
	if (fmt != NULL) {
		vfprintf(stderr, fmt, ap);
		fputs(": ", stderr);
	}
	fputs(strerror(e), stderr);
	fputc('\n', stderr);
}

void
verrx(eval, fmt, ap)
	int eval;
	const char *fmt;
	va_list ap;
{
	vwarnx(fmt, ap);
	exit(eval);
}

void
verr(eval, fmt, ap)
	int eval;
	const char *fmt;
	va_list ap;
{
	vwarn(fmt, ap);
	exit(eval);
}

void
warnx(fmt)
	const char *fmt;
{
	va_list ap;
	va_start(ap, fmt);
	vwarnx(fmt, ap);
	va_end(ap);
}

void
warn(fmt)
	const char *fmt;
{
	va_list ap;
	va_start(ap, fmt);
	vwarn(fmt, ap);
	va_end(ap);
}

void
errx(eval, fmt)
	int eval;
	const char *fmt;
{
	va_list ap;
	va_start(ap, fmt);
	verrx(eval, fmt, ap);
	va_end(ap);
}

void
err(eval, fmt)
	int eval;
	const char *fmt;
{
	va_list ap;
	va_start(ap, fmt);
	verr(eval, fmt, ap);
	va_end(ap);
}
