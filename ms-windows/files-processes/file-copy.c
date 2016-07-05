#include <windows.h>
#include <stdio.h>

#define BUF_SIZE 65536
#define DEBUG 1

int main(int argc, char *argv[])
{
    char buffer[BUF_SIZE];
    int bufsize;
    DWORD dwShareMode = 0;
    LPSECURITY_ATTRIBUTES lpSecurityAttributes = NULL;
    HANDLE hTemplateFile = NULL;

    HANDLE sourceFile;
    DWORD numOfBytesRead;
    LPOVERLAPPED lpOverlapped = NULL;

    HANDLE destinationFile;
    DWORD numOfBytesWritten;


    if (argc != 4) {
        fprintf(stderr, "Usage: %s <buffer size> <src> <dest>\n", argv[0]);
        ExitProcess(1);
    }

    bufsize = atoi(argv[1]);
    if (bufsize > BUF_SIZE) {
        fprintf(stderr,"Error: %s: max. buffer size is %d\n",argv[0], BUF_SIZE);
        ExitProcess(1);
    }

    sourceFile = CreateFile (
                     argv[2],
                     GENERIC_READ,
                     dwShareMode,
                     lpSecurityAttributes,
                     OPEN_ALWAYS,
                     FILE_ATTRIBUTE_READONLY,
                     hTemplateFile
                 );
    if (sourceFile == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "File open operation failed on file: %s\n", argv[2]);
        ExitProcess(1);
    }

    destinationFile = CreateFile (
                          argv[3],
                          GENERIC_WRITE,
                          dwShareMode,
                          lpSecurityAttributes,
                          CREATE_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          hTemplateFile
                      );
    if (destinationFile == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "File create operation failed on file: %s\n", argv[3]);
        ExitProcess(1);
    }

    while (1) {
        if (!(ReadFile(sourceFile, buffer, bufsize, &numOfBytesRead, lpOverlapped) && numOfBytesRead > 0))
            break;
        printf("Read %d bytes\n", numOfBytesRead);
        if (!(WriteFile(destinationFile, buffer, numOfBytesRead, &numOfBytesWritten, lpOverlapped)))
            break;
        printf("Wrote %d bytes\n", numOfBytesWritten);
    }

    CloseHandle(sourceFile);
    CloseHandle(destinationFile);
    ExitProcess(0);
}
