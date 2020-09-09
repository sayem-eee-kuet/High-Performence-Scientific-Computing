#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from statistics import mean
from collections import Counter
# #from sklearn.linear_model import LinearRegression
# from sklearn import linear_model
# from sklearn.metrics import mean_squared_error, r2_score


data_1 = np.loadtxt('parallelAbsError.dat')
data_2 = np.loadtxt('serialAbsError.dat')
# data_3 = np.loadtxt('trap_ompl2.dat')


N = data_1[:, 0]
err = data_1[:, 2]
err_1 = data_2[:, 2]


# Plotting
fig = plt.figure()
plt.loglog(N, err, 'black', label='Abs Error: Serial Data',
           marker='o', markerfacecolor='red', markersize=4)
plt.loglog(N, err_1, 'blue', label='Abs Error: Parallel Data', marker='o',
           markerfacecolor='black', markersize=4)
## Theoritical error of MC: err is proportional to Itr ^ (-1/2) ###
plt.loglog(N, 1000/np.sqrt(N), 'green', label='Theory:'r'$E(N)\propto N^{-1/2}$', marker='o',
           markerfacecolor='black', markersize=4)
# plt.loglog(N, y_3, 'green', label='trap_ompl2 Error', marker='o',
#            markerfacecolor='red', markersize=4)

plt.legend()
plt.grid(True)
plt.minorticks_on()
# Customize the major grid
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel('Iteration, N')
plt.ylabel('Abs Error')
# plt.title('Numerical Intergration: Err vs Iteration')
# plt.show()
fig.savefig("Comparison between serial and parallel_1.png",
            bbox_inches="tight")
plt.show()
