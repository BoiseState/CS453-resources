
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>  // must include stdio  for pvm3.h to compile correctly
#include <sys/times.h> /* for times system call */
#include <sys/time.h>  /* for gettimeofday system call */

/*#define DEBUG 1*/

#define RANDOM_SEED   12345678 

//The main work routine
void generateRandomNumbers(long long);  
double getMilliSeconds();


/* The main work routine */
void generateRandomNumbers(long long int count)  
{
	long long int i;
	long int x;

	srandom(RANDOM_SEED);
    for (i = 0; i < count; i++) {
		x = random();
		printf("%ld\n", x);
  	}
}


int main(int argc, char **argv)
{
	long long int count;

    double timeStart = 0;
    double timeElapsed = 0;

  	if (argc < 2) {
        fprintf(stderr, "Usage: %s <n>\n" ,argv[0]);
        exit(1);
    }
    sscanf(argv[1],"%lld",&count); /* lld for long long int */

    timeStart = getMilliSeconds();	//And we are off
    generateRandomNumbers(count);
	printf("generated %lld random numbers\n", count);

    timeElapsed = getMilliSeconds() - timeStart;
    printf("Elapsed time:  %lf seconds\n",(double)(timeElapsed/1000.0));
    fflush(stdout);

    exit(0);
}
