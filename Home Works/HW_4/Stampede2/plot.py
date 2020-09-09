import matplotlib
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt


numberCore = [68, 136, 272, 544, 1088]
# print(x)
t_total = [0.519483, 0.519671, 0.518695, 0.518730, 0.518259]
t_reduction = [0.001696, 0.001231, 0.001045, 0.001188, 0.000905]

speedW = []

for i in range(len(numberCore)):
    w = t_total[0] / t_total[i]
    speedW.append(w)

fig1 = plt.figure()
plt.semilogy(numberCore, speedW, 'blue', label='Total Time vs Number of cores', marker='o',
             markerfacecolor='red', markersize=4)
plt.legend()
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.xlabel('Number of Cores')
plt.ylabel('Speed Up')
#plt.title('Time vs Number of Sample point curve')
plt.show()
fig1.savefig("Speed Up: Weak scaling test",
            bbox_inches="tight")

plt.show()

fig = plt.figure()
plt.plot(numberCore, t_total, 'blue', label='Total Time vs Number of cores', marker='o',
         markerfacecolor='red', markersize=4)
# plt.plot(numberCore, t_reduction, 'blue', label='Reduction Time vs Number of cores', marker='o',
#          markerfacecolor='black', markersize=4)
# plt.show()
# plt.loglog(N, T, 'r', label='Model:' r'$T = 2.173e-08 \times N + 5.439e-3$', marker='o',
#            markerfacecolor='red', markersize=4)
plt.legend()
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle=':', linewidth='0.5', color='black')
plt.xlabel('Number of Cores')
plt.ylabel('Times(sec)')
#plt.title('Time vs Number of Sample point curve')
plt.show()
fig.savefig("Total Time vs Number of Cores",
            bbox_inches="tight")
