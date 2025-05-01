#!/bin/bash

Open()  { exec {fd}<>/dev/tcp/localhost/$(<port) ; }
Close() { exec {fd}<&- ; }

Open
{
    # echo single
    echo thread
    # echo process

    echo echo Hello
    echo echo world!
    echo echo
    echo echo Hello world!
    echo quit
} >&$fd
cat <&$fd
Close
exit

Open
echo exit >&$fd
Close

