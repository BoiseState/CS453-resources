#!/bin/bash
#Setup our library path so the grader will run 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./lib
#Execute the grader under valgrind
valgrind --quiet --leak-check=full ./grader
