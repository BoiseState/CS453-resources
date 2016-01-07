/* signal-ex6 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void onintr(int);

int main(void)
{
	struct sigaction sa;

	sa.sa_handler = onintr;
	/*sa.sa_handler = SIG_IGN;*/
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		perror("signal-ex6:");

	/* processing section */
	for(;;) 
		sleep(4);

	exit(0);
}

void onintr(int signo) /* clean up on interrupt */
{	
	printf("Caught Ctl-C\n");
	exit(1);
}
