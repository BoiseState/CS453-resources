#ifndef SEQUENCE_H
#define SEQUENCE_H

typedef void *Sequence;

#include "Jobs.h"
#include "Pipeline.h"

extern Sequence newSequence();
extern void addSequence(Sequence sequence, Pipeline pipeline);
extern void freeSequence(Sequence sequence);
extern void execSequence(Sequence sequence, Jobs jobs, int *eof);

#endif
