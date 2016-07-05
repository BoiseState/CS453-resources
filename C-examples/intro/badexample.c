

#include <stdio.h>
/*
   We are expecting 4 command line arguments:
   the first one a string, the next an integer, the next a float
   and the last one a double
*/

int main(int argc, char *argv[])
{
    int i;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <string> <int> <float> <double>\n", argv[0]);
        return 1;
    }

    for (i=0; i<argc; i++) {
        printf("argument %d = %s\n", argv[0]);
        printf("argument %d = %s\n", atoi(argv[1]));
        /*
           atof() converts to a double only
           strtod(...)/strtof(...) convert to double/float and
           do better error handling. strtof(...) was added in ANSI C'99
           while strtod(...) is there in ANSI C'89
        */
        printf("argument %d = %f\n", atof(argv[1]));
        printf("argument %d = %lf\n", atof(argv[1]));
    }
    return 0;
}
