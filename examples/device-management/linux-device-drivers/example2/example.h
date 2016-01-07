

#ifndef __EXAMPLE_H
#define __EXAMPLE_H
/*
 * example.h -- definitions for the char module
 *
 */

#ifndef EXAMPLE_MAJOR
#define EXAMPLE_MAJOR 0   /* dynamic major by default */
#endif

#ifndef EXAMPLE_NR_DEVS
#define EXAMPLE_NR_DEVS 4    /* example0 through example3 */
#endif
/*
 * Split minors in two parts
 */
#define TYPE(dev)   (MINOR(dev) >> 4)  /* high nibble */
#define NUM(dev)    (MINOR(dev) & 0xf) /* low  nibble */

/*
 * The different configurable parameters
 */

struct Example_Device {
	int minor;
	char *data;
}; 

#endif /* __EXAMPLE_H */
