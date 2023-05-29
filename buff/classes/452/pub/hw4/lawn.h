#ifndef LAWN_H
#define LAWN_H

typedef void *Lawn;

extern Lawn lawn_new(int lawnsize, int molesize);
extern void lawn_free(Lawn l);

#endif
