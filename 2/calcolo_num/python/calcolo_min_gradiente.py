import numpy as np
import matplotlib.pyplot as plt

#passo fisso (alpha costante)
def gradiente_iter(f, df, x0, alpha=0.1, maxiter=100, plot=False):
    for i in range(maxiter):
        x = x0 - alpha*df(x0)
        x0 = x
        if plot:
            plt.plot(x, f(x), 'yo')
    return x0, maxiter

#passo variabile (alpha variabile)
def backtracking(f, df, x):
    rho = 0.5
    alpha = 1.0 #valore iniziale di partenza
    while f(x - alpha*df(x)) > f(x) - 0.25*alpha*df(x)**2:
        alpha *= rho
    return alpha
def gradiente_error(f, df, x0, error=1e-10, plot=False):
    k = 0
    while True:
        alpha = backtracking(f, df, x0)
        x = x0 - alpha*df(x0)
        if np.abs(x - x0) < error:
            break
        x0 = x
        if plot:
            plt.plot(x, f(x), 'yo')
        k += 1
    return x0, k




def main():
  f = lambda x : (x**2)
  df = lambda x: 2*x
  sol = gradiente_iter(f, df, 1)
  print(f"Metodo del gradiente iterativo: {sol[0]}\nIterazioni: {sol[1]}")
  sol = gradiente_error(f, df, 1)
  print(f"Metodo del gradiente errore backtracking: {sol[0]}\nIterazioni: {sol[1]}")

  #grafica
  x = np.linspace(-1, 1, 10000)
  plt.axhline(0, color='k')  
  plt.plot(x, f(x), 'b', label='')
  plt.show()
if __name__ == "__main__":    
    main();
