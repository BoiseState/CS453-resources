
#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include <stdlib.h>
#include <List.h>
#include "HashObject.h"

typedef struct hashtable HashTable;
typedef struct hashtable * HashTablePtr;

struct hashtable {
	int size;
	unsigned int M;
	unsigned int (*h)(unsigned int M, unsigned int key);
	unsigned int (*getKey) (void * obj);
	ListPtr *table;
	void (*freeHashTable)(HashTablePtr table);
	void (*insert)(HashTablePtr table, HashObject *obj);
	HashObjectPtr (*remove)(HashTablePtr table, unsigned int key);
	HashObjectPtr (*search)(HashTablePtr table, unsigned int key);
};

HashTablePtr createhashTable(unsigned int M, 
						 unsigned int (*h)(unsigned int, unsigned int),
						 unsigned int (* getKey)(void * obj));

#endif /* __HASHTABLE_H */
