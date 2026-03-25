import math
import sys
import sympy as sp
 
netwon = True
x = sp.symbols('x')
f_expr = x**2 -2

# calcola la derivata simbolica
f_prime_expr = sp.diff(f_expr, x)

# converte in funzione Python numerica
f = sp.lambdify(x, f_expr)
f1 = sp.lambdify(x, f_prime_expr)

def phi(x):
    if(netwon): 
        if (f1(x) != 0): return 1/f1(x)
        else:
         print("Errore divisione per 0!")
         exit(1)
    else: return 1

def g(x):
    return x - f(x) * phi(x)

def punto_fisso(x_0, a, b, approx=sys.float_info.epsilon, max_iter=10000):
    x = x_0
    for i in range(max_iter):
        x_new = g(x)
        # Controllo se esce dai limiti [a, b]
        if x_new < a or x_new > b:
            print(f"Uscito dal limite [{a}, {b}]")
            exit(1)
        if abs(x_new - x) <= approx:
            print(f"Convergenza raggiunta dopo {i+1} iterazioni")
            return x_new
        x = x_new
    print(f"Non converge con {max_iter} iterazioni!")
    exit(1)

a = 0
b = 2
x0 = (a + b) / 2
sol = punto_fisso(x0, a, b)
print(f"Soluzione approssimata: {sol:.32f}")

