#!/bin/bash

# The Y-Combinator: repetition without recursion or iteration.

fact() {
    if [ $2 -eq 0 ] ; then
	echo 1
    else
	echo $(($2*$($1 $1 $(($2-1)))))
    fi
}

Y() {
    $1 $1 $2
}

Y fact 5

