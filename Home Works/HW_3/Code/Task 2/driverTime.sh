#!/bin/bash
g++ -Wall -O3 -ffast-math -mavx -o mc10d_1_b_time mc10d_1_b_time.cpp -lm
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o mc10d_parallel_optimized_2_c mc10d_parallel_2_c.cpp -lm
#g++ -Wall -o mc10d mc10d.cpp

file_1="timeParallel.dat"
file_2="timeSerial.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

i=1
while [[ i -le 11 ]]
do
    ./mc10d_1_b_time $((10**i)) >> timeSerial.dat
    ./mc10d_parallel_optimized_2_c $((10**i)) >> timeParallel.dat
    ((i = i + 1))
done
echo "Done! Check data file."

