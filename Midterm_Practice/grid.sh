#!/bin/bash
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o grid grid.cpp -lm

file_1="grid.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

# #for threadNo in 2 5 10 100 1000
# for threadNo in 1000
# do
#   echo "Number of player $threadNo" >> problem5.dat
#   echo "-------------------------------------------" >> problem5.dat
#   mpirun -np $threadNo problem5 >> problem5.dat
#   echo "===========================================" >> problem5.dat
# done
i=8
./grid $((10**i)) >> grid.dat

echo "Done! Check data file!"



