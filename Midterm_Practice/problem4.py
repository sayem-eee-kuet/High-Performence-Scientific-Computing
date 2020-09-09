#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt


data_1 = np.loadtxt('problem4b.dat')

W = data_1[:]
N = len(W)

sum = W.sum(axis=0)
avgWin = sum / N

print(avgWin)
