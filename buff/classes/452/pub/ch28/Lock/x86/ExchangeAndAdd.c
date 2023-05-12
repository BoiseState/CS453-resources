// xadd SRC,DEST
//   TEMP <- SRC + DEST;
//   SRC <- DEST;
//   DEST <- TEMP;

// dec DEST
//   DEST <- DEST – 1;

extern int atomic_lock(int *lck) {
  int val=1;
  asm volatile("   lock       \n\t"
               "   xadd %0,%1 \n\t"
               "   or   %0,%0 \n\t"
               "   jz   1f    \n\t" // %0==0 -> we locked it,  return 0
               "   lock       \n\t" // %0>0  -> it was locked, dec & return 1
               "   decb %1    \n\t"
               "1: nop        \n\t"
               : "+r"(val), // %0 r=register
                 "+m"(*lck) // %1 m=memory
               :
               : "cc");     // flags
  return val;
}

#include "Decr.c"

extern int atomic_test(int *lck) { return *lck; }
