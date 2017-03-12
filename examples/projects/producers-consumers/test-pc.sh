#!/bin/sh

for poolsize in 10 100 1000
do
	for sleeptime in 0  1 10
	do
		for items in 10 100 1000
		do
			for p in  1 2 4 8 
			do
				for c in 1 2 4 8 
				do
					pc $poolsize $items $p $c $sleeptime  > /dev/null
				done
			done
		done
	done
done
