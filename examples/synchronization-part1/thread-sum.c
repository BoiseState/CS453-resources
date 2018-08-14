#include <unistd.h>
#include <stdlib.h>
/*#include <jemalloc/jemalloc.h>*/
#include <stdio.h>
#include <sysexits.h>
#include <pthread.h>
#include <string.h>

void *partial_sum(void *ptr);
int *values;
int n;
int result[2]; /* partial sums arrays */

float report_cpu_time(void);

int  main( int argc, char **argv)
{
    int i;
    long sum;
    float start_time, total_time;
    pthread_t thread1, thread2;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n> \n", argv[0]);
        exit(EX_USAGE);
    }
    n = atoi(argv[1]);
    values = (int *) malloc(sizeof(int)*n);
    for (i=0; i<n; i++)
        values[i] = 1;


    start_time = report_cpu_time();

    pthread_create(&thread1, NULL, partial_sum, (void *) "1");
    pthread_create(&thread2, NULL, partial_sum, (void *) "2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sum = result[0] + result[1];
    total_time = report_cpu_time() - start_time;

    printf("Total sum = %ld time taken = %lf seconds\n", sum, total_time );

    exit(EXIT_SUCCESS);
}

void *partial_sum(void *ptr)
{
    char *message;
    int sum;
    int i;
    int start, end, index;

    message = (char *) ptr;
    printf("%s ", message);

    sum = 0;
    if (strcmp(message,"1") == 0)  {
        index = 0;
        start = 0;
        end = n/2;
    } else {
        index = 1;
        start = n/2 + 1;
        end = n - 1;
    }

    for (i=start; i<=end; i++)
        sum += values[i];

    result[index] = sum;
    pthread_exit(NULL);
}
