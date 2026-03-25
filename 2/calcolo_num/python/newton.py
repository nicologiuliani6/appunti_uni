import numpy as np
import matplotlib.pyplot as plt
  
def newton(f, df, x0, tol1=1e-6, tol2=1e-6, maxit=10000):
    """
    f: funzione
    df: derivata di f
    x0: punto iniziale
    tol1: tolleranza sulla differenza x_n - x_{n-1}
    tol2: tolleranza sul valore di f(x)
    maxit: numero massimo di iterazioni
    """
    k = 0
    while k < maxit:
        fx = f(x0)
        if abs(fx) < tol2:  # criterio sul valore della funzione
            break        
        dfx = df(x0)
        if dfx == 0:
            raise ValueError("Derivata nulla, non posso continuare")
        x_n = x0 - fx / dfx
        if abs(x_n - x0) < tol1:  # criterio sulla differenza tra iterazioni
            x0 = x_n
            break
        x0 = x_n
        k += 1
    return x0, k

if __name__ == "__main__":
  f  = lambda x: np.cos(x)
  df = lambda x: -np.sin(x)
  x0 = 1
  soluzione = newton(f, df, x0, 1.e-6, 1.e-5, 100)
  print(f"SOL = {soluzione[0]}")
  print(f"ITER = {soluzione[1]}")
