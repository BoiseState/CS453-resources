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
    int status1, status2;

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

    /* wait for the first child */
    if (waitpid(pid1, &status1, 0) != pid1) {
        perror("waitpid");
        exit(errno);
    } else if(WIFEXITED(status1)) { /* check if first child exited normally */
        printf("Child [%d] exited with status %d\n", pid1, WEXITSTATUS(status1));
    }

    /* wait for the second child */
    if (waitpid(pid2, &status2, 0) != pid2) {
        perror("waitpid");
        exit(errno);
    } else if(WIFEXITED(status2)) { /* check if second child exited normally */
        printf("Child [%d] exited with status %d\n", pid2, WEXITSTATUS(status2));
    }

    exit(EXIT_SUCCESS);
}
