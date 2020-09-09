#!/bin/bash
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o mc10d_parallel_optimized_2_a mc10d_parallel_2_a.cpp -lm
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o mc10d_parallel_optimized_2_b mc10d_parallel_2_b.cpp -lm
#g++ -Wall -o mc10d mc10d.cpp

file_1="dataParallel_2_a.dat"
file_2="dataParallel_2_b.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

if [ -f $file_2 ] ; then
    rm $file_2
fi

thNum=2
# i=1
# while [[ i -le 12 ]]
# do
#     ./mc10d_parallel_optimized_2_a $((10**i)) $thNum >> dataParallel_2_a.dat
#     # ./mc10d_parallel_optimized_1 $((10**i)) >> dataParallel_1.dat
#     ((i = i + 1))
# done
# echo "Done! Check data file."

i=12
./mc10d_parallel_optimized_2_b $((10**i)) $thNum >> dataParallel_2_b.dat

# i=10
# ./mc10d $((10**i)) >> dataParallel.dat
# echo "Done! Check data file."
# python3 plot.py