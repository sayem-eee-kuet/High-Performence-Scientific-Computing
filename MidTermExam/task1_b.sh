#!/bin/bash
task=1_b
g++ -Wall -fopenmp -O3 -ffast-math -mavx -o task$task task$task.cpp -lm

file_1="task$task.dat"


if [ -f $file_1 ] ; then
    rm $file_1
fi

echo "Test case..." >> $file_1
./task$task 1.4 >> $file_1

echo "Program case..." >> $file_1
for x in 1.4 17
#for threadNo in 1000
do
   echo "====" >> $file_1

  ./task$task $x >> $file_1
done

# i=0
# end=(10**4)
# while [[ i -le end ]]
# do
#     ./task$task $i >> $file_1
#     ((i = i + 1))
# done