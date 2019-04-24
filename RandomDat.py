import numpy as np

ArrayCount = np.loadtxt('GraphCount_Dense.txt');
print('Mean number of the nodes connected in the graph : ',np.mean(ArrayCount))
print('Maximum number of the nodes connected in the graph : ',max(ArrayCount))
print('Minimum number of the nodes connected in the graph ',min(ArrayCount))
print('Median number of the nodes connected in the graph : ',np.median(ArrayCount))
