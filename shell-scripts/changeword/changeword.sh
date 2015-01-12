#!/bin/sh
# sed/changeword

prog=`basename $0`
case $# in
0|1) echo 'Usage:' $prog '<old string> <new string>'; exit 1;;
esac

old=$1
new=$2
for f in *
do
        if [ "$f" != "$prog" ]
        then
            if [ -f "$f" ]
            then
                sed "s/$old/$new/g" $f > $f.new
                mv $f $f.orig
                mv $f.new $f
                echo $f done
            fi
        fi
done


# a simpler version

#for f in *
#do
#        if [ "$f" != "$prog" ]; then
#            if [ -f "$f" ]; then
#                sed -i.orig "s/$old/$new/g" $f 
#                echo $f done
#            fi
#        fi
#done
