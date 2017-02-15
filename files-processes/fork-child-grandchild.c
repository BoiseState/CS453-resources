/* files-processes/fork-child-grandchild.c */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

static void run_child();
static void run_grandchild();

/**
 * Demonstrates creating a child process and a grandchild process.
 * Child waits for grandchild to finish. Parent waits for child to finish.
 */
int main(int argc, char *argv[])
{
    pid_t pid;

    printf("original process, pid = %d\n", getpid());

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid == 0) {  /* child */
        run_child();
    }

    /* original process waits for its child to finish */
    if (waitpid(pid, NULL, 0) != pid) {
        perror("waitpid");
        exit(errno);
    }

    /* We're the parent (the original process); we continue executing,
       knowing that we're not the parent of the other process. */
    exit(EXIT_SUCCESS);
}

void run_child()
{
    pid_t pid;

    printf("child = %d, parent = %d\n", getpid(), getppid());

    if ((pid = fork()) < 0) {
        perror("child fork");
        exit(errno);
    } else if (pid == 0) {  /* grandchild */
        run_grandchild();
    }

    /* child waits for the grandchild */
    if (waitpid(pid, NULL, 0) != pid) {
        perror("waitpid");
        exit(errno);
    }
    exit(EXIT_SUCCESS); /* the child can now exit */
}

void run_grandchild()
{
    printf("grandchild = %d, parent = %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
}
