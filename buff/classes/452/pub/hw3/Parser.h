#ifndef PARSER_H
#define PARSER_H

typedef void *Tree;

extern Tree parseTree(char *s);
extern void freeTree(Tree t);

#endif
