// dec DEST
//   *DEST <- *DEST - 1;

extern void atomic_unlock(int *lck) {
  asm volatile("lock;"
               "decw %[lck];"
               : // OutputOperands
                 [lck]"+m"(*lck) // m=memory
               : // InputOperands
               : // Clobbers
                 "cc");          // flags
}
