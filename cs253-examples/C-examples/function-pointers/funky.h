#ifndef __FUNKY_H
#define __FUNKY_H

/**
 * Squares the given integer and returns the result (e.g. x^2).
 * @param x The value to square.
 * @return The result.
 */
int square(int x);

/**
 * Cubes the given integer and returns the result (e.g. x^3).
 * @param x The value to square.
 * @return The result.
 */
int cube(int x);


/**
 * Prints the given string x times (all on one line).
 * @param x The number of times to print.
 * @param string The string to print.
 */
void repeat(int x, char *string);

/**
 * Prints the given string x times (each on a separate line).
 * @param x The number of times to print.
 * @param string The string to print.
 */
void repeatln(int x, char *string);

#endif /* __FUNKY_H */
