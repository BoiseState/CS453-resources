/* timeout: set time limit on a process */

#include <stdio.h>
#include <windows.h>
#include <signal.h>

#define CHILD_PROC_TERMINATION_CODE 99
#define PROC_TERMINATION_CODE 127
#define BUFF_SZ 512

HANDLE hChildProc; /* child process handle */

void OnAlarm(int signo);
void Error(char *msg, char *arg);
DWORD WINAPI AlarmRun(LPVOID threadData);
void Alarm(int *pNumSecs);

int main(int argc, char *argv[])
{
	void Error(char *msg, char *arg);
	int sec=10, i;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwChildID = 0;
	char *szProgName;
	DWORD dwExitStatus;
	char szBuff[BUFF_SZ];

	// Initialize data
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	szBuff[0] = 0;
	
	// Check for optional timeout
	szProgName = argv[0];
	if (argc > 1 && argv[1][0] == '-') {
		sec = atoi(&argv[1][1]);
		argc--;
		argv++;
	}

	// Check for command
	if (argc < 2) {
		Error("Usage: %s [-10] command", szProgName);
	}
	
	// Build command (in case 1 or more args to command)
	for (i=1; i<argc; i++) {
		strcat(szBuff, argv[i]);
		strcat(szBuff, " ");
	}
	
	// Run command
	/* Start the child process */
	if ( ! CreateProcess( 
		NULL,		// No module name (use command line)
		szBuff,	// Command line
		NULL,		// Process handle not inheritable
		NULL,		// Thread handle not inheritable. 
		FALSE,	// Set handle inheritance to FALSE. 
		0,			// No creation flags. 
		NULL,		// Use parent's environment block. 
		NULL,		// Use parent's starting directory. 
		&si,		// Pointer to STARTUPINFO structure.
		&pi )	// Pointer to PROCESS_INFORMATION struct
	)
	{
		Error( "CreateProcess failed for %s.", szBuff );
	}
	hChildProc = pi.hProcess;

	// Setup handler for SIGINT signal	
	signal(SIGINT, OnAlarm);
	
	// Create alarm thread to kill child proc if doesn't finish in time
	Alarm(&sec);
	
	// Wait for child proc to finish (either via termination by alarm or normally)
	WaitForSingleObject(hChildProc, INFINITE);
	GetExitCodeProcess(hChildProc, &dwExitStatus);
	if (dwExitStatus == CHILD_PROC_TERMINATION_CODE)
		Error("\"%s\" killed", szBuff);

	ExitProcess(dwExitStatus);
}



// Called when signal raised by alarm thread
void OnAlarm(int signo) /* kill child process if alarm arives */
{
	TerminateProcess(hChildProc, CHILD_PROC_TERMINATION_CODE);
}

// Error function for parent process
void Error(char *msg, char *arg)
{
	fprintf(stderr, msg, arg);
	fprintf(stderr,"\n");
	
	ExitProcess(PROC_TERMINATION_CODE);
}


// Alarm thread procedure
DWORD WINAPI AlarmRun(LPVOID threadData)
{
	int numSecs = *((int *)threadData);
	Sleep(1000 * numSecs);
	raise(SIGINT);
	
	ExitThread(0);
}

// Alarm function to create thread for timeout purposes on child proc
void Alarm(int *pNumSecs)
{
	LPHANDLE phThread;
	DWORD dwThreadID;

	phThread = CreateThread(
			NULL,							// Security Descriptor (handle not inheritable)
			0,								// initial stack size (default)
			AlarmRun,					// thread function
			pNumSecs,					// thread argument
			0,								// creation option (run immediately)
			&dwThreadID					// thread identifier
	);
		
	if (! phThread) {
		fprintf(stderr, "Unable to create alarm thread.\n");
		ExitProcess(1);
	}
}
