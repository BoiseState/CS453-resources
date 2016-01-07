#!/bin/bash

./booga_load

echo
cat /proc/driver/booga
echo

./test-booga 0 100 r &
./test-booga 1 100 r &
./test-booga 2 100 r &
./test-booga 3 100 r &
./test-booga 3 100 w &
./test-booga 2 100 w &
./test-booga 1 100 w &
./test-booga 0 100 w &

wait

echo
cat /proc/driver/booga
echo

./booga_unload
