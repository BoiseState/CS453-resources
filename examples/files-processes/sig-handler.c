
/* ch2/sig-handler.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

void ourhandler(int signo);

int main(void)
{
	printf("Try to stop me...I dare you!\n");
	fflush(stdout);

	signal(SIGTSTP, ourhandler); // CTRL+z
	signal(SIGINT, ourhandler);  // CTRL+c

	while(1); // run forever

	exit(EXIT_SUCCESS);
}

/**
 * Ignores CTRL+c and CTRL+z (and prints an annoying message).
 */
void ourhandler(int signo)
{
	printf("Haha! You can't stop me with signal %s!!\n", strsignal(signo));
}
