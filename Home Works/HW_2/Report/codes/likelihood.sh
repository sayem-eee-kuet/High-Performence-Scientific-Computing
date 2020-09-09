#!/bin/bash
g++ -Wall -o likelihood_fqn likelihood_fqn.cpp

file_1="likelihood.dat"

if [ -f $file_1 ] ; then
    rm $file_1
fi

i=2
while [[ i -le 10 ]]
do
	./likelihood_fqn $((10**i)) >> likelihood.dat
echo "i = "$i "is done"
((i = i + 1))
done