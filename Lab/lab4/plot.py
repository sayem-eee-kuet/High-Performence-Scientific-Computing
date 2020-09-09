#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt


# you can inspect this from jupyter notebook; its a matrix of your data
data = np.loadtxt('data.dat')
xv = data[:, 0]  # ":" means grab all of the rows, and 0 is from column 0
yv = data[:, 1]

fig = plt.figure()
plt.loglog(xv, yv)
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.xlabel('Iteration')
plt.ylabel('Error')
plt.title('Numerical Intergration: Err vs Iteration')
plt.show()
fig.savefig("Numerical Intergration: Err vs Iteration.png",
            bbox_inches="tight")
