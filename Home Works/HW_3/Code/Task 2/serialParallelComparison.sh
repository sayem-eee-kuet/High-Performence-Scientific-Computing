#!/bin/bash
g++ -Wall -O3 -ffast-math -mavx -o mc10d_1_b mc10d_1_b.cpp -lm
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o mc10d_parallel_optimized_2_d mc10d_parallel_2_d.cpp -lm
#g++ -Wall -o mc10d mc10d.cpp

file_1="serialAbsError.dat"
file_2="parallelAbsError.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

i=1
while [[ i -le 10 ]]
do
    ./mc10d_parallel_optimized_2_d $((10**i)) >> parallelAbsError.dat
    ./mc10d_1_b $((10**i)) >> serialAbsError.dat
    # ./mc10d_parallel_optimized_1 $((10**i)) >> dataParallel_1.dat
    ((i = i + 1))
done
echo "Done! Check data file."
python3 plotAbs.py