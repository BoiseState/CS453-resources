#!/bin/sh 

case $# in
0|1) echo "Usage: $( basename $0 ) <data-file> <prog>"; exit 1;;
esac

datafile=$1
prog=$2
outfile=junk

/bin/rm -f $outfile
/bin/rm -f $prog.log
for i in 1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536
do
	echo -n "buffer size = " $i  >> $prog.log
	(time $prog $i $datafile $outfile)  &>>  $prog.log
	echo >> $prog.log
	/bin/rm -f $outfile
done

