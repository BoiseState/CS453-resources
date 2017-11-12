#!/bin/bash

prog=$(basename $0)
case $# in
0|1) echo 'Usage:' $prog '<original dir> <backup dir>'; exit 1;;
esac

orig=$1
backup=$2

for d in $orig $backup
do
    find "$d" -mmin +15 ! -type d -print  > "$d".list
    tar -cpf - -X "$d".list  "$d" | (cd backup; tar xf -)
    /bin/rm -f $d.list
done
