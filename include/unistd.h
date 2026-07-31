/*
 * include/unistd.h - bsd-games wrapper for AIX 1.2
 *
 * AIX 1.2 unistd.h does not declare getopt, optarg, or optind.
 * Add them here.
 */
#ifndef _H_UNISTD_BSDGAMES
#define _H_UNISTD_BSDGAMES
#include "/usr/include/unistd.h"
/* getopt support - missing from AIX 1.2 unistd.h */
extern int   getopt(int, char **, const char *);
extern char *optarg;
extern int   optind;
extern int   opterr;
extern int   optopt;
#endif
