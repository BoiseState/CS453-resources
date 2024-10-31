// cmpxchg SRC,DEST
//   TEMP <- *DEST
//   IF accumulator = TEMP
//       THEN
//           ZF <- 1;
//           *DEST <- SRC;
//       ELSE
//           ZF <- 0;
//           accumulator <- TEMP;
//           *DEST <- TEMP;
//   FI;

extern int atomic_lock(int *lck) {
  unsigned char old;
  const int zero=0;
  const int one=1;
  asm volatile("lock;"
               "cmpxchg %[one],%[lck];"
               "setnz   %[old];"
               : // OutputOperands
                 [old]"=b"(old),  // b=byte
                 [lck]"+m"(*lck)  // m=memory
               : // InputOperands
                 [zero]"a"(zero), // a=register r0-r3
                 [one]"r"(one)    // r=register
               : // Clobbers
                 "cc");           // flags
  return old;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int  atomic_test(int *lck)   { return *lck; }
