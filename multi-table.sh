#!/bin/sh
if [ $# -ne 2 ]
then
	echo "Invalid input"
	exit 1
fi

if [ $1 -le 0 -o $2 -le 0 ]
then
	echo "Input must be greater than 0"
	exit 1
fi

t=0
for i in $(seq 1 "$1")
do
	for j in $(seq 1 "$2")
	do
		t=`expr $i \* $j`
		echo -n "$i*$j=$t\t"
	done
	echo ""
done
exit 0
