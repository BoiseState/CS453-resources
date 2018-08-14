/* ch2/fork-and-wait.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DEBUG 1

void childs_play(void);
void err_sys(char *msg);

int main(void)
{
    pid_t   pid;

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) { /* child */
        childs_play();
        exit(EXIT_SUCCESS);
    }

    /* parent continues concurrently with child */

#ifdef DEBUG
    printf("Created child with pid %d\n",pid);
    sleep(4);
#endif

    printf("Shoo away!\n");

    /* wait for normal termination of child process */
    if (waitpid(pid, NULL, 0) != pid) {
        err_sys("waitpid error");
    }
    exit(EXIT_SUCCESS);
}

void childs_play(void)
{
#ifdef DEBUG
    sleep(3);
#endif

    printf("Hey, I need some money! \n");

#ifdef DEBUG
    sleep(1);
#endif
}

void err_sys(char *msg)
{
    fprintf(stderr, msg);
    fflush(NULL); /* flush all output streams */
    exit(EXIT_FAILURE); /* exit abnormally */
}
