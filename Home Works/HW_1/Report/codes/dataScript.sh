#!/bin/bash
#g++ monteCarlo.cpp -o monteCarlo
g++ -Wall -o monteCarlo monteCarlo.cpp
gcc -Wall -o trap trap.c 

file_1="data.dat"
file_2="trapData.dat"
file_3="avgErrdata.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

i=1
while [[ i -le 30 ]]
do
    ./monteCarlo $((2**i)) >> data.dat
    ((i = i + 1))
done

#trap data
if [ -f $file_2 ] ; then
    rm $file_2
fi

i=1
while [[ i -le 30 ]]
do
    ./trap $((2**i)) >> trapData.dat 
    ((i = i + 1))
done


# Script for Rerun

if [ -f $file_3 ] ; then
    rm $file_3
fi


for (( i=1; i<=30; i++ ))
do  
	for (( j=1; j<=200; j++ ))
	do
		./monteCarlo $((2**i)) >> avgErrdata.dat
	done
done

python3 plot.py
