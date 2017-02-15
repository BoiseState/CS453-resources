/* Our own header, to be included *after* all standard system headers */

#ifndef __OURHDR_H
#define __OURHDR_H

#include    <sys/types.h>   /* required for some of our prototypes */
#include    <stdio.h>       /* for convenience */
#include    <stdlib.h>      /* for convenience */
#include    <string.h>      /* for convenience */
#include    <unistd.h>      /* for convenience */

#define MAXLINE 4096            /* max line length */

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
/* default file access permissions for new files */
#define DIR_MODE    (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)
/* default permissions for new directories */

typedef void    Sigfunc(int);   /* for signal handlers */


void    err_dump(const char *, ...);    /* {App misc_source} */
void    err_msg(const char *, ...);
void    err_quit(const char *, ...);
void    err_ret(const char *, ...);
void    err_sys(const char *, ...);

#endif  /* __OURHDR_H */
