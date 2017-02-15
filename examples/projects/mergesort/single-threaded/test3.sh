#!/bin/sh

#use cutoff equal to n to force use of insertion sort

for i in  100000 200000 400000 500000 1000000 
do
	mergesort $i $i
done
