// bts BitOffset,BitBase
//   CF <- Bit(BitBase, BitOffset);
//   Bit(BitBase, BitOffset) <-1;

// setcc DEST
//   IF condition        // setc or setb for CF
//      THEN DEST <- 1;
//      ELSE DEST <- 0;
//   FI;

extern int atomic_lock(int *lck) {
  unsigned char old;
  asm volatile("lock       \n\t"
               "btsw $0,%1 \n\t"
               "setc %0    \n\t"
               : "=b"(old), // %0 b=byte
                 "+m"(*lck) // %1 m=memory
               : "m"(*lck)  // %2 m=memory
               : "cc");     // flags
  return old;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int  atomic_test(int *lck)   { return *lck; }
