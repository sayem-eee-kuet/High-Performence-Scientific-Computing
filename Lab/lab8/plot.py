#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from statistics import mean
from collections import Counter

data_1 = np.loadtxt('trapData.dat')
data_2 = np.loadtxt('trap_ompl1.dat')
data_3 = np.loadtxt('trap_ompl2.dat')


N = data_2[:, 0]
y_1 = data_1[:, 1]
y_2 = data_2[:, 1]
y_3 = data_3[:, 1]


# Plotting
fig = plt.figure()
plt.loglog(N, y_1, 'black', label='Trap Error', marker='o',
           markerfacecolor='red', markersize=4)
## Theoritical error of MC: err is proportional to Itr ^ (-1/2) ###
plt.loglog(N, y_2, 'blue', label='trap_ompl1 Error', marker='o',
           markerfacecolor='red', markersize=4)
plt.loglog(N, y_3, 'green', label='trap_ompl2 Error', marker='o',
           markerfacecolor='red', markersize=4)

plt.legend()
plt.grid(True)
plt.minorticks_on()
# Customize the major grid
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel('Iteration, N')
plt.ylabel('Error 'r'$|\pi - \pi_{N}|$')
#plt.title('Numerical Intergration: Err vs Iteration')
# plt.show()
fig.savefig("avg_Err_vs_Iteration.png", bbox_inches="tight")
