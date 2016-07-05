#!/bin/sh

case $# in
0) echo 'Usage: ' `basename $0` ' <log file>'; exit 1;;
esac

logfile=$1
echo > $logfile
while true
do
	fork-hello-world >> $logfile
	usleep 100
	echo >> $logfile
done
