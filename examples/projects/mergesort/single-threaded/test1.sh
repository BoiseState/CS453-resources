#!/bin/sh
# Try different values of insertion sort threshold to find best 
# value of threshold to switch to insertion sort

for i in 1  10  20  30  40  50 60 70 80 90 100 200 300 500 1000
do
	echo -n "insertion sort threshold value: " $i " "
	mergesort 5000000 $i
done
