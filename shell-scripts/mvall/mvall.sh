#!/bin/bash

if [ $# -le 1 ]
then
	echo "Usage " $(basename $0) " <oldext> <newext>"
	exit 1
fi

#case $# in
#0|1)
#	echo "Usage " $(basename $0) " <oldext> <newext>"
#	exit 1
#esac

oldext=$1
newext=$2

for f in *.$oldext
do
  echo $f
  base=$(basename $f .$oldext)
  mv $f $base.$newext
done
