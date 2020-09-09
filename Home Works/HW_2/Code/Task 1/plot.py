#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from statistics import mean
from collections import Counter

data = np.loadtxt('avgErrdata.dat')


x_n = data[:, 0]
y_err = data[:, 1]

unique_elements, counts_elements = np.unique(x_n, return_counts=True)

frqn = int(counts_elements.mean())

# Theoritical error of MC: err is proportional to Itr^(-1/2)
# y_theory = np.array(1./np.sqrt(data[:, 0])
# print(y_theory)


sum_xa = 0
sum_ya = 0.0

#### Avg Error calculation ####
maxi = int(len(x_n)/frqn)
maxj = frqn
mean_xa = []
mean_ya = []
j = 0
for i in range(0, maxi):
    for j in range(0, maxj):
        #print(j, int(data1[i*maxj + j, 0]))
        sum_xa = sum_xa + int(data[i*maxj + j, 0])
        sum_ya = sum_ya + data[i*maxj + j, 1]

    mean_xa.append(sum_xa/maxj)
    mean_ya.append(sum_ya/maxj)
    sum_xa = 0
    sum_ya = 0.0

itr_a = np.array(mean_xa)
err_a = np.array(mean_ya)
### Avg calculation End ###

# Plotting
fig = plt.figure()
plt.loglog(itr_a, err_a, 'black', label='Avg Error', marker='o',
           markerfacecolor='red', markersize=4)
### Theoritical error of MC: err is proportional to Itr ^ (-1/2) ###
plt.loglog(x_n, 1./np.sqrt(data[:, 0]), 'blue', label='E(Theory)', marker='o',
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
