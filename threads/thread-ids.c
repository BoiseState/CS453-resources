
/*
Compile this program as

gcc threads-hello-world.c -lpthread

*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *run( void *ptr ); 
  
int main(int argc, char **argv)
{
	int i, n;
	int *value;
    pthread_t *tid; 
     
	if (argc != 2) {
	 	fprintf(stderr, "Usage: thread-ids <num-threads>\n");
		exit(EXIT_FAILURE);
	}
	n = atoi(argv[1]);
	tid = (pthread_t *) malloc(sizeof(pthread_t) * n);
	for (i=0; i<n; i++) {
		value = (int *) malloc(sizeof(int));
		*value = i;
    	pthread_create(&tid[i], NULL, run, (void *) value);
	}
  
	for (i=0; i<n; i++)
     	pthread_join(tid[i], NULL);

    exit(EXIT_SUCCESS);
}
  
void *run(void *ptr)
{
	printf("I am thread %d with thread id %X\n", *(int *)ptr, (unsigned int) pthread_self());
	pthread_exit(NULL);
}
