
/* ch2/print-pid.c */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	printf("after exec pid=%d\n",getpid());
	exit(EXIT_SUCCESS);
}
