#include	<windows.h>
#include	<stdio.h>
#include "error.h"

#define	ARRAY_SIZE	 10000
#define	SHM_SIZE	100000

int	buffer[ARRAY_SIZE];	/* uninitialized data = bss */

void *_end, *end, *_etext, *etext, *_edata, *edata,
				*__data_start, *__text_start;


int main(void)
{
	int shmid, offset;
	HANDLE hFileMapping;
	LPVOID lpMapAddress;
	SYSTEM_INFO si;
	
	/*printf("text start = %x\n",&__text_start);*/ // not supported in Linux
	printf("first address above the text = 0x%I64x\n",&etext);
	/*printf("data start = %x\n",&__data_start);*/ // not supported in Linux
	printf("first address above initialized data = 0x%I64x\n",&edata);
	printf("first address above unitialized data = 0x%I64x\n\n",&end);

	printf("buffer[] from 0x%I64x to 0x%I64x\n", &buffer[0], &buffer[ARRAY_SIZE]);
	printf("stack around 0x%I64x\n", &shmid);

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

	// MSDN:ms-help://MS.VSCC/MS.MSDNVS/memory/hh/winbase/filemap_8p9h.htm
	// The combination of the high and low offsets must specify an offset 
	// within the file that matches the system's memory allocation granularity, 
	// or the function fails. That is, the offset must be a multiple of the 
	// allocation granularity. Use the GetSystemInfo function, which fills in 
	// the members of a SYSTEM_INFO structure, to obtain the system's memory 
	// allocation granularity. 
	GetSystemInfo(&si);
	printf("System memory allocation granularity: %d\n", si.dwAllocationGranularity);
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

	memcpy(buffer, lpMapAddress, ARRAY_SIZE);
	// NOTE: buffer is empty string because the kernel zeros the shared memory when 
	//		CreateFileMapping is called with INVALID_HANDLE_VALUE.
	printf("From shared memory: %s\n", buffer);

	if (! UnmapViewOfFile(lpMapAddress))
		err_sys("Could not unmap view of file");
	if (! CloseHandle(hFileMapping))
		err_sys("Could not close the handle to the file mapping");

	ExitProcess(0);
}
