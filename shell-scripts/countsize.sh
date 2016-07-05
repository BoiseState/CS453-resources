#!/bin/sh

prog=$(basename $0)
case $# in
0|1) echo "Usage: $prog <folder> <size in K>"; exit 1;;
esac

folder=$1
limit=$2
limitinbytes=$[limit*1024]
count=0

cd $folder
for f in *
do
    if [ -f $f ]
    then
        size=$(ls -l $f| awk '{print $5}')
	if  [ $size -ge $limitinbytes ]
        then
            count=$[count+1]
            echo $f $size
        fi
    fi
done
echo $count "files bigger than " $limit"K" " found in folder $folder"
