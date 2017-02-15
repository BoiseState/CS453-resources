#!/bin/sh

case $# in
0) echo 'Usage: '`basename $0`' <textfile> [<k> <most|least>] '; exit 1 ;;

1) cat $1 | tr -cs "A-Za-z'" "[\012*]" | tr A-Z a-z | sed "/^'$/d" | sort | uniq -c | sort -rn | wc -l
   exit 0;;

2) echo 'Usage: wordfreq <textfile> [<k> <most|least>] '; exit 1 ;;

3)
	if test $3 = "most"
	then
		cat $1 | tr -cs "A-Za-z'" "[\012*]" | tr A-Z a-z |  sed "/^'$/d" | sort | uniq -c | sort -rn | sed ${2}q
	else
		cat $1 | tr -cs "A-Za-z'" "[\012*]" | tr A-Z a-z | sed "/^'$/d" | sort | uniq -c | sort -n | sed ${2}q
	fi
esac
