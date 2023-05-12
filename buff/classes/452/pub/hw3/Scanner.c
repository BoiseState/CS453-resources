#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Scanner.h"
#include "error.h"

typedef struct {
  int eos;
  char *str;
  char *pos;
  char *curr;
} *ScannerRep;

extern Scanner newScanner(char *s) {
  ScannerRep r=(ScannerRep)malloc(sizeof(*r));
  if (!r)
    ERROR("malloc() failed");
  r->eos=0;
  r->str=strdup(s);
  r->pos=r->str;
  r->curr=0;
  return r;
}

extern void freeScanner(Scanner scan) {
  ScannerRep r=scan;
  free(r->str);
  if (r->curr)
    free(r->curr);
  free(r);
}

static char *thru(char *p, char *q) {
  for (; *p && strchr(q,*p); p++);
  return p;
}

static char *upto(char *p, char *q) {
  for (; *p && !strchr(q,*p); p++);
  return p;
}

static char *wsthru(char *p) { return thru(p," \t"); }
static char *wsupto(char *p) { return upto(p," \t"); }

extern char *nextScanner(Scanner scan) {
  ScannerRep r=scan;
  if (r->eos)
    return 0;
  char *old=wsthru(r->pos);
  char *new=wsupto(old);
  int size=new-old;
  if (size==0) {
    r->eos=1;
    return 0;
  }
  if (r->curr)
    free(r->curr);
  r->curr=(char *)malloc(size+1);
  if (!r->curr)
    ERROR("malloc() failed");
  memmove(r->curr,old,size);
  (r->curr)[size]=0;
  r->pos=new;
  return r->curr;
}

extern char *currScanner(Scanner scan) {
  ScannerRep r=scan;
  if (r->eos)
    return 0;
  if (r->curr)
    return r->curr;
  return nextScanner(scan);
}

extern int cmpScanner(Scanner scan, char *s) {
  ScannerRep r=scan;
  currScanner(scan);
  if (r->eos)
    return 0;
  if (strcmp(s,r->curr))
    return 0;
  return 1;
}

extern int eatScanner(Scanner scan, char *s) {
  int r=cmpScanner(scan,s);
  if (r)
    nextScanner(scan);
  return r;
}

extern int posScanner(Scanner scan) {
  ScannerRep r=scan;
  return (r->pos)-(r->str);
}
