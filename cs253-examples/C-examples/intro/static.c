#include <stdio.h>

int keepItStatic(int x)
{
    static int y = 0;
    y = x + y;
    return y;
}

int main(int argc, char **argv)
{
    int i;
    for(i = 0; i < 5; i++) {
        int result = keepItStatic(i);
        printf("[%d] result: %d\n", i, result);
    }

    return 0;
}
