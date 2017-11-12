
/* ch2/timeout.c: set time limit on a process */

#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

int pid; /* child process id */
char *progname;

static void onalarm(int signo);

int main(int argc, char *argv[])
{
	void error(char *msg, char *arg);
	int sec=10; /* default timeout */
	int status;

	/*signal(SIGINT, SIG_IGN);*/
	progname = argv[0];
	if (argc > 1 && argv[1][0] == '-') {
		sec = atoi(&argv[1][1]);
		argc--;
		argv++;
	}

	if (argc < 2) {
		error("Usage: %s [-10] command", progname);
	}

	signal(SIGALRM, onalarm);
	alarm(sec);
	if ((pid=fork()) == 0) {
		execvp(argv[1], &argv[1]);
		error("couldn't start %s", argv[1]);
	}
	if ((wait(&status) == -1) || WIFSIGNALED(status)) {
    	int signo = WTERMSIG(status);
		printf("%s %s", argv[1], strsignal(signo));
    }
	exit(WEXITSTATUS(status));
}

static void onalarm(int signo) /* kill child process when alarm arives */
{
	kill(pid, SIGKILL);
}

void error(char *msg, char *arg)
{
	fprintf(stderr, msg, arg);
	fprintf(stderr,"\n");
	exit(EX_SOFTWARE);
}

