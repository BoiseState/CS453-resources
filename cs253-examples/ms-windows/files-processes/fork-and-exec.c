#include <stdio.h>
#include <windows.h>
#include <sys/types.h>

#define BUFFER_SIZE 512

void PrintMessage( char *szMsg );
void ErrSys( char *szMsg );

int main(void)
{
    STARTUPINFO si1;
    PROCESS_INFORMATION pi;
    LPVOID lpMsgBuf;

    // Initialize data
    ZeroMemory( &si1, sizeof(si1) );
    si1.cb = sizeof(si1);
    ZeroMemory( &pi, sizeof(pi) );

    if ( ! CreateProcess(
                NULL,               // No module name (use command line)
                "notepad",  // Command line for process
                NULL,               // Process handle not inheritable
                NULL,               // Thread handle not inheritable.
                FALSE,          // Set handle inheritance to FALSE.
                0,                  // No creation flags.
                NULL,               // Use parent's environment block.
                NULL,               // Use parent's starting directory.
                &si1,               // Pointer to STARTUPINFO structure.
                &pi )           // Pointer to PROCESS_INFORMATION struct
       ) {
        // Try to format the error message from the last failed call (returns # of TCHARS in message -- 0 if failed)
        if ( FormatMessage(
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
            PrintMessage( (LPSTR)lpMsgBuf );
            // Free the buffer.
            LocalFree( lpMsgBuf );
        }

        ErrSys( "CreateProcess failed." );
    }

    printf( "Created child with pid %d\n", pi.dwProcessId );
    /* parent continues concurrently with child */
    Sleep(2000);

    WaitForSingleObject(pi.hProcess, INFINITE);
    ExitProcess(0);
}


void PrintMessage( char *szMsg )
{
    printf("%s ", szMsg);
}

void ErrSys(char *szMsg)
{
    fprintf(stderr, szMsg);
    fflush(NULL); /* flush all output streams */
    ExitProcess(1); /* exit abnormally */
}
