#!/bin/bash
g++ -Wall -o monteCarlopi monteCarlopi.cpp

file_1="avgErrdata.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

i=2
while [[ i -le 10 ]]
do
echo "i = "$i "starts"
    for (( j=1; j<=50; j++ ))
	   do
		./monteCarlopi $((10**i)) >> avgErrdata.dat
	   done
echo "i = "$i "is done"
((i = i + 1))
done

python3 plot.py