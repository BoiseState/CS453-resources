/* files-processes/fork-two-children.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Demonstrates creating a two child processes using the fork system call.
 * The parent waits for both children to finish before exiting.
 *
 * For more info on wait, see
 *
 * man 2 wait
 */
int main(void)
{
    pid_t pid1, pid2; /* keep track of both so we can wait for both */

    printf("original process, pid = %d\n", getpid());

    /* create the first child */
    if ((pid1 = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid1 == 0) { /* child */
        printf("first child, pid = %d, parent = %d\n", getpid(),getppid());
        fflush(stdout);
        exit(EXIT_SUCCESS);
    }

    /* create the second child */
    if ((pid2 = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid2 == 0) { /* child */
        printf("second child, pid = %d, parent = %d\n", getpid(),getppid());
        fflush(stdout);
        exit(EXIT_SUCCESS);
    }

    if (waitpid(pid1, NULL, 0) != pid1) { /* wait for the first child */
        perror("waitpid");
        exit(errno);
    }
    if (waitpid(pid2, NULL, 0) != pid2) { /* wait for the second child */
        perror("waitpid");
        exit(errno);
    }

    exit(EXIT_SUCCESS);
}
