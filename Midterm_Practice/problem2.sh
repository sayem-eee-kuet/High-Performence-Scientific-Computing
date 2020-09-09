#!/bin/bash
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o problem2 problem2.cpp -lm
gcc -Wall -fopenmp -O3 -ffast-math -mavx -o diceMP diceMP.c -lm

file_1="problem2.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

threadNum=2
i=1000000
# while [[ i -le 6 ]]
# do
#     ./problem2 $((10**i)) $threadNum >> problem2_$threadNum.dat
#     #./diceMP $((10**i)) $threadNum >> problem2.dat
#     ((i = i + 1))
# done

while [[ threadNum -le 8 ]]
do
    ./problem2 $i $threadNum >> problem2.dat
    #./diceMP $((10**i)) $threadNum >> problem2.dat
    ((threadNum = threadNum * 2))
done

# N=1
# ./problem2 $N $threadNum >> problem2.dat


echo "Done! Check data file."