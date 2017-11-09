
/* C-examples/strings/strings-ex4.c
 *
 * This example shows the proper way to tokenize a string when the tokens
 * need to be passed to other parts of the program. It separates the
 * parsing code into a function that can be reused in other programs
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 1024;
const int MAX_TOKENS = 100;

char **parseInput(char *s, char *delimiter, int *numTokens);

int main(int argc, char **argv)
{
    char *save;
    char *s;
    char **token;
    int numTokens = 0;
    int i;
    /*char *delimiter = " ;!,\"[]{}`\t\n";*/
    char *delimiter = " ;";

    s = (char *) malloc(sizeof(char) * MAX_LENGTH);
    strcpy(s, " tigger pooh abracadabra woo ;; woo & choo choo");
    // (strcpy is okay here because we know that our src string is less than
    // MAX_LENGTH. However, if we didn't know the length of our src string
    // ahead of time, we would want to use strncpy.)

    /* save a copy because strtok will eat it up */
    save = (char *) malloc(sizeof(char)*(strlen(s)+1));
    strcpy(save, s);

    token = parseInput(s, delimiter, &numTokens);

    printf("%s: Found %d tokens\n", argv[0], numTokens);
    for (i = 0; i < numTokens; i++)
        printf("token[%d] = %s\n", i, token[i]);

    strcpy(s, save); /* restore s */
    return 0;
}



char **parseInput(char *s, char *delimiter, int *numTokens) 
{
    char *nextToken;
    char **token = (char **) malloc (sizeof(char *) * MAX_TOKENS);

    /* tokenize the string s */
    nextToken = strtok(s, delimiter);
    *numTokens = 0;
    while (nextToken != NULL) {
        token[*numTokens] = (char *) malloc(sizeof(char) * (strlen(nextToken)+1));
        strcpy(token[*numTokens], nextToken);
        (*numTokens)++;
        nextToken = strtok(NULL, delimiter);
    }
    /*Now the tokens are copied into token[0..numTokens-1];*/
    return token;
}
