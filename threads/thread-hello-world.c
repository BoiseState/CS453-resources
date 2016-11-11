
/*
Compile this program as

gcc threads-hello-world.c -lpthread

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

static void *print_message_function( void *ptr );

int  main()
{
    pthread_t thread1, thread2;
    char *message1 = "Goodbye";
    char *message2 = "World";

    pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    /* sleep(1); */
    /* pause(); */
    exit(EXIT_SUCCESS);
}

static void *print_message_function(void *ptr)
{
    char *message;
    message = (char *) ptr;
    printf("%s ", message);
    fflush(stdout);
    /*pause();*/
    pthread_exit(NULL);
}
