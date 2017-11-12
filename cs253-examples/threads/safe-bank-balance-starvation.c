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

#define GOOD 0
#define BAD 1

static void *run(void *);
static void good_session(int, FILE *);
static void bad_session(int, FILE *);

typedef struct account account;
struct account {
    double balance;
    pthread_mutex_t mutex;
};

/* shared account */
static account *myacct;
static int version = GOOD;

/** deposits the specified amount into the account. */
void deposit(struct account *acct, double amount)
{
    acct->balance += amount;
}

/** withdraws the specified amount from the account. */
void withdraw(struct account *acct, double amount)
{
    acct->balance -= amount;
}

int main(int argc, char **argv)
{
    int i;
    int num_threads = 0;
    int *id;
    pthread_t *tids;


    if (argc < 3) {
        fprintf(stderr, "Usage: %s <num_threads (1-3)> <good|bad>\n", argv[0]);
        exit(1);
    }

    num_threads = atoi(argv[1]);
    if (num_threads > 3) {
        fprintf(stderr, "Usage: %s Too many threads. Defaulting to 3.\n", argv[0]);
        num_threads = 3;
    }

    if(strcmp(argv[2], "good") == 0) {
        version = GOOD;
        printf("Running good version...\n");
    } else {
        version = BAD;
        printf("Running bad version...\n");
    }

    /* create an account and set balance to 0 */
    myacct = (struct account *) malloc(sizeof(struct account));
    myacct->balance = 0.0;
    printf("initial balance = %lf\n", myacct->balance);

    /* initialize the shared mutex */
    pthread_mutex_init(&(myacct->mutex), NULL);

    /* create threads */
    tids = (pthread_t *) malloc(sizeof(pthread_t)*num_threads);
    for(i = 0; i < num_threads; i++) {
        id = (int *) malloc(sizeof(int));
        *id = i;
        pthread_create(&tids[i], NULL, run, (void *) id);
    }

    /* Wait for all threads to finish */
    for (i = 0; i < num_threads; i++) {
        pthread_join(tids[i], NULL);
    }

    printf("final balance = %lf\n", myacct->balance);

    free(myacct);
    free(tids);

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
static void *run(void *arg)
{
    int id = *((int *)arg);
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
    if(version == GOOD) {
        good_session(id, fp);
    } else {
        bad_session(id, fp);
    }
    printf("Thread [%d]: Session ended\n", id);

    free(arg);
    pthread_exit(NULL);
}

/**
 * Starves the other threads from depositing if this thread goes to sleep.
 */
void bad_session(int id, FILE *fp)
{
    double amount;

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
void good_session(int id, FILE *fp)
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

