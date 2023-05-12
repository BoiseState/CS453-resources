// cmpxchg SRC,DEST
//   TEMP <- DEST
//   IF accumulator = TEMP
//       THEN
//           ZF <- 1;
//           DEST <- SRC;
//       ELSE
//           ZF <- 0;
//           accumulator <- TEMP;
//           DEST <- TEMP;
//   FI;

extern int atomic_lock(int *lck) {
  unsigned char old;
  const int zero=0;
  const int one=1;
  asm volatile("lock          \n\t"
               "cmpxchg %4,%1 \n\t"
               "setnz   %0    \n\t"
               : "=b"(old), // %0 b=byte
                 "+m"(*lck) // %1 m=memory
               : "m"(*lck), // %2 m=memory
                 "a"(zero), // %3 a=register r0-r3
                 "r"(one)   // %4 r=register
               : "cc");     // flags
  return old;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int  atomic_test(int *lck)   { return *lck; }
