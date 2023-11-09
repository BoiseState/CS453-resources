// ldaddal DST,SRCR,SRCM
//   DST <- [SRCM];
//   [SRCM] <- DST + SRCR;

extern void atomic_unlock(int *lck) {
  asm volatile("   mov     w0,-1    \n\t"
               "   ldaddal w0,w0,%0 \n\t"
               : "+m"(*lck) // %0 m=memory
               :
               : "cc");     // flags
}
