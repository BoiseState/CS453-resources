#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
	int i, c;
	while((s[0] = c = getch()) == ' ' || c == '\t') {
		/* do nothing, just skipping whitespace */
	}

	s[1] = '\0';
	if(!isdigit(c) && c != '.') {
		return c; /* not a number */
	}

	i = 0;
	if(isdigit(c)) { /* collect integer part */
		while(isdigit(s[++i] = c = getch())) {
			/* do nothing, just keep getting numbers */
		}
	}
	if(c == '.') { /* collect fractional part */
		while(isdigit(s[++i] = c = getch())) {
			/* do nothing, just keep getting numbers */
		}
	}

	s[i] = '\0';
	if(c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}
