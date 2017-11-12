

/* C-examples/strings/strings-ex1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 256

/*char c = '\0';*/

int main()
{
    char *r = "winnie";
    char *s;
    char q[MAXLEN];
    int stat;

    s = (char *) malloc(sizeof(char) * MAXLEN);
    strcpy(s,"tigger"); /* initialize string s */
    strcpy(q, "pooh");

    printf("String r = %s length of r = %lu\n",r, strlen(r));

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
    exit(0);
}

