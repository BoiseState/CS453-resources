#!/bin/sh

echo > data.$$ #$$ is process id, so we get a unique name
for ((i=1; i <= 100; i++))
do
	echo $i >> data.$$
done

sum=0
for x in $(cat data.$$)
do
	sum=$[sum+$x]
done
echo "sum = " $sum

/bin/rm -f data.$$
