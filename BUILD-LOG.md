
dirtbike # whoami
root
dirtbike # uname -as
AIX dirtbike 1 3.0 i386
dirtbike # su lolo
$ timex ./configure
For normal usage the installation prefix will be empty.  If you wish
to install everything in another directory to that in which it will
finally be located (so that your packaging system can then move it
there) you should name that directory here.  This is most likely to
be the case if you are packaging bsd-games for a Linux distribution.
Installation prefix [] [ Using default ]
There may be some programs here you have from another package and so
do not want to build and install.  The most likely ones are banner,
factor and fortune.
Games not to build [dab] [ Using default ]
Games to build [adventure arithmetic atc backgammon banner battlestar bcd boggle caesar canfield countmail cribbage dm factor fish fortune gomoku hack hangman hunt mille monop morse number phantasia pig pom ppt primes quiz rain random robots sail snake tetris trek wargames worm worms wtf wump] [ Using default ]

*** NOTE - The default directories for installation follow the
*** Filesystem Hierarchy Standard version 2.0 (FHS).  If your
*** system still uses the older FSSTND 1.2, or if you wish to install
*** under /usr/local, you will need to check the paths and make
*** changes as appropriate.  If this is your first installation with
*** the new FHS paths, you may need to remove some old files after
*** installation.

Games directory [/usr/local/bsdgames/games] [ Using default ]
Manpage root directory [/usr/local/bsdgames/man] [ Using default ]

Hunt includes a daemon for coordinating games with multiple players
Daemon directory [/usr/local/bsdgames/games] [ Using default ]

Fortune includes a non-game utility strfile
Non-game binary directory [/usr/bin] [ Using default ]

You may wish to restrict the use of games by user, terminal, load,
etc..  This can be done by the use of dm.  If you use this
configuration, then games will be kept in a non-world-searchable
directory such as /usr/lib/games/dm and replaced by symlinks to dm.
Even if you don't choose this option, you will still be asked
for the directory name, since you are building dm, and can change
manually later.  It is strongly recommended that you keep the
default answer of 'n'.
Use dm and hide games [n] [ Using default ]
Directory for hidden games [/usr/lib/games/dm] [ Using default ]
Section 6 manpage directory [/usr/local/bsdgames/man/man6] [ Using default ]
Section 8 manpage directory [/usr/local/bsdgames/man/man8] [ Using default ]
Section 5 manpage directory [/usr/local/bsdgames/man/man5] [ Using default ]
Directory for miscellaneous documentation [/usr/local/bsdgames/doc] [ Using default ]
Library directory for constant data
        (architecture independent) [/usr/local/bsdgames/share] [ Using default ]
Library directory for variable data [/usr/local/bsdgames/var] [ Using default ]
Set owners/groups on installed files [n] [ Using default ]

See SECURITY for a discussion of security issues related to score files.
There are at least two possible security policies if you want them to
work.  You can make the files world-writable, and then anyone who wants
can put anything in them, which may not be desirable if you think people
might cheat this way.  Or you can make the games that use them setgid
games, and give the files permissions 0664.  Note, however, that some
of the games may well be insecure when this is done and
malicious users may still be able to overwrite anything writable by
group games, since the games were probably not designed with security in
mind, although version 2.2 is more secure than earlier versions.
The default is neither of these: it creates scorefiles with
permissions 0644 and gives the games no special privileges, which is
more secure but means that the games will fail when trying to write
to their scorefiles.
Binary permissions [0755] [ Using default ]
Game with scorefile permissions [0755] [ Using default ]
Daemon permissions [0755] [ Using default ]
Directory for hidden games permissions [0750] [ Using default ]
dm permissions [2755] [ Using default ]
Manpage permissions [0644] [ Using default ]
Constant data permissions [0644] [ Using default ]
Variable data permissions [0644] [ Using default ]
Permissions on variable data that should not be world readable [0640] [ Using default ]
Use .so or symlinks for manpages [symlinks] [ Using default ]
Gzip manpages [n] [ Using default ]

It is presumed in some places by the Makefiles that the compiler
will be some form of cc.
C compiler [cc] [ Using default ]
Optimize flags [-O] [ Using default ]

The default warning flags should give a compile with few warnings.
C compiler warning flags [] [ Using default ]

You probably want the default here, or could use -lncurses_g for
debugging ncurses.  Use -lcurses -ltermcap if you want to try that,
but note that this is no longer supported and may not work.
Ncurses library [-lcurses] [ Using default ]

If you have a directory /usr/include/ncurses with the ncurses include
files in it, and the <curses.h>, <termcap.h>, etc. in /usr/include
are for BSD curses/termcap, you will need to put -I/usr/include/ncurses
here.  Otherwise (if the ncurses includes are in /usr/include), leave
this blank.  Leave it blank if /usr/include/ncurses is a symbolic link
to /usr/include.
Ncurses includes [] [ Using default ]

factor can use libcrypto from OpenSSL to handle large numbers.
Use libcrypto [n] [ Using default ]
Other CFLAGS [] [ Using default ]
Other LDFLAGS [] [ Using default ]
Checking for getloadavg...not found.
Checking for fgetln...not found.
Checking for strlcpy...not found.
Checking for sig_t...not found.
Checking for getprogname...not found.

For some special purposes you may want to link all games with a
particular library, in addition to those they would normally be linked
with.  Unless you know you want this, you can leave it empty.
Base libraries [] [ Using default ]
Yacc program [yacc] [ Using default ]
Lex program [lex] [ Using default ]
Lex library [-ll] [ Using default ]

You can choose the default pager for those games that use one (for
example, for viewing instructions).  This can be an absolute path,
or the name of the pager to be searched for via the PATH at runtime.
All these games will also honour the PAGER environment variable if set,
in the correct (POSIX.2) way.
Pager [/usr/bin/pager] [ Using default ]

Fortune comes with some potentially offensive fortunes.  You should
only install these if you are sure that your users want them.
Install offensive fortunes [n] [ Using default ]

Sail needs its own directory it can write to for temporary files
to synchronise among multiple players.  Note that with the
default permissions given here this will not work: you may want
to choose permissions appropriate to the security policy you are
using.  It may be more secure if this directory is not world
accessible (e.g. mode 2770).
Directory for sail temporary files [/usr/local/bsdgames/var/sail] [ Using default ]
Sail directory permissions [0750] [ Using default ]

You can configure the exact names used for data files by various
of the games.  Most probably the defaults are OK.

Note that bsd-games no longer comes with its own word list.
For hangman you should specify the path to a word list to be read
at runtime (probably /usr/share/dict/words or /usr/dict/words).
For boggle you should specify one to be used at compile time to
generate boggle's own data.  In both cases they should probably be
English dictionaries; all words which do not consist entirely of
lower-case ASCII letters will be silently ignored.

Directory for atc static data [/usr/local/bsdgames/share/atc] [ Using default ]
Score file for atc [/usr/local/bsdgames/var/atc_score] [ Using default ]
Score file for battlestar [/usr/local/bsdgames/var/battlestar.log] [ Using default ]
Dictionary for boggle (CHECK ANSWER) [/usr/dict/words] [ Using default ]
Directory for boggle static data [/usr/local/bsdgames/share/boggle] [ Using default ]
Score file for canfield [/usr/local/bsdgames/var/cfscores] [ Using default ]
File for cribbage instructions [/usr/local/bsdgames/share/cribbage.instr] [ Using default ]
Score file for cribbage [/usr/local/bsdgames/var/criblog] [ Using default ]
Configuration file for dm [/etc/dm.conf] [ Using default ]
File to disable games playing [/etc/nogames] [ Using default ]
Log file for dm [/usr/local/bsdgames/var/games.log] [ Using default ]
File for fish instructions [/usr/local/bsdgames/share/fish.instr] [ Using default ]
Directory for fortune files [/usr/local/bsdgames/share/fortune] [ Using default ]
Directory for hack variable data [/usr/local/bsdgames/var/hack] [ Using default ]

This directory will need to be writable by hack at runtime.
Note that with the default permissions given here this will
not work: you may want to choose permissions appropriate to the
security policy you are using (e.g. 2775 root.games for setgid
games).
Hack directory permissions [0755] [ Using default ]
Words file for hangman (CHECK ANSWER) [/usr/dict/words] [ Using default ]
File for monop cards [/usr/local/bsdgames/share/monop-cards.pck] [ Using default ]
Directory for phantasia variable data [/usr/local/bsdgames/var/phantasia] [ Using default ]
Directory for quiz static data [/usr/local/bsdgames/share/quiz] [ Using default ]
Score file for robots [/usr/local/bsdgames/var/robots_roll] [ Using default ]
Score file for sail [/usr/local/bsdgames/var/saillog] [ Using default ]
Score file for snake [/usr/local/bsdgames/var/snake.log] [ Using default ]
Raw score file for snake [/usr/local/bsdgames/var/snakerawscores] [ Using default ]
Score file for tetris [/usr/local/bsdgames/var/tetris-bsd.scores] [ Using default ]
Acronym database for wtf [/usr/local/bsdgames/share/acronyms] [ Using default ]
File for wump info [/usr/local/bsdgames/share/wump.info] [ Using default ]
Generating Makeconfig from Makeconfig.in
Generating hide-game from hide-game.in
Generating install-man from install-man.in
Generating install-score from install-score.in
Generating atc/pathnames.h from atc/pathnames.h.in
Generating battlestar/pathnames.h from battlestar/pathnames.h.in
Generating boggle/boggle/bog.h from boggle/boggle/bog.h.in
Generating canfield/canfield/pathnames.h from canfield/canfield/pathnames.h.in
Generating cribbage/pathnames.h from cribbage/pathnames.h.in
Generating dm/pathnames.h from dm/pathnames.h.in
Generating fish/pathnames.h from fish/pathnames.h.in
Generating fortune/fortune/pathnames.h from fortune/fortune/pathnames.h.in
Generating hack/pathnames.h from hack/pathnames.h.in
Generating hangman/pathnames.h from hangman/pathnames.h.in
Generating monop/pathnames.h from monop/pathnames.h.in
Generating phantasia/pathnames.h from phantasia/pathnames.h.in
Generating quiz/pathnames.h from quiz/pathnames.h.in
Generating robots/pathnames.h from robots/pathnames.h.in
Generating sail/pathnames.h from sail/pathnames.h.in
Generating snake/snake/pathnames.h from snake/snake/pathnames.h.in
Generating tetris/pathnames.h from tetris/pathnames.h.in
Generating wump/pathnames.h from wump/pathnames.h.in
Generating the main Makefile, please wait...
Patching Makefrag files for AIX make compatibility...
Done.

real     4:05.16
user       34.06
sys      2:21.11

$ timex make
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/crc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv crc.o adventure/crc.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/setup.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv setup.o adventure/setup.o
        cc   adventure/setup.o   -o adventure/setup
        adventure/setup adventure/glorkz >adventure/data.c
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/data.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv data.o adventure/data.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/done.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv done.o adventure/done.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/init.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv init.o adventure/init.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/io.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv io.o adventure/io.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o adventure/main.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/save.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv save.o adventure/save.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/subr.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv subr.o adventure/subr.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/vocab.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv vocab.o adventure/vocab.o
        cc -O  -Dlint    -Iinclude   -Iadventure  -c adventure/wizard.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv wizard.o adventure/wizard.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/err.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv err.o lib/err.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/getprogname.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getprogname.o lib/getprogname.o
        cc   adventure/crc.o adventure/data.o adventure/done.o adventure/init.o adventure/io.o adventure/main.o adventure/save.o adventure/subr.o adventure/vocab.o adventure/wizard.o lib/err.o lib/getprogname.o   -o adventure/adventure
        cc -O  -Dlint    -Iinclude   -Iarithmetic  -c arithmetic/arithmetic.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv arithmetic.o arithmetic/arithmetic.o
        cc   arithmetic/arithmetic.o lib/getprogname.o lib/err.o   -o arithmetic/arithmetic
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/extern.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extern.o atc/extern.o
        cd atc && yacc -d grammar.y
        mv atc/y.tab.c atc/grammar.c
        mv atc/y.tab.h atc/grammar.h
        touch atc/grammar.h
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/grammar.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "grammar.y",L680/C14: Array subscript out of range.
w "grammar.y",L681/C14: Array subscript out of range.
w "grammar.y",L82/C5:   Unreachable statement.
        mv grammar.o atc/grammar.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/graphics.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv graphics.o atc/graphics.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/input.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "atc/input.c",L358/C1:        setplane
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L133/C17.
w "atc/input.c",L372/C1:        turn
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L137/C17.
w "atc/input.c",L381/C1:        circle
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L117/C17.
w "atc/input.c",L391/C1:        left
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L126/C17.
w "atc/input.c",L402/C1:        right
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L131/C17.
w "atc/input.c",L413/C1:        Left
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L112/C17.
w "atc/input.c",L423/C1:        Right
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L113/C17.
w "atc/input.c",L433/C1:        delayb
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L121/C17.
w "atc/input.c",L474/C1:        beacon
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L115/C17.
w "atc/input.c",L482/C1:        ex_it
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L123/C17.
w "atc/input.c",L490/C1:        airport
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L114/C17.
w "atc/input.c",L498/C1:        climb
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L118/C17.
w "atc/input.c",L506/C1:        descend
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L122/C17.
w "atc/input.c",L514/C1:        setalt
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L132/C17.
w "atc/input.c",L524/C1:        setrelalt
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L134/C17.
w "atc/input.c",L548/C1:        benum
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L116/C17.
w "atc/input.c",L579/C1:        to_dir
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L136/C17.
w "atc/input.c",L587/C1:        rel_dir
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L130/C17.
w "atc/input.c",L611/C1:        mark
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L127/C17.
w "atc/input.c",L623/C1:        unmark
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L138/C17.
w "atc/input.c",L635/C1:        ignore
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L125/C17.
w "atc/input.c",L647/C1:        dir_no
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L73/C6.
        mv input.o atc/input.o
        cd atc && lex lex.l
        mv atc/lex.yy.c atc/lex.c
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/lex.c
"/usr/include/sgtty.h", line 57: warning: ECHO redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "atc/lex.c",L105/C1:  Unreachable statement.
w "atc/lex.c",L108/C1:  Unreachable statement.
w "atc/lex.c",L111/C1:  Unreachable statement.
w "atc/lex.c",L114/C1:  Unreachable statement.
w "atc/lex.c",L117/C1:  Unreachable statement.
w "atc/lex.c",L120/C1:  Unreachable statement.
w "atc/lex.c",L123/C1:  Unreachable statement.
w "atc/lex.c",L126/C1:  Unreachable statement.
w "atc/lex.c",L129/C1:  Unreachable statement.
w "atc/lex.c",L132/C1:  Unreachable statement.
w "atc/lex.c",L144/C1:  Unreachable statement.
w "atc/lex.c",L281/C9:  Array subscript out of range.
w "atc/lex.c",L282/C9:  Array subscript out of range.
w "atc/lex.c",L286/C9:  Array subscript out of range.
w "atc/lex.c",L477/C44: Array subscript out of range.
w "atc/lex.c",L488/C49: Array subscript out of range.
        mv lex.o atc/lex.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/list.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv list.o atc/list.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/log.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv log.o atc/log.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o atc/main.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/tunable.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv tunable.o atc/tunable.o
        cc -O  -Dlint   -DBSD -DYY_NO_UNPUT -Iinclude   -Iatc  -c atc/update.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "atc/update.c",L263/C1:       number
|    Function definition semantics overridden by prototype at
|    "atc/extern.h",L95/C6.
        mv update.o atc/update.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/strlcpy.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv strlcpy.o lib/strlcpy.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/flock.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv flock.o lib/flock.o
        cc   atc/extern.o atc/grammar.o atc/graphics.o atc/input.o atc/lex.o atc/list.o atc/log.o atc/main.o atc/tunable.o atc/update.o lib/strlcpy.o lib/flock.o lib/err.o lib/getprogname.o -lm -lcurses -ll  -o atc/atc
        ./substscr g m atc/atc.6.in atc/atc.6
Generating atc/atc.6 from atc/atc.6.in
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/backgammon -Ibackgammon/common_source -c backgammon/backgammon/extra.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extra.o backgammon/backgammon/extra.o
        cc  -Dlint   -DV7 -Iinclude   -Ibackgammon/backgammon -Ibackgammon/common_source -c backgammon/backgammon/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o backgammon/backgammon/main.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/backgammon -Ibackgammon/common_source -c backgammon/backgammon/move.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv move.o backgammon/backgammon/move.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/backgammon -Ibackgammon/common_source -c backgammon/backgammon/text.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv text.o backgammon/backgammon/text.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/backgammon -Ibackgammon/common_source -c backgammon/backgammon/version.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv version.o backgammon/backgammon/version.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/allow.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv allow.o backgammon/common_source/allow.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/board.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv board.o backgammon/common_source/board.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/check.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv check.o backgammon/common_source/check.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/fancy.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv fancy.o backgammon/common_source/fancy.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/init.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv init.o backgammon/common_source/init.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/odds.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv odds.o backgammon/common_source/odds.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/one.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv one.o backgammon/common_source/one.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/save.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv save.o backgammon/common_source/save.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/subs.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "backgammon/common_source/subs.c",L125/C1:    writec
|    Function definition semantics overridden by prototype at
|    "backgammon/common_source/back.h",L182/C6.
w "backgammon/common_source/subs.c",L257/C1:    yorn
|    Function definition semantics overridden by prototype at
|    "backgammon/common_source/back.h",L185/C5.
        mv subs.o backgammon/common_source/subs.o
        cc -O  -Dlint   -DEXEC_PATH=\"/usr/local/bsdgames/games/backgammon\" -DTEACH_PATH=\"/usr/local/bsdgames/games/teachgammon\" -Iinclude   -Ibackgammon/common_source  -c backgammon/common_source/table.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "backgammon/common_source/table.c",L199/C1:   dotable
|    Function definition semantics overridden by prototype at
|    "backgammon/common_source/back.h",L144/C5.
        mv table.o backgammon/common_source/table.o
        cc   backgammon/backgammon/extra.o backgammon/backgammon/main.o backgammon/backgammon/move.o backgammon/backgammon/text.o backgammon/backgammon/version.o backgammon/common_source/allow.o backgammon/common_source/board.o backgammon/common_source/check.o backgammon/common_source/fancy.o backgammon/common_source/init.o backgammon/common_source/odds.o backgammon/common_source/one.o backgammon/common_source/save.o backgammon/common_source/subs.o backgammon/common_source/table.o -lcurses  -o backgammon/backgammon/backgammon
        ./substscr g m backgammon/backgammon/backgammon.6.in backgammon/backgammon/backgammon.6
Generating backgammon/backgammon/backgammon.6 from backgammon/backgammon/backgammon.6.in
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/teachgammon -Ibackgammon/common_source -c backgammon/teachgammon/data.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv data.o backgammon/teachgammon/data.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/teachgammon -Ibackgammon/common_source -c backgammon/teachgammon/teach.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv teach.o backgammon/teachgammon/teach.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/teachgammon -Ibackgammon/common_source -c backgammon/teachgammon/ttext1.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ttext1.o backgammon/teachgammon/ttext1.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/teachgammon -Ibackgammon/common_source -c backgammon/teachgammon/ttext2.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ttext2.o backgammon/teachgammon/ttext2.o
        cc -O  -Dlint   -DV7 -Iinclude   -Ibackgammon/teachgammon -Ibackgammon/common_source -c backgammon/teachgammon/tutor.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv tutor.o backgammon/teachgammon/tutor.o
        cc   backgammon/teachgammon/data.o backgammon/teachgammon/teach.o backgammon/teachgammon/ttext1.o backgammon/teachgammon/ttext2.o backgammon/teachgammon/tutor.o backgammon/common_source/allow.o backgammon/common_source/board.o backgammon/common_source/check.o backgammon/common_source/fancy.o backgammon/common_source/init.o backgammon/common_source/one.o backgammon/common_source/save.o backgammon/common_source/subs.o backgammon/common_source/table.o -lcurses  -o backgammon/teachgammon/teachgammon
        cc -O  -Dlint    -Iinclude   -Ibanner  -c banner/banner.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv banner.o banner/banner.o
        cc   banner/banner.o lib/err.o lib/getprogname.o   -o banner/banner
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/battlestar.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv battlestar.o battlestar/battlestar.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command1.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv command1.o battlestar/command1.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command2.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv command2.o battlestar/command2.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command3.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv command3.o battlestar/command3.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command4.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv command4.o battlestar/command4.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command5.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv command5.o battlestar/command5.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command6.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "battlestar/command6.c",L117/C1:      post
|    Function definition semantics overridden by prototype at
|    "battlestar/extern.h",L365/C6.
        mv command6.o battlestar/command6.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/command7.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv command7.o battlestar/command7.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/cypher.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv cypher.o battlestar/cypher.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/dayfile.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dayfile.o battlestar/dayfile.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/dayobjs.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dayobjs.o battlestar/dayobjs.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/fly.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv fly.o battlestar/fly.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/getcom.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getcom.o battlestar/getcom.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/globals.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv globals.o battlestar/globals.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/init.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv init.o battlestar/init.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/misc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv misc.o battlestar/misc.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/nightfile.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv nightfile.o battlestar/nightfile.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/nightobjs.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv nightobjs.o battlestar/nightobjs.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/parse.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv parse.o battlestar/parse.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/room.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "battlestar/room.c",L117/C1:  truedirec
|    Function definition semantics overridden by prototype at
|    "battlestar/extern.h",L379/C13.
        mv room.o battlestar/room.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/save.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv save.o battlestar/save.o
        cc -O  -Dlint    -Iinclude   -Ibattlestar  -c battlestar/words.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv words.o battlestar/words.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/fgetln.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv fgetln.o lib/fgetln.o
        cc   battlestar/battlestar.o battlestar/command1.o battlestar/command2.o battlestar/command3.o battlestar/command4.o battlestar/command5.o battlestar/command6.o battlestar/command7.o battlestar/cypher.o battlestar/dayfile.o battlestar/dayobjs.o battlestar/fly.o battlestar/getcom.o battlestar/globals.o battlestar/init.o battlestar/misc.o battlestar/nightfile.o battlestar/nightobjs.o battlestar/parse.o battlestar/room.o battlestar/save.o battlestar/words.o lib/fgetln.o lib/err.o lib/getprogname.o -lcurses  -o battlestar/battlestar
        cc -O  -Dlint    -Iinclude   -Ibcd  -c bcd/bcd.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv bcd.o bcd/bcd.o
        cc   bcd/bcd.o   -o bcd/bcd
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Iboggle/boggle  -c boggle/boggle/bog.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv bog.o boggle/boggle/bog.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Iboggle/boggle  -c boggle/boggle/help.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv help.o boggle/boggle/help.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Iboggle/boggle  -c boggle/boggle/mach.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv mach.o boggle/boggle/mach.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Iboggle/boggle  -c boggle/boggle/prtable.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv prtable.o boggle/boggle/prtable.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Iboggle/boggle  -c boggle/boggle/timer.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv timer.o boggle/boggle/timer.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Iboggle/boggle  -c boggle/boggle/word.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv word.o boggle/boggle/word.o
        cc   boggle/boggle/bog.o boggle/boggle/help.o boggle/boggle/mach.o boggle/boggle/prtable.o boggle/boggle/timer.o boggle/boggle/word.o lib/err.o lib/getprogname.o -lcurses  -o boggle/boggle/boggle
        cc -O  -Dlint    -Iinclude   -Iboggle/mkdict -Iboggle/boggle -c boggle/mkdict/mkdict.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv mkdict.o boggle/mkdict/mkdict.o
        cc   boggle/mkdict/mkdict.o   -o boggle/mkdict/mkdict
        boggle/mkdict/mkdict </usr/dict/words >boggle/mkdict/dictionary
25627 words
        cc -O  -Dlint    -Iinclude   -Iboggle/mkindex -Iboggle/boggle -c boggle/mkindex/mkindex.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv mkindex.o boggle/mkindex/mkindex.o
        cc   boggle/mkindex/mkindex.o   -o boggle/mkindex/mkindex
        boggle/mkindex/mkindex <boggle/mkdict/dictionary >boggle/mkindex/dictindex
        cc -O  -Dlint    -Iinclude   -Icaesar  -c caesar/caesar.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv caesar.o caesar/caesar.o
        cc   caesar/caesar.o lib/err.o lib/getprogname.o -lm  -o caesar/caesar
        ./substscr g s caesar/rot13.in caesar/rot13
Generating caesar/rot13 from caesar/rot13.in
        cc -O  -Dlint    -Iinclude   -Icanfield/canfield  -c canfield/canfield/canfield.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv canfield.o canfield/canfield/canfield.o
        cc   canfield/canfield/canfield.o -lcurses  -o canfield/canfield/canfield
        ./substscr g m canfield/canfield/canfield.6.in canfield/canfield/canfield.6
Generating canfield/canfield/canfield.6 from canfield/canfield/canfield.6.in
        cc -O  -Dlint    -Iinclude   -Icanfield/cfscores -Icanfield/canfield -c canfield/cfscores/cfscores.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv cfscores.o canfield/cfscores/cfscores.o
        cc   canfield/cfscores/cfscores.o lib/err.o lib/getprogname.o   -o canfield/cfscores/cfscores
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/cards.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv cards.o cribbage/cards.o
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/crib.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "cribbage/crib.c",L303/C1:    playhand
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L98/C6.
w "cribbage/crib.c",L358/C1:    discard
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L73/C7.
w "cribbage/crib.c",L388/C1:    cut
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L71/C6.
w "cribbage/crib.c",L432/C1:    prcrib
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L101/C7.
w "cribbage/crib.c",L463/C1:    peg
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L96/C6.
w "cribbage/crib.c",L636/C1:    score
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L108/C6.
        mv crib.o cribbage/crib.o
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/extern.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extern.o cribbage/extern.o
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/instr.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv instr.o cribbage/instr.o
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/io.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "cribbage/io.c",L81/C1:       msgcard
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L91/C6.
w "cribbage/io.c",L96/C1:       msgcrd
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L92/C6.
w "cribbage/io.c",L121/C1:      printcard
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L103/C7.
w "cribbage/io.c",L135/C1:      prcard
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L100/C7.
w "cribbage/io.c",L162/C1:      prhand
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L102/C7.
        mv io.o cribbage/io.o
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/score.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "cribbage/score.c",L108/C1:   scorehand
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L109/C6.
        mv score.o cribbage/score.o
        cc -O  -Dlint    -Iinclude   -Icribbage  -c cribbage/support.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "cribbage/support.c",L205/C1: prpeg
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L104/C7.
w "cribbage/support.c",L244/C1: cdiscard
|    Function definition semantics overridden by prototype at
|    "cribbage/cribbage.h",L67/C7.
        mv support.o cribbage/support.o
        cc   cribbage/cards.o cribbage/crib.o cribbage/extern.o cribbage/instr.o cribbage/io.o cribbage/score.o cribbage/support.o lib/err.o lib/getprogname.o -lcurses  -o cribbage/cribbage
        ./substscr g m cribbage/cribbage.6.in cribbage/cribbage.6
Generating cribbage/cribbage.6 from cribbage/cribbage.6.in
        cc -O  -Dlint    -D_GNU_SOURCE -DSUPPORT_UTMP  -Iinclude   -Idm  -c dm/dm.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dm.o dm/dm.o
        cc -O  -Dlint    -D_GNU_SOURCE -DSUPPORT_UTMP  -Iinclude   -Idm  -c dm/utmpentry.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv utmpentry.o dm/utmpentry.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/getloadavg.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getloadavg.o lib/getloadavg.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/snprintf.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv snprintf.o lib/snprintf.o
        cc   dm/dm.o dm/utmpentry.o lib/getloadavg.o lib/flock.o lib/err.o lib/getprogname.o lib/snprintf.o   -o dm/dm
        ./substscr g m dm/dm.8.in dm/dm.8
Generating dm/dm.8 from dm/dm.8.in
        ./substscr g m dm/dm.conf.5.in dm/dm.conf.5
Generating dm/dm.conf.5 from dm/dm.conf.5.in
        cc -O  -Dlint   -D_GNU_SOURCE -Iinclude   -Ifactor -Iprimes -c factor/factor.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv factor.o factor/factor.o
        cc -O  -Dlint   -D_GNU_SOURCE -Iinclude   -Iprimes  -c primes/pr_tbl.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pr_tbl.o primes/pr_tbl.o
        cc   factor/factor.o primes/pr_tbl.o lib/err.o lib/getprogname.o lib/snprintf.o   -o factor/factor
        cc -O  -Dlint    -Iinclude   -Ifish  -c fish/fish.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv fish.o fish/fish.o
        cc   fish/fish.o lib/err.o lib/getprogname.o   -o fish/fish
        cc -O  -Dlint    -Iinclude   -Ifortune/strfile  -c fortune/strfile/strfile.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv strfile.o fortune/strfile/strfile.o
        cc   fortune/strfile/strfile.o lib/err.o lib/getprogname.o   -o fortune/strfile/strfile
        fortune/strfile/strfile -rs fortune/datfiles/farber fortune/datfiles/farber.dat
        fortune/strfile/strfile -rs fortune/datfiles/fortunes fortune/datfiles/fortunes.dat
        fortune/strfile/strfile -rs fortune/datfiles/fortunes2 fortune/datfiles/fortunes2.dat
        fortune/strfile/strfile -rs fortune/datfiles/limerick fortune/datfiles/limerick.dat
        fortune/strfile/strfile -rs fortune/datfiles/startrek fortune/datfiles/startrek.dat
        fortune/strfile/strfile -rs fortune/datfiles/zippy fortune/datfiles/zippy.dat
        tr a-zA-Z n-za-mN-ZA-M < fortune/datfiles/fortunes-o.fake > fortune/datfiles/fortunes-o
        fortune/strfile/strfile -rsx fortune/datfiles/fortunes-o fortune/datfiles/fortunes-o.dat
        tr a-zA-Z n-za-mN-ZA-M < fortune/datfiles/fortunes2-o.fake > fortune/datfiles/fortunes2-o
        fortune/strfile/strfile -rsx fortune/datfiles/fortunes2-o fortune/datfiles/fortunes2-o.dat
        tr a-zA-Z n-za-mN-ZA-M < fortune/datfiles/limerick-o.fake > fortune/datfiles/limerick-o
        fortune/strfile/strfile -rsx fortune/datfiles/limerick-o fortune/datfiles/limerick-o.dat
        tr a-zA-Z n-za-mN-ZA-M < fortune/datfiles/unamerican-o.fake > fortune/datfiles/unamerican-o
        fortune/strfile/strfile -rsx fortune/datfiles/unamerican-o fortune/datfiles/unamerican-o.dat
        cc -O  -Dlint    -DHAVE_RE_COMP -Iinclude   -Ifortune/fortune -Ifortune/strfile -c fortune/fortune/fortune.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv fortune.o fortune/fortune/fortune.o
        cc   fortune/fortune/fortune.o lib/flock.o lib/getprogname.o lib/err.o   -o fortune/fortune/fortune
        ./substscr g m fortune/fortune/fortune.6.in fortune/fortune/fortune.6
Generating fortune/fortune/fortune.6 from fortune/fortune/fortune.6.in
        cc -O  -Dlint    -Iinclude   -Ifortune/unstr -Ifortune/strfile -c fortune/unstr/unstr.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv unstr.o fortune/unstr/unstr.o
        cc   fortune/unstr/unstr.o lib/err.o lib/getprogname.o   -o fortune/unstr/unstr
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Igomoku  -c gomoku/bdinit.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv bdinit.o gomoku/bdinit.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Igomoku  -c gomoku/bdisp.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv bdisp.o gomoku/bdisp.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Igomoku  -c gomoku/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o gomoku/main.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Igomoku  -c gomoku/makemove.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv makemove.o gomoku/makemove.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Igomoku  -c gomoku/pickmove.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pickmove.o gomoku/pickmove.o
        cc -O  -Dlint   -DNEW_STYLE -Iinclude   -Igomoku  -c gomoku/stoc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv stoc.o gomoku/stoc.o
        cc   gomoku/bdinit.o gomoku/bdisp.o gomoku/main.o gomoku/makemove.o gomoku/pickmove.o gomoku/stoc.o lib/err.o lib/getprogname.o -lcurses  -o gomoku/gomoku
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/makedefs.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv makedefs.o hack/makedefs.o
        cc   hack/makedefs.o   -o hack/makedefs
        hack/makedefs hack/def.objects.h >hack/hack.onames.h
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/alloc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv alloc.o hack/alloc.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.Decl.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.Decl.o hack/hack.Decl.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.apply.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.apply.o hack/hack.apply.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.bones.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.bones.o hack/hack.bones.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.c",L747/C1:        cansee
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L66/C5.
        mv hack.o hack/hack.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.cmd.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.cmd.c",L302/C1:    getdir
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L86/C5.
        mv hack.cmd.o hack/hack.cmd.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.do.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.do.c",L194/C1:     goto_level
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L99/C6.
        mv hack.do.o hack/hack.do.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.do_name.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.do_name.o hack/hack.do_name.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.do_wear.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.do_wear.o hack/hack.do_wear.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.dog.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.dog.c",L474/C1:    inroom
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L146/C5.
        mv hack.dog.o hack/hack.dog.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.eat.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.eat.c",L392/C1:    newuhs
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L158/C6.
        mv hack.eat.o hack/hack.eat.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.end.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.end.o hack/hack.end.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.engrave.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.engrave.c",L88/C1: engr_at
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L182/C14.
w "hack/hack.engrave.c",L101/C1:        sengr_at
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L183/C5.
w "hack/hack.engrave.c",L132/C1:        wipe_engr_at
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L185/C6.
        mv hack.engrave.o hack/hack.engrave.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.fight.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.fight.o hack/hack.fight.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.invent.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.invent.c",L724/C1: xprname
|    Function definition semantics overridden by prototype at
|    "hack/hack.invent.c",L82/C14.
        mv hack.invent.o hack/hack.invent.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.ioctl.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.ioctl.o hack/hack.ioctl.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.lev.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.lev.c",L82/C1:     savelev
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L245/C6.
w "hack/hack.lev.c",L218/C1:    getlev
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L251/C6.
        mv hack.lev.o hack/hack.lev.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.main.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.main.c",L543/C1:   chdirx
|    Function definition semantics overridden by prototype at
|    "hack/hack.main.c",L98/C13.
        mv hack.main.o hack/hack.main.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.makemon.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.makemon.c",L183/C1:        enexto
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L264/C7.
        mv hack.makemon.o hack/hack.makemon.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.mhitu.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.mhitu.o hack/hack.mhitu.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.mklev.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.mklev.c",L322/C1:  addrsx
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L277/C6.
w "hack/hack.mklev.c",L453/C1:  maker
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L284/C5.
w "hack/hack.mklev.c",L719/C1:  makeniche
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L289/C6.
        mv hack.mklev.o hack/hack.mklev.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.mkmaze.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.mkmaze.o hack/hack.mkmaze.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.mkobj.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.mkobj.o hack/hack.mkobj.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.mkshop.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.mkshop.o hack/hack.mkshop.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.mon.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.mon.o hack/hack.mon.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.monst.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.monst.o hack/hack.monst.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.o_init.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.o_init.o hack/hack.o_init.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.objnam.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.objnam.o hack/hack.objnam.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.options.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.options.c",L92/C1: parseoptions
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L373/C6.
        mv hack.options.o hack/hack.options.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.pager.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.pager.c",L365/C1:  page_file
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L386/C5.
        mv hack.pager.o hack/hack.pager.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.potion.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.potion.o hack/hack.potion.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.pri.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.pri.c",L159/C1:    tmp_at
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L405/C6.
w "hack/hack.pri.c",L191/C1:    Tmp_at
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L406/C6.
w "hack/hack.pri.c",L239/C1:    at
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L408/C6.
w "hack/hack.pri.c",L435/C1:    news0
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L416/C6.
        mv hack.pri.o hack/hack.pri.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.read.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.read.c",L541/C1:   litroom
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L438/C6.
        mv hack.read.o hack/hack.read.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.rip.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.rip.o hack/hack.rip.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.rumors.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.rumors.o hack/hack.rumors.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.save.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.save.o hack/hack.save.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.search.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.search.o hack/hack.search.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.shk.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.shk.o hack/hack.shk.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.shknam.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.shknam.o hack/hack.shknam.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.steal.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.steal.o hack/hack.steal.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.termcap.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.termcap.o hack/hack.termcap.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.timeout.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.timeout.o hack/hack.timeout.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.topl.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.topl.o hack/hack.topl.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.track.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.track.o hack/hack.track.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.trap.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.trap.o hack/hack.trap.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.tty.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.tty.o hack/hack.tty.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.u_init.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.u_init.o hack/hack.u_init.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.unix.c
"hack/config.h", line 196: warning: TRUE redefined
"hack/config.h", line 197: warning: FALSE redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.unix.o hack/hack.unix.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.vault.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.vault.o hack/hack.vault.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.version.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.version.o hack/hack.version.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.wield.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.wield.o hack/hack.wield.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.wizard.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.wizard.c",L145/C4: Expression has no side-effects.
        mv hack.wizard.o hack/hack.wizard.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.worm.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.worm.c",L212/C1:   cutworm
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L635/C6.
        mv hack.worm.o hack/hack.worm.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.worn.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hack.worn.o hack/hack.worn.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/hack.zap.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hack/hack.zap.c",L495/C1:    buzz
|    Function definition semantics overridden by prototype at
|    "hack/extern.h",L656/C6.
        mv hack.zap.o hack/hack.zap.o
        cc -O  -Dlint    -Iinclude   -Ihack  -c hack/rnd.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv rnd.o hack/rnd.o
        cc   hack/alloc.o hack/hack.Decl.o hack/hack.apply.o hack/hack.bones.o hack/hack.o hack/hack.cmd.o hack/hack.do.o hack/hack.do_name.o hack/hack.do_wear.o hack/hack.dog.o hack/hack.eat.o hack/hack.end.o hack/hack.engrave.o hack/hack.fight.o hack/hack.invent.o hack/hack.ioctl.o hack/hack.lev.o hack/hack.main.o hack/hack.makemon.o hack/hack.mhitu.o hack/hack.mklev.o hack/hack.mkmaze.o hack/hack.mkobj.o hack/hack.mkshop.o hack/hack.mon.o hack/hack.monst.o hack/hack.o_init.o hack/hack.objnam.o hack/hack.options.o hack/hack.pager.o hack/hack.potion.o hack/hack.pri.o hack/hack.read.o hack/hack.rip.o hack/hack.rumors.o hack/hack.save.o hack/hack.search.o hack/hack.shk.o hack/hack.shknam.o hack/hack.steal.o hack/hack.termcap.o hack/hack.timeout.o hack/hack.topl.o hack/hack.track.o hack/hack.trap.o hack/hack.tty.o hack/hack.u_init.o hack/hack.unix.o hack/hack.vault.o hack/hack.version.o hack/hack.wield.o hack/hack.wizard.o hack/hack.worm.o hack/hack.worn.o hack/hack.zap.o hack/rnd.o -lcurses  -o hack/hack
        ./substscr g m hack/hack.6.in hack/hack.6
Generating hack/hack.6 from hack/hack.6.in
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/endgame.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv endgame.o hangman/endgame.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/extern.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extern.o hangman/extern.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/getguess.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getguess.o hangman/getguess.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/getword.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getword.o hangman/getword.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o hangman/main.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/playgame.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv playgame.o hangman/playgame.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/prdata.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv prdata.o hangman/prdata.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/prman.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv prman.o hangman/prman.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/prword.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv prword.o hangman/prword.o
        cc -O  -Dlint    -Iinclude   -Ihangman  -c hangman/setup.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv setup.o hangman/setup.o
        cc   hangman/endgame.o hangman/extern.o hangman/getguess.o hangman/getword.o hangman/main.o hangman/playgame.o hangman/prdata.o hangman/prman.o hangman/prword.o hangman/setup.o lib/err.o lib/getprogname.o -lcurses  -o hangman/hangman
        ./substscr g m hangman/hangman.6.in hangman/hangman.6
Generating hangman/hangman.6 from hangman/hangman.6.in
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/hunt -Ihunt/huntd -c hunt/hunt/connect.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/hunt/connect.c",L43/C1: do_connect
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L435/C7.
        mv connect.o hunt/hunt/connect.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/hunt -Ihunt/huntd -c hunt/hunt/hunt.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv hunt.o hunt/hunt/hunt.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/hunt -Ihunt/huntd -c hunt/hunt/otto.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/hunt/otto.c",L164/C1:   otto
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L455/C7.
w "hunt/hunt/otto.c",L235/C1:   stop_look
|    Function definition semantics overridden by prototype at
|    "hunt/hunt/otto.c",L152/C13.
w "hunt/hunt/otto.c",L543/C1:   go_for_ammo
|    Function definition semantics overridden by prototype at
|    "hunt/hunt/otto.c",L148/C13.
        mv otto.o hunt/hunt/otto.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/hunt -Ihunt/huntd -c hunt/hunt/playit.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv playit.o hunt/hunt/playit.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/pathname.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pathname.o hunt/huntd/pathname.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/poll.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv poll.o lib/poll.o
        cc   hunt/hunt/connect.o hunt/hunt/hunt.o hunt/hunt/otto.o hunt/hunt/playit.o hunt/huntd/pathname.o lib/poll.o lib/err.o lib/getprogname.o -lcurses  -o hunt/hunt/hunt
        ./substscr g m hunt/hunt/hunt.6.in hunt/hunt/hunt.6
Generating hunt/hunt/hunt.6 from hunt/hunt/hunt.6.in
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/answer.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/huntd/answer.c",L378/C1:        get_ident
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L444/C15.
        mv answer.o hunt/huntd/answer.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/ctl.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ctl.o hunt/huntd/ctl.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/ctl_transact.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ctl_transact.o hunt/huntd/ctl_transact.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/draw.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/huntd/draw.c",L369/C1:  translate
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L478/C7.
        mv draw.o hunt/huntd/draw.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/driver.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/huntd/driver.c",L476/C1:        checkdam
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L428/C7.
        mv driver.o hunt/huntd/driver.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/execute.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/huntd/execute.c",L444/C1:       add_shot
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L420/C7.
w "hunt/huntd/execute.c",L486/C1:       create_shot
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L433/C16.
        mv execute.o hunt/huntd/execute.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/expl.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/huntd/expl.c",L49/C1:   showexpl
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L473/C7.
        mv expl.o hunt/huntd/expl.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/extern.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extern.o hunt/huntd/extern.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/faketalk.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv faketalk.o hunt/huntd/faketalk.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/get_names.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv get_names.o hunt/huntd/get_names.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/makemaze.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv makemaze.o hunt/huntd/makemaze.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/shots.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "hunt/huntd/shots.c",L1065/C1:        opposite
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L454/C6.
w "hunt/huntd/shots.c",L1106/C1:        fixshots
|    Function definition semantics overridden by prototype at
|    "hunt/huntd/hunt.h",L443/C7.
        mv shots.o hunt/huntd/shots.o
        cc -O  -Dlint   -DRANDOM -DREFLECT -DMONITOR -DOOZE -DFLY -DVOLCANO -DBOOTS -DOTTO -DINTERNET -DLOG -DBSD_RELEASE=44 -DUSE_CURSES -DSIGNAL_TYPE=void -DHUNTD=\"/usr/local/bsdgames/games/huntd\" -Iinclude   -Ihunt/huntd  -c hunt/huntd/terminal.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv terminal.o hunt/huntd/terminal.o
        cc   hunt/huntd/answer.o hunt/huntd/ctl.o hunt/huntd/ctl_transact.o hunt/huntd/draw.o hunt/huntd/driver.o hunt/huntd/execute.o hunt/huntd/expl.o hunt/huntd/extern.o hunt/huntd/faketalk.o hunt/huntd/get_names.o hunt/huntd/makemaze.o hunt/huntd/pathname.o hunt/huntd/shots.o hunt/huntd/terminal.o lib/poll.o lib/err.o lib/getprogname.o   -o hunt/huntd/huntd
        ./substscr g m hunt/huntd/huntd.6.in hunt/huntd/huntd.6
Generating hunt/huntd/huntd.6 from hunt/huntd/huntd.6.in
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/comp.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "mille/comp.c",L439/C1:       canplay
|    Function definition semantics overridden by prototype at
|    "mille/mille.h",L248/C5.
        mv comp.o mille/comp.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/end.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv end.o mille/end.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/extern.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extern.o mille/extern.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/init.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv init.o mille/init.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/mille.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv mille.o mille/mille.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/misc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv misc.o mille/misc.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/move.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "mille/move.c",L506/C1:       account
|    Function definition semantics overridden by prototype at
|    "mille/mille.h",L246/C6.
        mv move.o mille/move.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/print.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "mille/print.c",L106/C1:      show_card
|    Function definition semantics overridden by prototype at
|    "mille/mille.h",L277/C6.
        mv print.o mille/print.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/roll.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv roll.o mille/roll.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/save.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv save.o mille/save.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/types.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "mille/types.c",L48/C1:       is_repair
|    Function definition semantics overridden by prototype at
|    "mille/mille.h",L262/C5.
w "mille/types.c",L57/C1:       safety
|    Function definition semantics overridden by prototype at
|    "mille/mille.h",L275/C5.
        mv types.o mille/types.o
        cc -O  -Dlint    -Iinclude   -Imille  -c mille/varpush.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv varpush.o mille/varpush.o
        cc   mille/comp.o mille/end.o mille/extern.o mille/init.o mille/mille.o mille/misc.o mille/move.o mille/print.o mille/roll.o mille/save.o mille/types.o mille/varpush.o lib/err.o lib/getprogname.o -lcurses  -o mille/mille
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/cards.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv cards.o monop/cards.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/execute.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv execute.o monop/execute.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/getinp.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getinp.o monop/getinp.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/houses.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv houses.o monop/houses.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/jail.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv jail.o monop/jail.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/misc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv misc.o monop/misc.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/monop.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv monop.o monop/monop.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/morg.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv morg.o monop/morg.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/print.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "monop/print.c",L85/C1:       printsq
|    Function definition semantics overridden by prototype at
|    "monop/monop.h",L182/C6.
        mv print.o monop/print.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/prop.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "monop/prop.c",L99/C1:        del_list
|    Function definition semantics overridden by prototype at
|    "monop/monop.h",L188/C6.
        mv prop.o monop/prop.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/rent.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv rent.o monop/rent.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/roll.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv roll.o monop/roll.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/spec.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv spec.o monop/spec.o
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/trade.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv trade.o monop/trade.o
        cc   monop/cards.o monop/execute.o monop/getinp.o monop/houses.o monop/jail.o monop/misc.o monop/monop.o monop/morg.o monop/print.o monop/prop.o monop/rent.o monop/roll.o monop/spec.o monop/trade.o lib/err.o lib/getprogname.o   -o monop/monop
        cc -O  -Dlint    -Iinclude   -Imonop  -c monop/initdeck.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv initdeck.o monop/initdeck.o
        cc   monop/initdeck.o   -o monop/initdeck
        monop/initdeck monop/cards.inp monop/cards.pck
There were 16 com. chest and 16 chance cards
        ./substscr g m monop/monop.6.in monop/monop.6
Generating monop/monop.6 from monop/monop.6.in
        cc -O  -Dlint    -Iinclude   -Imorse  -c morse/morse.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv morse.o morse/morse.o
        cc   morse/morse.o   -o morse/morse
        cc -O  -Dlint   -D_GNU_SOURCE -Iinclude   -Inumber  -c number/number.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv number.o number/number.o
        cc   number/number.o lib/err.o lib/getprogname.o   -o number/number
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/fight.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv fight.o phantasia/fight.o
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/gamesupport.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "phantasia/gamesupport.c",L11/C1:     changestats
|    Function definition semantics overridden by prototype at
|    "phantasia/phantglobs.h",L77/C6.
        mv gamesupport.o phantasia/gamesupport.o
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/interplayer.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "phantasia/interplayer.c",L540/C1:    userlist
|    Function definition semantics overridden by prototype at
|    "phantasia/phantglobs.h",L128/C6.
        mv interplayer.o phantasia/interplayer.o
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/io.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "phantasia/io.c",L156/C1:     getanswer
|    Function definition semantics overridden by prototype at
|    "phantasia/phantglobs.h",L95/C5.
        mv io.o phantasia/io.o
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o phantasia/main.o
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/misc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
w "phantasia/misc.c",L65/C1:    descrlocation
|    Function definition semantics overridden by prototype at
|    "phantasia/phantglobs.h",L63/C13.
w "phantasia/misc.c",L447/C1:   descrtype
|    Function definition semantics overridden by prototype at
|    "phantasia/phantglobs.h",L65/C13.
        mv misc.o phantasia/misc.o
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/phantglobs.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv phantglobs.o phantasia/phantglobs.o
        cc   phantasia/fight.o phantasia/gamesupport.o phantasia/interplayer.o phantasia/io.o phantasia/main.o phantasia/misc.o phantasia/phantglobs.o -lm -lcurses  -o phantasia/phantasia
        cc -O  -Dlint    -Iinclude   -Iphantasia  -c phantasia/setup.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv setup.o phantasia/setup.o
        cc   phantasia/phantglobs.o phantasia/setup.o -lm  -o phantasia/setup
        cd phantasia && ./setup -m monsters.asc
        touch phantasia/scorefiles.stamp
        cc -O  -Dlint    -Iinclude   -Ipig  -c pig/pig.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pig.o pig/pig.o
        cc   pig/pig.o lib/err.o lib/getprogname.o   -o pig/pig
        cc -O  -Dlint    -Iinclude   -Ipom  -c pom/pom.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pom.o pom/pom.o
        cc   pom/pom.o lib/err.o lib/getprogname.o -lm  -o pom/pom
        cc -O  -Dlint    -Iinclude   -Ippt  -c ppt/ppt.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ppt.o ppt/ppt.o
        cc   ppt/ppt.o lib/err.o lib/getprogname.o   -o ppt/ppt
        cc -O  -Dlint   -D_GNU_SOURCE -Iinclude   -Iprimes  -c primes/pattern.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pattern.o primes/pattern.o
        cc -O  -Dlint   -D_GNU_SOURCE -Iinclude   -Iprimes  -c primes/primes.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv primes.o primes/primes.o
        cc   primes/pattern.o primes/pr_tbl.o primes/primes.o lib/err.o lib/getprogname.o -lm  -o primes/primes
        ./substscr g n quiz/datfiles/index.in quiz/datfiles/index
Generating quiz/datfiles/index from quiz/datfiles/index.in
        cc -O  -Dlint    -Iinclude   -Iquiz  -c quiz/quiz.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv quiz.o quiz/quiz.o
        cc -O  -Dlint    -Iinclude   -Iquiz  -c quiz/rxp.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv rxp.o quiz/rxp.o
        cc   quiz/quiz.o quiz/rxp.o lib/fgetln.o lib/snprintf.o lib/err.o lib/getprogname.o   -o quiz/quiz
        ./substscr g m quiz/quiz.6.in quiz/quiz.6
Generating quiz/quiz.6 from quiz/quiz.6.in
        cc -O  -Dlint    -Iinclude   -Irain  -c rain/rain.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv rain.o rain/rain.o
        cc   rain/rain.o lib/getprogname.o lib/err.o -lcurses  -o rain/rain
        cc -O  -Dlint    -Iinclude   -Irandom  -c random/random.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv random.o random/random.o
        cc   random/random.o lib/err.o lib/getprogname.o   -o random/random
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/auto.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
"robots/auto.c", line 63: warning: MIN redefined
"robots/auto.c", line 64: warning: MAX redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv auto.o robots/auto.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/extern.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv extern.o robots/extern.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/flush_in.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv flush_in.o robots/flush_in.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/init_field.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv init_field.o robots/init_field.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/main.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o robots/main.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/make_level.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv make_level.o robots/make_level.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/move.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv move.o robots/move.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/move_robs.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv move_robs.o robots/move_robs.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/play_level.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv play_level.o robots/play_level.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/query.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv query.o robots/query.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/rnd_pos.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv rnd_pos.o robots/rnd_pos.o
        cc -O  -Dlint   -DFANCY -DMAX_PER_UID=5 -Iinclude   -Irobots  -c robots/score.c
"/usr/include/sys/ioctl.h", line 74: warning: CTRL redefined
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv score.o robots/score.o
        cc   robots/auto.o robots/extern.o robots/flush_in.o robots/init_field.o robots/main.o robots/make_level.o robots/move.o robots/move_robs.o robots/play_level.o robots/query.o robots/rnd_pos.o robots/score.o lib/err.o lib/getprogname.o -lcurses  -o robots/robots
        ./substscr g m robots/robots.6.in robots/robots.6
Generating robots/robots.6 from robots/robots.6.in
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/assorted.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv assorted.o sail/assorted.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/game.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv game.o sail/game.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/globals.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv globals.o sail/globals.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/dr_1.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dr_1.o sail/dr_1.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/dr_2.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dr_2.o sail/dr_2.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/dr_3.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dr_3.o sail/dr_3.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/dr_4.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dr_4.o sail/dr_4.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/dr_5.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dr_5.o sail/dr_5.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/dr_main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dr_main.o sail/dr_main.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/lo_main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv lo_main.o sail/lo_main.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o sail/main.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/misc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv misc.o sail/misc.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/parties.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv parties.o sail/parties.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_1.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_1.o sail/pl_1.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_2.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_2.o sail/pl_2.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_3.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_3.o sail/pl_3.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_4.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_4.o sail/pl_4.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_5.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_5.o sail/pl_5.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_6.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_6.o sail/pl_6.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_7.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_7.o sail/pl_7.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/pl_main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv pl_main.o sail/pl_main.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/sync.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv sync.o sail/sync.o
        cc -O  -Dlint    -Iinclude   -Isail  -c sail/version.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv version.o sail/version.o
        cc -O  -Dlint    -Iinclude   -Ilib  -c lib/vwprintw.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv vwprintw.o lib/vwprintw.o
        cc   sail/assorted.o sail/game.o sail/globals.o sail/dr_1.o sail/dr_2.o sail/dr_3.o sail/dr_4.o sail/dr_5.o sail/dr_main.o sail/lo_main.o sail/main.o sail/misc.o sail/parties.o sail/pl_1.o sail/pl_2.o sail/pl_3.o sail/pl_4.o sail/pl_5.o sail/pl_6.o sail/pl_7.o sail/pl_main.o sail/sync.o sail/version.o lib/strlcpy.o lib/flock.o lib/err.o lib/getprogname.o lib/vwprintw.o lib/snprintf.o -lcurses  -o sail/sail
        cc -O  -Dlint    -Iinclude   -Isnake/snake  -c snake/snake/snake.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv snake.o snake/snake/snake.o
        cc   snake/snake/snake.o lib/err.o lib/getprogname.o -lcurses -lm  -o snake/snake/snake
        ./substscr g m snake/snake/snake.6.in snake/snake/snake.6
Generating snake/snake/snake.6 from snake/snake/snake.6.in
        cc -O  -Dlint    -Iinclude   -Isnake/snscore -Isnake/snake -c snake/snscore/snscore.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv snscore.o snake/snscore/snscore.o
        cc   snake/snscore/snscore.o lib/err.o lib/getprogname.o   -o snake/snscore/snscore
        cc -O  -Dlint    -Iinclude   -Itetris  -c tetris/input.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv input.o tetris/input.o
        cc -O  -Dlint    -Iinclude   -Itetris  -c tetris/scores.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv scores.o tetris/scores.o
        cc -O  -Dlint    -Iinclude   -Itetris  -c tetris/screen.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv screen.o tetris/screen.o
        cc -O  -Dlint    -Iinclude   -Itetris  -c tetris/shapes.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv shapes.o tetris/shapes.o
        cc -O  -Dlint    -Iinclude   -Itetris  -c tetris/tetris.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv tetris.o tetris/tetris.o
        cc   tetris/input.o tetris/scores.o tetris/screen.o tetris/shapes.o tetris/tetris.o lib/err.o lib/getprogname.o -lcurses  -o tetris/tetris
ld warning: Multiply defined symbol ospeed, in /usr/lib/libcurses.a, has more than one size
        ./substscr g m tetris/tetris.6.in tetris/tetris.6
Generating tetris/tetris.6 from tetris/tetris.6.in
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/abandon.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv abandon.o trek/abandon.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/attack.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv attack.o trek/attack.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/autover.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv autover.o trek/autover.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/capture.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv capture.o trek/capture.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/cgetc.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv cgetc.o trek/cgetc.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/check_out.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv check_out.o trek/check_out.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/checkcond.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv checkcond.o trek/checkcond.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/compkl.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv compkl.o trek/compkl.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/computer.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv computer.o trek/computer.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/damage.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv damage.o trek/damage.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/damaged.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv damaged.o trek/damaged.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/dcrept.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dcrept.o trek/dcrept.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/destruct.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv destruct.o trek/destruct.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/dock.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dock.o trek/dock.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/dumpgame.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dumpgame.o trek/dumpgame.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/dumpme.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dumpme.o trek/dumpme.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/dumpssradio.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv dumpssradio.o trek/dumpssradio.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/events.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv events.o trek/events.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/externs.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv externs.o trek/externs.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/getcodi.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getcodi.o trek/getcodi.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/getpar.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv getpar.o trek/getpar.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/help.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv help.o trek/help.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/impulse.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv impulse.o trek/impulse.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/initquad.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv initquad.o trek/initquad.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/kill.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv kill.o trek/kill.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/klmove.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv klmove.o trek/klmove.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/lose.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv lose.o trek/lose.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/lrscan.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv lrscan.o trek/lrscan.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/main.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv main.o trek/main.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/move.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv move.o trek/move.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/nova.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv nova.o trek/nova.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/out.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv out.o trek/out.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/phaser.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv phaser.o trek/phaser.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/play.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv play.o trek/play.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/ram.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ram.o trek/ram.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/ranf.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv ranf.o trek/ranf.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/rest.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv rest.o trek/rest.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/schedule.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv schedule.o trek/schedule.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/score.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv score.o trek/score.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/setup.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv setup.o trek/setup.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/setwarp.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv setwarp.o trek/setwarp.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/shield.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv shield.o trek/shield.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/snova.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv snova.o trek/snova.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/srscan.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv srscan.o trek/srscan.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/systemname.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv systemname.o trek/systemname.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/torped.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv torped.o trek/torped.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/visual.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv visual.o trek/visual.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/warp.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv warp.o trek/warp.o
        cc -O  -Dlint    -Iinclude   -Itrek  -c trek/win.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv win.o trek/win.o
        cc   trek/abandon.o trek/attack.o trek/autover.o trek/capture.o trek/cgetc.o trek/check_out.o trek/checkcond.o trek/compkl.o trek/computer.o trek/damage.o trek/damaged.o trek/dcrept.o trek/destruct.o trek/dock.o trek/dumpgame.o trek/dumpme.o trek/dumpssradio.o trek/events.o trek/externs.o trek/getcodi.o trek/getpar.o trek/help.o trek/impulse.o trek/initquad.o trek/kill.o trek/klmove.o trek/lose.o trek/lrscan.o trek/main.o trek/move.o trek/nova.o trek/out.o trek/phaser.o trek/play.o trek/ram.o trek/ranf.o trek/rest.o trek/schedule.o trek/score.o trek/setup.o trek/setwarp.o trek/shield.o trek/snova.o trek/srscan.o trek/systemname.o trek/torped.o trek/visual.o trek/warp.o trek/win.o lib/err.o lib/getprogname.o -lm  -o trek/trek
        ./substscr g m trek/trek.6.in trek/trek.6
Generating trek/trek.6 from trek/trek.6.in
        cc -O  -Dlint    -Iinclude   -Iworm  -c worm/worm.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv worm.o worm/worm.o
        cc   worm/worm.o lib/err.o lib/getprogname.o -lcurses  -o worm/worm
        cc -O  -Dlint    -Iinclude   -Iworms  -c worms/worms.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv worms.o worms/worms.o
        cc   worms/worms.o lib/err.o lib/getprogname.o -lcurses  -o worms/worms
        ./substscr g s wtf/wtf.in wtf/wtf
Generating wtf/wtf from wtf/wtf.in
        ./substscr g m wtf/wtf.6.in wtf/wtf.6
Generating wtf/wtf.6 from wtf/wtf.6.in
        cc -O  -Dlint    -Iinclude   -Iwump  -c wump/wump.c
MetaWare High C Compiler R2.2g
(c) Copyright 1987-90, MetaWare Incorporated
        mv wump.o wump/wump.o
        cc   wump/wump.o lib/err.o lib/getprogname.o   -o wump/wump

real    14:28.61
user     4:41.90
sys      2:23.31

$ timex make check
        set -e; for f in tests/*.test; do echo $f; $f; done
tests/battlestar.test
battlestar test 1... PASS
battlestar test 2... PASS
battlestar test 3... PASS
battlestar test 4... PASS
battlestar test 5... PASS
battlestar test 6... PASS (skipped)
battlestar test 7... PASS (skipped)
battlestar test 8... PASS
battlestar test 9... PASS
battlestar test 10... PASS
battlestar test 11... PASS
battlestar test 12... PASS
battlestar test 13... PASS
battlestar test 14... PASS
battlestar test 15... PASS
battlestar test 16... PASS
battlestar test 17... PASS
battlestar test 18... PASS
battlestar test 19... PASS
battlestar test 20... PASS
battlestar test 21... PASS
battlestar test 22... PASS
battlestar test 23... PASS
battlestar test 24... PASS
battlestar test 25... PASS
battlestar test 26... PASS
battlestar test 27... PASS
battlestar test 28... PASS
battlestar test 29... PASS
battlestar test 30... PASS
battlestar test 31... PASS
battlestar test 32... PASS
battlestar test 33... PASS
battlestar test 34... PASS
battlestar test 35... PASS
battlestar test 36... PASS
battlestar test 37... PASS
battlestar test 38... PASS
battlestar test 39... PASS
battlestar test 40... PASS
battlestar test 41... PASS
battlestar test 42... PASS
battlestar test 43... PASS
tests/bcd.test
bcd test 1... PASS
bcd test 2... PASS
bcd test 3... PASS
bcd test 4... PASS
bcd test 5... PASS
tests/caesar.test
caesar test 1... PASS
caesar test 2... PASS
caesar test 3... PASS
tests/factor.test
factor test 1... PASS
factor test 2... PASS
factor test 3... PASS
factor test 4... PASS
factor test 5... PASS
tests/morse.test
morse test 1... PASS
morse test 2... PASS
morse test 3... PASS
morse test 4... PASS
morse test 5... PASS
morse test 6... PASS
morse test 7... PASS
tests/number.test
number test 1... PASS
number test 2... PASS
number test 3... PASS
tests/pig.test
pig test 1... PASS
pig test 2... PASS
pig test 3... PASS
tests/pom.test
pom test 1... PASS
pom test 2... PASS
pom test 3... PASS
pom test 4... PASS
pom test 5... PASS
pom test 6... PASS
pom test 7... PASS
pom test 8... PASS
pom test 9... PASS
pom test 10... PASS
pom test 11... PASS
pom test 12... PASS
pom test 13... PASS
pom test 14... PASS
pom test 15... PASS
pom test 16... PASS
pom test 17... PASS
pom test 18... PASS
pom test 19... PASS
pom test 20... PASS
pom test 21... PASS
pom test 22... PASS
pom test 23... PASS
pom test 24... PASS
tests/ppt.test
ppt test 1... PASS
ppt test 2... PASS
ppt test 3... PASS
tests/primes.test
primes test 1... PASS
primes test 2... PASS
primes test 3... PASS

real       21.85
user        2.36
sys         6.03

$ exit
dirtbike # whoami
root
dirtbike # timex make install
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 adventure/adventure /usr/local/bsdgames/games/adventure
        : adventure
        /u/build/BSDGames-master/install-man adventure/adventure.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 arithmetic/arithmetic /usr/local/bsdgames/games/arithmetic
        : arithmetic
        /u/build/BSDGames-master/install-man arithmetic/arithmetic.6
        set -e; for d in /usr/local/bsdgames/share/atc /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for g in Game_List `cat atc/games/Game_List`; do install -c -m 0644 atc/games/$g /usr/local/bsdgames/share/atc/$g; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 atc/atc /usr/local/bsdgames/games/atc
        : atc
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/atc_score
        /u/build/BSDGames-master/install-man atc/atc.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 backgammon/backgammon/backgammon /usr/local/bsdgames/games/backgammon
        : backgammon
        /u/build/BSDGames-master/install-man backgammon/backgammon/backgammon.6
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 backgammon/teachgammon/teachgammon /usr/local/bsdgames/games/teachgammon
        : teachgammon
        /u/build/BSDGames-master/install-man backgammon.6 teachgammon.6
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 banner/banner /usr/local/bsdgames/games/banner
        : banner
        /u/build/BSDGames-master/install-man banner/banner.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 battlestar/battlestar /usr/local/bsdgames/games/battlestar
        : battlestar
        /u/build/BSDGames-master/install-man battlestar/battlestar.6
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/battlestar.log
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 bcd/bcd /usr/local/bsdgames/games/bcd
        : bcd
        /u/build/BSDGames-master/install-man bcd/bcd.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/share/boggle /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 boggle/boggle/boggle /usr/local/bsdgames/games/boggle
        : boggle
        /u/build/BSDGames-master/install-man boggle/boggle/boggle.6
        install -c -m 0644 boggle/boggle/helpfile /usr/local/bsdgames/share/boggle/helpfile
        set -e; for d in /usr/local/bsdgames/share/boggle /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0644 boggle/mkdict/dictionary /usr/local/bsdgames/share/boggle/dictionary
        set -e; for d in /usr/local/bsdgames/share/boggle /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0644 boggle/mkindex/dictindex /usr/local/bsdgames/share/boggle/dictindex
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 caesar/caesar /usr/local/bsdgames/games/caesar
        : caesar
        install -c -m 0755 caesar/rot13 /usr/local/bsdgames/games/rot13
        : rot13
        /u/build/BSDGames-master/install-man caesar/caesar.6
        /u/build/BSDGames-master/install-man caesar.6 rot13.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 canfield/canfield/canfield /usr/local/bsdgames/games/canfield
        : canfield
        /u/build/BSDGames-master/install-man canfield/canfield/canfield.6
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/cfscores
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 canfield/cfscores/cfscores /usr/local/bsdgames/games/cfscores
        : cfscores
        /u/build/BSDGames-master/install-man canfield.6 cfscores.6
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 countmail/countmail /usr/local/bsdgames/games/countmail
        : countmail
        /u/build/BSDGames-master/install-man countmail/countmail.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/share /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 cribbage/cribbage /usr/local/bsdgames/games/cribbage
        : cribbage
        install -c -m 0644 cribbage/cribbage.n /usr/local/bsdgames/share/cribbage.instr
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/criblog
        /u/build/BSDGames-master/install-man cribbage/cribbage.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man8 /usr/local/bsdgames/man/man5 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 2755 dm/dm /usr/local/bsdgames/games/dm
        /u/build/BSDGames-master/install-man dm/dm.8
        /u/build/BSDGames-master/install-man dm/dm.conf.5
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 factor/factor /usr/local/bsdgames/games/factor
        : factor
        /u/build/BSDGames-master/install-man factor/factor.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/share /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 fish/fish /usr/local/bsdgames/games/go-fish
        : go-fish
        install -c -m 0644 fish/fish.instr /usr/local/bsdgames/share/fish.instr
        rm -sf fish/go-fish.6; ln -s fish.6 fish/go-fish.6 # hack for rename
        /u/build/BSDGames-master/install-man fish/go-fish.6
        rm -f fish/go-fish.6
        set -e; for d in /usr/local/bsdgames/share/fortune /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for f in farber fortunes fortunes2 limerick startrek zippy \
            fortunes-o fortunes2-o limerick-o unamerican-o farber.dat fortunes.dat fortunes2.dat limerick.dat startrek.dat zippy.dat \
                fortunes-o.dat fortunes2-o.dat limerick-o.dat unamerican-o.dat; do \
                install -c -m 0644 fortune/datfiles/$f \
                    /usr/local/bsdgames/share/fortune/$f; \
            done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 fortune/fortune/fortune /usr/local/bsdgames/games/fortune
        : fortune
        /u/build/BSDGames-master/install-man fortune/fortune/fortune.6
        set -e; for d in /usr/bin /usr/local/bsdgames/man/man8 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 fortune/strfile/strfile /usr/bin/strfile
        /u/build/BSDGames-master/install-man fortune/strfile/strfile.8
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 gomoku/gomoku /usr/local/bsdgames/games/gomoku
        : gomoku
        /u/build/BSDGames-master/install-man gomoku/gomoku.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 hack/hack /usr/local/bsdgames/games/hack
        : hack
        /u/build/BSDGames-master/mkdirp /usr/local/bsdgames/var/hack
        set -e; for f in data help hh rumors; do install -c -m 0644 hack/$f /usr/local/bsdgames/var/hack/$f; done
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/hack/perm
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/hack/record
        /u/build/BSDGames-master/install-man hack/hack.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 hangman/hangman /usr/local/bsdgames/games/hangman
        : hangman
        /u/build/BSDGames-master/install-man hangman/hangman.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 hunt/hunt/hunt /usr/local/bsdgames/games/hunt
        : hunt
        /u/build/BSDGames-master/install-man hunt/hunt/hunt.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 hunt/huntd/huntd /usr/local/bsdgames/games/huntd
        /u/build/BSDGames-master/install-man hunt/huntd/huntd.6
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 mille/mille /usr/local/bsdgames/games/mille
        : mille
        /u/build/BSDGames-master/install-man mille/mille.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/share /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 monop/monop /usr/local/bsdgames/games/monop
        : monop
        /u/build/BSDGames-master/install-man monop/monop.6
        install -c -m 0644 monop/cards.pck /usr/local/bsdgames/share/monop-cards.pck
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 morse/morse /usr/local/bsdgames/games/morse
        : morse
        /u/build/BSDGames-master/install-man bcd.6 morse.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 number/number /usr/local/bsdgames/games/number
        : number
        /u/build/BSDGames-master/install-man number/number.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/var/phantasia /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 phantasia/phantasia /usr/local/bsdgames/games/phantasia
        : phantasia
        (set -e; for f in gold lastdead mess monsters motd void; do \
            cp phantasia/$f /usr/local/bsdgames/var/phantasia/$f; \
            /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/phantasia/$f; done)
        (set -e; for f in scoreboard characs; do \
            if [ ! -f /usr/local/bsdgames/var/phantasia/$f ]; then \
                cp phantasia/$f /usr/local/bsdgames/var/phantasia/$f; fi; done; \
            /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/phantasia/scoreboard; \
            /u/build/BSDGames-master/install-score -p /usr/local/bsdgames/var/phantasia/characs)
        /u/build/BSDGames-master/install-man phantasia/phantasia.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 pig/pig /usr/local/bsdgames/games/pig
        : pig
        /u/build/BSDGames-master/install-man pig/pig.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 pom/pom /usr/local/bsdgames/games/pom
        : pom
        /u/build/BSDGames-master/install-man pom/pom.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 ppt/ppt /usr/local/bsdgames/games/ppt
        : ppt
        /u/build/BSDGames-master/install-man bcd.6 ppt.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 primes/primes /usr/local/bsdgames/games/primes
        : primes
        /u/build/BSDGames-master/install-man primes/primes.6
        set -e; for d in /usr/local/bsdgames/share/quiz /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for c in africa america areas arith asia babies bard chinese  collectives ed elements europe flowers greek inca index latin  locomotive midearth morse mult murders poetry posneg pres province  seq-easy seq-hard sexes sov spell state trek ucc; do install -c -m 0644 quiz/datfiles/$c /usr/local/bsdgames/share/quiz/$c; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 quiz/quiz /usr/local/bsdgames/games/quiz
        : quiz
        /u/build/BSDGames-master/install-man quiz/quiz.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 rain/rain /usr/local/bsdgames/games/rain
        : rain
        /u/build/BSDGames-master/install-man rain/rain.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 random/random /usr/local/bsdgames/games/random
        : random
        /u/build/BSDGames-master/install-man random/random.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 robots/robots /usr/local/bsdgames/games/robots
        : robots
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/robots_roll
        /u/build/BSDGames-master/install-man robots/robots.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 sail/sail /usr/local/bsdgames/games/sail
        : sail
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/saillog
        /u/build/BSDGames-master/mkdirp /usr/local/bsdgames/var/sail
        /u/build/BSDGames-master/install-man sail/sail.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 snake/snake/snake /usr/local/bsdgames/games/snake
        : snake
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/snake.log
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/snakerawscores
        /u/build/BSDGames-master/install-man snake/snake/snake.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 snake/snscore/snscore /usr/local/bsdgames/games/snscore
        : snscore
        /u/build/BSDGames-master/install-man snake.6 snscore.6
        set -e; for d in  /; do /u/build/BSDGames-master/mkdirp $d; done
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 tetris/tetris /usr/local/bsdgames/games/tetris-bsd
        : tetris-bsd
        /u/build/BSDGames-master/install-score /usr/local/bsdgames/var/tetris-bsd.scores
        rm -f tetris/tetris-bsd.6; ln tetris/tetris.6 tetris/tetris-bsd.6
        /u/build/BSDGames-master/install-man tetris/tetris-bsd.6
        rm -f tetris/tetris-bsd.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/doc /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 trek/trek /usr/local/bsdgames/games/trek
        : trek
        /u/build/BSDGames-master/install-man trek/trek.6
        install -c -m 0644 trek/USD.doc/trek.me /usr/local/bsdgames/doc/trek.me
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 wargames/wargames /usr/local/bsdgames/games/wargames
        : wargames
        /u/build/BSDGames-master/install-man wargames/wargames.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 worm/worm /usr/local/bsdgames/games/worm
        : worm
        /u/build/BSDGames-master/install-man worm/worm.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 worms/worms /usr/local/bsdgames/games/worms
        : worms
        /u/build/BSDGames-master/install-man worms/worms.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/share /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 wtf/wtf /usr/local/bsdgames/games/wtf
        : wtf
        install -c -m 0644 wtf/acronyms /usr/local/bsdgames/share/acronyms
        install -c -m 0644 wtf/acronyms.comp /usr/local/bsdgames/share/acronyms.comp
        /u/build/BSDGames-master/install-man wtf/wtf.6
        set -e; for d in /usr/local/bsdgames/games /usr/local/bsdgames/man/man6 /usr/local/bsdgames/share /; do /u/build/BSDGames-master/mkdirp $d; done
        install -c -m 0755 wump/wump /usr/local/bsdgames/games/wump
        : wump
        install -c -m 0644 wump/wump.info /usr/local/bsdgames/share/wump.info
        /u/build/BSDGames-master/install-man wump/wump.6

real     2:31.31
user       10.61
sys        41.36

dirtbike #
