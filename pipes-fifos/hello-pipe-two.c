#include "common.h"
#include <sys/wait.h>

int main(void)
{
    pid_t pids[2];
    int fd[2][2];
    int n, i, status;
    char line[MAXLINE];
    char message[MAXLINE];

    if (pipe(fd[0]) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    /* parent creates child 1 */
    pids[0] = fork();
    switch(pids[0]) {
    case -1:
        close(fd[0][0]);
        close(fd[0][1]);
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0:
        snprintf(message, MAXLINE, "%d goodbye world ", getpid());
        close(fd[0][0]); /* close read end of pipe */
        write(fd[0][1], message, strlen(message)+1);
        printf("child 1 wrote %ld chars to the parent in the pipe: %s\n",
               strlen(message)+1, message);
        exit(EXIT_SUCCESS);
    }

    /* parent creates child 2 */
    if (pipe(fd[1]) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }
    pids[1] = fork();
    switch(pids[1]) {
    case -1:
        close(fd[1][0]);
        close(fd[1][1]);
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0:
        snprintf(message, MAXLINE, "%d hello world ", getpid());
        close(fd[1][0]); /* close read end of pipe */
        write(fd[1][1], message, strlen(message)+1);
        printf("child 2 wrote %ld chars to the parent in the pipe: %s\n",
               strlen(message)+1, message);
        exit(EXIT_SUCCESS);
    }

    /* wait for each child to finish before reading */
    for(i = 0; i < 2; i++) {
        if (waitpid(pids[i], &status, 0) != pids[i]) {
            perror("waitpid");
        } else if(WIFEXITED(status)) { /* check if child exited normally */
            /* parent reads from pipe */
            close(fd[i][1]); /* close write end of pipe */
            n = read(fd[i][0], line, MAXLINE);
            printf("parent read %d chars from the child in the pipe: %s\n", n, line);
        }
    }
    exit(EXIT_SUCCESS);
}
