
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


int prime(long long x)
{
    long long i;
    long long sqrtx = ceil(sqrt(x));

    for (i = 2; i < sqrtx; i++) {
        if (x % i == 0)
            return FALSE;
    }
    return TRUE;
}


int main(int argc, char **argv)
{

    long long n;
    long long sqrtn;
    long long i;


    if (argc != 2) {
        fprintf(stderr, "Usage: %s <n>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    n = atoll(argv[1]);
    sqrtn = ceil(sqrt(n));

    printf("sqrtn = %lld\n", sqrtn);

    printf("\n prime factors of %lld = ", n);
    for (i = 2; i < sqrtn; i++) {
        if (prime(i)) {
            while (n % i == 0)  {
                printf(" %lld ", i);
                n = n/i;
            }
            if (n == 1) break;
        }
    }
    if (n > 1)
        printf(" %lld ", n);
    printf("\n");

    exit(EXIT_SUCCESS);

}

