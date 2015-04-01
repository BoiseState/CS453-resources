/**
 * WordObj.h
 *
 */
#ifndef WORDOBJ_H_
#define WORDOBJ_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_FREQ_DIGITS 20

typedef struct word WordObj;
typedef struct word *WordObjPtr;

struct word
{
	char *word;
	unsigned long int frequency;
};

WordObjPtr createWordObj(const char *word, const unsigned long int frequency);
char *toString(const void * obj);
void freeWordObj(void * obj);
int equals(const void * obj1, const void * obj2);

#endif /* WORDOBJ_H_ */
