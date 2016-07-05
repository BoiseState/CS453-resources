#include    "common.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
    int     n;
    pid_t   pid;
    char    line[MAXLINE];
    int fifo;
    int status;

    status = mkfifo("fifo1", 0600); // read/write by user's processes
    if (status < 0) {
        perror("hello-fifo");
    }

    if ((pid = fork()) < 0)
        err_sys("fork error");

    else if (pid > 0) {     /* parent */
        fifo = open("fifo1", O_WRONLY);
        write(fifo, "hello world\n", 12);

    } else {                /* child */
        fifo = open("fifo1", O_RDONLY);
        n = read(fifo, line, MAXLINE);
        printf("child read %d characters from the parent in the pipe: %s", n, line);
    }

    unlink("fifo1");
    exit(EXIT_SUCCESS);
}
