
#include <windows.h>
#include <stdio.h>

HANDLE hTimer;

void CALLBACK OnAlarm(PVOID lpParam, BOOLEAN timerOrWait);

int main(void)
{
    CreateTimerQueueTimer(&hTimer, NULL, OnAlarm, NULL, 2000, 0, WT_EXECUTEONLYONCE);
    Sleep(10000);
}

void CALLBACK OnAlarm(PVOID lpParam, BOOLEAN timerOrWait)
{
    DeleteTimerQueueTimer(NULL, hTimer, NULL);
    printf("alarm function called!\n");
}
