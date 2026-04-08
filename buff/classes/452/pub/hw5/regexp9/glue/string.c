extern int strlen(const char *s) {
  const char *t=s;
  while (*t)
    t++;
  return t-s;
}

extern char *strcpy(char *dest, const char *src) {
  char *d=dest;
  const char *s=src;
  while ((*d=*s)) {
    d++;
    s++;
  }
  return dest;
}

extern char *strcat(char *dest, const char *src) {
  char *d=dest;
  while (*d)
    d++;
  strcpy(d,src);
  return dest;
}

extern int strncmp(const char *s1, const char *s2, int n) {
  while (*s1 && *s2 && *s1==*s2 && --n>0) {
    s1++;
    s2++;
  }
  return *s1-*s2;
}

extern char *strchr(const char *s, int c) {
  while (*s && *s!=c)
    s++;
  return *s ? (char *)s : 0;
}

extern char *strrchr(const char *s, int c) {
  const char *t=s;
  while (*t)
    t++;
  while (t>=s && *t!=c)
    t--;
  return t>=s ? (char *)t : 0;
}

extern char *strstr(const char *haystack, const char *needle) {
  const char *s=haystack;
  int n=strlen(needle);
  while (*s && strncmp(s,needle,n))
    s++;
  return *s ? (char *)s : 0;
}

extern void *memset(void *s, int c, int n) {
  void *t=s;
  while (n>0) {
    *(char *)t++=c;
    n--;
  }
  return s;
}

extern void *memccpy(void *dest, const void *src, int c, int n) {
  char *d=dest;
  const char *s=src;
  while ((*d=*s)!=c && --n>0) {
    d++;
    s++;
  }
  return n==0 ? 0 : d+1;
}
