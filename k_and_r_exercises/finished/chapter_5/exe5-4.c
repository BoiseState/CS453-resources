/**
* @author Aza Tulepbergenov
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char* s, char* t);

int main(int argc, char ** argv)
{
    int result = strend(argv[1], argv[2]);
    printf("String \"%s\" is in the end of string \"%s\": %s\n", argv[2], argv[1],result == 1 ? "TRUE":"FALSE");
    return 0;
}

/**
 * Returns 1 if the string t occurs at the end of the string s, and zero
 * otherwise.
 *
 */
int strend(char* s, char* t)
{

    int result = 0;
    char* endOfS = (char*) malloc(sizeof(char)*strlen(t));
    char* tempOfS = endOfS;
    char* tempOfT = t;
    int i = 0;

    while (*s != '\0') {
        *endOfS = *(s +(strlen(s) - strlen(t)) + i);
        endOfS++;
        s++;
        i ++;
    }
    endOfS = tempOfS;
    int boolCount = 0;
    while (*t != '\0') {
        if (*t == *endOfS)
            boolCount++;
        t++;
        endOfS++;
    }
    t = tempOfT;
    if (boolCount == strlen(t))
        result = 1;
    free(tempOfS);
    return result;
}
