#include <windows.h>
#include <signal.h>
#include <stdio.h>

static void onintr(int sig);

int main(void)
{
	/*if (signal(SIGINT, SIG_IGN) != SIG_IGN)*/
	signal(SIGINT, onintr);

	/* processing section */
	Sleep(4000);

	ExitProcess(0);
}

void onintr(int sig) // clean up on interrupt
{	
	printf("Caught Ctl-C\n");
	ExitProcess(1);
}
