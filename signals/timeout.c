
/* ch2/timeout.c: set time limit on a process */

#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

/* alarm signal handler function */
static void onalarm(int signo);

/* child process id. global so we have access to it in the 
 * signal handler. */
static int pid;

int main(int argc, char *argv[])
{
    void error(char *msg, char *arg);
    int timeout = 10;
    int status;
    char *progname;

    progname = argv[0];
    if (argc > 1 && argv[1][0] == '-') {
        timeout = atoi(&argv[1][1]);
        argc--;
        argv++;
    }

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-<timeout>] <command>\n", progname);
        exit(EXIT_FAILURE);
    }

    /* install alarm signal handler */
    signal(SIGALRM, onalarm);

    /* set alarm for timeout seconds */
    alarm(timeout);

    /* send child on its way */
    if ((pid = fork()) == 0) {
        printf("child [%d] executing %s\n", getpid(), argv[1]);
        execvp(argv[1], &argv[1]);
        perror("exec failed");
        exit(EXIT_FAILURE);
    }

    /* wait for it to finish */
    if((pid = wait(&status)) == -1) {
        perror("wait");
        exit(EXIT_FAILURE);
    } else if(WIFEXITED(status)) {
        printf("child [%d] exited normally with status %d\n", pid, WEXITSTATUS(status));
    } else if(WIFSIGNALED(status)) {
        printf("child [%d] terminated by signal %s\n", pid, strsignal(WTERMSIG(status)));
    }

    exit(WEXITSTATUS(status));
}

static void onalarm(int signo)   /* kill child process when alarm arives */
{
    kill(pid, SIGKILL);
}

