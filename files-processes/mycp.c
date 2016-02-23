
/*
 * A simple file copy example. Not for use on directories or links.
 */

#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sysexits.h>
#include <unistd.h>

int main(int argc, char * argv[]);

#define MODE 0666
#define BUF_SIZE 4194304


int main(int argc, char *argv[])
{
    int src, dst, in, out;
    char buf[BUF_SIZE];
    int bufsize;

    if (argc != 4) {
        fprintf(stderr,"Usage: %s <buffer size> <src> <dest>\n", argv[0]);
        exit(EX_USAGE);
    }
    bufsize = atoi(argv[1]);
    if (bufsize > BUF_SIZE) {
        fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[0], BUF_SIZE);
        exit(EX_USAGE);
    }

    src = open(argv[2], O_RDONLY);
    if (src < 0) exit(EX_NOINPUT);
    dst = creat(argv[3], MODE);
    if (dst < 0) exit(EX_CANTCREAT);

    while (1) {
        in = read(src, buf, bufsize);
        if (in <= 0) break;
        out = write(dst, buf, in);
        if (out <= 0) break;
    }

    close(src);
    close(dst);
    exit(EXIT_SUCCESS);
}

/* vim: set ts=4: */
