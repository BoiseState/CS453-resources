/**
* @author Aza Tulepbergenov
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000 /*assume max line is 1000*/

char* getlineWithPointers(char* s);
int atoiWithPointers(char* s);

int main(int argc, char ** argv)
{

    /*Testing getline()****************************/
    printf("*****Testing getline()*****\n");
    char* s = (char*) malloc(sizeof(char)*MAXLINE);
    s = getlineWithPointers(s);
    printf("I got this line: %s", s);
    free(s);
    /*********************************************/

    /*Testing atoi()******************************/
    printf("*****Testing atoi()*****\n");
    char* s1 = "352";
    int resulted = atoiWithPointers(s1);
    int expected = atoi(s1);
    printf("Expected = %d\n", expected);
    printf("Resulted = %d\n", resulted);

    s1 = "-500";
    resulted = atoiWithPointers(s1);
    expected = atoi(s1);
    printf("Expected = %d\n", expected);
    printf("Resulted = %d\n", resulted);
    /*********************************************/

    return 0;
}

/**
* Get line into s.
* Returns s.
* Note, it is reponsibility of a caller to this function to malloc and free
* memory.
*/
char* getlineWithPointers(char* s)
{
    int c, i;
    char* temp;
    temp = s;

    i = 0;
    while ((c=getchar()) != EOF && c!= '\n') {
        *s = c;
        s++;
    }
    if (c == '\n') {
        *s = c;
        s++;
    }
    *s = '\0';
    s = temp;
    return s;
}

/**
* Converts s to integer.
*/
int atoiWithPointers(char* s)
{

    int i, n, sign;
    char* temp = s;

    for (i = 0; isspace(*s); s++) /* skips white space */
        ;
    sign = (*s == '-') ? -1 : 1; //if *s == '-', then sign = -1, else sign = 1.
    if (*s == '+' || *s =='-') {
        s++;
    }
    for (n = 0; isdigit(*s); s++) {
        n = 10 * n + (*s - '0');
    }
    return sign*n;
}


