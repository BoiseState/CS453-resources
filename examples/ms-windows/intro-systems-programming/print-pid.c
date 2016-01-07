#include <stdio.h>
#include <windows.h>

int main()
{
	printf("After CreateProcess pid = %d\n", GetCurrentProcessId());
	Sleep(5000); //5 seconds
	ExitProcess(0);
}
