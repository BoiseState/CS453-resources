// ldaddal DST,SRCR,SRCM
//   DST <- [SRCM];
//   [SRCM] <- DST + SRCR;

extern int atomic_lock(int *lck) {
  int val=0;
  asm volatile("   mov     w0,1       \n\t"
               "   ldaddal w0,w0,[%1] \n\t"
               "   cbz     w0,1f      \n\t" // w0=0 -> we locked it, return 0
               "   mov     w0,-1      \n\t" // w0>0  -> it was locked, dec & return 1
               "   ldaddal w0,w0,[%1] \n\t"
               "   mov     %0,1       \n\t"
               "1: nop                \n\t"
               : "+r"(val) // %0 r=register
               : "r"(lck)  // %1 r=register
               : "cc");    // flags
}

#include "Decr.c"

extern int atomic_test(int *lck) { return *lck; }
