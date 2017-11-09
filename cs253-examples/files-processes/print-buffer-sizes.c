
/* ch2/print-buffer-sizes.c */

#include    "ourhdr.h"
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

    if ( (fp = fopen("/etc/hosts", "r")) == NULL)
        err_sys("fopen error");
    if (getc(fp) == EOF)
        err_sys("getc error");
    pr_stdio("/etc/hosts", fp);
    exit(EXIT_SUCCESS);
}

void pr_stdio(const char *name, FILE *fp)
{
    printf("stream = %s, ", name);
    /* following is nonportable to non Linux systems */
    printf(", buffer size = %ld\n", fp->_IO_buf_end - fp->_IO_buf_base);
}
