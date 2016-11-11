
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <Account.h>

void *threadMain(void *);
pthread_t *tids;

AccountPtr account;

int numThreads;
int count;

int main(int argc, char **argv)
{
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <numThreads> <iterations>\n", argv[0]);
        exit(1);
    }

    numThreads  = atoi(argv[1]);
    count = atoi(argv[2]);
    if (numThreads > 32) {
        fprintf(stderr, "Usage: %s Too many threads  specified. Defaulting to 32.\n", argv[0]);
        numThreads = 32;
    }

    account = account_init();
    printf("initial balance = %lf\n", account->balance);


    tids = (pthread_t *) malloc(sizeof(pthread_t)*numThreads);
    for (i=0; i<numThreads; i++)
        pthread_create(&tids[i], NULL, threadMain, (void *) NULL);

    for (i=0; i<numThreads; i++)
        pthread_join(tids[i], NULL);

    printf("final balance = %lf\n", account->balance);
    exit(0);
}

#define MAX_AMOUNT 10
void *threadMain(void *arg)
{
    int i;
    int amount;

    for (i=0; i<count; i++) {
        amount = 1;
        credit(account, amount);
    }
    pthread_exit(NULL);
}
