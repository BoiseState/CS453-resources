
/* files-processes/fork-and-exec.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Forks off a child process that will execute the specified program.
 * Parent will wait for child to terminate before exiting.
 *
 * man 3 execlp
 */
int main(int argc, char *argv[])
{
    pid_t pid;
    int status;
    char *exe = NULL;   /* program to exec */
    char **args = NULL; /* args to pass to exec'd program */

    /* check command line args in parent */
    if(argc >= 2) {
        exe = argv[1];
        args = &argv[1];
    }

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(errno);
    } else if (pid == 0) {  /* child */
        if(exe == NULL) { /* no args, use execlp */
            execlp("ls", "ls", (char *) NULL);
        } else { /* if there are args, use execvp (or could always use vp)*/
            execvp(exe, args);
        }
        /* if we get this far, something is not right */
        perror("exec failed");
        exit(errno);
    }

    /* parent continues concurrently with child */
    printf("Created child with pid %d\n",pid);

    /* wait for normal termination of child process */
    printf("Parent waiting for child to finish...\n");
    if (waitpid(pid, &status, 0) != pid) {
        perror("waitpid");
        exit(errno);
    } else if(WIFEXITED(status)) {
        printf("[%d] Child exited with status %d\n", getpid(), WEXITSTATUS(status));
    } else if(WIFSIGNALED(status)) {
        printf("[%d] Child terminated by signal %s\n", getpid(), strsignal(WTERMSIG(status)));
    }
    printf("Parent exiting\n");
    exit(EXIT_SUCCESS);
}
