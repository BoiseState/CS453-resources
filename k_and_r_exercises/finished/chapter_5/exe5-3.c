#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strcatModif(char *s, char *t);

int main(int argc, char ** argv)
{

    if (argc != 3) {
        printf("Usage: ./foo -s1 -s2");
    }

    char * result;
    result = strcatModif(argv[1], argv[2]);
    printf("result is: %s\n", result);
    free(result);
    return 0;
}

char* strcatModif(char *s, char *t)
{

    char * temp = (char *) malloc(strlen(s) + strlen(t) + 1);

    char * tempOfTemp = temp;
    //char * temp = (char *) malloc(7);

    printf("temp points to %s before loop\n", temp);
    *(temp+((strlen(s) + strlen(t)))) = '\0';
    *temp = 1;

    int i;
    for (i = 0; i < 7; i ++) {
        printf("I point blah to %d\n", *temp);
        temp++;
    }


    while (*temp != '\0') { //WHY IT ASSUMES '/0'????
        printf("temp points to %s", temp);
        *temp = 0;

        temp++;
    }

    temp = tempOfTemp;
    //Copying s to temp
    while (*s != '\0') {
        *temp = *s;
        temp ++;
        s++;
    }
    //s++;

    while (*t != '\0') {
        *temp = *t; //copy t
        temp++;
        t++;
    }
    *temp = '\0';
    temp = tempOfTemp;
    printf("temp is %s\n", temp);
    return temp;
}
