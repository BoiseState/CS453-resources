#!/bin/sh

for queues in 2 5 10
do
	for poolsize in 10 100 1000
	do
		for sleeptime in 0 1 10
		do
			for items in 100 1000
			do
				for p in  1 2 5 10 
				do
					for c in 1 2 5 10
					do
						pc-mq $queues $poolsize $items $p $c $sleeptime  > /dev/null
					done
				done
			done
		done
	done
done
