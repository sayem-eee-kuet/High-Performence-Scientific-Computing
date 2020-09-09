#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt
from statistics import mean
from collections import Counter
# #from sklearn.linear_model import LinearRegression
# from sklearn import linear_model
# from sklearn.metrics import mean_squared_error, r2_score


data_1 = np.loadtxt('3_c_dataStrong.dat')
data_2 = np.loadtxt('3_c_dataWeak.dat')
# data_3 = np.loadtxt('trap_ompl2.dat')


N = data_1[:, 2]
timeS = data_1[:, 1]
timeW = data_2[:, 1]

unique_elements, counts_elements = np.unique(N, return_counts=True)

frqn = int(counts_elements.mean())
# print(frqn)
# print(N)
# print(len(N))

sum_xa = 0
sum_ya = 0.0
sum_ya_2 = 0.0
#### Avg Error calculation ####
maxi = int(len(N)/frqn)
maxj = frqn
mean_xa = []
mean_ya = []
mean_ya_2 = []
j = 0
for i in range(0, maxi):
    for j in range(0, maxj):
        #print(j, int(data1[i*maxj + j, 0]))
        sum_xa = sum_xa + int(data_1[i*maxj + j, 2])
        sum_ya = sum_ya + data_1[i * maxj + j, 1]
        sum_ya_2 = sum_ya + data_2[i*maxj + j, 1]

    mean_xa.append(sum_xa/maxj)
    mean_ya.append(sum_ya / maxj)
    mean_ya_2.append(sum_ya_2/maxj)
    sum_xa = 0
    sum_ya = 0.0
    sum_ya_2 = 0.0

N = np.array(mean_xa)
timeS = np.array(mean_ya)
timeW = np.array(mean_ya_2)

# print(N)
# print(timeS)
# print(timeW)
speedS = []
speedW = []

for i in range(len(N)):
    s = timeS[0] / timeS[i]
    speedS.append(s)
    w = timeW[0] / timeW[i]
    speedW.append(w)

# print(speedW)
# print(speedS)
# # # Plotting
fig = plt.figure()
plt.semilogx(N, speedS, 'black', label='Strong scaling',
             marker='o', markerfacecolor='red', markersize=4)
plt.semilogx(N, speedW, 'blue', label='Weak scaling', marker='o',
             markerfacecolor='black', markersize=4)
# # plt.semilogy(N, speedS, 'black', label='Strong scaling',
# #                         marker='o', markerfacecolor='red', markersize=4)
# # plt.semilogy(N, speedW, 'blue', label='Weak scaling',
# #                         marker='o', markerfacecolor='red', markersize=4)
# # ## Theoritical error of MC: err is proportional to Itr ^ (-1/2) ###
# # plt.loglog(N, 822.6336/np.sqrt(N), 'green', label='Theory:'r'$E(N)\propto N^{-1/2}$', marker='o',
# #            markerfacecolor='black', markersize=4)
# # plt.loglog(N, y_3, 'green', label='trap_ompl2 Error', marker='o',
# #            markerfacecolor='red', markersize=4)

plt.legend()
plt.grid(True)
plt.minorticks_on()
# Customize the major grid
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel('Number of thread, N')
plt.ylabel('Speed up')
# plt.title('Numerical Intergration: Err vs Iteration')
# plt.show()
fig.savefig("3_c_scaling.png", bbox_inches="tight")
plt.show()
