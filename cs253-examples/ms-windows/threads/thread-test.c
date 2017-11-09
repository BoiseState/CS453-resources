#include <windows.h>
#include <stdio.h>


DWORD WINAPI Run(LPVOID arg);

#define MAX 20000

int main(int argc, char *argv[])
{
    LPHANDLE hThread[MAX];
    DWORD dwThreadIDs[MAX];
    int i;

    for (i=0; i<MAX; i++) {
        hThread[i] = CreateThread(
                         NULL,                      // Security Descriptor (handle not inheritable)
                         0,                         // initial stack size (default)
                         Run,                       // thread function
                         NULL,                      // thread argument
                         0,                         // creation option (run immediately)
                         &dwThreadIDs[i]        // thread identifier
                     );
        if (hThread[i] == NULL) {
            printf("Error in creating thread. Bailing out!\n");
            Sleep(3000);
            ExitProcess(1);
        } else {
            printf("Created thread number %d, id %d\n", i, dwThreadIDs[i]);
        }
    }


    for (i=0; i<MAX; i++)
        WaitForSingleObject(hThread[i], INFINITE);

    ExitProcess(0);
}

DWORD WINAPI Run(LPVOID arg)
{
    Sleep(10000);
    printf("This is  thread id = %d\n", GetCurrentThreadId());


    ExitThread(0);
}