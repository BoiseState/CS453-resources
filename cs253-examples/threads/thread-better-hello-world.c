
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *print_message_function( void *ptr );

int  main()
{
    pthread_t thread1, thread2;
    char *message1 = "Goodbye";
    char *message2 = "World";

    pthread_create(&thread1, NULL, print_message_function, (void*) message1);
    pthread_create(&thread2, NULL, print_message_function, (void*) message2);

    pthread_join(thread1, NULL); /* wait for thread1 to finish */
    pthread_join(thread2, NULL); /* wait for thread2 to finish */
    printf("\n");
    exit(0);
}

void *print_message_function( void *ptr )
{
    char *message;
    message = (char *) ptr;
    printf("%s ", message);
    pthread_exit(NULL);
}
