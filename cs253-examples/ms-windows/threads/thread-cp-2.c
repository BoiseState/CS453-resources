/*
 * Solution to Programming Assignment 1. (Amit Jain)
 * A simple solution to the synchronization problem that works for
 * most cases but is not guaranteed to work.
 *
 */
#include <windows.h>
#include <stdio.h>


#define MAX_BUF_SIZE 8192

int in, out;
FILE *src, *dst;
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

DWORD WINAPI reader(LPVOID);
DWORD WINAPI writer(LPVOID);


int main(int argc, char *argv[])
{
    LPHANDLE hThread1, hThread2;
    DWORD dwThreadID1, dwThreadID2;
    DWORD dwExitStatus;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <buffer size> <src> <dest>\n", argv[0]);
        ExitProcess(1);
    }

    bufsize = atoi(argv[1]);
    if (bufsize > 8192) {
        fprintf(stderr, "Error: %s: max. buffer size is MAX_BUF_SIZE\n",argv[0]);
        ExitProcess(1);
    }


    src = fopen(argv[2], "r");
    if (NULL == src)
        ExitProcess(2);

    dst = fopen(argv[3], "w");
    if (NULL == dst)
        ExitProcess(3);

    readbuffer = bufA;
    writebuffer = bufB;

    /* create the reader and writer threads */

    hThread1 = CreateThread(
                   NULL,                            // Security Descriptor (handle not inheritable)
                   0,                               // initial stack size (default)
                   reader,                      // thread function
                   NULL,                            // thread argument
                   0,                               // creation option (run immediately)
                   &dwThreadID1             // thread identifier
               );

    if (! hThread1) {
        fprintf(stderr, "Unable to create thread 1.\n");
        ExitProcess(4);
    }

    hThread2 = CreateThread(
                   NULL,                            // Security Descriptor (handle not inheritable)
                   0,                               // initial stack size (default)
                   writer,                      // thread function
                   NULL,                            // thread argument
                   0,                               // creation option (run immediately)
                   &dwThreadID2             // thread identifier
               );

    if (! hThread2) {
        fprintf(stderr, "Unable to create thread 2.\n");
        ExitProcess(5);
    }


    /* the main program (i.e. the heavyweight parent process) waits
     * for the threads to finish.
     */
    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);

    fclose(src);
    fclose(dst);

    ExitProcess(0);
}

DWORD WINAPI reader(LPVOID arg)
{
    char *tmp;

    printf("Reader thread, file = %d\n",src->_file);
    fflush(stdout);
    while (1) {
        in = fread(
                 readbuffer,        // Storage location for data
                 1,                 // Item size in bytes
                 bufsize,           // Maximum number of items to be read
                 src                // Pointer to FILE structure
             );
        readStarted=TRUE;
        printf("read %d character\n",in);
        if (!(flag)) {
            tmp = readbuffer;
            readbuffer = writebuffer;
            writebuffer = tmp;
            flag = TRUE;
        }
        if (0 == in)
            break;
    }
    ExitThread(0);
}
/*
void reader(void)
{
    char *tmp;

    printf("Reader thread, file = %d\n",src);
    fflush(stdout);
    while (1) {
        in = read(src, readbuffer, bufsize);
        readStarted=TRUE;
        printf("read %d character\n",in);
        if (!(flag)) {
            tmp = readbuffer; readbuffer=writebuffer; writebuffer=tmp;
            flag = TRUE;
        }
        if (in <= 0) break;
    }
    pthread_exit(0);
}
*/

DWORD WINAPI writer(LPVOID arg)
{
    char *tmp;

    printf("Writer thread, file = %d\n",dst->_file);
    fflush(stdout);

    while (!readStarted);

    while (1) {
        out = fwrite(
                  writebuffer,  // Pointer to data to be written
                  1,                    // Item size in bytes
                  in,               // Maximum number of items to be written
                  dst               // Pointer to FILE structure
              );
        printf("wrote %d character\n",out);
        if (flag) {
            tmp = readbuffer;
            readbuffer = writebuffer;
            writebuffer = tmp;
            flag = FALSE;
        }
        if (0 == out)
            break;
    }
    ExitThread(0);
}
/*
void writer(void)
{
    char *tmp;

    printf("Writer thread, file = %d\n",dst);
    fflush(stdout);

    while (!readStarted);

    while (1) {
        out = write(dst, writebuffer, in);
        printf("wrote %d character\n",out);
        if (flag) {
            tmp = readbuffer; readbuffer=writebuffer; writebuffer=tmp;
            flag = FALSE;
        }
        if (out <= 0) break;
    }
    pthread_exit(0);
}
*/
