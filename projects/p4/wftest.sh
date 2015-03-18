#!/bin/bash

case $# in
0) echo "Usage: wftest.sh {std|self} <textfile>"; exit 1;;
1) echo "Usage: wftest.sh {std|self} <textfile>"; exit 1;;
esac

textfile=`basename $2`
inputdir=sample-input


if test "$1" = "std"
then
	# run std list test and compare output
else
	# run self-organizing list test and compare output
fi
