/* lib/vwprintw.c - vwprintw for AIX 1.3 libcurses (which lacks it).
 *
 * vwprintw(win, fmt, ap): vsprintf into a scratch buffer then waddstr.
 * Uses include/curses.h (via -Iinclude) for WINDOW and waddstr.
 */
#include <curses.h>

#ifndef HAVE_vwprintw

int
vwprintw(win, fmt, ap)
    WINDOW     *win;
    const char *fmt;
    va_list     ap;
{
    char buf[4096];
    vsprintf(buf, fmt, ap);
    return waddstr(win, buf);
}

#endif /* HAVE_vwprintw */
