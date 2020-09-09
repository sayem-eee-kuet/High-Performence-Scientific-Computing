#!/bin/bash
# Compile with warnning massages
gcc -Wall -std=c99 -o rand rand.c
gcc -Wall -std=c99 -o matrix matrix.c

# Problem 01
echo "Problem 01: Generate Ranadom Number and Histogram:"
./rand 10000
python3 histogram.py

# Problem 02
echo "Problem 02: Matrix Residual: Residual.dat"
./matrix >> rasidual.dat