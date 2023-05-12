// gcc -Wall -o blocks blocks.c && ./blocks

#include <stdio.h>

int main() {
  int a=1;                                      /* B1 */
  int b=1;                                      /* B1 */
  {
    int b=2;                           /* B2 */ /* B1 */
    {
      int a=3;               /* B3 */  /* B2 */ /* B1 */
      printf("%d %d\n",a,b); /* B3 */  /* B2 */ /* B1 */
    }
    {
      int b=4;               /* B4 */  /* B2 */ /* B1 */
      printf("%d %d\n",a,b); /* B4 */  /* B2 */ /* B1 */
    }
    printf("%d %d\n",a,b);             /* B2 */ /* B1 */
  }
  printf("%d %d\n",a,b);                        /* B1 */
  return 0;                                     /* B1 */
}
