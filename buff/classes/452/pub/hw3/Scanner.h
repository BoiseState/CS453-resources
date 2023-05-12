#ifndef SCANNER_H
#define SCANNER_H

typedef void *Scanner;

extern Scanner newScanner(char *s);
extern void freeScanner(Scanner scan);

extern char *nextScanner(Scanner scan);
extern char *currScanner(Scanner scan);
extern int cmpScanner(Scanner scan, char *s);
extern int eatScanner(Scanner scan, char *s);
extern int posScanner(Scanner scan);

#endif
