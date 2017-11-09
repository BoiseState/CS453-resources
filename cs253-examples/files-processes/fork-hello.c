
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

/**
 * Demonstrates creating a single child process using the fork system call.
 * For more info on fork and getpid, see
 * man 2 fork
 * man 2 getpid
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    char *message = "Hello!";

    printf("\n\n[%d] Before fork\n", getpid());

    pid = fork(); /* from this point on, both processes are runnning the following code */

    if (pid < 0) {              /* something went wrong */
        perror("fork");         /* parent will be the only one to get here */
        exit(errno);            /* parent exits abnormally */
    } else if (pid == 0) {      /* is the pid 0? if so, we know we are child */
        /* sleep(5); */
        printf("[%d] %s\n", getpid(), message); /* child is the only one to get in here */
        exit(EXIT_SUCCESS);     /* child is done at this point */
    }

    /* parent continues here */
    printf("[%d] Created child with pid %d\n", getpid(), pid);
    /* sleep(3); */
    exit(EXIT_SUCCESS);
}
