import numpy as np
import matplotlib.pyplot as plt


def bisezione(f, a, b, ERROR_MARGIN=1e-5, k=0):
    # Calcola punto medio
    x0 = (a + b) / 2
    # Controllo margine di errore
    if abs(a - b) < ERROR_MARGIN:
        return (x0, k)
    # Controllo che il segno ai limiti sia opposto
    if f(a) * f(b) > 0:
        print("ERRORE: i limiti non racchiudono una radice.")
        return None, None
    # Plot (opzionale, utile per debug o grafica)
    if __name__ == "__main__": plt.plot(x0, f(x0), 'ro')
    # Incrementa contatore iterazioni
    k += 1
    # Ricorsione
    if f(a) * f(x0) <= 0:
        return bisezione(f, a, x0, ERROR_MARGIN, k)
    else:
        return bisezione(f, x0, b, ERROR_MARGIN, k)


if __name__ == "__main__":
  f = lambda x: (x**2 - 10)
  a = 1
  b = 4
  N = 100
  x = np.linspace(a, b, N)
  y = f(x)
  plt.plot(x, y)
  plt.axhline(0, color="black", linewidth=0.8)
  sol = bisezione(f, a, b)
  print(f"STOP: radice ≈ {sol[0]}")  
  print(f"ITERAZIONI= {sol[1]}")    
  plt.show()
