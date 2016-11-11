
/**
 * This example shows how to assign sequential ids 0..n-1 to n threads. This is
 * preferable to using pthread_self() as the thread ids assigned by the system
 * are unpredictable and not supposed to be portable beyond being used in
 * pthread library calls.
 *
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *run( void *ptr );

int main(int argc, char **argv)
{
    int i, n;
    int *value;
    pthread_t *tid;

    if (argc != 2) {
        fprintf(stderr, "Usage: thread-ids <num-threads>\n");
        exit(EXIT_FAILURE);
    }
    n = atoi(argv[1]);
    tid = (pthread_t *) malloc(sizeof(pthread_t) * n);

    for (i = 0; i < n; i++) {
        value = (int *) malloc(sizeof(int));
        *value = i;
        pthread_create(&tid[i], NULL, run, (void *) value);
    }

    for (i = 0; i < n; i++)
        pthread_join(tid[i], NULL);

    free (tid);
    exit(EXIT_SUCCESS);
}

void *run(void *ptr)
{
    int id = *(int *) ptr;
    free(ptr); // we are done with it, free it to avoid a leak

    printf("I am thread %d with thread id %X\n", id, (unsigned int) pthread_self());
    pthread_exit(NULL);
}
