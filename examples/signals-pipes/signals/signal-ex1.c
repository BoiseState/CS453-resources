#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void onintr(int);

int main(void)
{
	/*if (signal(SIGINT, SIG_IGN) != SIG_ERR)*/
	/*if (signal(SIGINT, SIG_IGN) != SIG_IGN)*/
	if (signal(SIGINT, onintr) == SIG_ERR)
		perror("signal-ex1:");

	/* processing section */
	for(;;) 
		sleep(10);

	exit(0);
}

void onintr(int signo) 
{	
	printf("Caught Ctl-C\n");
	/* clean up on interrupt and then exiting would be an option in some programs */
	/*exit(1);*/
}
