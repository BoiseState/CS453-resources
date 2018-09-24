
/*
* A sample program that probes various memory locations
* and catches SIGSEGV and keeps on trying. It takes one
* argument that specifies the number of times to catch the
* SIGSEGV signal before quitting.
*
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <setjmp.h>

void signalHandler(int sig);
jmp_buf env;
int count = 0;
int orig_count = 0;
unsigned int *ptr;

#define TRUE 1

int main(int argc, char **argv) 
{
	int code;
	long seed;
	
	if (argc < 2) {
		fprintf(stderr,"Usage %s <count> [<seed>] \n",argv[0]);
		exit(1);
	}
	count = atoi(argv[1]);
	orig_count = count;
    /*set a seed for random number generator*/
	if (argc < 3) 
			seed = 0; 
    else
		seed = atoi(argv[2]);
	srandom(seed);

    if (signal(SIGSEGV, signalHandler) == SIG_ERR)
		printf("Could not setup the signal handler\n");


	/* hey try another stab at places where we shouldn't be!
	   this might cause a segmentation violation!!! (but we
       are prepared to handle it)
	*/
	code = sigsetjmp(env,TRUE);
	if (code == 1) {
		/*returning from the signal handler, change the pointer*/
		ptr=(unsigned int *) random();
		printf("trying memory location [%p]\n", ptr);
		fflush(NULL);
	}
	*ptr = 999;

	printf("Ha!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("Succeeded after %d tries\n", orig_count - count);
	exit(0);
}

void signalHandler(int sig) {

	count--;
	if (count < 0) exit(1);
	/*just to make it easier to watch it happen*/
	/*sleep(1); */
	printf("Caught segmentation violation\n");
	fflush(NULL);
	siglongjmp(env,1);
}

/* vim: set tabstop=4:*/
