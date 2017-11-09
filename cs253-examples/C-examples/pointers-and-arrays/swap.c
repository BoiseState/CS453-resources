#include <stdio.h>

void swap_wrong(int, int);
void swap(int *, int *);

/**
 * Demonstrates how to and how not to swap integer values in a function.
 *
 * @author marissa
 */
int main()
{
    int x = 3;
    int y = 5;
    printf("x: %d, y:%d\n", x, y);

    // BAD!
    swap_wrong(x, y);

    printf("\nAfter swap_wrong(x,y)\n");
    printf("x: %d, y:%d\n", x, y);

    // call method 1: pass in addresses directly.
    swap(&x, &y);

    printf("\nAfter swap(&x, &y)\n");
    printf("x: %d, y:%d\n", x, y);

    // call method 2: setup pointers before passing to function.
    int *px = &x;
    int *py = &y;
    swap(px, py);

    printf("\nAfter swap(px, py)\n");
    printf("x: %d, y:%d\n", x, y);

    return 0;
}
/*
 * This doesn't work! We are passing in a copy of the int variable, so
 * we are only updating the local copies.
 */
void swap_wrong(int x, int y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

/*
 * Pass-by-reference. This works because we are passing in a copy of the address
 * of the int variable (a pointer). So, when we dereference (e.g. *px), we are
 * updating the data stored at the given address, which exists outside of the
 * scope of this function. This means the values will remain changed when we
 * return from the function call.
 */
void swap(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
