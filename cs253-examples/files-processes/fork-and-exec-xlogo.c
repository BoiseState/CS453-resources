
/* files-processes/fork-and-exec-xlogo.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Forks off multiple child processes that will execute the xlogo program.
 * Parent will wait for any child to terminate before exiting.
 *
 * How can we make the parent to wait for all 3 children? A specific child?
 *
 * man 2 waitpid
 */
int main(int argc, char **argv)
{
    pid_t pids[4];
    pid_t pid;
    int i, status;

    for (i = 0; i < 4; i++) {
        if ((pid = fork()) == 0) {
            execlp("xlogo", "xlogo", (char *) 0);
            // if we get here, something went wrong
            perror("execlp");
            exit(errno);
        } else if (pid > 0) {
            pids[i] = pid;
            printf("pids[%d] is %d\n",i,pids[i]);
        } else {
            perror("fork");
            exit(errno);
        }
    }

    /* wait for any process to terminate */
    if((pid = waitpid(-1, &status, 0)) == -1) {
        perror("waitpid");
    } else if(WIFEXITED(status)) {
        printf("[%d] child [%d] exited with status %d\n", getpid(), pid, WEXITSTATUS(status));
    } else if(WIFSIGNALED(status)) {
        printf("[%d] child [%d] terminated by signal %s\n", getpid(), pid, strsignal(WTERMSIG(status)));
    }

    exit(EXIT_SUCCESS);
}
