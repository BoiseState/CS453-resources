/* files-processes/fork-and-wait.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DEBUG 1

static void childs_play();

/**
 * Demonstrates creating a child process using the fork system call and
 * waiting for it to finish before terminating.
 *
 * For more info on wait and waitpid, see
 *
 * man 2 wait
 */
int main(int argc, char *argv[])
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid == 0) { /* child */
        childs_play();
        exit(EXIT_SUCCESS);
    }

    /* parent continues concurrently with child */

#ifdef DEBUG
    printf("[%d] Created child with pid %d\n", getpid(), pid);
#endif

    /* parent waits for normal termination of child process */
    if (waitpid(pid, NULL, 0) != pid) {
        perror("waitpid"); /* something went wrong */
        exit(errno);
    }

    printf("[%d] Shoo away!\n", getpid());

    exit(EXIT_SUCCESS);
}

static void childs_play()
{
    printf("[%d] Hey, I need some money! \n", getpid());
    sleep(1);
}
