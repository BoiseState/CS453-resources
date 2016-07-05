

#include <stdio.h>
#include <stdlib.h>

void foo(const int *x)
{
    int *tmp = x;
    *tmp = 5;
    /* try *x = 5 */
}

int main()
{

    int *x = malloc(sizeof(int));
    foo(x);
    printf("%d\n", *x);

    return 0;
}
