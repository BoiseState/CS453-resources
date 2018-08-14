/* ch2/fork-child-grandchild.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void err_sys(char *msg);
void run_child(void);
void run_grandchild(void);

int main(void)
{
    pid_t pid;

    printf("original process, pid = %d\n", getpid());

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* child */
        run_child();
    }

    /* original process waits for its child to finish */
    if (waitpid(pid, NULL, 0) != pid) {
        err_sys("waitpid error");
    }

    /* We're the parent (the original process); we continue executing,
       knowing that we're not the parent of the other process. */
    exit(EXIT_SUCCESS);
}

void run_child(void)
{
    pid_t   pid;

    printf("child = %d, parent = %d\n", getpid(), getppid());

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {  /* grandchild */
        run_grandchild();
    }

    /* child waits for the grandchild */
    if (waitpid(pid, NULL, 0) != pid) {
        err_sys("waitpid error");
    }
    exit(EXIT_SUCCESS); /* the child can now exit */
}

void run_grandchild(void)
{
    printf("grandchild = %d, parent = %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
}

void err_sys(char *msg)
{
    fprintf(stderr, msg);
    fflush(NULL); /* flush all output streams */
    exit(EXIT_FAILURE); /* exit abnormally */
}
