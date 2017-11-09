/*
 * Creates three threads that compute for a long time. Good way
 * to check how threads are scheduled on a manycore machine.
 *
*/

#include <windows.h>
#include <stdio.h>
#include <math.h>


int main()
{
    LPHANDLE phThread1, phThread2, phThread3;
    DWORD dwThreadID1, dwThreadID2, dwThreadID3;
    DWORD WINAPI ComputeUntilHellAlmostFreezes(LPVOID);

    phThread1 = CreateThread(
                    NULL,                               // Security Descriptor (handle not inheritable)
                    0,                                  // initial stack size (default)
                    ComputeUntilHellAlmostFreezes,  // thread function
                    NULL,                               // thread argument
                    0,                                  // creation option (run immediately)
                    &dwThreadID1                    // thread identifier
                );

    phThread2 = CreateThread(
                    NULL,                               // Security Descriptor (handle not inheritable)
                    0,                                  // initial stack size (default)
                    ComputeUntilHellAlmostFreezes,  // thread function
                    NULL,                               // thread argument
                    0,                                  // creation option (run immediately)
                    &dwThreadID2                    // thread identifier
                );

    phThread3 = CreateThread(
                    NULL,                               // Security Descriptor (handle not inheritable)
                    0,                                  // initial stack size (default)
                    ComputeUntilHellAlmostFreezes,  // thread function
                    NULL,                               // thread argument
                    0,                                  // creation option (run immediately)
                    &dwThreadID3                    // thread identifier
                );


    // Wait for threads to complete before exiting (effectively JOIN on both threads)
    WaitForSingleObject(phThread1, INFINITE);
    WaitForSingleObject(phThread2, INFINITE);
    WaitForSingleObject(phThread3, INFINITE);
    ExitProcess(0);
}

DWORD WINAPI ComputeUntilHellAlmostFreezes(LPVOID arg)
{
    int i;
    double tmp;

    for (i=0; i<90000000; i++) {
        tmp = sqrt((double) i);
        if (i%1000 == 0)
            printf("I am thread %d\n", GetCurrentThreadId());
    }

    ExitThread(0);
}
