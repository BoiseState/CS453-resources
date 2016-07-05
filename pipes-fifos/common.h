/* Our own header, to be included *after* all standard system headers */

#ifndef __COMMON_H
#define __COMMON_H

#include <stdio.h>      /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <string.h>     /* for convenience */
#include <unistd.h>     /* for convenience */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>


#define min(a,b)    ((a) < (b) ? (a) : (b))
#define max(a,b)    ((a) > (b) ? (a) : (b))

#define TRUE 1

#define MAXLINE 4096


void err_sys(const char *fmt, ...);


#define red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define cyan  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
#define green "\033[4;32m"        /* 4 -> underline ;  32 -> green */
#define blue  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */

#define black  "\033[0;30m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"

#define none   "\033[0m"        /* to flush the previous property */


#endif  /* __COMMON_H */
