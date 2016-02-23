/*****************************************************************************
 * FILE: Exception.h
 * AUTHOR: Jordan Forrest
 * DESCRIPTION:
 * Inclusion of this file provides the capabillity of exception handling.
 * The exception handling uses the try/throw/catch interface.  Here is an
 * example of what a try block should look like:
 *
 *  Exception *e=NewException();
 *
 *  try(e)
 *  {
 *      printf("Throwing an exception...\n");
 *      throw("Error: BARF!");
 *      printf("Should never be here!");
 *  }
 *  catch
 *  {
 *      printf("Exception caught.\n");
 *      printStackTrace(e);
 *  }
 *
 */

#ifndef EXCEPTION_H
#define EXCEPTION_H

typedef struct Exception_tag {
    char *error;
} Exception;

extern Exception *NewException();
extern void PrintStackTrace(Exception *e);
extern void throw(char *errmsg);
extern void fatal(char *msg);

#endif /* EXCEPTION_H */
