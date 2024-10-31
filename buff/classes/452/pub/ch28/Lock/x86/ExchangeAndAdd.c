// xadd SRC,DEST
//   TEMP <- SRC + *DEST;
//   SRC <- *DEST;
//   *DEST <- TEMP;

// dec DEST
//   *DEST <- *DEST - 1;

extern int atomic_lock(int *lck) {
  int val=1;
  asm volatile("   lock;"
               "   xadd %[val],%[lck];"
               "   or   %[val],%[val];"
               "   jz   1f;"            // %[val]==0 -> we locked it,  return 0
               "   lock;"               // %[val]>0  -> it was locked, dec & return 1
               "   decw %[lck];"
               "1: nop;"
               : // OutputOperands
                 [val]"+r"(val), // r=register
                 [lck]"+m"(*lck) // m=memory
               : // InputOperands
               : // Clobbers
                 "cc");         // flags
  return val;
}

extern void atomic_unlock(int *lck) {
  asm volatile("lock;"
               "decw %[lck];"
               : // OutputOperands
                 [lck]"+m"(*lck) // m=memory
               : // InputOperands
               : // Clobbers
                 "cc");          // flags
}

extern int atomic_test(int *lck) { return *lck; }
