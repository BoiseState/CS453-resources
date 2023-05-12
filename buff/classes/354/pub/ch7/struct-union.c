  struct {
    char c;
    int i;
    double d;
  } s;

  union {
    char c;
    int i;
    double d;
  } u;

  printf("sizeof(s)=%d\n",sizeof(s));
  printf("sizeof(u)=%d\n",sizeof(u));
  return 0;
}
