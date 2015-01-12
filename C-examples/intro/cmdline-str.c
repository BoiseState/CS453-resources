#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printUsage(char[]);

int main(int argc, char *argv[])
{
    if(argc < 5)
    {
        printUsage(argv[0]);
    }

    // Parse int argument
    unsigned int x = 0;
    if(strcmp(argv[1],"-i") == 0)
    {
        x = (unsigned int) atoi(argv[2]);
        if (x > 100 || x < 0)
        {
            printf("error: integer must be between 0 and 100");
            printUsage(argv[0]);
        }	
    }
    else
    {
       printf("error: -i expected\n");
       printUsage(argv[0]);
    }

    // Parse string argument
    char *string; // This is like a String Object reference in Java
    if(strcmp(argv[3], "-s") == 0)
    {
   		string = argv[4];
    }	
    else
    {
        printf("error: -s expected\n");
        printUsage(argv[0]);
    }    

    printf("Your integer: %d\n", x);
    printf("Your string: %s (%d chars)\n", string, (int) strlen(string));
    
    int i;
    int len = (int) strlen(string);
    for(i = 0; i < len; i++)
    {
        printf("%d: %c\n", i, string[i]);
    } 

	return 0;
}

void printUsage(char prog[])
{
    printf("Usage: %s -i <int between 0-100> -s <string>\n", prog);
    exit(1);
}
