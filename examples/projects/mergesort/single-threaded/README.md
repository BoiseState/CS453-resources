
#Introduction

This folder contains a serial implementation of mergesort.

#Manifest

Makefile         Build file.

mergesort.c      The source file that contains the mergesort and related functions.

mergesortTest.c  The driver that generates random data, runs and times mergesort.

timing.c         The timing functions.

test1.sh         Try different values of insertion sort threshold to find best 
                 value of threshold to switch to insertion sort.

test2.sh         Time mergesort for different values of n.


#Building and running

To build, use:

`make`

Run as follows:


`mergesort <input size> [<seed>]`
