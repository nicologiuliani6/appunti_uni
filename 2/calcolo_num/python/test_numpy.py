import numpy as np
import matplotlib.pyplot as plt

a = 0
b = 10
N = 50

x = np.linspace(a, b, N)
y1 = np.sin(x)
y2 = np.cos(x)

plt.plot(x, y1)
plt.plot(x, y2)
plt.show()
