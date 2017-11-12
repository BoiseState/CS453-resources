#include "point.h"

struct point createPoint(const int x, const int y)
{
	struct point pt;
	pt.x = x;
	pt.y = y;
	return pt;
}

void translate(struct point *pt, const int xAmt, const int yAmt)
{
	pt->x += xAmt;
	pt->y += yAmt;
}
