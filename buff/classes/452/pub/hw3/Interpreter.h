#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Parser.h"
#include "Tree.h"
#include "Jobs.h"

extern void interpretSequence(T_sequence s, int *eof, Jobs jobs);

#endif
