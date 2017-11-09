#include <stdio.h>
#include <windows.h>
#include <sys/types.h>

#define BUFFER_SIZE 256

void ChildsPlay();
void ErrSys(char *szMsg);

int main ( int argc, char *argv[] )
{
    STARTUPINFO si1;
    PROCESS_INFORMATION pi;
    DWORD dwChildID = 0;
    char szBuff[BUFFER_SIZE];

    // Initialize data
    ZeroMemory( &si1, sizeof(si1) );
    si1.cb = sizeof(si1);
    ZeroMemory( &pi, sizeof(pi) );

    // Check to see if child (arg2 = childID) or parent (1 arg)
    if (argc == 2) {
        // Child
        dwChildID = atoi( argv[1] );

        if (dwChildID == 1) {
            ChildsPlay();
            ExitProcess(0);
        } else {
            ErrSys( "Unknown child created." );
            ExitProcess(1);
        }
    } else if (argc != 1) { // Parent has no args (1 = name of program, 2 = name + 1 arg, etc)
        ErrSys("Incorrect number of arguments.");
        ExitProcess(1);
    }

    // Parent

    // Fill in the command line for 1st child
    sprintf_s(szBuff, BUFFER_SIZE, "%s 1", argv[0]);

    /* Start the child process */
    if ( !CreateProcess(
                NULL,  // No module name (use command line)
                szBuff,  // Command line
                NULL,  // Process handle not inheritable
                NULL,  // Thread handle not inheritable.
                FALSE,  // Set handle inheritance to FALSE.
                0,  // No creation flags.
                NULL,  // Use parent's environment block.
                NULL,  // Use parent's starting directory.
                &si1,  // Pointer to STARTUPINFO structure.
                &pi )  // Pointer to PROCESS_INFORMATION struct
       ) {
        ErrSys( "CreateProcess failed." );
    }

    printf("Created child with pid %d\n", pi.dwProcessId);
    /* parent continues concurrently with child */

    Sleep(2000);  // Windows Sleep() is in milliseconds

    printf("Shoo away!\n");

    /* wait for normal termination of child process */
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    Sleep(2000); //so we can watch the output
    ExitProcess(0);
}

void ChildsPlay()
{
    printf("Hey, I need some money! \n");
}

void ErrSys(char *szMsg)
{
    fprintf(stderr, szMsg);
    fflush(NULL); /* flush all output streams */
    ExitProcess(1); /* exit abnormally */
}
