#include	<windows.h>
#include	<stdio.h>
#include "error.h"

#define	ARRAY_SIZE	 10000
#define	MALLOC_SIZE	100000
#define	SHM_SIZE	100000

char buffer[ARRAY_SIZE];	/* uninitialized data = bss */

void *_end, *end, *_etext, *etext, *_edata, *edata,
				*__data_start, *__text_start;


int main(void)
{
	int shmid, offset;
	char *ptr;
	HANDLE hFileMapping;
	LPVOID lpMapAddress;
	SYSTEM_INFO si;
	
	/*printf("text start = 0x%I64x\n",&__text_start);*/
	printf("first address above the text = 0x%I64x\n",&etext);
	/*printf("data start = 0x%I64x\n",&__data_start);*/
	printf("first address above initialized data = 0x%I64x\n",&edata);
	printf("first address above unitialized data = 0x%I64x\n\n",&end);

	printf("buffer[] from 0x%I64x to 0x%I64x\n", &buffer[0], &buffer[ARRAY_SIZE]);
	printf("stack around 0x%I64x\n", &shmid);
	
	strcpy(buffer, "Hello World");

	if ( (ptr = malloc(MALLOC_SIZE)) == NULL)
		err_sys("malloc error");
	printf("malloced from 0x%I64x to 0x%I64x\n", ptr, ptr+MALLOC_SIZE);

	hFileMapping = CreateFileMapping(
		INVALID_HANDLE_VALUE ,	// Map a large temporary space which is backed by the 
										//		system paging files instead of by an existing file
		NULL,							// Default security. 
		PAGE_READWRITE,			// Read/write permission. 
		0,								// High order DWORD of file size
		SHM_SIZE,					// Low order DWORD of file size
		"MyFileMappingObject"	// Name of mapping object.
	);
	if (NULL == hFileMapping)
		err_sys("Could not create file mapping object");

	GetSystemInfo(&si);
	offset = (SHM_SIZE / si.dwAllocationGranularity) * si.dwAllocationGranularity;
	printf("Memory offset: %d\n", offset);

	lpMapAddress = MapViewOfFile(
		hFileMapping,				// Handle to mapping object. 
		FILE_MAP_ALL_ACCESS,		// Read/write permission 
		0,								// High order DWORD of offset
		offset,						// Low order DWORD of offset (see MSDN note above)
		0								// Map entire file. 
	);
	if (lpMapAddress == NULL)
		err_sys("Could not map view of file");
	printf("shared memory attached from 0x%I64x to 0x%I64x\n",
				(INT_PTR)lpMapAddress, (INT_PTR)lpMapAddress+SHM_SIZE);
	
	memcpy(lpMapAddress, buffer, ARRAY_SIZE);
	printf("Shared memory contents: %s\n", (char *)lpMapAddress);
	Sleep(5000);

	if (! UnmapViewOfFile(lpMapAddress))
		err_sys("Could not unmap view of file");
	if (! CloseHandle(hFileMapping))
		err_sys("Could not close the handle to the file mapping");

	ExitProcess(0);
}
