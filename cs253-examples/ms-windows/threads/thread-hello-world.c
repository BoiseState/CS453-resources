#include <windows.h>
#include <stdio.h>

DWORD WINAPI PrintMessageFunction( LPVOID ptr );

int  main()
{
    LPHANDLE phThread1, phThread2;
    DWORD dwThreadID1, dwThreadID2;
    char *szMessage1 = "Goodbye";
    char *szMessage2 = "World";

    phThread1 = CreateThread(
                    NULL,                           // Security Descriptor (handle not inheritable)
                    0,                              // initial stack size (default)
                    PrintMessageFunction,   // thread function
                    szMessage1,                 // thread argument
                    0,                              // creation option (run immediately)
                    &dwThreadID1                // thread identifier
                );

    phThread2 = CreateThread(
                    NULL,                           // Security Descriptor (handle not inheritable)
                    0,                              // initial stack size (default)
                    PrintMessageFunction,   // thread function
                    szMessage2,                 // thread argument
                    0,                              // creation option (run immediately)
                    &dwThreadID2                // thread identifier
                );


    ExitProcess(0);
}

DWORD WINAPI PrintMessageFunction( LPVOID ptr )
{
    char *szMessage;
    szMessage = (char *) ptr;
    printf("%s ", szMessage);
    ExitThread(0);
}
