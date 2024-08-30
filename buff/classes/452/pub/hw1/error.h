#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

// We want to be able to reference these macros like function calls:
//     if (...)
//         ERROR(...);
//     else
//         ...
// So, ERROR(...) should expand to a single C statement,
// that requires the reference to add the semicolon.
// If the expansion ended with a semicolon, or was {...},
// adding a semicolon would make *two* statements,
// which would interfere with the "else".

// Since these definitions each contain multiple fprintf() calls, the
// calls must be wrapped in a {...}, which must be wrapped in a
// different kind of statement, which *requires* an added semicolon.
// In C and C++, a "do" loop:
//    do {...} while (...)
// is the only such statement.
// To execute the body exactly once, its test must evaluate to false.

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
