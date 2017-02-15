#!/bin/bash

make

valgrind --leak-check=yes ./genbin 10 1234
valgrind --leak-check=yes ./gentxt 10 1234
valgrind --leak-check=yes ./readbin > read.bin 
valgrind --leak-check=yes ./readtxt 10 > read.txt 
valgrind --leak-check=yes ./readtxt 100

diff data.txt read.bin
diff data.txt read.txt
