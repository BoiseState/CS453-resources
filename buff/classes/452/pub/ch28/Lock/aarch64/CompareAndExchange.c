#error "untested: need armv8.1"

// ldaddal DST,SRCR,SRCM
//   DST <- [SRCM];
//   [SRCM] <- DST + SRCR;

extern int atomic_lock(int *lck) {
  int old=1;
  const int one=1;
  asm volatile("   cas;"
               "1: dmb   sy;"
               : // OutputOperands
                 [old]"=m"(old) // m=memory
               : // InputOperands
                 [lck]"r"(lck), // r=register
                 [one]"r"(one)  // r=register
               : // Clobbers
               : "cc");    // flags
  return old;
}

extern void atomic_unlock(int *lck) {
  asm volatile("dmb sy;"
               "str wzr,[%[lck]];"
               : // OutputOperands
               : // InputOperands
                 [lck]"r"(lck)  // r=register
               : // Clobbers
	       );
}

extern int atomic_test(int *lck) { return *lck; }
