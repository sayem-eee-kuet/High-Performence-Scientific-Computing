import time
import numpy as np

#Fix column, store successive rows: OPTION 2
tic = time.time();   #on unix system use time.time() for walltime
cols = 4000;
rows = 4000;
x = np.zeros( (cols,rows) , dtype = int);
for i in range(0,4000,1):   
  for j in range(0,4000,1):
  	x[j][i] = i + j;
toc = time.time();
timeCol = toc - tic;
print(timeCol);

#Fix row, store succesive columns: OPTION 1
tic1 = time.time();
for j in range(0,4000,1):   
  for i in range(0,4000,1):
  	x[j][i] = i + j;
toc1 = time.time();
timeRow = toc1 - tic1;
print(timeRow);
