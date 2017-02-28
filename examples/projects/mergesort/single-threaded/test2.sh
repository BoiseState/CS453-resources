#!/bin/sh
# Time mergesort for different values of n 

for i in  100000 200000 400000 500000 5000000 10000000 20000000 30000000
do
	mergesort $i 1
done
