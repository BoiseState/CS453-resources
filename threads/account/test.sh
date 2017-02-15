#!/bin/sh

for i in 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 20 24 28 32
do
	echo "Testing with " $i "threads and 10000 operations per thread."
	for count in 1 2 3 4 5 6 7 8 9 10
	do
		echo "---- Test $count ----"
		TestAccount $i 10000 
		echo
	done
	echo
done
