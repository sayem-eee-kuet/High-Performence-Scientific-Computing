#!/bin/bash
mpicc -Wall -o bayesParallel bayesParallel.c -lm
mpicc -Wall -o bayesParallelReduction bayesParallelReduction.c -lm

file_1="task1.dat"
file_2="task2.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

i=5
threadNo=4

# mpirun -np $threadNo helloMPI
# ./bayesSerial $((10**i)) >> serialData.dat
mpirun -np $threadNo bayesParallel $((10**i)) >> task1.dat
mpirun -np $threadNo bayesParallelReduction $((10**i)) >> task2.dat
echo "Done! Check data file: task1.dat & task2.dat."
#python3 plot.py