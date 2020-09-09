#!/bin/bash

gcc -Wall trapezoidal.c -o trapezoidal
gcc -Wall -fopenmp -o trap_ompl2 trap_ompl2.c
gcc -Wall -fopenmp -o trap_ompl1 trap_ompl1.c

file_1="trapData.dat"
file_2="trap_ompl2.dat"
file_3="trap_ompl1.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

if [ -f $file_3 ] ; then
    rm $file_3
fi

i=1
while [[ i -le 9 ]]
do
    ./trapezoidal $((10**i)) >> trapData.dat
    ./trap_ompl1 $((10**i)) >> trap_ompl1.dat
    ./trap_ompl2 $((10**i)) >> trap_ompl2.dat
    ((i = i + 1))
done
echo "Check the data file for Error vs Iteration."

echo "Time for N = 1,000,000,000"
echo "Time for trap.c (serial)"
time(./trapezoidal 1000000000)
echo "Time for trap_ompl1.c (parallel)"
time(./trap_ompl1 1000000000)
echo "Time for trap_ompl2.c (parallel)"
time(./trap_ompl2 10000000000)