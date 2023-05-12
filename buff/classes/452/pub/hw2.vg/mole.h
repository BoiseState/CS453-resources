#ifndef MOLE_H
#define MOLE_H

#include "lawn.h"

typedef void *Mole;

extern Mole mole_new(Lawn l, int vimlo, int vimhi);
extern void mole_whack(Mole m);

#endif
