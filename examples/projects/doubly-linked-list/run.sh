#!/bin/bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
testsuite/UnitTestList
# Maybe we want to have all the results in a file?
# make sure and redirect stdout and stderr if you want both!
# testsuite/UnitTestList >> results.txt
testsuite/SimpleTestList
#Modify this Script to pass command line args to set RandomTestList
testsuite/RandomTestList 10 100
valgrind --leak-check=full testsuite/RandomTestList 10 100
