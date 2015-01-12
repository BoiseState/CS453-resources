#!/bin/sh
# backup2.sh

prog=$(basename $0)
case $# in
0|1) echo 'Usage:' $prog '<original dir> <backup dir>'; exit 1;;
esac

orig=$1
backup=$2
if test -d $backup
then
    echo "Backup directory $backup already exists!"
    echo -n "Do you want to remove the backup directory $backup? (y/n)"
    read answer
    if test "$answer" = "y"
    then
        /bin/rm -fr $backup
    else
        exit 1
    fi
fi

mkdir  $backup
echo "Creating the directory tree"
find $orig -type d -exec mkdir $backup/"{}" \;

#make hard links to all regular files
echo "Creating links to the files"
find $orig -type f -exec ln {} $backup/"{}" \;

echo "done!"

