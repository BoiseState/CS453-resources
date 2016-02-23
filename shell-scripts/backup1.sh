#!/bin/sh
# recursive/backup1.sh

prog=$(basename $0)
case $# in
0|1) echo 'Usage:' $prog '<original dir> <backup dir>'; exit 1;;
esac

orig=$1
backup=$2
interval=900 #backup every 15 minutes

while true
do
    if test -d $backup
    then
        /bin/rm -fr $backup
    fi
    echo "Creating the directory copy at" $(date)
    /bin/cp -pr $orig $backup
    sleep $interval
done
