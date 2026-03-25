import numpy as np
import matplotlib.pyplot as plt

#passo fisso (alpha costante)
def gradiente_iter(f, df1, df2, x1_0, x2_0, alpha=0.1, maxiter=8000, plot=False):
    for i in range(maxiter):
        x1 = x1_0 - alpha * df1(x1_0, x2_0)
        x1_0 = x1
        x2 = x2_0 - alpha * df2(x1_0, x2_0)
        x2_0 = x2
        if plot: 
            plt.plot(x1, x2, 'bo', markersize=12)
    return x1_0, x2_0, maxiter

#passo variabile (alpha variabile)
def backtracking(f, df1, df2, x1, x2):
    rho = 0.5
    alpha = 1.0 #valore iniziale di partenza
    while f(x1 - alpha*df1(x1, x2), x2) > f(x1, x2) - 0.25*alpha*df1(x1, x2)**2:
        alpha *= rho
    while f(x1 , x2 - alpha*df2(x1, x2)) > f(x1, x2) - 0.25*alpha*df2(x1, x2)**2:
        alpha *= rho
    return alpha
    
def gradiente_error(f, df1, df2, x1_0, x2_0, error=1e-10, plot=False):
    k = 0
    while True:
        alpha = backtracking(f, df1, df2, x1_0, x2_0)
        x1 = x1_0 - alpha*df1(x1_0, x2_0)
        x2 = x2_0 - alpha*df2(x1_0, x2_0)
        if np.sqrt((x1-x1_0)**2 + (x2-x2_0)**2) < error:
            break
        x1_0 = x1
        x2_0 = x2
        if plot: 
            plt.plot(x1, x2, 'bo', markersize=12)
        k += 1
    return x1_0, x2_0, k


def main():
    f = lambda x1, x2 : (x1 - 5)**2 + (x2 -2)**2
    df1 = lambda x1, x2: 2*x1 - 10 + 0
    df2 = lambda x1, x2: 0 + 2*x2 - 4
    # Griglia per il grafico
    x = np.linspace(0, 8, 200)
    y = np.linspace(0, 5, 200)
    X, Y = np.meshgrid(x, y)
    Z = f(X, Y)
    plt.figure(figsize=(6,5))
    plt.contour(X, Y, Z, levels=30, cmap='viridis')
    plt.plot(5, 2, 'r*', markersize=12, label='Minimo (5,2)')

    sol = gradiente_iter(f, df1, df2, 1, 1)
    print(f"Metodo del gradiente iterativo: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = gradiente_error(f, df1, df2, 1, 1)
    print(f"Metodo del gradiente errore backtracking: ({sol[0]}, {sol[1]}. Iterazioni: {sol[2]}")
  
    plt.xlabel('x1')
    plt.ylabel('x2')
    plt.legend()
    plt.title('f(x1, x2) = (x1 - 5)^2 + (x2 - 2)^2')
    plt.show()

if __name__ == "__main__":
    main()
