#!/bin/sh

for queues in 5 10
do
	for poolsize in 10 100 300
	do
		for sleeptime in 1 10
		do
			for items in 2000
			do
				for p in  5 10 
				do
					for c in 5 10
					do
						pc-mq $queues $poolsize $items $p $c $sleeptime  > /dev/null
					done
				done
			done
		done
	done
done
