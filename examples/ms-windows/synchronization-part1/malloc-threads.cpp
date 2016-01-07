#include <windows.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

DWORD WINAPI Run( LPVOID pData );

int cAllocs = 0;

void main(int argc, char *argv[])
{
	// Verify arguments
	if ( argc != 3 ) {
		cerr << "Usage :" << argv[0] << " <#threads> <#allocations> " << endl;
		ExitProcess(1);
	}
	
	int cThreads = atoi(argv[1]);
	cAllocs = atoi(argv[2]);
	
	LPHANDLE phThreads = new HANDLE [cThreads];
	LPDWORD pdwThreadIDs = new DWORD [cThreads];
	
	for (int i=0; i<cThreads; i++) {
		phThreads[i] = CreateThread(
			NULL,								// Security Descriptor (handle not inheritable)
			0,									// initial stack size (default)
			Run,								// thread function
			&pdwThreadIDs[i],				// thread argument
			0,									// creation option (run immediately)
			&pdwThreadIDs[i]				// thread identifier
		);
		
		if (! phThreads[i]) {
			cerr << "Unable to create thread " << i << " of " << cThreads << " threads." << endl;
			ExitProcess(1);
		}
	}

	// Wait for threads to complete before exiting (effectively JOIN on all threads)
	WaitForMultipleObject(cThreads, phThreads, TRUE, INFINITE);

	delete [] phThreads;
	delete [] pdwThreadIDs;
	
	ExitProcess(0);
}

  
DWORD WINAPI Run( LPVOID pData )
{
	int *pInt;
	for (int i=0; i<cAllocs; i++) {
		pInt = new int;
		delete pInt;
	}
	
	cout << "Thread " << (*(LPDWORD)pData) << " complete" << endl;
	
	ExitThread(0);
}
