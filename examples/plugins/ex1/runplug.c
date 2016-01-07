/* Author: Dan Crow (modified by Amit Jain)
 * File:     runplug.c
 * Others:   plugin1.c plugin2.c
 * Purpose: Tries to open a plug-in.  It will ask for the name of a
 * plug-in, in which user should simply have to type the name.  This
 * program should then look in the current directory to find the plug-in.
 * Compile: Use make
 *
 * Note: This program is Linux specific and not ANSI C.
 */

#define MAX_BUF 1024

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* dll include file */
#include <dlfcn.h>

/* dll variables */
void *handle;           /* handle of shared library */
void (*function)(void); /* pointer to the plug-in function */
const char *dlError;    /* error string */

int main(int argc, char **argv)
{
  char buf[MAX_BUF];
  char plugName[MAX_BUF];

  while (1)
  {
    /* get plug-in name */
    printf("Enter plugin name (exit to exit): ");
    fgets(buf, MAX_BUF, stdin);
    buf[strlen(buf)-1] = '\0';       /* change \n to \0 */
    sprintf(plugName, "./%s", buf);  /* start from current dir */

    /* checks for exit */
    if (!strcmp(plugName, "./exit"))
      return 0;

    /* open a library */
    handle = dlopen(plugName, RTLD_LAZY);
    if ((dlError = dlerror()))
    {
      printf("Opening Error: %s\n", dlError);
      continue;
    }

    /* loads the plugin function */
    function = dlsym( handle, "plugin");
    if ((dlError = dlerror()))
      printf("Loading Error: %s\n", dlError);

    /* execute the function */
    (*function)(); /* function() */
    if ((dlError = dlerror()))
      printf("Execution Error: %s\n", dlError);

	sleep(20);
	/* run the plugin again */
    (*function)();
    if ((dlError = dlerror()))
      printf("Execution Error: %s\n", dlError);

    /* close library 1 */
    dlclose(handle);
    if ((dlError = dlerror()))
      printf("Closing Error: %s\n", dlError);
  }

  return 0;
}
