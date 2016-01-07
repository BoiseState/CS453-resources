#include <process.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void __cdecl Run( LPVOID pData );

// Global vars for thread visibility
int cAllocs = 0;
LPBOOL pfThreadsComplete;

void main(int argc, char *argv[])
{
	int cThreads;
	LPHANDLE phThreads;
	LPDWORD pdwThreadIDs;
	int i;
	DWORD dwExitStatus;	
	
	// Verify arguments
	if ( argc != 3 ) {
		fprintf(stderr, "Usage : %s <#threads> <#allocations>\n", argv[0]);
		ExitProcess(1);
	}
	
	cThreads = atoi(argv[1]);
	cAllocs = atoi(argv[2]);
	
	phThreads = malloc(sizeof(HANDLE) * cThreads);
	pdwThreadIDs = malloc(sizeof(DWORD) * cThreads);
	pfThreadsComplete = malloc(sizeof(BOOL) * cThreads);
	
	// Set the flag for each thread to FALSE (indicates not complete for each thread, they will reset when done)
	for (i=0; i<cThreads; i++)
		pfThreadsComplete[i] = FALSE;
	
	// Create each thread
	for (i=0; i<cThreads; i++) {
		pdwThreadIDs[i] = i;
		phThreads[i] = (HANDLE)_beginthread( 
								Run,						// Start address of routine that begins execution of new thread
								0,							// Stack size for new thread or 0 (default size)
								&pdwThreadIDs[i]		// Argument list to be passed to new thread or NULL. 
							);

		if (! phThreads[i]) {
			fprintf(stderr, "Unable to create thread %d of %d threads.\n", i, cThreads);
			ExitProcess(1);
		}
	}

	// The windows C thread library does not have a "simple" mechanism for waiting or joining on threads
	// (use flags instead)
	for (i=0; i<cThreads; i++)
	{
		while (pfThreadsComplete[i] != TRUE) {
			Sleep(250);
		}
	}

	free(phThreads);
	free(pdwThreadIDs);
	free(pfThreadsComplete);
	
	ExitProcess(0);
}

  
void __cdecl Run( LPVOID pData )
{
	int *pInt;
	int i;
	DWORD threadID = (*(LPDWORD)pData);
	
	for (i=0; i<cAllocs; i++) {
		pInt = malloc(sizeof(int));
		free(pInt);
	}
	
	fprintf(stderr, "Thread %d complete.\n", threadID);
	
	// Indicate complete
	pfThreadsComplete[threadID] = TRUE;
	
	_endthread();
}
