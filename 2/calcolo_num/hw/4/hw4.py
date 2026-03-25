import sys
sys.path.append("ProblemiInversi")
import utilities
import operators
import solvers
import numpy as np
import matplotlib.pyplot as plt

from skimage import data

# Lettura dei dati da skimage
x = data.moon()
x = x / x.max()


kernel = utilities.gaussian2d_kernel(k=11, sigma=3.5)
A = operators.ConvolutionOperator(kernel)


y = A(x)
y_delta = y + utilities.gaussian_noise(y, noise_level=0.05)

gd_tv_solver = solvers.GDTotalVariation(A, beta=1e-3)

# Scelta parametri TV (beta e lambda)
beta = 1e-3
lmbda = 1

# Scelta di x0, kmax, tolf, tolx
x0 = np.zeros_like(x)
kmax = 30
tolf = 1e-8
tolx = 1e-8

# Soluzione
x_TV, obj_val, grad_norm = gd_tv_solver.solve(y_delta, lmbda, x0, kmax, tolf, tolx)

# Visualizzazione ricostruzione
plt.figure(figsize=(10, 4))
plt.subplot(1, 3, 1)
plt.imshow(x, cmap="gray")
plt.title("Originale")
plt.axis("off")

plt.subplot(1, 3, 2)
plt.imshow(y_delta, cmap="gray")
plt.axis("off")
plt.title("Corrotta")

plt.subplot(1, 3, 3)
plt.imshow(x_TV, cmap="gray")
plt.axis("off")
plt.title("Ricostruzione")
plt.show()

#Calcolo metriche di errore
print('ER',utilities.rel_err(x_TV,x))
print('PSNR',utilities.psnr(x_TV,x))
print('SSIM',utilities.ssim(x_TV,x))