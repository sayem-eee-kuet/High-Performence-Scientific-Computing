#!/bin/bash
gcc trap.c -o trap
file="data.dat"

if [ -f $file ] ; then
    rm $file
fi

i=1
while [[ i -le 30 ]]
do
    ./trap $((2**i)) >> data.dat 
    ((i = i + 1))
done

python3 plot.py
