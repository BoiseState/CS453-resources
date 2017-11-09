
/*
 * A simple attempt to the synchronization problem that works for
 * most cases but is not guaranteed to work.
 *
 */
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

/*#define DEBUG */

#define MODE 0666
#define MAX_BUF_SIZE 65536

int in, out;
int src, dst;
int bufsize;
char buf[MAX_BUF_SIZE];

/* flag is used to synchronize between the reader and writer threads
 * flag=READ implies buffer is empty and the reader thread can fill
 * in the buffer. The reader sets the flag to WRITE after it is done
 * reading one block. The writer thread writes out the buffer and
 * sets the flag back to READ.
 */
#define READ 1
#define WRITE 2
int flag=READ;

void *reader(void *);
void *writer(void *);


int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    if (argc != 4) {
        fprintf(stderr,"Usage: %s <buffer size> <src> <dest>\n", argv[0]);
        exit(EX_USAGE);
    }

    bufsize = atoi(argv[1]);
    if (bufsize > MAX_BUF_SIZE) {
        fprintf(stderr,"Error: %s: max. buffer size is MAX_BUF_SIZE\n",argv[0]);
        exit(EX_USAGE);
    }

    src = open(argv[2], O_RDONLY);
    if (src < 0) exit(EX_NOINPUT);
    dst = creat(argv[3], MODE);
    if (dst < 0) exit(EX_CANTCREAT);

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
    exit(EXIT_SUCCESS);
}


/*
 * reader(): The function reader() is the entire reader thread. It
 * synchronizes with the writer thread, which execute the writer() function.
 */
void *reader(void *arg)
{
    printf("Reader thread, file = %d\n",src);
    fflush(stdout);
    while (1) {
        if (flag == READ) {
            in = read(src, buf, bufsize);
#ifdef DEBUG
            printf("read %d character\n",in);
            fflush(stdout);
#endif
            flag = WRITE;
            if (in <= 0) break;
        }
        /*usleep(10000); // 1/100th sec*/
    }
    pthread_exit(0);
}



/*
 *
 * writer(): The main function for the writer thread.
 */
void *writer(void *arg)
{
    printf("Writer thread, file = %d\n",dst);
    fflush(stdout);
    while (1) {
        if (flag == WRITE) {
            out = write(dst, buf, in);
#ifdef DEBUG
            printf("wrote %d character\n",out);
            fflush(stdout);
#endif
            flag = READ;
            if (out <= 0) break;
        }
        /*usleep(10000); // 1/100th sec*/
    }
    pthread_exit(0);
}
