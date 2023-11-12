// ldaddal DST,SRCR,SRCM
//   DST <- [SRCM];
//   [SRCM] <- DST + SRCR;

extern void atomic_unlock(int *lck) {
  asm volatile("mov     w1,-1;"
               "ldaddal w2,w1,[%[lck]];"
               : // OutputOperands
               : // InputOperands
                 [lck]"r"(lck) // r=register
               : // Clobbers
                 "cc");         // flags
}
