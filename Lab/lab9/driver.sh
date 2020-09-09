#!/bin/bash
mpicc -Wall -o bayesParallel bayesParallel.c -lm
gcc -Wall -o bayesSerial bayesSerial.c -lm 
#g++ -Wall -o mc10d mc10d.cpp

file_1="parallelData.dat"
file_2="serialData.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

i=5
threadNo=10

./bayesSerial $((10**i)) >> serialData.dat
mpirun -np $threadNo bayesParallel $((10**i)) >> parallelData.dat
echo "Done! Check data file."
#python3 plot.py