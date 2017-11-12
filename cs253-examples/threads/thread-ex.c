
/*
 *
  Create three threads to see how they are scheduled.
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <pthread.h>


void *run(void *);

int main(int argc, char *argv[])
{
    pthread_t merlot, pinot, cabernet;

    pthread_create(&merlot, NULL, run, (void*) "merlot");
    pthread_create(&pinot, NULL, run, (void*) "pinot");
    pthread_create(&cabernet, NULL, run, (void*) "cabernet");

    /* the main program waits for the threads to finish. */
    pthread_join(merlot, NULL);
    pthread_join(pinot, NULL);
    pthread_join(cabernet, NULL);
    exit(EXIT_SUCCESS);
}


void *run(void *arg)
{
    char *name = (char *)arg;
    int i;
    for (i=0; i<500000; i++) {
        printf("This is the %s thread\n",name);
    }
    pthread_exit(NULL);
}
