 
/* 
 * Solution to multi-threaded file copy using semaphores for synchronization. 
 */ 
#include <windows.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_BUF_SIZE 65536

size_t in, out;
FILE *src, *dst;
size_t bufsize;
LONG lPrevCount;
char buf[MAX_BUF_SIZE];

DWORD WINAPI reader(LPVOID resrvd);
DWORD WINAPI writer(LPVOID resrvd);

HANDLE hReadersTurn;
HANDLE hWritersTurn;
  

int main(int argc, char *argv[])
{
	HANDLE thread1, thread2;
	DWORD thread1ID, thread2ID;

	if (argc != 4) {
		fprintf(stderr,"Usage: %s <buffer size> <src> <dest>\n", argv[0]);
		exit(1);
	}
	
	bufsize = atoi(argv[1]);
	if (bufsize > MAX_BUF_SIZE) {
		fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[0], MAX_BUF_SIZE);
		exit(1);
	}	

	src = fopen(argv[2], "r");
	if (src < 0) exit(2);
	dst = fopen(argv[3], "w");
	if (dst < 0) exit(3);

	hReadersTurn = CreateSemaphore(
		NULL,				// Security attributes
		1,					// Initial count (signaled)
		1,					// Maximum count (binary sem)
		"ReaderSem"		// Name of sem
	);
	hWritersTurn = CreateSemaphore(
		NULL,				// Security attributes
		0,					// Initial count (not-signaled)
		1,					// Maximum count (binary sem)
		"WriterSem"		// Name of sem
	);
  
	
	/* create the reader and writer threads */

	thread1 = CreateThread(
		NULL,				// Security attributes
		0,					// Stack size (default)
		&reader,			// Start function
		NULL,				// Thread Parameter
		0,					// Creation flags
		&thread1ID		// Thread ID
	);
	thread2 = CreateThread(
		NULL,				// Security attributes
		0,					// Stack size (default)
		&writer,			// Start function
		NULL,				// Thread Parameter
		0,					// Creation flags
		&thread2ID		// Thread ID
	);

	/* the main program (i.e. the heavyweight parent process) waits
	 * for the threads to finish.
	 */ 
	 
	WaitForSingleObject(thread1, INFINITE);
	WaitForSingleObject(thread2, INFINITE);

	fclose(src);
	fclose(dst);
	exit(0);
}

  

/* 
 * reader(): The function reader() is the entire reader thread. It 
 * synchronizes with the writer thread, which execute the writer() function.
 */ 
DWORD WINAPI reader(LPVOID resrvd)
{
#ifdef _DEBUG			
	printf("Starting reader thread. \n");
	fflush(stdout);
#endif
	while (1) {
			WaitForSingleObject(hReadersTurn, INFINITE);
			in = fread(buf, 1, bufsize, src);
			ReleaseSemaphore(hWritersTurn, 1, &lPrevCount);
#ifdef _DEBUG			
			printf("read %d character\n",in);
			fflush(stdout);
#endif
		if (in <= 0) break;
	}
	ExitThread(0);
}



/*
 * 
 * writer(): The main function for the writer thread.
 */ 
DWORD WINAPI writer(LPVOID resrvd) 
{
#ifdef _DEBUG			
	printf("Starting writer thread. \n");
	fflush(stdout);
#endif
	while (1) {
			WaitForSingleObject(hWritersTurn, INFINITE);
			out = fwrite(buf, 1, in, dst);
			ReleaseSemaphore(hReadersTurn, 1, &lPrevCount);
#ifdef _DEBUG			
			printf("wrote %d character\n",out);
			fflush(stdout);
#endif
		if (out <= 0) break;
	}
	ExitThread(0);
}
