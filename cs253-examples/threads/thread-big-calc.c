
/*
 Shows how to get speedup using threads.
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

void *run( void *ptr );
int *results;
long max;
long n;

int main(int argc, char **argv)
{
    int i;
    int *value;
    pthread_t *tid;

    if (argc != 3) {
        fprintf(stderr, "Usage: thread-ids <num-threads> <max>\n");
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    max = atoll(argv[2]);
    tid = (pthread_t *) malloc(sizeof(pthread_t) * n);
    results = (int *) malloc(sizeof(int) * n);
    for (i=0; i<n; i++) {
        value = (int *) malloc(sizeof(int));
        *value = i+1;
        pthread_create(&tid[i], NULL, run, (void *) value);
    }

    for (i=0; i<n; i++)
        pthread_join(tid[i], NULL);

    exit(EXIT_SUCCESS);
}

void *run(void *ptr)
{
    long i;
    int id = *(int *) ptr;
    long answer = id;
    printf("I am thread %d with thread id %X\n", id, (unsigned int) pthread_self());

    for (i=0; i<max/n; i++)
        answer = answer % (long) ceil(sqrt(i)) ;

    results[id] = answer;

    pthread_exit(NULL);
}
