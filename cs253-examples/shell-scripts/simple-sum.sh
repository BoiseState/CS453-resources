#!/bin/sh

sum=0
for x in 1 2 3 4 5
do
    sum=$[sum + $x]
done
echo "sum = " $sum
