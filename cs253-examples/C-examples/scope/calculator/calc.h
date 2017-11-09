#ifndef __CALC_H
#define __CALC_H

#define NUMBER '0' /* signal that a number was found */

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);

#endif /* __CALC_H */
