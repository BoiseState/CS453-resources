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
    int status;

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
    if (waitpid(pid, &status, 0) != pid) {
        perror("waitpid");
        exit(errno);
    } else if(WIFEXITED(status)) { /* check if child exited normally */
        printf("[%d] Child exited with status %d\n", getpid(), WEXITSTATUS(status));
    }

    printf("[%d] Shoo away!\n", getpid());

    exit(EXIT_SUCCESS);
}

static void childs_play()
{
    printf("[%d] Hey, I need some money! \n", getpid());
    sleep(1);
}
