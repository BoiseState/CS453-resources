
#include <stdio.h>

/**
 * Remove runs of blanks with one blank in given input. See associated 
 * state diagram state-diagram.jpg for explanation of how this program works.
 *
 * gcc -Wall -o remove-blanks remove-blanks.c
 */
#define START 0
#define BLANK_RUN 1
#define NOT_IN_BLANK_RUN 2

int main(int argc, char *argv[])
{
    int c;  
	int state =  START;

    c = getchar();
    while (c != EOF ) {
		if (c == ' ') {
			if (state == BLANK_RUN) { 
				//skip printing
			} else { //state == NOT_IN_BLANK_RUN || state == START
				putchar(c);
				state = BLANK_RUN;
			}
		} else {  //(c != ' ')
			putchar(c);
			state = NOT_IN_BLANK_RUN;
		}

        c = getchar();
    }
    return 0;
}
