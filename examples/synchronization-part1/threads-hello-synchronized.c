#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <limits.h>

void *print_message_function(void *ptr);

sem_t worlds_turn;

int main(void)
{
     pthread_t thread1, thread2;
     char *message1 = "Hello";
     char *message2 = "World\n";

     sem_init(&worlds_turn, 0, 1);
     sem_wait(&worlds_turn); /* world goes second */

     pthread_create(&thread1, NULL, print_message_function, (void *) message1);
     sem_wait(&worlds_turn);
     pthread_create(&thread2, NULL, print_message_function, (void *) message2);

	 pthread_join(thread1, NULL);
	 pthread_join(thread2, NULL);

     /* not really necessary to destroy since we are exiting anyway */
     sem_destroy (&worlds_turn);

     printf("\n");
     exit(0);
}


void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s ", message);
     fflush(stdout);
     sem_post(&worlds_turn);
     pthread_exit(0);
}

