
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

/* Signal handler */
static void segfault(int signo);

/*
 * Demonstrates basic signal usage.
 *
 * @author CS253 Instructors
 */
int main()
{
    signal(SIGSEGV, segfault);      // Timer/alarm

	int *ptr = NULL;

	*ptr = 666;
	printf("Woah! Able to dereference a null pointer!\n");

    exit(EXIT_SUCCESS);
}

static void segfault(int signo)
{
    printf("Caught Segmentation Fault! Baling out!! \n"); fflush(stdout);
	exit(EXIT_FAILURE);
}
