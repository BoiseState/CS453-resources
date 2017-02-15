#include <stdio.h>
#include "point.h"

int main(int argc, char **argv)
{
	struct point p1 = {100, 200};
	struct point p2 = {150, 250};
	struct point p3 = p1;
	struct point p4 = createPoint(3, 4);

	p3.x = 200;

	printf("p1[%p]: (%d, %d)\n", &p1, p1.x, p1.y);
	printf("p2[%p]: (%d, %d)\n", &p2, p2.x, p2.y);
	printf("p3[%p]: (%d, %d)\n", &p3, p3.x, p3.y);
	printf("p4[%p]: (%d, %d)\n", &p4, p4.x, p4.y);

	printf("sizeof(p4) is %lu\n", sizeof(p4));

	translate(&p1, 500, -200);
	printf("p1[%p]: (%d, %d)\n", &p1, p1.x, p1.y);

	return 0;
}
