
/* C-examples/strings/strings-ex2.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 1024;

int main()
{
    char *token;
    char *save;
    char *s;
    /*char *delimiter = " ;!,\"[]{}`\t\n";*/
    char *delimiter = " ;";

    s = (char *) malloc(sizeof(char) * MAX_LENGTH);
    strcpy(s, " tigger pooh abracadabra woo ;; woo & choo choo");

    /* save a copy because strtok will eat it up */
    save = (char *) malloc(sizeof(char)*(strlen(s)+1));
    strcpy(save, s);

    printf("starting to tokenize the string: %s\n", s);
    /* tokenize the string q */
    token = strtok(s, delimiter);
    while (token != NULL) {
        printf("next token = %s\n", token);
        token = strtok(NULL,  delimiter);
    }

    s = save; /* restore s */
    return 0;
}
