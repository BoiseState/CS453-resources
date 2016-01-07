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
	char szBuff[BUFFSZ];
	
	// Initialize data
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	si.dwFlags = 0;
	ZeroMemory( &pi, sizeof(pi) );

	// Setup security to allow inheritance (for pipe handles)
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;	// Default security
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);

	if (1 == argc) {
		// PARENT
	
		// Create the child process (add a "1" as an arg to indicate not parent)
		sprintf(szBuff, "%s 1", argv[0]);
		
		if (! CreateProcess(
					NULL,						// App name
					szBuff,					// Command line
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
	
		// parent waits for the last process in the pipeline to finish
		WaitForSingleObject(pi.hProcess, INFINITE);

	} else {
	
		// "A" child process
		
		if (atoi(argv[1]) == 1) {
			/* first child process */

			// Create the pipe 
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
			
			// Create the child process (add a "2" as an arg to indicate 2nd child)
			sprintf(szBuff, "%s 2", argv[0]);
			
			if (! CreateProcess(
						NULL,						// App name
						szBuff,					// Command line
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
						"wc",						// Command line
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

			// Wait on completion of all pipes
			WaitForSingleObject(pi.hProcess, INFINITE);

		} else {
			/* second child process */

			// Create the pipe 
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
				
			// THIS IS THE MIDDLE PROCESS IN THE PIPELINE
				
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

		}
   }
   
}
