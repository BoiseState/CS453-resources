#!/bin/bash
# Test for race conditions

make test-example

echo
echo
cat /proc/driver/example
echo
echo

for i in  1 2 3 4 5 6 7 8 9 10
do
./test-example 0 10000000 r > /dev/null 2>&1 &
./test-example 0 10000000 r > /dev/null 2>&1 &
./test-example 0 10000000 r > /dev/null 2>&1 &
./test-example 0 10000000 r > /dev/null 2>&1 &
./test-example 0 64 w > /dev/null 2>&1 &
./test-example 0 64 w > /dev/null 2>&1 &
./test-example 0 64 w > /dev/null 2>&1 &
./test-example 0 64 w > /dev/null 2>&1 &
done

wait

echo
echo
cat /proc/driver/example
echo
echo
