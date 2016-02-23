#!/bin/bash

printf "Select your favorite animal:\n"
select term in \
    'Dolphin' \
    'Panda' \
    'Tiger' \
    'Bronco'
do
    case $REPLY in        #REPLY is built in variable
        1 ) NAME="Flipper the Dolphin";;
        2 ) NAME="Happy Panda";;
        3 ) NAME="Tony the Tiger";;
        4 ) NAME="Buster Bronco";;
        * ) printf "invalid." ;;
    esac
    if [[ -n $term ]]; then
        printf "$NAME is your favorite animal!\n"
        break
    fi
done
