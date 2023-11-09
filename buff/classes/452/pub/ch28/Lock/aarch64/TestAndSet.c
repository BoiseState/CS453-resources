// Under construction!

// tst DST,SRC
//   ZF <- [DST] && SRC;
//   [DST] <- [DST] & SRC;

extern int atomic_lock(int *lck) {
  int val=0;
  asm volatile("   tst %1,1 \n\t"
               "   beq 1f   \n\t"
               "   mov %0,1 \n\t"
               "1: nop      \n\t"
               : "+r"(val) // %0 r=register
               : "r"(lck)  // %1 r=register
               : "cc");    // flags
  return val;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int atomic_test(int *lck) { return *lck; }
