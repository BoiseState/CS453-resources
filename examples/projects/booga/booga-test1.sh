#!/bin/bash

./booga_load

./test-booga 0 0 r
./test-booga 0 1 r
./test-booga 0 2 r
./test-booga 0 10 r
./test-booga 0 10 r 
./test-booga 0 100 r
./test-booga 0 1000 r
./test-booga 0 10000 r
./test-booga 0 100000 r
./test-booga 0 200000 r

./test-booga 0 1000 w
./test-booga 1 1000 w
./test-booga 2 1000 w
./test-booga 3 1000 w

./test-booga 0 0 r | wc -m
./test-booga 0 1 r | wc -m
./test-booga 0 2 r | wc -m
./test-booga 0 10 r | wc -m
./test-booga 0 10 r  | wc -m
./test-booga 0 100 r | wc -m
./test-booga 0 1000 r | wc -m
./test-booga 0 10000 r | wc -m
./test-booga 0 100000 r | wc -m
./test-booga 0 200000 r | wc -m


./booga_unload
