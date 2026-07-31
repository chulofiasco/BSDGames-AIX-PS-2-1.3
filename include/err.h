/* err.h - BSD err/warn functions for AIX 1.2 / MetaWare High C */
#ifndef _ERR_H_
#define _ERR_H_

#include <stdarg.h>

void err(int, const char *, ...);
void errx(int, const char *, ...);
void warn(const char *, ...);
void warnx(const char *, ...);
void verr(int, const char *, va_list);
void verrx(int, const char *, va_list);
void vwarn(const char *, va_list);
void vwarnx(const char *, va_list);

#endif /* _ERR_H_ */
