#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

/**
 * Try passing in integer argument less than 0 and greater
 * than max unsigned int.
 *
 * How can we fix this issue?
 */
void printUsage(char[]);

int main(int argc, char *argv[])
{
    if(argc < 5) {
        printUsage(argv[0]);
    }

    // Parse int argument
    unsigned int x = 0;
    if(strcmp(argv[1],"-i") == 0) {
        int temp = atoi(argv[2]);
        if (temp > UINT_MAX || temp < 0) {
            printf("error: integer (%d) must be between %u and %u\n\n",
                   temp, 0, UINT_MAX);
            printUsage(argv[0]);
        }
        // only keep the value if it is in valid range
        x = (unsigned int) temp;
    } else {
        printf("error: -i expected\n");
        printUsage(argv[0]);
    }

    // Parse string argument
    char *string; // This is like a String Object reference in Java
    if(strcmp(argv[3], "-s") == 0) {
        string = argv[4];
    } else {
        printf("error: -s expected\n");
        printUsage(argv[0]);
    }

    printf("Your integer: %u\n", x);
    printf("Your string: %s (%d chars)\n", string, (int) strlen(string));

    int i;
    int len = (int) strlen(string);
    for(i = 0; i < len; i++) {
        printf("%d: %c\n", i, string[i]);
    }

    return 0;
}

void printUsage(char prog[])
{
    printf("Usage: %s -i <int between %u-%u> -s <string>\n", prog, 0,
           UINT_MAX);
    exit(1);
}
