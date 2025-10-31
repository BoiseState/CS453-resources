// ldxrb DEST,*SRC
//   DEST <- *SRC;
//   set exclusive status for SRC

// stxrb STATUS,SRC,*DEST
//   STATUS <- exclusive status for DEST ? 0 : 1
//   IF STATUS == 0 THEN
//     *DEST <- SRC;
//     unset exclusive status for DEST;
//   FI;

// dmb sy
//   Data Memory Barrier
//   https://stackoverflow.com/questions/15491751/
//         real-life-use-cases-of-barriers-dsb-dmb-isb-in-arm
//     One simple example of a barrier requirement is a
//     spinlock. If you implement a spinlock using
//     compare-and-swap (or LDREX/STREX on ARM) and without a
//     barrier, the processor is allowed to speculatively load
//     values from memory and lazily store computed values to
//     memory, and neither of those are required to happen in the
//     order of the loads/stores in the instruction stream.
//     
//     The DMB in particular prevents memory access reordering
//     around the DMB. Without DMB, the processor could reorder a
//     store to memory protected by the spinlock after the spinlock
//     is released. Or the processor could read memory protected by
//     the spinlock before the spinlock was actually locked, or
//     while it was locked by a different context.

extern int atomic_lock(int *lck) {
  int old=1;
  const int one=1;
  asm volatile("1: ldxr w2,[%[lck]];"
               "   cbnz w2,1f;"              // if (*lck==0)
               "   stxr w2,%[one],[%[lck]];" //   *lck=1
               "   cbnz w2,1b;"              // if (exclusive)
               "   str  wzr,%[old];"         //   old=0
               "1: dmb  sy;"
               : // OutputOperands
                 [old]"=m"(old) // m=memory
               : // InputOperands
                 [lck]"r"(lck), // r=register
                 [one]"r"(one)  // r=register
               : // Clobbers
                 "cc");		// flags
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

extern int  atomic_test(int *lck)   { return *lck; }
