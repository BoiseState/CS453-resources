/**
 * NOTE: This is compilable code in Visual Studio.  However it crashes after making
 * the longjmp call.  Upon investigation in MSDN, I found the following restriction
 * under the remarks section for the longjmp function:
 *
 *		Do not use longjmp to transfer control out of an interrupt-handling routine 
 *		unless the interrupt is caused by a floating-point exception. In this case, a 
 *		program may return from an interrupt handler via longjmp if it first 
 *		reinitializes the floating-point math package by calling _fpreset. 
 *
 * As a result, I believe that mixing signals and longjmps in windows is taboo.
 */

#include <windows.h>
#include <signal.h>
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

static void onintr(int sig);

int main(void)
{
	int code;

	if (signal(SIGINT, onintr) == SIG_ERR) 
		printf("Error in setting up interrupt handler\n");
	code = setjmp(env);
	printf("before the loop: code = %d\n",code);

	for (;;) {
		/* main processing loop */
		Sleep(100);
	}

}

void onintr(int sig) 
{
	// re-establish signal handler
	if (signal(SIGINT, onintr) == SIG_ERR) 
		printf("Error in setting up interrupt handler\n");
	printf("Caught Interrupt\n");
	// long jump back to before the main loop.
	longjmp(env, 7643368);
}
