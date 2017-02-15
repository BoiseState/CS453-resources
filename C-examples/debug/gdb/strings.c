
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

int main()
{
    char *r = "winnie";
    char *s;
    char q[MAXLEN];
    int stat;
    char *delimiter = " ;";
    char *token;
    char *save;
    char *copy;

    s = (char *) malloc(sizeof(char) * MAXLEN);
    strcat(s,"tigger"); /* initialize string s */
    strcat(q, "pooh");

    printf("String r = %s length of r = %ld\n",r, strlen(r));

    strcpy(q, r); // r is copied to q

    strcat(s, r);
    printf("r = %s s = %s q = %s \n",r, s, q);

    stat = strcmp(r,s);
    if (stat < 0)
        printf("r < s (lexicographically)\n");
    else if (stat == 0)
        printf("r == s (lexicographically)\n");
    else
        printf("r > s (lexicographically)\n");




    free(s);
    s = (char *) malloc(sizeof(char)*MAXLEN);
    strcpy(s, " tigger pooh abracadabra woo ;; woo & choo choo");

    /* save a copy because strtok will eat it up */
    save = (char *) malloc(sizeof(char)*(strlen(s)+1));
    strcpy(save, s);

    printf("starting to tokenize the string: %s \n", s);
    /* tokenize the string q */
    token = strtok(s, delimiter); /* use space as a delimiter */
    /* you should copy the token to a local space since right now token is
     * pointing to inside the string s, which is liable to change. This is
     * especially needed if you will pass the token around to other functions. */
    copy = (char *) malloc (sizeof(char)*(strlen(token)+1));
    strcpy(copy, token);
    while (token != NULL) {
        printf("next token = %s\n", token);
        token = strtok(NULL,  delimiter);
    }

    strcpy(s, save); /* restore s */
    printf("starting to tokenize the string: %s \n", s);
    /* tokenize the string s */
    token = strsep(&s, " ;"); /* use space as a delimiter */


    while (token != NULL) {
        printf("next token = %s\n", token);
        token = strsep(&s,  " ;");
    }
    exit(0);

}
