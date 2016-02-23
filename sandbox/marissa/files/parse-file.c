#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "Object.h"

const int MAX_LINE_LENGTH = 2048;
const char *delimiters = " 0123456789\t;{}()[].#<>\n\r+-/%*\"^~&=!|:\\?,";

int main(int argc, char *argv[])
{
    FILE *fin;

    // Read file name from command line
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    // Open file for reading.
    fin = fopen(argv[1], "r");
    if (!fin) {
        perror(argv[1]);
        exit(errno);
    }
    printf("opened file %s\n", argv[1]);

    int totalCount = 0;

    // Read line-by-line (using fgets).
    char buffer[MAX_LINE_LENGTH];
    while(fgets(buffer, sizeof(buffer), fin)) {
        printf("%s", buffer);

        // Break line into words using strtok.
        char *nextWord;
        struct object *word;

        // Pass in the buffer to the initial strtok call, and NULL in subsequent calls.
        nextWord = strtok(buffer, delimiters);

        while(nextWord != NULL) {
            // increment word count.
            totalCount++;

            // create word object with unique id.
            // THIS CREATES A MEMORY LEAK! We never free it in this example.
            word = createObject(totalCount, nextWord);

            // THIS CREATES A MEMORY LEAK!! See what we are doing in printList for
            // an example of how to fix it.
            printf("%s\n", toString(word));

            // get the next token.
            nextWord = strtok(NULL, delimiters);
        }
    }





    return 0;
}
