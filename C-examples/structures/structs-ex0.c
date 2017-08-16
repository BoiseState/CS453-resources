/**
 * Example that illustrates use of a dynamically allocated structure
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 3;

    struct string {
        int len;
        char *str;
    } *p, *p2;

    p = (struct string *) malloc(sizeof(struct string) * n);
    p2 = p;

    int i, j;
    char c = 'a';
    for(i = 0; i < n; i++) {
        p[i].len = (i+1) * n; // length is offset by n so we can see effects of operators below
        p[i].str = (char *) malloc(sizeof(char) * p[i].len + 1);
        for(j = 0; j < p[i].len; j++) {
            p[i].str[j] = c++;
        }
        p[i].str[j + 1] = '\0';
    }

    for(i = 0; i < n; i++) {
        printf("[%d] len: %d, str:  %s\n", i, p[i].len, p[i].str);
    }

    printf("\np: %p, p->len: %d\n", p, p->len);
    int newlen = ++p->len;
    printf("(%s)\n\tp: %p, newlen: %d\n", "++p->len", p, newlen);

    newlen = (++p)->len;
    printf("(%s)\n\tp: %p, newlen: %d\n", "(++p)->len", p, newlen);

    newlen = (p++)->len;
    printf("(%s)\n\tp: %p, newlen: %d\n", "(p++)->len", p, newlen);

    newlen = p->len;
    printf("(%s)\n\tp: %p, newlen: %d\n", "p->len", p, newlen);


    printf("\np2: %p, p2->str: %p (%s)\n", p2, p2->str, p2->str);
    char newstr = *p2->str;
    printf("(%s)\n\tp2: %p, p2->str: %p (%s), newstr: %c\n", "*p2->str", p2,  p2->str, p2->str, newstr);

    newstr = *p2->str++;
    printf("(%s)\n\tp2: %p, p2->str: %p (%s), newstr: %c\n", "*p2->str++", p2, p2->str, p2->str, newstr);

    newstr = (*p2->str)++;
    printf("(%s)\n\tp2: %p, p2->str: %p (%s), newstr: %c\n", "(*p2->str)++", p2, p2->str, p2->str, newstr);

    newstr = *p2++->str;
    printf("(%s)\n\tp2: %p, p2->str: %p (%s), newstr: %c\n", "*p2++->str", p2, p2->str, p2->str, newstr);

    newstr = *p2->str;
    printf("(%s)\n\tp2: %p, p2->str: %p (%s), newstr: %c\n", "*p2->str", p2, p2->str, p2->str, newstr);


    return 0;
}
