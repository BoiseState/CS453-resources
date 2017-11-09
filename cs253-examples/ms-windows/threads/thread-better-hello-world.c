#include <windows.h>
#include <stdio.h>

DWORD WINAPI PrintMessageFunction( LPVOID ptr );

int  main()
{
    char *szMessage1 = "Goodbye";
    char *szMessage2 = "World";
    LPHANDLE hThread1, hThread2;
    DWORD dwThreadID1, dwThreadID2;

    hThread1 = CreateThread(
                   NULL,                            // Security Descriptor (handle not inheritable)
                   0,                               // initial stack size (default)
                   PrintMessageFunction,    // thread function
                   szMessage1,                  // thread argument
                   0,                               // creation option (run immediately)
                   &dwThreadID1             // thread identifier
               );

    if (! hThread1) {
        fprintf(stderr, "Unable to create thread 1.\n");
        ExitProcess(1);
    }

    hThread2 = CreateThread(
                   NULL,                            // Security Descriptor (handle not inheritable)
                   0,                               // initial stack size (default)
                   PrintMessageFunction,    // thread function
                   szMessage2,                  // thread argument
                   0,                               // creation option (run immediately)
                   &dwThreadID2             // thread identifier
               );

    if (! hThread2) {
        fprintf(stderr, "Unable to create thread 2.\n");
        ExitProcess(2);
    }

    // Wait for threads to complete before exiting (effectively JOIN on both threads)
    WaitForSingleObject(hThread1, INFINITE);
    WaitForSingleObject(hThread2, INFINITE);
    ExitProcess(0);
}

DWORD WINAPI PrintMessageFunction( LPVOID ptr )
{
    char *szMessage;
    szMessage = (char *) ptr;
    printf("%s ", szMessage);
    ExitThread(0);
}
