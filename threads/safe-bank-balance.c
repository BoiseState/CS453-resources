
/*
   Uses Pthread Mutexes to protect the bank balance variable. This isn't a good
   coding style.  For a better way to code this see subfolder account. Also
   monitors will be discussed extensively in the Operating Systems class.

   @author amit
   @author marissa (slight modifications)
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

static void *thread_main(void *);

typedef struct account account;
struct account {
    double balance;
    pthread_mutex_t mutex;
};

/* shared account */
static account *myacct;

int main(int argc, char **argv)
{
    int i;
    int num_threads, count;
    pthread_t *tids;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <num_threads> <iterations>\n", argv[0]);
        exit(1);
    }

    num_threads  = atoi(argv[1]);
    count = atoi(argv[2]);

    if (num_threads > 32) {
        fprintf(stderr, "Usage: %s Too many threads. Defaulting to 32.\n", argv[0]);
        num_threads = 32;
    }

    /* create an account and set balance to 0 */
    myacct = (account *) malloc(sizeof(account));
    myacct->balance = 0.0;
    printf("initial balance = %lf\n", myacct->balance);

    /* initialize the shared mutex */
    pthread_mutex_init(&(myacct->mutex), NULL);

    /* create threads */
    tids = (pthread_t *) malloc(sizeof(pthread_t) * num_threads);
    for(i = 0; i < num_threads; i++) {
        pthread_create(&tids[i], NULL, thread_main, (void *) &count);
    }

    /* wait for threads to finish */
    for(i = 0; i < num_threads; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("final balance = %lf\n", myacct->balance);

    free(myacct);

    exit(EXIT_SUCCESS);
}
/**
 * Each thread will add a dollar to the account n times.
 * @arg n the number of times to execute.
 */
void *thread_main(void *n)
{
    int i;
    int amount;
    int count = *((int *)n);

    for(i = 0; i < count; i++) {
        amount = 1;
        pthread_mutex_lock(&(myacct->mutex));
        myacct->balance += amount;
        pthread_mutex_unlock(&(myacct->mutex));
    }

    pthread_exit(NULL);
}
