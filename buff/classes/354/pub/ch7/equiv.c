// gcc -o equiv equiv.c && ./equiv

typedef struct { int a; } S1,S2;
typedef struct { int a; } S3;

typedef union { int a; } U1,U2;
typedef union { int a; } U3;

typedef enum {x1} E1;
typedef enum {x2} E2;

int main() {
  S1 s1; S2 s2; S3 s3;
  U1 u1; U2 u2; U3 u3;
  E1 e1; E2 e2;

  s1=s2;
  s1=s3;  /* error */
  u1=u2;
  u1=u3;  /* error */
  e1=e2;

  return 0;
}
