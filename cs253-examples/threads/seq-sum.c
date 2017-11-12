
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *partial_sum(void *ptr);
int *values;
int n;
int result[2]; /* partial sums arrays */

float report_cpu_time();

int  main( int argc, char **argv)
{
    int i;
    long sum;
    float start_time, total_time;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n> \n", argv[0]);
        exit(1);
    }
    n = atoi(argv[1]);
    values = (int *) malloc(sizeof(int)*n);
    for (i=0; i<n; i++)
        values[i] = 1;

    start_time = report_cpu_time();
    sum = 0;
    for (i=0; i<n; i++) {
        sum += values[i];
    }
    total_time = report_cpu_time() - start_time;

    printf("Total sum = %ld time taken = %lf seconds \n", sum, total_time);
    exit(0);
}



