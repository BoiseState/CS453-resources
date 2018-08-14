
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	struct rlimit rlim;
	int *ptr;

	getrlimit(RLIMIT_DATA, &rlim);
	printf("Data segment: current usage: %ld maximum usage: %ld \n",
            rlim.rlim_cur, rlim.rlim_max);
	rlim.rlim_cur = 10000;
	rlim.rlim_max = 10000;
	setrlimit(RLIMIT_DATA, &rlim);
	getrlimit(RLIMIT_DATA, &rlim);
	printf("Data segment: current usage: %ld maximum usage: %ld \n",
            rlim.rlim_cur, rlim.rlim_max);

	ptr = (int *) malloc(200000);
	printf ("ptr = %lx \n",(unsigned long) ptr);
	getrlimit(RLIMIT_DATA, &rlim);
	printf("Data segment: current usage: %ld maximum usage: %ld \n",
            rlim.rlim_cur, rlim.rlim_max);

	/*for (i=0; i<200000; i++)*/
			/*ptr[i] = i;*/
	
	exit(0);
}

