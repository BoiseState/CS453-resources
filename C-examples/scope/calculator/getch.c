#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	if(bufp > 0) {
		return buf[--bufp];
	} else {
		return getchar();
	}
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE) {
		printf("ungetch: too many characaters\n");
	} else {
		buf[bufp++] = c;
	}
}
