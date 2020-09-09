import numpy as np
import matplotlib.pyplot as plt
import time
import glob
import os
from PIL import Image
import glob

# Create the frames
frames = []
imgs = glob.glob("frame_*.png")
for i in imgs:
    new_frame = Image.open(i)
    frames.append(new_frame)

# Save into a GIF file that loops forever
frames[0].save('png_to_gif.gif', format='GIF',
               append_images=frames[1:],
               save_all=True,
               duration=80, loop=0)


data = np.loadtxt('wave.dat')
x = np.array(data[:, 1])
y = np.array(data[:, 2])
ex = np.array(data[:, 3])

# Plotting
# fig = plt.figure()
# for n in range(401):
#     plt.plot(x[n], y[n], 'black', label='Amplitude', marker='o',
#              markerfacecolor='red', markersize=4)
#     plt.grid(True)
#     plt.minorticks_on()
#     plt.grid(which='major', linestyle='-', linewidth='0.5', color='black')
#     # Customize the minor grid
#     plt.grid(which='minor', linestyle='--', linewidth='0.5', color='black')

#     plt.xlabel('Iteration')
#     plt.ylabel('Amplitude')
#     # plt.title('Numerical Intergration: Err vs Iteration')
#     fig.savefig('frame_%d.png' % n,
#                 bbox_inches="tight")
#     # plt.show()


# frameRate = 5
# cmd = ('convert -delay 80 frame_*.png movie_80.gif')
# os.system(cmd)

# for filename in glob.glob('frame_*.png'):
#     os.remove(filename)
