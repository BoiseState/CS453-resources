/*
 * Demonstrate how to block and unblock signals
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "ourhdr.h"

static void onintr();


int main(void)
{
	sigset_t newmask, oldmask, pendmask;

	signal(SIGINT, onintr);

	sigemptyset(&newmask);
	sigaddset(&newmask, SIGINT);
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("Error in blocking signals\n");

	/* processing section: SIGINT remains pending */
	sleep(5);

	if (sigpending(&pendmask) < 0)
			err_sys("sigpending error");
	if (sigismember(&pendmask, SIGINT))
			printf("\n Signal SIGINT is pending\n");

	if (sigprocmask(SIG_UNBLOCK, &newmask, &oldmask) < 0)
		err_sys("Error in unblocking signals\n");

	/* better to restore the old mask, since the signal might be
	 * already blocked before here (if this code was part of a function
	 * that can be called from various places)
	 *
	 * if (sigprocmask(SIG_SETMASK, &oldmask, NULL) <0)
     *		err_sys("Error in unblocking signals\n");
	 */

	exit(0);
}

void onintr() 
{	
	printf("Caught Ctl-C\n");
	exit(1);
}
