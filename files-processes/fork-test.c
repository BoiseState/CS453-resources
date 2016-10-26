
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>

#define MAXNUM 20000
#define TIMEOUT 30

int main(void)
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
