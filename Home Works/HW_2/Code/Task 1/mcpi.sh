#!/bin/bash
g++ -Wall -o monteCarlopi monteCarlopi.cpp

file_1="pi.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

i=2
while [[ i -le 10 ]]
do
    ./monteCarlopi $((10**i)) >> pi.dat
    echo "i = "$i "is done"
    ((i = i + 1))
done
echo "Job is done. Check the data file!"