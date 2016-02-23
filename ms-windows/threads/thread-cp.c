/*
 * A simple attempted to the synchronization problem that works for
 * most cases but is not guaranteed to work.
 *
 */
#include <windows.h>
#include <stdio.h>

#define DEBUG 1

#define MAX_BUF_SIZE 8192

size_t in, out;
FILE *src, *dst;
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
int flag = READ;

DWORD WINAPI reader(LPVOID);
DWORD WINAPI writer(LPVOID);


int main(int argc, char *argv[])
{
    HANDLE hThread1, hThread2;
    DWORD dwThreadID1, dwThreadID2;

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



/*
 * reader(): The function reader() is the entire reader thread. It
 * synchronizes with the writer thread, which execute the writer() function.
 */
DWORD WINAPI reader(LPVOID arg)
{
    printf("Reader thread, file = %d\n", src->_file);
    fflush(stdout);

    while (1) {
        if (flag == READ) {
            in = fread(
                     buf,           // Storage location for data
                     1,             // Item size in bytes
                     bufsize,       // Maximum number of items to be read
                     src            // Pointer to FILE structure
                 );
#ifdef DEBUG
            printf("read %d character\n", in);
#endif
            fflush(stdout);
            flag = WRITE;
            if (0 == in)
                break;
        }
    }
    ExitThread(0);
}



/*
 *
 * writer(): The main function for the writer thread.
 */
DWORD WINAPI writer(LPVOID arg)
{
    printf("Writer thread, file = %d\n",dst->_file);
    fflush(stdout);

    while (1) {
        if (flag == WRITE) {
            out = fwrite(
                      buf,      // Pointer to data to be written
                      1,            // Item size in bytes
                      in,       // Maximum number of items to be written
                      dst       // Pointer to FILE structure
                  );
#ifdef DEBUG
            printf("wrote %d character\n", out);
#endif
            fflush(stdout);
            flag = READ;
            if (0 == out)
                break;
        }
    }
    ExitThread(0);
}
