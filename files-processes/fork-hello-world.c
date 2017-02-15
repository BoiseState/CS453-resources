/* files-processes/fork-hello-world.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>

/* #define DEBUG */

static void print_message(char *msg);

/**
 * Demonstrates creating a two child processes using the fork system call.
 * For more info on fork and getpid, see
 *
 * man 2 fork
 * man 2 getpid
 *
 * Notice that the order in which Hello and World are printed is not always the
 * same and the parent doesn't necessarily wait for the children to finish.
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    char *message1 = "Hello";
    char *message2 = "World";

#ifdef DEBUG
    printf("\n\n[%d] Before fork\n", getpid());
#endif

    /* create a child process */
    if ((pid = fork()) < 0) { /* uh-oh, something went wrong */
        perror("fork");
        exit(errno);
    } else if (pid == 0) {  /* first child */
        print_message(message1);
        /* sleep(2); */
        exit(EXIT_SUCCESS); /* first child exits */
    }

    /* parent continues and creates another child */
#ifdef DEBUG
    printf("[%d] Created child with pid %d\n", getpid(), pid);
#endif

    /* create a child process */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid == 0) {  /* second child */
        print_message(message2);
        /* sleep(2); */
        exit(EXIT_SUCCESS);
    }


    /* parent continues here */
#ifdef DEBUG
    printf("[%d] Created child with pid %d\n", getpid(), pid);
#endif
    /* sleep(2); */

    exit(EXIT_SUCCESS);
}

static void print_message(char *message)
{
    printf("%s ", message); /* child is the only one to get in here */
    fflush(NULL);
}
