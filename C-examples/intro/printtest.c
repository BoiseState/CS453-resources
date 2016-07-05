#include <stdio.h>



int main(void)
{
    float pi = 113.14159f;
    printf("Testing the formatting of printf\n");
    printf("Original question from quiz\n");
    printf("Value of pi is : %d, %f, %1.2f, %1.4f\n", (int) pi, pi, pi, pi);
    printf("The test !!!\n");
    printf("Value of pi is : %d, %f, %.2f, %.4f\n", (int) pi, pi, pi, pi);


    return 0;

}
