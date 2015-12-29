#include	"common.h"


int main(void) {
    int		n, fd[2];
    pid_t	pid;
    char	line[MAXLINE];

    if (pipe(fd) < 0)
        err_sys("pipe error");

    if ((pid = fork()) < 0)
        err_sys("fork error");

    else if (pid > 0) {		/* parent */
        close(fd[0]); /* close read end of pipe */
        write(fd[1], "hello world\n", 12);

    } else {				/* child */
        close(fd[1]); /* close write end of pipe */
        n = read(fd[0], line, MAXLINE);
        printf("child read %d characters from the parent in the pipe: %s", n, line);
    }

    exit(EXIT_SUCCESS);
}
