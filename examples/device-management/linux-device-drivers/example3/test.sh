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
./test-example 0 64 r  >& /dev/null &
./test-example 0 64 w >& /dev/null &
./test-example 0 64 r >& /dev/null  &
./test-example 0 64 w >& /dev/null &
./test-example 0 64 r >& /dev/null  &
./test-example 0 64 w >& /dev/null &
./test-example 0 64 r  >& /dev/null &
./test-example 0 64 w >& /dev/null &
done

wait

echo
echo
cat /proc/driver/example
echo
echo
