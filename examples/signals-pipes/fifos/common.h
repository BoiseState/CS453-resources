/* Our own header, to be included *after* all standard system headers */

#ifndef	__COMMON_H
#define	__COMMON_H

#include <stdio.h>		/* for convenience */
#include <stdlib.h>		/* for convenience */
#include <string.h>		/* for convenience */
#include <unistd.h>		/* for convenience */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>


#define	min(a,b)	((a) < (b) ? (a) : (b))
#define	max(a,b)	((a) > (b) ? (a) : (b))

#define TRUE 1

#define MAXLINE 4096


void err_sys(const char *fmt, ...);


#define red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define blue  "\033[0;34m"        /* 9 -> strike ;  34 -> blue */
#define none   "\033[0m"        /* to flush the previous property */


#endif	/* __COMMON_H */
