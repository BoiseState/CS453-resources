// ldxrb DEST,[SRC]
//   DEST <- *SRC;
//   set exclusive status for *SRC

// stxrb STATUS,SRC,[DEST]
//   STATUS <- exclusive status for *DEST ? 0 : 1
//   IF STATUS == 0 THEN
//     *DEST <- SRC;
//     unset exclusive status for *DEST;
//   FI;

extern int atomic_lock(int *lck) {
  int val=1;
  asm volatile("   ldxrb w0,[%1]    \n\t"
               "   cbnz  w0,1f      \n\t"
               "   mov   w0,1       \n\t"
               "   stxrb w2,w0,[%1] \n\t"
               "   mov   %0,w2      \n\t"
               "1: nop              \n\t"
               : "+r"(val) // %0 r=register
               : "r"(lck)  // %1 r=register
               : "cc");    // flags
  return val;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int  atomic_test(int *lck)   { return *lck; }
