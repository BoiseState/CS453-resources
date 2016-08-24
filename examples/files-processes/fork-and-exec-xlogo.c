#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void err_sys(char *msg);

int main(int argc, char **argv)
{
    pid_t  pids[4], pid;
    int i, status;

    for (i=0; i<4; i++) {
        if ((pid = fork()) == 0) {
            execlp("xlogo", "xlogo", (char *) 0);
            // if we get here, something went wrong
            /* fprintf(stderr, "Child %d (%d): ", i, getpid()); */
            /* perror("execlp failed"); */
        } else if (pid > 0) {
            pids[i] = pid;
            printf("pids[%d] is %d\n",i,pids[i]);
        } else {
            err_sys("fork error");
        }
    }

    /* other code */
    /*for (i = 0; i < 3; i++)*/
        waitpid(-1, &status, 0);
    exit(0);
}

void err_sys(char *msg)
{
    fprintf(stderr, msg);
    fflush(NULL); /* flush all output streams */
    exit(EXIT_FAILURE); /* exit abnormally */
}
