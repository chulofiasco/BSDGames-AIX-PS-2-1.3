#ifndef _TERMCAP_H_BSDGAMES
#define _TERMCAP_H_BSDGAMES

/* termcap declarations - functions provided by -lcurses on AIX 1.2 */

extern char	 PC;	/* padding character */
extern char	*BC;	/* backspace string */
extern char	*UP;	/* cursor-up string */
extern short	 ospeed;/* terminal baud rate for tputs() */

extern int	tgetent(char *, const char *);
extern int	tgetnum(const char *);
extern int	tgetflag(const char *);
extern char	*tgetstr(const char *, char **);
extern char	*tgoto(const char *, int, int);
extern int	tputs(const char *, int, int (*)(int));

#endif /* _TERMCAP_H_BSDGAMES */
