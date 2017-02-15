
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>

#define MAXNUM 20000
#define TIMEOUT 30

/**
 * A "fork bomb". Forks off as many children as it can until it reaches the
 * system limit. To see the max user process limit on your system, use
 *
 * ulimit -u
 * ulimit -a will show all limits for various system resources
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    int i;

    for (i = 0; i < MAXNUM; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(errno);
        } else if (pid == 0) {  /* ith child */
            printf("[%d] I am child number %d (my parent is %d)\n", getpid(), i, getppid());
            sleep(TIMEOUT);
            exit(EXIT_SUCCESS);
        }
        printf("[%d] Created child number %d with pid %d\n", getpid(), i, pid);
    }

    exit(EXIT_SUCCESS);
}
