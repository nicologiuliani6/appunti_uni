import numpy as np
import matplotlib.pyplot as plt

import numpy as np
import matplotlib.pyplot as plt

def punto_fisso(g, a, b, x0=None, tol=1e-6, max_iter=100000, plot=False):
    if x0 is None:
        x0 = (a + b) / 2  # punto iniziale

    x_prev = x0
    for i in range(max_iter):
        x_next = g(x_prev)

        # controllo uscita dai limiti
        if not (a <= x_next <= b):
            print(f"PUNTO FISSO: Iterazione {i}: uscita dai limiti [{a}, {b}] con x={x_next}")
            return -1, i

        # criterio di arresto: differenza tra iterazioni
        if abs(x_next - x_prev) < tol:
            if plot:
                plt.axvline(x_next, color='k', linestyle='--')
            return x_next, i + 1

        if plot:
            plt.plot([x_prev, x_prev], [x_prev, x_next], 'r', alpha=0.5)
            plt.plot([x_prev, x_next], [x_next, x_next], 'r', alpha=0.5)

        x_prev = x_next

    print("⚠️ Raggiunto numero massimo di iterazioni senza convergenza.")
    return x_prev, max_iter



if __name__ == "__main__":
  f = lambda x: np.log(x + 1) - x*g(x)   # funzione f(x)
  g = lambda x: np.log(x + 1)      # funzione g(x) per punto fisso
  a = 0
  b = 2
  x = np.linspace(a, b, 1000)
  plt.axhline(0, color='k')            # linea orizzontale a y=0
  
  plt.plot(x, f(x), 'b', label='f(x)=ln(x+1)-x')
  plt.plot(x, g(x), 'g', label='g(x)=ln(x+1)')
  plt.plot(x, x, 'orange', label='y=x')
  
  #Calcolo punto fisso
  sol = punto_fisso(g, a, b, 0.8)
  print(f"PUNTO FISSO = {sol[0]:0.4f}, iterazioni={sol[1]}")
  plt.show()

