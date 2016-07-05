#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define STATE_LEN 8

void* random_printer(void *ptr);
int  main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, random_printer,(void*)1);
    pthread_create(&thread2, NULL, random_printer, (void*)2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    exit(0);
}

void* random_printer(void *ptr)
{
    //get the seed that was passed into the thread
    int seed = (size_t)ptr;
    //create our random_data buff on the stack
    struct random_data buff = {};
    //create a place to store the result from random_r on the stack
    int32_t result =0;
    //create our statebuff for initState_r. Note: that statebuff must not be less than 8 bytes
    char statebuf[STATE_LEN];
    //init our state for random_r
    initstate_r(seed,statebuf,STATE_LEN,&buff);
    printf("%p\n",&buff);
    int i;
    for(i=0; i<10000; i++ ) {
        //get our random numbers.
        random_r(&buff,&result);
        printf("%d\n",result);
    }
    pthread_exit(NULL);
}
