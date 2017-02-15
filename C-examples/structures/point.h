#ifndef __POINT_H
#define POINT_H

/**
 * @brief Represents a point in a coordinate system.
 */
struct point {
	int x;
	int y;
};

/**
 * @brief Creates a point at the given x, y coordinates. 
 *
 * @param x
 * @param y
 *
 * @return The new point structure.
 */
struct point createPoint(const int x, const int y);


/**
 * @brief Translates a given point by the xAmt and yAmt
 *
 * @param pt The point to translate. 
 * @param xAmt The x amount.
 * @param yAmt The y amount.
 */
void translate(struct point *pt, const int xAmt, const int yAmt);

#endif /* __POINT_H */
