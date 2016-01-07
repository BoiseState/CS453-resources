#include <windows.h>
#include <stdio.h>

#include	"error.h"

#define BUFFSZ 4096
#define MAX_LINE 256

int main(int argc, char *argv[])
{
	HANDLE pipe[2];
	char line[MAX_LINE];
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	STARTUPINFO si;
	char szBuff[BUFFSZ];
	DWORD dwBytes;
	
	// Setup security to allow inheritance (for pipe handles)
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;  // Default security
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);

	// Initialize data
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	si.dwFlags = 0;
	ZeroMemory( &pi, sizeof(pi) );

	// Check for parent or child
	if (1 == argc) {
		// PARENT
		
		// Create an anonymous pipe
		if (! CreatePipe(
					&(pipe[0]),	// Reader
					&(pipe[1]),	// Writer
					&sa,				// Security attributes (inheritance = TRUE)
					BUFFSZ			// Suggested buffer size
				)
		)
			err_sys("pipe error");
		
		// In order for the child to inherit the pipe, set the current stdin handle
		// to the reader handle of the pipe "before" calling create process.
		if (! SetStdHandle(STD_INPUT_HANDLE, pipe[0]))
			err_sys("Unable to set input pipe");
		
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
		
		CloseHandle(pipe[0]);
		WriteFile(pipe[1], "hello world\n", 12, &dwBytes, NULL);

	} else {
		// CHILD

		// Get the stdin pipe handle
		pipe[0] = GetStdHandle(STD_INPUT_HANDLE);

		ReadFile(pipe[0], line, MAX_LINE, &dwBytes, NULL);
		
		// STDOUT_FILENO is defined in /usr/include/unistd.h
		WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), line, dwBytes, &dwBytes, NULL);
	}

	ExitProcess(0);
}
