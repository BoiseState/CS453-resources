#!/bin/sh
# Show number of context switches per unit time (specififed as cmdline argument)
# 

case $# in
0) echo 'Usage: wcs.sh <#milliseconds>'; exit 1;;
esac

microsecs=$[$1*1000]

#initial number of context switches
prev=`cat /proc/stat | grep ctxt | awk '{print $2}'`

while true
do
	usleep $microsecs
	num=`cat /proc/stat | grep ctxt | awk '{print $2}'`
	current=$[$num-$prev]
	prev=$num
	echo $current
done
