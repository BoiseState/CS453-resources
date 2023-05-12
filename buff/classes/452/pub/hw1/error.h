#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

#define WARNLOC(file,line,kind,args...) do {  \
  fprintf(stderr,"%s:%d: ",file,line);        \
  fprintf(stderr,"%s: ",kind);                \
  fprintf(stderr,args);                       \
  fprintf(stderr,"\n");                       \
  fflush(stderr);                             \
} while (0)

#define ERRORLOC(file,line,kind,args...) do { \
  WARNLOC(file,line,kind,args);               \
  exit(1);                                    \
} while (0)

#define WARN(args...) WARNLOC(__FILE__,__LINE__,"warning",args)
#define ERROR(args...) ERRORLOC(__FILE__,__LINE__,"error",args)

#endif
