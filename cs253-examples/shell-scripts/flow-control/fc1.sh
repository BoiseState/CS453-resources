#!/bin/bash
A="a"
B="b"
if [ "$A" \> "$B" ];then # > < must be escaped with \
    echo "$A > $B"
elif [ "$A" \< "$B" ]; then
    echo "$A < $B"
else
    echo "$A = $B"
fi
