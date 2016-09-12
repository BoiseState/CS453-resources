# Compiling and Linking (eventually, we will do this in a Makefile)

1. Try compiling everything in one shot.

     ```bash
     gcc -Wall caller1.c caller2.c phone.c
     ```

2. Compile executable from caller1.c.

     ```bash
     gcc -Wall caller1.c
     ```

     What's happening? Look at pre-processor result.

     ```bash
     gcc -Wall -E caller1.c
     ```

3. Need to use #ifndef in phone.h.

     ```c
     #ifndef __PHONE_H
     #define __PHONE_H

     /* contents */

     #endif /*__PHONE_H*/
	 ```

4. Now compile executable from caller1.c.

     ```bash
     gcc -Wall caller1.c
     ```

     What's the problem? (call not defined). Need to compile/link phone.c.

5. Try compiling executable from phone.c by itself. (No main method.)

     ```bash
     gcc -Wall phone.c
     ```

6. Compile, but don't try to link.

     ```bash
     gcc -Wall -c phone.c
     gcc -Wall -c caller1.c
     ```

7. Now link object files together into executable.

     ```bash
     gcc -Wall phone.o caller1.o -o caller1
     ```

8. Build executable for caller2. Just need to compile caller2.c.

     ```bash
     gcc -Wall -c caller2.c
     gcc -Wall phone.o caller2.o -o caller2
     ```

9. To clean up, get rid of executables and object files (.o)

     ```bash
     rm -f caller1 caller2 *.o
     ```
