/* In Class exercise packing bits */
#include <stdio.h>
#include <limits.h>

unsigned int pack(unsigned char, unsigned char, unsigned char, unsigned char);
void unpackWithShift(unsigned int val);
void unpackWithMask(unsigned int val);

unsigned int isBitISet(unsigned int ch, int i)
{
    unsigned int mask = 1U << i;
    return mask & ch;
}

void visualize(unsigned int x)
{
    int i;
    for(;;) { /* modify this!! */
        if(1) /* modify this!! */
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

int main(void)
{
    unsigned char red = 255;   // 1111 1111
    unsigned char green = 135; // 1000 0111
    unsigned char blue = 111;  // 0110 1111
    unsigned char alpha = 100; // 0110 0100

    unsigned int result = 0;// 1111 1111 | 1000 0111 | 0110 1111 | 0110 0100
    result=pack(red, green, blue, alpha);
    unpackWithShift(result);
    unpackWithMask(result);

    return 0;
}

unsigned int pack(unsigned char red,
                  unsigned char green,
                  unsigned char blue,
                  unsigned char alpha)
{
    printf("Pack red=%u, green=%u, blue=%u, alpha=%u\n",red,green,blue,alpha);
    unsigned int result = UINT_MAX;
    printf("result %u\n",result);
    visualize(result);

    /* result = result<<24;  */

    // pack it here

    return result;
}

void unpackWithShift(unsigned int val)
{
    printf("Unpacking bits by shifting\n");







}

void unpackWithMask(unsigned int val)
{
    printf("Unpacking bits by masking\n");








}

