
/*
 Check limit on user processes/threads with
   ulimit -a
 May cause system to be unusable for a short time if you exceed limit!!
 Try it as root to see if you can get more resources.
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


void *run(void *);

#define MAX 10000

int main(int argc, char *argv[])
{
    int i, status;
    int count = 0;
    pthread_t *tids = (pthread_t *) malloc (sizeof(pthread_t) * MAX);

    for (i=0; i<MAX; i++) {
        status  = pthread_create(&tids[i], NULL, run, (void*) NULL );
        if (status != 0) {
            perror("thread-test");
            break;
        }
        printf("Created thread number %d: \n",i);
        count++;
    }
    printf("thread-test: created %d threads successfully\n", count);

    for (i=0; i<count; i++) {
        pthread_join(tids[i], NULL);
    }

    exit(0);
}


void *run(void *arg)
{
    printf("This is  thread id = %lX\n",pthread_self());
    sleep(30);
    pthread_exit(NULL);
}
