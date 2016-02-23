#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE_LENGTH 2048

int main(int argc, char **argv)
{
    if(argc != 2) {
        printf("Usage: %s <filepath>\n", argv[0]);
        exit(1);
    }

    FILE *fin = fopen(argv[1], "r");
    if(!fin) {
        perror(argv[1]);
        exit(errno);
    }

    char buffer[MAX_LINE_LENGTH];

    while(fgets(buffer, sizeof(buffer), fin)) {
        printf("%s", buffer);
    }

    fclose(fin);
    return 0;
}
