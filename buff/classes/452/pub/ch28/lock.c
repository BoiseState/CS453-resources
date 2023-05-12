extern void lock(int *lck) {
  disableInterrupts();
  while (*lck) {
    enableInterrupts();
    disableInterrupts();
  }
  *lck=1;
  enableInterrupts();
}

extern void unlock(int *lck) {
  disableInterrupts();
  *lck=0;
  enableInterrupts();
}
