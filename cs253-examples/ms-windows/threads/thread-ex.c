#include <windows.h>
#include <stdio.h>


DWORD WINAPI Run(LPVOID threadData);

void main(int argc, char *argv[])
{
    LPHANDLE hMerlot, hPinot, hCabernet;
    DWORD dwThreadIdMerlot, dwThreadIdPinot, dwThreadIdCabernet;
    DWORD dwExitStatus;

    hMerlot = CreateThread(
                  NULL,                     // Security Descriptor (handle not inheritable)
                  0,                            // initial stack size (default)
                  Run,                      // thread function
                  "merlot",             // thread argument
                  0,                            // creation option (run immediately)
                  &dwThreadIdMerlot     // thread identifier
              );

    if (! hMerlot) {
        fprintf(stderr, "Unable to create thread Merlot.\n");
        ExitProcess(1);
    }

    hPinot = CreateThread(
                 NULL,                      // Security Descriptor (handle not inheritable)
                 0,                         // initial stack size (default)
                 Run,                       // thread function
                 "pinot",                   // thread argument
                 0,                         // creation option (run immediately)
                 &dwThreadIdPinot       // thread identifier
             );

    if (! hPinot) {
        fprintf(stderr, "Unable to create thread Pinot.\n");
        ExitProcess(1);
    }

    hCabernet = CreateThread(
                    NULL,                       // Security Descriptor (handle not inheritable)
                    0,                          // initial stack size (default)
                    Run,                        // thread function
                    "cabernet",             // thread argument
                    0,                          // creation option (run immediately)
                    &dwThreadIdCabernet     // thread identifier
                );

    if (! hCabernet) {
        fprintf(stderr, "Unable to create thread Cabernet.\n");
        ExitProcess(1);
    }

    // Wait for threads to complete before exiting (effectively JOIN on all threads)

    WaitForSigleObject(hMerlot, INFINITE);
    WaitForSigleObject(hPinot, INFINITE);
    WaitForSigleObject(hCabernet, INFINITE);
    ExitProcess(0);
}


DWORD WINAPI Run(LPVOID threadData)
{
    char *szName = (char *)threadData;
    int i;

    for (i=0; i<10; i++) {
        printf("This is the %s thread\n", szName);
    }

    ExitThread(0);
}
