#!/bin/bash
./UnitTestList
# Maybe we want to have all the results in a file?
# make sure and redirect stdout and stderr if you want both!
# testsuite/UnitTestList >> results.txt
./SimpleTestList
#Modify this Script to pass command line args to set RandomTestList
./RandomTestList 10 100
valgrind --leak-check=full ./RandomTestList 10 100
