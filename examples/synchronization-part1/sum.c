#include <unistd.h>
#include <stdlib.h>
/*#include <jemalloc/jemalloc.h>*/
#include <stdio.h>
#include <sysexits.h>
#include <string.h>

float report_cpu_time(void);

int  main( int argc, char **argv)
{
	int *values;
	long long i;
	long long n;
    long long sum;
    float start_time, total_time;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n> \n", argv[0]);
        exit(EX_USAGE);
    }
    n = strtoull(argv[1], NULL, 10);
    values = (int *) malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
        values[i] = 1;

    start_time = report_cpu_time();

	sum = 0;
    for (i = 0; i < n; i++)
        sum += values[i];

    total_time = report_cpu_time() - start_time;

    printf("Total sum = %lld time taken = %lf seconds\n", sum, total_time );

    exit(EXIT_SUCCESS);
}

