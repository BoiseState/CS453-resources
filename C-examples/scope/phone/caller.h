/* NOTE: We are missing something here. Notice what happens when I 
 * complile using gcc -E caller1.c */

#include "phone.h"

/* What if I want to use a variable (total_calls) to keeps track of the number
 * of calls this caller has made? */

/**
 * @brief Prints who this caller is. 
 */
void whoami(void);


/**
 * @brief Calls the phone n times. 
 *
 * @param n
 */
void make_calls(const int n);
