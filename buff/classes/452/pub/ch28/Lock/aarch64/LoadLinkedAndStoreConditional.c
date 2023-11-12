// ldxrb DEST,*SRC
//   DEST <- *SRC;
//   set exclusive status for SRC

// stxrb STATUS,SRC,*DEST
//   STATUS <- exclusive status for DEST ? 0 : 1
//   IF STATUS == 0 THEN
//     *DEST <- SRC;
//     unset exclusive status for DEST;
//   FI;

extern int atomic_lock(int *lck) {
  int val=1;
  asm volatile("   ldxrb w1,[%[lck]];"
               "   cbnz  w1,1f;"
               "   mov   w1,1;"
               "   stxrb w2,w1,[%[lck]];"
               "   mov   %w[val],w2;"
               "1: nop;"
               : // OutputOperands
                 [val]"=r"(val) // r=register
               : // InputOperands
                 [lck]"r"(lck)  // r=register
               : // Clobbers
                 "cc");		 // flags
  return val;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int  atomic_test(int *lck)   { return *lck; }
