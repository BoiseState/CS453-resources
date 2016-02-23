/* ch2/fork-two-children.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void err_sys(char *msg);

int main(void)
{
    pid_t   pid1, pid2;

    printf("original process, pid = %d\n", getpid());

    /* create the first child */
    if ((pid1 = fork()) < 0) {
        err_sys("fork error");
    } else if (pid1 == 0) { /* child */
        printf("first child, pid = %d, parent = %d\n", getpid(),getppid());
        fflush(stdout);
        exit(EXIT_SUCCESS);
    }

    /* create the second child */
    if ((pid2 = fork()) < 0) {
        err_sys("fork error");
    } else if (pid2 == 0) { /* child */
        printf("second child, pid = %d, parent = %d\n", getpid(),getppid());
        fflush(stdout);
        exit(EXIT_SUCCESS);
    }

    if (waitpid(pid1, NULL, 0) != pid1) /* wait for the first child */
        err_sys("waitpid error");
    if (waitpid(pid2, NULL, 0) != pid2) /* wait for the second child */
        err_sys("waitpid error");

    exit(EXIT_SUCCESS);
}

void err_sys(char *msg)
{
    fprintf(stderr, msg);
    fflush(NULL); /* flush all output streams */
    exit(EXIT_FAILURE); /* exit abnormally */
}
