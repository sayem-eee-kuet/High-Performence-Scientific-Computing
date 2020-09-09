#!/usr/bin/python3
import numpy as np
import matplotlib.pyplot as plt


fig = plt.figure()
x = np.loadtxt("rand.dat")
plt.hist(x, bins=100)
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.show()
plt.savefig("Rand Numbers Histrogram.png", bbox="tight")
