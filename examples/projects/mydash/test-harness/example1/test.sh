#!/bin/sh

case $# in
0) echo "Usage " `basename $0` " <program> [<verbose=true|false>]"; exit 1;;
esac

program=$1
debug=true
if test "$2" != ""
then
	debug=$2
fi
count=10

$program < inputs/test1.in > outputs/test1.out

if test "$debug" = "true"
then
	diff  outputs/test1.out outputs/test1.out.correct 
else
	diff  outputs/test1.out outputs/test1.out.correct > /dev/null 2>&1
fi

if test "$?" = "0"
then
	echo "test1 passed!"
else
	echo "test1 FAILED!"
fi


