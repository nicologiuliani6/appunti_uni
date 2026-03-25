import numpy as np
import time 
# Proiezione sui vincoli
def project(x):
    # 1️⃣ vincoli box 0 ≤ xi ≤ 1
    x = np.clip(x, 0, 1)

    # 2️⃣ proiezione ortogonale sul vincolo lineare
    peso = np.dot(pesi, x)

    if peso > capacita:
        norm_p2 = np.dot(pesi, pesi)
        correction = (peso - capacita) / norm_p2
        x = x - correction * pesi

        # dopo la proiezione ricontrolliamo il box
        x = np.clip(x, 0, 1)

    return x
def backtracking_ascent(f, x0, grad, alpha0, c=1e-4, p=0.5):
    while True:
        x_new = x0 + alpha0 * grad   # ASCESA

        # Condizione di Armijo per massimizzazione
        if f(x_new) >= f(x0) + c * alpha0 * np.linalg.norm(grad)**2:
            break

        alpha0 *= p

    return alpha0
def GA_backtracking(f, grad_f, x0, alpha0,
                    c=1e-4, p=0.5,
                    maxit=5000,
                    tol_grad=1e-6,
                    tol_diff_iter=1e-6):

    xk = np.array(x0, float)
    storico = [xk.copy()]

    for k in range(maxit):

        grad = grad_f(xk)

        if np.linalg.norm(grad) < tol_grad:
            break

        alpha = backtracking_ascent(f, xk, grad, alpha0, c, p)

        x_new = xk + alpha * grad   # ASCESA
        x_new = project(x_new)      # proiezione vincoli

        if np.linalg.norm(x_new - xk) < tol_diff_iter:
            break

        xk = x_new
        storico.append(xk.copy())

    return xk, alpha, np.array(storico), k

def knapsack(values, weights, capacity):
    """
    Risolve il problema dello zaino 0-1 usando programmazione dinamica.
    
    :param values: lista dei valori degli oggetti
    :param weights: lista dei pesi degli oggetti
    :param capacity: capacità massima dello zaino
    :return: valore massimo ottenibile
    """
    n = len(values)
    # Creiamo una matrice (n+1) x (capacity+1)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            if int(weights[i-1]) <= w:
                dp[i][w] = max(
                    dp[i-1][w],
                    dp[i-1][w - int(weights[i-1])] + int(values[i-1])
                )
            else:
                dp[i][w] = dp[i-1][w]
    
    return dp[n][capacity]


# ---- DATI ZAINO ----
valori = np.array([60., 100., 120., 180., 60., 40., 30., 75.])
pesi = np.array([10., 20., 30., 50., 15., 35., 55., 20.])
capacita = 150
start = time.time()
risultato = knapsack(valori, pesi, capacita)
end = time.time()
print(f"Valore massimo ottenibile: {risultato}")
print(f"Tempo esecuzione KP: {end - start:.6f} secondi")
f = lambda x : np.dot(valori, x)
grad_f  = lambda x : valori

# ---- ESECUZIONE ----
x0 = np.random.rand(np.size(valori))
start = time.time()
sol, alpha_finale, storico, it = GA_backtracking(f, grad_f, x0, alpha0=0.01)
end = time.time()

print("Valore massimo GD:", f(sol))
#print("Iterazioni:", it)
print(f"Tempo esecuzione DP: {end - start:.6f} secondi")
