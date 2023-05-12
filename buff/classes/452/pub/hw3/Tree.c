#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tree.h"
#include "error.h"

#define ALLOC(t) \
  t v=malloc(sizeof(*v)); \
  if (!v) ERROR("malloc() failed"); \
  return memset(v,0,sizeof(*v));

extern T_sequence new_sequence() {ALLOC(T_sequence)}
extern T_pipeline new_pipeline() {ALLOC(T_pipeline)}
extern T_command  new_command()  {ALLOC(T_command)}
extern T_words    new_words()    {ALLOC(T_words)}
extern T_word     new_word()     {ALLOC(T_word)}
