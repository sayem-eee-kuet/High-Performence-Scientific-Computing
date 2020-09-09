#!/usr/bin/python3
import numpy as np
from matplotlib import pyplot as plt

data = np.loadtxt('wave.dat')
x = np.array(data[:, 1])
y = np.array(data[:, 2])
ex = np.array(data[:, 3])
# constant = (1 + np.sqrt(2))**4
# outArray = []
# index = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
# lenght = len(data_1)

# for i in range(lenght-1):
#     N2 = data_1[i+1]
#     N1 = data_1[i]
#     out = np.abs((N2/N1) - constant)
#     outArray.append(out)


# Plotting
fig = plt.figure()

# plt.plot(x, y, 'blue', label=r'$| \frac{N_{i+1}}{N_i} - (1 +\sqrt{2}) ^ 4 |$', marker='o',
#         markerfacecolor = 'red', markersize = 1)
# plt.plot(x, ex, 'black', label='Amplitude', marker='o',
#          markerfacecolor='red', markersize=4)

plt.plot(x, y, 'black')
#plt.plot(x, ex, 'black')

# plt.legend()
plt.grid(True)
plt.minorticks_on()
plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
# Customize the minor grid
plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

plt.xlabel('Length')
plt.ylabel('Amplitude')
# plt.title('Numerical Intergration: Err vs Iteration')
fig.savefig("Amplitude_Length.png",
            bbox_inches="tight")
plt.show()
