/**
timeout: set time limit on a process

Try it from the powershell as

timeout.exe -10 notepad
*/

#include <stdio.h>
#include <windows.h>

#define CHILD_PROC_TERMINATION_CODE 9
#define PROC_TERMINATION_CODE 127
#define BUFFER_SIZE 512

HANDLE hChildProc; /* child process handle */
HANDLE hTimer;

void Error(char *msg, char *arg);
void CALLBACK onAlarm(PVOID lpParam, BOOLEAN timerOrWait);


int main(int argc, char *argv[])
{
    void Error(char *msg, char *arg);
    int sec=10, i;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwChildID = 0;
    char *szProgName;
    DWORD dwExitStatus;
    char szBuff[BUFFER_SIZE];


    // Initialize data
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    szBuff[0] = 0;

    // Check for optional timeout
    szProgName = argv[0];
    if (argc > 1 && argv[1][0] == '-') {
        sec = atoi(&argv[1][1]) * 1000; //in milliseconds
        argc--;
        argv++;
    }

    // Check for command
    if (argc < 2) {
        Error("Usage: %s [-10] command", szProgName);
    }

    // Build command (in case 1 or more args to command)
    for (i=1; i<argc; i++) {
        strcat_s(szBuff, BUFFER_SIZE, argv[i]);
        strcat_s(szBuff, BUFFER_SIZE,  " ");
    }

    // Run command
    /* Start the child process */
    if ( ! CreateProcess(
                NULL,       // No module name (use command line)
                szBuff, // Command line
                NULL,       // Process handle not inheritable
                NULL,       // Thread handle not inheritable.
                FALSE,  // Set handle inheritance to FALSE.
                0,          // No creation flags.
                NULL,       // Use parent's environment block.
                NULL,       // Use parent's starting directory.
                &si,        // Pointer to STARTUPINFO structure.
                &pi )   // Pointer to PROCESS_INFORMATION struct
       ) {
        Error( "CreateProcess failed for %s.", szBuff );
    }
    hChildProc = pi.hProcess;

    CreateTimerQueueTimer(&hTimer, NULL, onAlarm, NULL, sec, 0, WT_EXECUTEONLYONCE);

    // Wait for child proc to finish (either via termination by alarm or normally)
    WaitForSingleObject(hChildProc, INFINITE);
    GetExitCodeProcess(hChildProc, &dwExitStatus);
    if (dwExitStatus == CHILD_PROC_TERMINATION_CODE)
        Error("\"%s\" killed", szBuff);

    ExitProcess(dwExitStatus);
}


// Error function for parent process
void Error(char *msg, char *arg)
{
    fprintf(stderr, msg, arg);
    fprintf(stderr,"\n");

    ExitProcess(PROC_TERMINATION_CODE);
}


/**
Callback function for the alarm. Delete the timer and terminate all child processes.
*/
void CALLBACK onAlarm(PVOID lpParam, BOOLEAN timerOrWait)
{
    DeleteTimerQueueTimer(NULL, hTimer, NULL);
    printf("Received alarm!\n");
    TerminateProcess(hChildProc, CHILD_PROC_TERMINATION_CODE);
}




