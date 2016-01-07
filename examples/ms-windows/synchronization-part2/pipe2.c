
/*
*
* Note that we can interchange what the child and the parent does...that is
* have the parent do ls and the child do sort and this example pipeline
* would still run. However now the pipeline would seem to run in the
* background.
*
*/

#include <windows.h>
#include <stdio.h>
#include <process.h>
#include "error.h"

#define BUFFSZ 4096

int main(int argc, char *argv[])
{
	HANDLE pipes[2];
	HANDLE prevHandle;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	STARTUPINFO si;
	
	// Initialize data
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	si.dwFlags = 0;
	ZeroMemory( &pi, sizeof(pi) );

	// Setup security to allow inheritance (for pipe handles)
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;  // Default security
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);

	// Create the pipe and set stdout to write handle on pipe
	if (! CreatePipe(
				&(pipes[0]),	// Reader
				&(pipes[1]),	// Writer
				&sa,				// Security attributes (inheritance = TRUE)
				BUFFSZ			// Suggested buffer size
			)
	)
		err_sys("pipe error");

	// Store the default handle for reset after create process call
	prevHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	// Set pipe to stdout
	if (! SetStdHandle(STD_OUTPUT_HANDLE, pipes[1]))
		err_sys("Unable to set stdout pipe");
	
	if (! CreateProcess(
				NULL,						// App name
				"ls",						// Command line
				&sa,						// Proc security attributes
				&sa,						// Thread security attributes
				TRUE,						// Inherit handles
				0,							// Creation flags
				NULL,						// Parent environment
				NULL,						// Parent dir
				&si,						// Startup info
				&pi						// Process info
			)
	)
		err_sys("Unable to create child proc\n");

	CloseHandle(pipes[1]);

	// Reset handle on stdout
	SetStdHandle(STD_OUTPUT_HANDLE, prevHandle);
		
	// Set pipe to stdin 
	SetStdHandle(STD_INPUT_HANDLE, pipes[0]);
	
	if (! CreateProcess(
				NULL,						// App name
				"sort",					// Command line
				&sa,						// Proc security attributes
				&sa,						// Thread security attributes
				TRUE,						// Inherit handles
				0,							// Creation flags
				NULL,						// Parent environment
				NULL,						// Parent dir
				&si,						// Startup info
				&pi						// Process info
			)
	)
		err_sys("Unable to create child proc\n");
		
	CloseHandle(pipes[0]);
	CloseHandle(prevHandle);

	ExitProcess(0);
}

