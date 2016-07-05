/*
   Modified version of safe-bank-balance.c

   Shows how one thread can starve others if the critical section isn't
   carefully selected.

   @author Marissa Schmidt
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

struct account {
    double balance;
    pthread_mutex_t mutex;
};

void *run(void *);
void goodSession(int, FILE *);
void badSession(int, FILE *);

/* Global variables */
struct account *myacct;
pthread_t *tids;
int numThreads;
int good = 0;

/**
 * Creates a new account with an initial balance and initializes
 * the account's mutex.
 * @param balance The starting balance of the account.
 */
struct account *createAccount(double balance)
{
    myacct = (struct account *) malloc(sizeof(struct account));
    myacct->balance = balance;
    pthread_mutex_init(&(myacct->mutex), NULL);
    return myacct;
}

/**
 * Deposits the specified amount into the account.
 */
void deposit(struct account *acct, double amount)
{
    acct->balance += amount;
}

/**
 * Withdraws the specified amount from the account.
 */
void withdraw(struct account *acct, double amount)
{
    acct->balance -= amount;
}

int main(int argc, char **argv)
{
    int i;
    int *value;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <numThreads (1-3)> <good|bad>\n", argv[0]);
        exit(1);
    }

    numThreads = atoi(argv[1]);
    if (numThreads > 3) {
        fprintf(stderr, "Usage: %s Too many threads  specified. Defaulting to 3.\n", argv[0]);
        numThreads = 3;
    }

    char *goodArg = argv[2];
    if(strcmp(goodArg, "good") == 0) {
        good = 1;
        printf("Running good version...\n");
    } else {
        good = 0;
        printf("Running bad version...\n");
    }

    /* Initialize account */
    myacct = createAccount(0.0);
    printf("initial balance = %lf\n", myacct->balance);

    /* Create threads */
    tids = (pthread_t *) malloc(sizeof(pthread_t)*numThreads);
    for (i=0; i<numThreads; i++) {
        value = (int *) malloc(sizeof(int));
        *value = i;
        pthread_create(&tids[i], NULL, run, (void *) value);
    }

    /* Wait for all threads to finish */
    for (i=0; i<numThreads; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("final balance = %lf\n", myacct->balance);
    exit(0);
}

/**
 * This is where the threads start.
 *
 * Each thread will read input from their own file. This kind of simulates
 * multiple users accessing the same account from different terminals.
 *
 * Each thread will read from a file called "input_<id>.txt". The file
 * should just have a list of floating point values. When a thread reads
 * a value < 1, then it will sleep for 30 seconds to simulate a user
 * starting a transaction, but not ending it.
 */
void *run(void *ptr)
{
    int id = *((int *)ptr);
    char filename[80];
    FILE *fp;

    /* Thread will read from file input_x.txt */
    sprintf(filename, "transactions_%d.txt", id);
    fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Can't open input file %s\n", filename);
        exit(1);
    }

    printf("Thread [%d]: Session started\n", id);
    if(good == 1) {
        goodSession(id, fp);
    } else {
        badSession(id, fp);
    }
    printf("Thread [%d]: Session ended\n", id);

    pthread_exit(NULL);
}

/**
 * Starves the other threads from depositing if this thread goes to sleep.
 */
void badSession(int id, FILE *fp)
{
    double amount;

    /* This is not a good place to lock! */
    pthread_mutex_lock(&(myacct->mutex));
    while(fscanf(fp, "%lf", &amount) != EOF) {
        if(amount < 1) {
            sleep(30); // Simulates user walking away from machine.
        }
        deposit(myacct, amount); // Uses shared myacct variable.
        printf("\tThread [%d]: Deposited: %f\n", id, amount);
        fflush(stdout);
    }
    pthread_mutex_unlock(&(myacct->mutex));
}

/**
 * Other threads can continue depositing if this thread goes to sleep. This
 * is good.
 */
void goodSession(int id, FILE *fp)
{
    double amount;

    while(fscanf(fp, "%lf", &amount) != EOF) {
        if(amount < 1) {
            sleep(30); // Simulates user walking away from machine.
        }
        /* lock around smallest chunk of code possible. */
        pthread_mutex_lock(&(myacct->mutex));
        deposit(myacct, amount); // Uses shared myacct variable.
        pthread_mutex_unlock(&(myacct->mutex));
        printf("\tThread [%d]: Deposited: %f\n", id, amount);
        fflush(stdout);
    }
}

