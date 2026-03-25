import numpy as np
import scipy.linalg as sp

# Matrice
A = np.array([[9,3,6],
              [3,4,6],
              [0,8,8]])

# Decomposizione LU
P, L, U = sp.lu(A)

# Verifica errore
err = np.linalg.norm(A - P @ L @ U)
print(f"Norma errore LU: {err}")


# pb test 2
# la funzione scipy.linalg.lu_factor restituisce due matrici della fattorizzazione LU:
# nella prima si memorizza sia L (triangolare inferiore) che U (triangolare superiore)
# nella seconda si memorizza P sotto forma di vettore di pivot
import numpy as np
import scipy as sp

# matrice A
A = np.array([
    [3, -7, 2, 2],
    [-3, 5, 1, 0],
    [6, -4, 0, -5],
    [-9, 5, -5, 12]
])

# fattorizzazione LU con pivoting
lu, piv = sp.linalg.lu_factor(A)
print("LU (L+U combinata):\n", lu)
print("Pivot indices:", piv)

# vettore b
b = np.array([-9, 5, 7, 11])

# risoluzione del sistema lineare Ax = b
x = sp.linalg.lu_solve((lu, piv), b)
print("Soluzione x =", x)

# norma dell'errore ||Ax - b||
err = np.linalg.norm(b - A @ x)
print("Norma errore:", err)

