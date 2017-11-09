
/* C-examples/strings/strings-ex3.c
 *
 * This example shows the proper way to tokenize a string when the tokens
 * need to be passed to other parts of the program. Study this program
 * and then attempt to refactor the parsing code into a separate function
 * with the prototype shown below and then modify main to use this function
   
   char **parseInput(char *s, char *delimiter, int *numTokens);

 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 1024;
const int MAX_TOKENS = 100;

int main(int argc, char **argv)
{
    char *nextToken;
    char *save;
    char *s;
    char **token;
    int numTokens;
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

    token = (char **) malloc (sizeof(char *) * MAX_TOKENS);
    printf("\nUsing strtok: starting to tokenize the string: %s \n", s);
    nextToken = strtok(s, delimiter);
    numTokens=0;
    while (nextToken != NULL) {
        printf("next token = %s\n", nextToken);
        token[numTokens] = (char *) malloc(sizeof(char) * (strlen(nextToken)+1));
        strcpy(token[numTokens], nextToken);
        numTokens++;
        nextToken = strtok(NULL, delimiter);
    }
    // Now the tokens are copied into token[0..numTokens-1];

    strcpy(s, save); /* restore s */
    return 0;
}
