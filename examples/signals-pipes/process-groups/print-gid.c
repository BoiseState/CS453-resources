#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
        printf("Right after exec: child process groupid=%d\n",getpgrp());
		fflush(NULL);
		sleep(5); /* wait for parent to try and change my group */
        printf("After 5 seconds: child process groupid=%d\n",getpgrp());
		fflush(NULL);
        exit(0);
}

