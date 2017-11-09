#include    "common.h"

int main(void)
{
    pid_t pid;
    int n, fd[2];
    char *message;
    char line[MAXLINE];

    if (pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    switch(pid) {
    case -1:
        close(fd[0]);
        close(fd[1]);
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0: /* child */
        close(fd[1]); /* close write end of pipe */
        n = read(fd[0], line, MAXLINE);
        printf("child read %d chars from the parent in the pipe: %s\n", n, line);
        close(fd[0]); /* close read end when we are done */
        exit(EXIT_SUCCESS);
    default: /* parent */
        message = "hello world";
        close(fd[0]); /* close read end of pipe */
        write(fd[1], message, strlen(message));
        write(fd[1], " you are awesome", strlen(" you are awesome")+1 );
        close(fd[1]); /* close write end when we are done */
        exit(EXIT_SUCCESS);
    }
}
