#!/bin/sh

for i in 1  10  20  30  40  50 60 70 80 90 100 200 300 500 1000
do
	echo -n "cutoff value: " $i " "
	mergesort 5000000 $i
done
