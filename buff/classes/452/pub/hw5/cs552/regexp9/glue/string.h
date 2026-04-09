extern int strlen(const char *s);
extern char *strcpy(char *dest, const char *src);
extern char *strcat(char *dest, const char *src);
extern int strncmp(const char *s1, const char *s2, int n);
extern char *strchr(const char *s, int c);
extern char *strrchr(const char *s, int c);
extern char *strstr(const char *haystack, const char *needle);
extern void *memset(void *s, int c, int n);
extern void *memccpy(void *dest, const void *src, int c, int n);
