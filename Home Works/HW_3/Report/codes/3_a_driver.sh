#!/bin/bash
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o mc10d_parallel_optimized_3_a mc10d_parallel_3_a.cpp -lm


file_1="3_a_data.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

threadNum=4
i=1
while [[ i -le 10 ]]
do
    ./mc10d_parallel_optimized_3_a $((10**i)) $threadNum >> 3_a_data.dat
    ((i = i + 1))
done
echo "Done! Check data file."