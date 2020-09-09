#!/bin/bash
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o problem4_a problem4_a.cpp -lm
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o problem4_b problem4_b.cpp -lm

part_a=a
part_b=b
part_b_ans=b_ans

file_1="problem4$part_a.dat"
file_2="problem4$part_b.dat"
file_3="problem4$part_b_ans.dat"

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
# while [[ i -le 8 ]]
# do
#      echo "Game: "$i >> problem4$part_a.dat
#     ./problem4_a >> problem4$part_a.dat
#     ((i=i+1))
# done

echo "Game: "$i >> problem4$part_a.dat
./problem4_a >> problem4$part_a.dat

i=2
echo "Game: "$i >> problem4$part_a.dat
./problem4_a >> problem4$part_a.dat

i=1
while [[ i -le 10000 ]]
do
     #echo "Game: "$i >> problem4$part_a.dat
    ./problem4_b >> problem4$part_b.dat
    ((i=i+1))
done
python3 problem4.py >> problem4$part_b_ans.dat