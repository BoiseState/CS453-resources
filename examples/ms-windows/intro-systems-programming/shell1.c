/* 
 * This program needs the file error.c and ourhdr.h to compile. 
 *
 */
#include	<sys/types.h>
#include <windows.h>
#include	"ourhdr.h"

int main(void)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD dwChildID = 0;
	char szBuff[MAXLINE];
	DWORD dwProcessExitStatus;

	// Initialize data
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	printf("%% ");	/* print prompt (printf requires %% to print %) */
	while (fgets(szBuff, MAXLINE, stdin) != NULL) {
		szBuff[strlen(szBuff) - 1] = 0;	/* replace newline with null */

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
			&si,  // Pointer to STARTUPINFO structure.
			&pi )  // Pointer to PROCESS_INFORMATION struct
		)
		{
			err_sys( "CreateProcess failed." );
		}

		/* parent */
		/* wait for normal termination of child process */
		WaitForSingleObject(pi.hProcess, INFINITE);

		printf("%% ");
	}
	exit(0);
}

