#include <windows.h>
#include <stdio.h>
#include <sys/types.h>

void ErrSys(char *szMsg);

#define MAXNUM 2000
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    DWORD dwChildID = 0;
    char *szBuff = (char *) malloc(sizeof(char)*BUFFER_SIZE);
    int i;

    // Initialize data
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Check to see if child (arg2 = childID) or parent (1 arg)
    if (argc == 2) {
        // Child
        dwChildID = atoi(argv[1]);
        Sleep(20 * 1000);
        printf("Child %d exiting.\n", dwChildID);
        ExitProcess(0);

    } else if (argc != 1) { // Parent has no args (1 = name of program, 2 = name + 1 arg, etc)
        ErrSys("Incorrect number of arguments.\n");
        ExitProcess(1);
    }

    // Parent

    for (i=0; i<MAXNUM; i++) {
        // Fill in the command line for each child
        sprintf_s(szBuff, BUFFER_SIZE, "%s %d", argv[0], i);

        /* Start the child process */
        if (! CreateProcess(
                    NULL,  // No module name (use command line)
                    (LPSTR)szBuff,  // Command line
                    NULL,  // Process handle not inheritable
                    NULL,  // Thread handle not inheritable.
                    FALSE,  // Set handle inheritance to FALSE.
                    0,  // No creation flags.
                    NULL,  // Use parent's environment block.
                    NULL,  // Use parent's starting directory.
                    &si,  // Pointer to STARTUPINFO structure.
                    &pi)  // Pointer to PROCESS_INFORMATION struct
           ) {
            ErrSys("CreateProcess failed.\n");
        }

        printf("Created child number %d with pid %d\n", i, pi.dwProcessId);
    }

    Sleep(10*1000);
    ExitProcess(0);
}


void ErrSys(char *szMsg)
{
    LPVOID lpMsgBuf;

    // Try to format the error message from the last failed call (returns # of TCHARS in message -- 0 if failed)
    if (FormatMessage(
                FORMAT_MESSAGE_ALLOCATE_BUFFER |                    // source and processing options
                FORMAT_MESSAGE_FROM_SYSTEM |
                FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,                                                       // message source
                GetLastError(),                                     // message identifier
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // language identifier (Default language)
                (LPTSTR) &lpMsgBuf,                                 // message buffer
                0,                                                          // maximum size of message buffer (ignored with FORMAT_MESSAGE_ALLOCATE_BUFFER set)
                NULL                                                        // array of message inserts
            )
       ) {
        // Display the formatted string.
        fprintf(stderr, "%s: %s \n", szMsg, (LPSTR)lpMsgBuf);
        LocalFree(lpMsgBuf);
    } else {
        fprintf(stderr, "%s: Could not get system error message!\n",  szMsg);
    }
    fflush(NULL); /* flush all output streams */
    ExitProcess(1); /* exit abnormally */
}
