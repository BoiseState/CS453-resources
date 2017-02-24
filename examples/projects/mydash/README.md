
README for Sample Code {#mainpage}
----------------------

|Filename       | Description                                                       |
|---------------|-------------------------------------------------------------------|
|README.dox     |This file                                                          |
|doxygen-config |Sample config file for doxygen                                     |
|Makefile       |**Incomplete** build file for the mydash project (adapt to your needs) |
|TestCases      |An incomplete list of test cases                                   |
|valgrind.supp  |Example suppression file for valgrind for the readline library     |
|mydash-src/Makefile | Build file for mydash (adapt to your needs)                  |
|mydash-src/mydash.c | Starter version of mydash.c                                  |
|mydash-src/error.c | Error handling code used in class examples                    |
|mydash-src/mydash.h| Header file for the mydash project                            |
|other-progs/test-readline.c|Example file on how to use auto completion with readline library |
|other-progs/loop.c   |Simple infinite loop program for testing purposes            |
|other-progs/Makefile |Makefile to build other program examples                     |

Readline
--------

See example file other-progs/test-readline.c.

Valgrind
--------

Use valgrind as follows

valgrind --leak-check=yes --suppressions=valgrind.supp dash

You will need the suppression file valgrind.supp that suppresses errors from
the readline library so you can focus on issues emanating from your code.

Documentation
-------------

Generate documentation using doxygen tool. Use 

make dox

to trigger doxygen. Use the sample doxygen-config file for using with your
project. Note that, just like javadocs, you can use any HTML tags in your
comments. All javadoc tags and comments are supported by doxygen.

