
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

static void sig_handler(int);

int main(void) {

	int status;
	pid_t parent_pid, child_pid;

	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		printf("Parent: Unable to create handler for SIGUSR1\n");

	if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		printf("Parent: Unable to create handler for SIGUSR2\n");

	parent_pid = getpid();

	if ((child_pid = fork()) == 0) {
		kill(parent_pid, SIGUSR1);
		for (;;) pause();
	} else {
		kill(child_pid, SIGUSR2);
		sleep(2);
		printf("Parent: Terminating child...");
		kill(child_pid, SIGTERM);
		wait(&status);
		printf("done\n");
	}
	exit(0);
}

void sig_handler(int signo) 
{
	printf("-----In the signal handler\n");	
	switch(signo) {
	case SIGUSR1:
		printf("Parent: received SIGUSR1\n");
		fflush(NULL);
		break;
	case SIGUSR2:
		printf("Child: received SIGUSR2\n");
		fflush(NULL);
		break;
	default: break;
	}
	return;
}
	
