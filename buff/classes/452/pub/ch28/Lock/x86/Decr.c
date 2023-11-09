// dec DEST
//   DEST <- DEST - 1;

extern void atomic_unlock(int *lck) {
  asm volatile("   lock    \n\t"
               "   decw %0 \n\t"
               : "+m"(*lck) // %0 m=memory
               :
               : "cc");     // flags
}
