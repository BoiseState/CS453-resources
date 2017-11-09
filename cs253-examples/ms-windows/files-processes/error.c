
#include <errno.h>      /* for definition of errno */
#include <stdarg.h>     /* ANSI C header file */
#include <windows.h>
#include <stdio.h>

#include    "error.h"

#define MAXLINE 4096

static void err_doit(const char *, va_list);

char    *pname = NULL;      /* caller can set this from argv[0] */

/* Nonfatal error related to a system call.
 * Print a message and return. */

void err_ret(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(fmt, ap);
    va_end(ap);
    return;
}

/* Fatal error related to a system call.
 * Print a message and terminate. */

void err_sys(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(fmt, ap);
    va_end(ap);
    ExitProcess(1);
}

/* Fatal error related to a system call.
 * Print a message, dump core, and terminate. */

void err_dump(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(fmt, ap);
    va_end(ap);
    abort();        /* dump core and terminate */
    ExitProcess(1);     /* shouldn't get here */
}

/* Nonfatal error unrelated to a system call.
 * Print a message and return. */

void err_msg(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(fmt, ap);
    va_end(ap);
    return;
}

/* Fatal error unrelated to a system call.
 * Print a message and terminate. */

void err_quit(const char *fmt, ...)
{
    va_list     ap;

    va_start(ap, fmt);
    err_doit(fmt, ap);
    va_end(ap);
    ExitProcess(1);
}

/* Print a message from caller, print formatted msg from system,
 * and return to caller. */

static void err_doit(const char *fmt, va_list ap)
{
    char    buf[MAXLINE];
    LPVOID  lpMsgBuf;
    DWORD dwErrorCode;

    vsprintf(buf, fmt, ap);
    strcat_s(buf, MAXLINE, "\n");
    fflush(stdout);     /* in case stdout and stderr are the same */
    fputs(buf, stderr);

    // Format the error message from the last failed call (if errorCode != 0)
    // (returns # of TCHARS in message -- 0 if failed)
    dwErrorCode = GetLastError();

    if (dwErrorCode != 0) {
        if ( FormatMessage(
                    FORMAT_MESSAGE_ALLOCATE_BUFFER |                    // source and processing options
                    FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL,                                                       // message source
                    dwErrorCode,                                            // message identifier
                    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // language identifier (Default language)
                    (LPTSTR) &lpMsgBuf,                                 // message buffer
                    0,                                                          // maximum size of message buffer (ignored with FORMAT_MESSAGE_ALLOCATE_BUFFER set)
                    NULL                                                        // array of message inserts
                )
           ) {
            // Display the formatted string.
            fprintf(stderr, "Err #%d: %s", dwErrorCode, (LPSTR)lpMsgBuf );
            // Free the buffer.
            LocalFree( lpMsgBuf );
        }
    }

    // Reset the error state
    SetLastError(0);

    fflush(NULL);       /* flushes all stdio output streams */
    return;
}
