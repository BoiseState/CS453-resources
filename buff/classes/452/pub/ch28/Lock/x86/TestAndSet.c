// bts BitOffset,BitBase
//   CF <- Bit(*BitBase, BitOffset);
//   Bit(*BitBase, BitOffset) <-1;

// setcc DEST
//   IF condition        // setc or setb for CF
//      THEN *DEST <- 1;
//      ELSE *DEST <- 0;
//   FI;

extern int atomic_lock(int *lck) {
  unsigned char old;
  asm volatile("lock;"
               "btsw $0,%[lck];"
               "setc %[old];"
               : // OutputOperands
                 [old]"=b"(old), // b=byte
                 [lck]"+m"(*lck) // m=memory
               : // InputOperands
               : // Clobbers
                 "cc");          // flags
  return old;
}

extern void atomic_unlock(int *lck) { *lck=0; }
extern int  atomic_test(int *lck)   { return *lck; }
