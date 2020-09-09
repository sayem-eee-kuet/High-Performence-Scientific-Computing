#!/usr/bin/python3
import numpy as np
import math
from matplotlib import pyplot as plt


def isSquare(N):
    # Find floating point value of
    # square root of x.
    sr = math.sqrt(N)

    # If square root is an integer
    return ((sr - math.floor(sr)) == 0)


#N = 100

# print(isSquare(N))

sum = 0

for i in range(1, 100000000):
    sum = sum + i
    if (isSquare(sum) == True):
        print(sum)
