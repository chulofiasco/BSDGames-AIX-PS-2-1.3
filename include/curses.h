/*
 * include/curses.h - MetaWare-compatible wrapper for AIX 1.2 curses.
 *
 * Provides all declarations from /usr/include/curses.h without including
 * unctrl.h, sgtty.h, or termio.h, which contain constructs MetaWare
 * misparses.  The implementations remain in -lcurses.
 */

#ifndef _BSDGAMES_CURSES_H
#define _BSDGAMES_CURSES_H

#include <stdio.h>

#define reg register

/*
 * curses_char: plain char used where the original curses.h used CHAR.
 * We avoid the name CHAR because MetaWare predefines it as an internal
 * constant (value 53), which causes parse errors.
 */
typedef char curses_char;

/*
 * chtype: character + attributes.
 * AIX non-NLS curses uses unsigned short.
 */
typedef unsigned short chtype;

/* SGTTY forward: curses internally uses it; callers don't need the full type */
typedef struct _sgtty_st SGTTY;

#ifndef TRUE
#define TRUE  1
#define FALSE 0
#endif

#define ERR  (-1)
#define OK   0

/* Window flags (from /usr/include/curses.h) */
#define _SUBWIN    01
#define _ENDLINE   02
#define _FULLWIN   04
#define _SCROLLWIN 010
#define _FLUSH     020
#define _ISPAD     040
#define _STANDOUT  0200
#define _NOCHANGE  (-1)

struct _win_st {
    short   _cury, _curx;
    short   _maxy, _maxx;
    short   _begy, _begx;
    short   _flags;
    chtype  _attrs;
    curses_char _clear;
    curses_char _leave;
    curses_char _scroll;
    curses_char _use_idl;
    curses_char _use_keypad;
    curses_char _use_meta;
    curses_char _nodelay;
    chtype  **_y;
    short   *_firstch;
    short   *_lastch;
    short   _tmarg, _bmarg;
};

typedef struct _win_st  WINDOW;
typedef struct screen   SCREEN;

extern int   InputPending;
extern int   didntdobotright;
extern int   LINES, COLS;
extern WINDOW *stdscr, *curscr;
extern char  *Def_term, ttytype[];

/* unctrl - provide declaration directly, avoiding unctrl.h */
extern char *_unctrl[];
#define unctrl(c)  (_unctrl[(c) & 0177])

/* Pseudo-functions for stdscr */
#define addch(ch)       waddch(stdscr, ch)
#define getch()         wgetch(stdscr)
#define addstr(str)     waddstr(stdscr, str)
#define addnstr(s,n)    do { int _i; for (_i=0; (s)[_i] && _i<(n); _i++) waddch(stdscr,(s)[_i]); } while (0)
#define getstr(str)     wgetstr(stdscr, str)
#define move(y, x)      wmove(stdscr, y, x)
#define clear()         wclear(stdscr)
#define erase()         werase(stdscr)
#define clrtobot()      wclrtobot(stdscr)
#define clrtoeol()      wclrtoeol(stdscr)
#define insertln()      winsertln(stdscr)
#define deleteln()      wdeleteln(stdscr)
#define refresh()       wrefresh(stdscr)
#define inch()          winch(stdscr)
#define insch(c)        winsch(stdscr, c)
#define delch()         wdelch(stdscr)
#define standout()      wstandout(stdscr)
#define standend()      wstandend(stdscr)
#define attron(at)      wattron(stdscr, at)
#define attroff(at)     wattroff(stdscr, at)
#define attrset(at)     wattrset(stdscr, at)
#define curs_set(x)     do {} while (0)

#define setscrreg(t,b)      wsetscrreg(stdscr, t, b)
#define wsetscrreg(win,t,b) (win->_tmarg = (t), win->_bmarg = (b))

/* mv variants */
#define mvwaddch(win,y,x,ch)    (wmove(win,y,x) == ERR ? ERR : waddch(win,ch))
#define mvwgetch(win,y,x)       (wmove(win,y,x) == ERR ? ERR : wgetch(win))
#define mvwaddstr(win,y,x,str)  (wmove(win,y,x) == ERR ? ERR : waddstr(win,str))
#define mvwgetstr(win,y,x,str)  (wmove(win,y,x) == ERR ? ERR : wgetstr(win,str))
#define mvwinch(win,y,x)        (wmove(win,y,x) == ERR ? ERR : winch(win))
#define mvwdelch(win,y,x)       (wmove(win,y,x) == ERR ? ERR : wdelch(win))
#define mvwinsch(win,y,x,c)     (wmove(win,y,x) == ERR ? ERR : winsch(win,c))
#define mvaddch(y,x,ch)         mvwaddch(stdscr, y, x, ch)
#define mvgetch(y,x)            mvwgetch(stdscr, y, x)
#define mvaddstr(y,x,str)       mvwaddstr(stdscr, y, x, str)
#define mvgetstr(y,x,str)       mvwgetstr(stdscr, y, x, str)
#define mvinch(y,x)             mvwinch(stdscr, y, x)
#define mvdelch(y,x)            mvwdelch(stdscr, y, x)
#define mvinsch(y,x,c)          mvwinsch(stdscr, y, x, c)

#define getyx(win,y,x)  y = (win)->_cury, x = (win)->_curx
#define winch(win)      ((win)->_y[(win)->_cury][(win)->_curx])

/* Video attributes (non-NLS) */
#define A_STANDOUT   0000200
#define A_UNDERLINE  0000400
#define A_REVERSE    0001000
#define A_BLINK      0002000
#define A_DIM        0004000
#define A_BOLD       0010000
#define A_INVIS      0020000
#define A_PROTECT    0040000
#define A_ALTCHARSET 0100000
#define A_NORMAL     0000000
#define A_ATTRIBUTES 0377600
#define A_CHARTEXT   0000177

/* Key codes (non-NLS) */
#define KEY_BREAK     0401
#define KEY_DOWN      0402
#define KEY_UP        0403
#define KEY_LEFT      0404
#define KEY_RIGHT     0405
#define KEY_HOME      0406
#define KEY_END       0550
#define KEY_BACKSPACE 0407
#define KEY_F0        0410
#define KEY_F(n)      (KEY_F0 + (n))
#define KEY_DL        0510
#define KEY_IL        0511
#define KEY_DC        0512
#define KEY_IC        0513
#define KEY_EIC       0514
#define KEY_CLEAR     0515
#define KEY_EOS       0516
#define KEY_EOL       0517
#define KEY_SF        0520
#define KEY_SR        0521
#define KEY_NPAGE     0522
#define KEY_PPAGE     0523
#define KEY_STAB      0524
#define KEY_CTAB      0525
#define KEY_CATAB     0526
#define KEY_ENTER     0527
#define KEY_SRESET    0530
#define KEY_RESET     0531
#define KEY_PRINT     0532
#define KEY_LL        0533
#define KEY_A1        0534
#define KEY_A3        0535
#define KEY_B2        0536
#define KEY_C1        0537
#define KEY_C3        0540

/* Function declarations (K&R style - no prototypes) */
extern WINDOW  *initscr();
extern WINDOW  *newwin();
extern WINDOW  *subwin();
extern WINDOW  *newpad();
extern char    *longname();
extern char     erasechar();
extern char     killchar();
extern int      wgetch();
extern SCREEN  *newterm();
extern int      endwin();
extern int      waddch();
extern int      waddstr();
extern int      wclear();
extern int      werase();
extern int      wclrtobot();
extern int      wclrtoeol();
extern int      wdelch();
extern int      wdeleteln();
extern int      wgetstr();
extern int      winsch();
extern int      winsertln();
extern int      wmove();
extern int      wprintw();
extern int      wrefresh();
extern int      wscanw();
extern int      wstandout();
extern int      wstandend();
extern int      wattron();
extern int      wattroff();
extern int      wattrset();
extern int      box();
extern int      scroll();
extern int      touchwin();
extern int      mvwin();
extern int      overlay();
extern int      overwrite();
extern int      printw();
extern int      scanw();
extern int      delwin();
extern int      mvprintw();
extern int      mvscanw();
extern int      mvwprintw();
extern int      mvwscanw();
extern int      putp();
extern int      vidattr();
extern int      waddnstr();

#endif /* _BSDGAMES_CURSES_H */
