#ifndef BUFFER_H
#define BUFFER_H

enum {max=5};			// maximum capacity of buffer

typedef int (*Busy)();
extern Busy full,empt;

extern int get();
extern void put(int data);

#endif
