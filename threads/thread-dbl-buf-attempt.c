 
/* 
 * A simple WRONG attempt to uses double buffering to increase concurrency for the reader/writer threads.
 * 
 */ 
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>


#define MODE 0666
#define MAX_BUF_SIZE 8192

int in, out;
int src, dst;
int bufsize;
char bufA[MAX_BUF_SIZE];
char bufB[MAX_BUF_SIZE];

char *readbuffer, *writebuffer;

/* flag is used to synchronize between the reader and writer threads
 * flag=FALSE implies buffer is empty and the reader thread can fill
 * in the buffer. The reader sets the flag to TRUE after it is done
 * reading one block. The writer thread writes out the buffer and
 * sets the flag to FALSE
 */
#define TRUE 1
#define FALSE 0
int flag=TRUE;
int readStarted=FALSE;

void reader(void);
void writer(void);

  
int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    if (argc != 4) {
		fprintf(stderr,"Usage: %s <buffer size> <src> <dest>\n", argv[0]);
		exit(1);
	}		
	
	bufsize = atoi(argv[1]);
	if (bufsize > 8192) {
		fprintf(stderr,"Error: %s: max. buffer size is MAX_BUF_SIZE\n",argv[0]);
		exit(1);
	}	


    src = open(argv[2], O_RDONLY);
    if (src < 0) exit(2);
    dst = creat(argv[3], MODE);
    if (dst < 0) exit(3);
	
	readbuffer = bufA;
	writebuffer = bufB;

    pthread_create(&thread1, NULL, (void*)&reader, (void*) NULL);
    pthread_create(&thread2, NULL, (void*)&writer, (void*) NULL);

  
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    close(src);
    close(dst);
    exit(0);
}
  
void reader(void)
{
	char *tmp;

    printf("Reader thread, file = %d\n",src);
    fflush(stdout);
    while (1) {
        in = read(src, readbuffer, bufsize);
		readStarted=TRUE;
        /*printf("read %d character\n",in);*/
        if (!(flag)) {  
			tmp = readbuffer; readbuffer=writebuffer; writebuffer=tmp;   
            flag = TRUE;
        }       
        if (in <= 0) break;
    }
    pthread_exit(0);
}

void writer(void) 
{
	char *tmp;

    printf("Writer thread, file = %d\n",dst);
    fflush(stdout);

	while (!readStarted);
	
    while (1) {
        out = write(dst, writebuffer, in);
        /*printf("wrote %d character\n",out);*/
        if (flag) {
			tmp = readbuffer; readbuffer=writebuffer; writebuffer=tmp;   
            flag = FALSE;
        }   
        if (out <= 0) break;
    }
    pthread_exit(0);
}
