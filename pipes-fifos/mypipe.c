
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Pipes output of first program to input of second program.
 * Simulates functionality of shell |
 *
 * man 2 pipe
 * man 2 dup2
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    int fd[2];

    /* check command line args in parent */
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <command> <command>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(pipe(fd) < 0) {
        perror("pipe error");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    switch(pid) {
    case -1: /* error */
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        exit(errno);
        break;
    case 0: /* child */
        close(fd[1]); /* close write end */
        dup2(fd[0], STDIN_FILENO); /* map read to stdin */
        execlp(argv[2], argv[2], (char *) NULL);
        perror("child exec failed");
        exit(EXIT_FAILURE);
    default: /* parent */
        close(fd[0]); /* close read end */
        dup2(fd[1], STDOUT_FILENO); /* map write to stdout */
        execlp(argv[1], argv[1], (char *) NULL);
        perror("parent exec failed");
        exit(EXIT_FAILURE);
        break;
    }
}
