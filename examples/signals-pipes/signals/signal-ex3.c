#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;
static void onintr();
#define TRUE 1

int main(void)
{
	int code;
	// sigsetjmp saves the state of the stack when it is called
	// any changes after are not guaranteed to be saved!
	int status = 111;

	if (signal(SIGINT, onintr) == SIG_ERR) 
		printf("Error in setting up interrupt handler\n");
	code = sigsetjmp(env,TRUE);
	printf("before the loop: code = %d status = %d\n",code, status);

	for (;;) {
		/* main processing loop */
		sleep(4);
	}
}

#define FROM_ONINTR 333333
void onintr(int signo) 
{
	/*re-establish signal handler*/
	if (signal(SIGINT, onintr) == SIG_ERR) 
		printf("Error in setting up interrupt handler\n");
	printf("Caught Interrupt\n");
	/*long jump back to before the main loop.*/
	siglongjmp(env, FROM_ONINTR);
}
