#!/bin/sh

for poolsize in 10 100 1000
do
	for sleeptime in 0  1 10
	do
		for items in 10 100 1000
		do
			for p in  1 2 3 4 5 6 7 8 9 10 
			do
				for c in 1 2 3 4 5 6 7 8 9 10
				do
					pc $poolsize $items $p $c $sleeptime  > /dev/null
				done
			done
		done
	done
done
