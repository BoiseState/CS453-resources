#include <errno.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>  // must include stdio  for pvm3.h to compile correctly

/*#define DEBUG 1*/

#define RANDOM_SEED   12345678

/* The main work routine */
void generateRandomNumbers(long long int count)
{
	long long int i;
	int x;

	srand( RANDOM_SEED );
	for (i = 0; i < count; i++) {
		x = rand();
#ifdef DEBUG
		printf_s("%d\n", x);
#endif
	}
}

int main(int argc, char **argv)
{
	long long int count;
	LARGE_INTEGER startTime, endTime, frequency;
	double timeElapsed = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <n>\n" ,argv[0]);
		exit(1);
	}
	sscanf_s(argv[1],"%lld",&count); /* lld for long long int */

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&startTime); // And we are off
	
	generateRandomNumbers(count);
	printf("seq-random: generated %lld random numbers\n", count);
	
	QueryPerformanceCounter(&endTime);
	timeElapsed = (float)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;
	printf("Elapsed time:  %f seconds\n", timeElapsed);
	fflush(stdout);

	exit(0);
}