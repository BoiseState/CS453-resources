#include <windows.h>
#include <stdio.h>
#include    "error.h"

void    pr_stdio(const char *, FILE *);

int main(void)
{
    FILE    *fp;

    fputs("enter any character\n", stdout);
    if (getchar() == EOF)
        err_sys("getchar error");
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin",  stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if ( (fp = fopen("C:\\Windows\\System32\\ntoskrnl.exe", "r")) == NULL)
        err_sys("fopen error");
    if (getc(fp) == EOF)
        err_sys("getc error");
    pr_stdio("junk", fp);

    ExitProcess(0);
}

void pr_stdio(const char *name, FILE *fp)
{
    printf("stream = %s, ", name);
    printf("_bufsiz = %d, _base = %d, _cnt = %d\n", fp->_bufsiz, fp->_base, fp->_cnt);
}
