#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "fpp.h"
#include "error.h"

/***************************************************************************
 * This function opens read and write streams for a file                   *
 * descriptor, and returns the pair.                                       *
 ***************************************************************************/
extern FPP *fpp_open(int fd) {
  FPP *fpp=(FPP *)malloc(sizeof(*fpp));
  if (!fpp)
    ERROR("fpp_open(): malloc() failed: %s",strerror(errno));
  fpp->r=fdopen(fd,"r");
  fpp->w=fdopen(dup(fd),"w");
  if (!fpp->r)
    ERROR("fpp_open(): fdopen(\"r\") failed: %s",strerror(errno));
  if (!fpp->w)
    ERROR("fpp_open(): fdopen(\"w\") failed: %s",strerror(errno));
  return fpp;
}

/***************************************************************************
 * This function closes a pair of streams.                                 *
 ***************************************************************************/
extern void fpp_close(FPP *fpp) {
  if (fclose(fpp->r))
    ERROR("fpp_close(): fclose(\"r\") failed: %s",strerror(errno));
  if (fclose(fpp->w))
    ERROR("fpp_close(): fclose(\"w\") failed: %s",strerror(errno));
  free(fpp);
}
