#ifndef FPP_H
#define FPP_H

#include <stdio.h>

/***************************************************************************
 * This module associates a pair of streams (read and write)               *
 * with a file descriptor.                                                 *
 ***************************************************************************/

typedef struct {
  FILE *r;
  FILE *w;
} FPP;

extern FPP *fpp_open(int fd);
extern void fpp_close(FPP *fpp);

#endif
