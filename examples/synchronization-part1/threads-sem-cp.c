 
/* 
 * Author: Amit Jain
 */ 
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


#define MODE 0666
#define MAX_BUF_SIZE 65536

int in, out;
int src, dst;
int bufsize;
char buf[MAX_BUF_SIZE];

void *reader(void *);
void *writer(void *);

sem_t writers_turn;
sem_t readers_turn;
  

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    if (argc != 4) {
		fprintf(stderr,"Usage: %s <buffer size> <src> <dest>\n", argv[0]);
		exit(1);
	}		
	
	bufsize = atoi(argv[1]);
	if (bufsize > MAX_BUF_SIZE) {
		fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[0], MAX_BUF_SIZE);
		exit(1);
	}	

    src = open(argv[2], O_RDONLY);
    if (src < 0) exit(2);
    dst = creat(argv[3], MODE);
    if (dst < 0) exit(3);

    sem_init(&readers_turn, 0, 1);
    sem_init(&writers_turn, 0, 1 );
  
     /* reader must go first */
    sem_wait(&writers_turn);
  
 	
	/* create the reader and writer threads */

    pthread_create(&thread1, NULL, reader, (void*) NULL);
    pthread_create(&thread2, NULL, writer, (void*) NULL);

	/* the main program (i.e. the heavyweight parent process) waits
	 * for the threads to finish.
	 */ 
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    close(src);
    close(dst);
    exit(0);
}

  

/* 
 * reader(): The function reader() is the entire reader thread. It 
 * synchronizes with the writer thread, which execute the writer() function.
 */ 
void *reader(void * arg)
{
#ifdef DEBUG			
    printf("Reader thread, file = %d\n",src);
    fflush(stdout);
#endif
    while (1) {
			sem_wait (&readers_turn);
            in = read(src, buf, bufsize);
			sem_post (&writers_turn);
#ifdef DEBUG			
            printf("read %d character\n",in);
			fflush(stdout);
#endif
        if (in <= 0) break;
    }
    pthread_exit(0);
}



/*
 * 
 * writer(): The main function for the writer thread.
 */ 
void *writer(void *arg) 
{
#ifdef DEBUG			
    printf("Writer thread, file = %d\n",dst);
    fflush(stdout);
#endif
    while (1) {
			sem_wait (&writers_turn);
            out = write(dst, buf, in);
			sem_post (&readers_turn);
#ifdef DEBUG			
            printf("wrote %d character\n",out);
			fflush(stdout);
#endif
        if (out <= 0) break;
    }
    pthread_exit(0);
}
