#include <stdio.h> // for printf
#include <stdlib.h> //for EXIT_SUCCESS
#include <string.h> //strcpy

/*
 * Simple function to reverse a string using indexes
 */
void reverse(char foo[])
{
    int f = 0;
    int b = strlen(foo)-1;
    char tmp = ' ';
    while(f < b) {
        tmp = foo[f];
        foo[f] = foo[b];
        foo[b] = tmp;
        f++;
        b--;
    }
}

int main(int argc, char *argv[])
{
    if(argc !=2) {
        printf("usage: %s <string>\n",argv[0]);
        exit(EXIT_SUCCESS);
    }
    int len = strlen(argv[1]) +1;
    char tmp[len];
    strcpy(tmp,argv[1]);
    reverse(tmp);
    printf("%s\n",tmp);
    return (EXIT_SUCCESS);
}


