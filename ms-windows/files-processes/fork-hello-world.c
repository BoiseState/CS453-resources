#include <stdio.h>
#include <sys/types.h>
#include <windows.h>

#define BUFFER_SIZE 512

void PrintMessage( void *p );
void ErrSys(char *szMsg);

int main(int argc, char *argv[])
{
    STARTUPINFO si1;
    STARTUPINFO si2;
    PROCESS_INFORMATION pi1;
    PROCESS_INFORMATION pi2;
    char *szMessage1 = "Goodbye";
    char *szMessage2 = "World";
    DWORD dwChildID = 0;
    char szBuff[BUFFER_SIZE];

    // Initialize data
    ZeroMemory( &si1, sizeof(si1) );
    si1.cb = sizeof(si1);
    ZeroMemory( &si2, sizeof(si2) );
    si2.cb = sizeof(si2);
    ZeroMemory( &pi1, sizeof(pi1) );
    ZeroMemory( &pi2, sizeof(pi2) );

    // Check to see if child (arg2 = childID) or parent (1 arg)
    if (argc == 2) {
        // Child
        dwChildID = atoi( argv[1] );

        if (1 == dwChildID) {
            PrintMessage(szMessage1);
            /*sleep(2);*/
            ExitProcess(0);
        } else if (2 == dwChildID) {
            PrintMessage(szMessage2);
            /*sleep(2);*/
            ExitProcess(0);
        } else {
            ErrSys( "Unknown child created." );
            ExitProcess(1);
        }
    } else if (argc != 1) { // Parent has no args (1 = name of program, 2 = name + 1 arg, etc)
        ErrSys( "Incorrect number of arguments." );
        ExitProcess(1);
    }

    // Parent

    // Fill in the command line for 1st child
    sprintf_s( szBuff, BUFFER_SIZE, "%s 1", argv[0] );

    /*printf("\n\nbefore CreateProcess\n"); */

    /* Start the child process */
    if ( ! CreateProcess(
                NULL,  // No module name (use command line)
                szBuff,  // Command line
                NULL,  // Process handle not inheritable
                NULL,  // Thread handle not inheritable.
                FALSE,  // Set handle inheritance to FALSE.
                0,  // No creation flags.
                NULL,  // Use parent's environment block.
                NULL,  // Use parent's starting directory.
                &si1,  // Pointer to STARTUPINFO structure.
                &pi1 )  // Pointer to PROCESS_INFORMATION struct
       ) {
        ErrSys( "CreateProcess failed." );
    }

    /*printf("Created 1st child with dwProcessId %d\n", pi1.dwProcessId);*/

    /* parent continues and creates another child */

    // Fill in the command line for 2nd child
    sprintf_s(szBuff, BUFFER_SIZE, "%s 2", argv[0]);

    /*printf("\n\nbefore CreateProcess\n"); */

    /* Start the child process */
    if ( ! CreateProcess(
                NULL,  // No module name (use command line)
                szBuff,  // Command line
                NULL,  // Process handle not inheritable
                NULL,  // Thread handle not inheritable.
                FALSE,  // Set handle inheritance to FALSE.
                0,  // No creation flags.
                NULL,  // Use parent's environment block.
                NULL,  // Use parent's starting directory.
                &si2,  // Pointer to STARTUPINFO structure.
                &pi2 )  // Pointer to PROCESS_INFORMATION struct
       ) {
        ErrSys( "CreateProcess failed." );
    }

    /*printf("Created 2nd child with dwProcessId %d\n", pi2.dwProcessId);*/
    //Sleep(2*1000); //2 seconds
    ExitProcess(0);
}

void PrintMessage( void *p )
{
    char *szMessage;
    szMessage = (char *) p;
    printf("%s ", szMessage);
}

void ErrSys(char *szMsg)
{
    fprintf(stderr, szMsg);
    fflush(NULL); /* flush all output streams */
    ExitProcess(1); /* exit abnormally */
}
