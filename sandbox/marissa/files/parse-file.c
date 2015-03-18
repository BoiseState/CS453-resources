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
    if (argc != 2)
    {
	printf("Usage: %s <filename>\n", argv[0]);
	exit(-1);
    }
    // Open file for reading.
    fin = fopen(argv[1], "r");
    if (!fin)
    {
	perror(argv[1]);
	exit(errno);
    }
    printf("opened file %s\n", argv[1]);

    int count = 0;

    // Read line-by-line (using fgets).
	char buffer[MAX_LINE_LENGTH];
	while(fgets(buffer, sizeof(buffer), fin))
	{
		printf("%s", buffer);
		char *nextWord;
		struct object *word;
		nextWord = strtok(buffer, delimiters);
		while(nextWord != NULL)
		{
			count++;
			// save word
			word = createObject(count, nextWord);
			//printf("%s\n", toString(word));
			printf("%s\n",nextWord);

			// get the next token.
			nextWord = strtok(NULL, delimiters);
		}
	}


    // Break line into words using strtok.


    return 0;
}
