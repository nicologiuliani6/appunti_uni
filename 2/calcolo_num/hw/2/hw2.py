import numpy as np
np.seterr(over='ignore', invalid='ignore')
import math
import matplotlib.pyplot as plt

# calcoliamo le derivate parziali
def numerical_df(f, n, eps=1e-8):
    """
    Crea lista di funzioni lambda per le derivate parziali compatibili con GD_backtracking
    che passa le variabili come *x.
    """
    df_list = []
    for i in range(n):
        # Possiamo definire la derivata rispetto a x_i = tasso di variazione di f diviso il piccolo offset ε lungo x_i
        df_list.append(
            # differenze finite in avanti
            lambda *x, i=i: (
                f(*[xi + eps if j==i else xi for j, xi in enumerate(x)]) - f(*x)
            ) / eps
        )
    return df_list

def GD_fisso(f, df, x0, alpha, maxit=8000, tol_grad=1e-6, tol_diff_iter=1e-5):
    """
    Implementazione del metodo di discesa del gradiente multivariabile con passo fisso.
    
    Parameters:
    f (function): funzione obiettivo
    df (function): lista delle derivate della funzione
    x0 (ndarray): lista dei valori iniziali
    alpha (float): passo fisso
    maxit (int): numero di iterazioni
    tol_grad (float): tolleranza sul gradiente
    tol_diff_iter (float): tolleranza sulla differenza di iterazione
    """
    xk_arr = [x0.copy()] 
    xk = np.array(x0, float) #facciamo una copia della lista input
    for iter in range(maxit):
        grad = [g(*xk) for g in df] #lista dei valori dei gradienti gia calcolato rispetto alle incognite
        i = 0
        #cicliamo tutte le incognite
        for xi in xk: 
            #x_(k+1, i) = x_(k,i) - \alpha * (\nabla f(x_1, ... ,x_i))_i
            xk[i] = xi - alpha * grad[i]
            i+=1
        norma2_grad = math.sqrt(sum(g**2 for g in grad))
        #controllo tolleranza sul gradiente
        if(norma2_grad < tol_grad): break
        #controllo tolleranza sulla norma della differenza del punto attuale e di quello precedentemente calcolato
        if (np.linalg.norm(xk - x0) < tol_diff_iter): break
        x0 = xk.copy()
        xk_arr.append(xk.copy())
    return xk, np.array(xk_arr), iter #torniamo la lista finale

def backtracking(f, x0, grad, alpha0, c=1e-4, p=0.5):
    """
    Backtracking (+ condizione di Armijo)

    Parameters:
    f (function): funzione obiettivo
    x0 (ndarray): punto corrente
    grad (list): gradiente in x0
    alpha0 (float > 0): passo iniziale
    c (float in  0,1): costante di diminuzione del passo
    p (float in 0,1): tasso di diminuzione dell'alpha ad ogni iterazione

    """

    while True:
        xk = x0.copy()
        i = 0
        for xi in x0:
            xk[i] = xi - alpha0 * grad[i]
            i += 1

        if f(*xk) <= f(*x0) - c * alpha0 * np.linalg.norm(grad)**2:
            break

        alpha0 *= p

    return alpha0
def GD_backtracking(f, df, x0, alpha0, c=1e-4, p=0.5, maxit=8000, tol_grad=1e-6, tol_diff_iter=1e-5):
    """
    Implementazione del metodo di discesa del gradiente multivariabile con passo fisso.
    
    Parameters:
    f (function): funzione obiettivo
    df (function): lista delle derivate della funzione
    x0 (ndarray): lista dei valori iniziali
    alpha0 (float > 0): passo di partenza
    c (float in  0,1): costante di diminuzione del passo
    p (float in 0,1): tasso di diminuzione dell'alpha ad ogni iterazione
    maxit (int): numero di iterazioni
    tol_grad (float): tolleranza sul gradiente
    tol_diff_iter (float): tolleranza sulla differenza di eterazione
    """
    xk_arr = [x0.copy()] 
    xk = np.array(x0, float) #facciamo una copia della lista input
    for iter in range(maxit):
        grad = [g(*xk) for g in df] #lista dei valori dei gradienti gia calcolato rispetto alle incognite
        
        #controllo tolleranza sul gradiente
        if(np.linalg.norm(grad) < tol_grad): break
        
        # scelta dinamica del passo
        alpha0 = backtracking(f, x0, grad, alpha0, c, p)

        #calcoliamo x_k+1 con l'alpha giusto
        i = 0
        #cicliamo tutte le incognite
        for xi in xk: 
            #x_(k+1, i) = x_(k,i) - \alpha * (\nabla f(x_1, ... ,x_i))_i
            xk[i] = xi - alpha0 * grad[i]
            i+=1

        #controllo tolleranza sulla norma della differenza del punto attuale e di quello precedentemente calcolato
        if (np.linalg.norm(xk - x0) < tol_diff_iter): break

        x0 = xk.copy() #x_k
        xk_arr.append(xk.copy())  # <-- aggiungi iterazione alla lista

    return xk, alpha0, np.array(xk_arr), iter #torniamo la lista finale

def OLS(A, b, n=1.0, p=2, reg=0.0, q=2):
    """
    Parametri:
    -----------
    A (ndarray): Matrice degli input.
    b (ndarray): Vettore degli output attesi.
    n (float, opzionale): Fattore scalare moltiplicativo fuori dalla norma.
    p  (float, opzionale): Potenza della norma
    reg (float, opzionale): fattore di regolarizzazione λ
    q (float, opzionale): norma della regolarizzazione
    """
    x0 = np.random.random(A.shape[1])  # array 1D randomico

    # funzione con regolarizzazione
    f = lambda *x: n * np.linalg.norm(A @ np.array(x) - b)**p + reg * np.linalg.norm(np.array(x))**q

    # derivate numeriche compatibili con *x
    df = numerical_df(f, A.shape[1])

    # GD_backtracking
    x_min, alpha, xk_arr, iter = GD_backtracking(f, df, x0=x0, alpha0=1.0)
    return x_min, alpha, xk_arr, iter 

def SGD_fisso(f, df, x0, alpha, batch_size, maxit=8000, tol_grad=1e-6, tol_diff_iter=1e-5):
    """
    Implementazione del metodo del gradiente stoccastico multivariabile con passo fisso.
    
    Parameters:
    f (function): funzione obiettivo
    df (function): lista delle derivate della funzione
    x0 (ndarray): lista dei valori iniziali
    alpha (float): passo fisso
    batch_size (int): dimensione degli elementi casuali di input
    maxit (int): numero di iterazioni
    tol_grad (float): tolleranza sul gradiente
    tol_diff_iter (float): tolleranza sulla differenza di eterazione
    """
    n = len(x0)
    xk = x0.copy()
    xk_arr = [xk.copy()]
    for iter in range(maxit):
        # scegli il batch
        indices = np.random.choice(n, size=batch_size, replace=False)
        xk_batch = xk[indices].copy()
        grad_batch = [df[i](*xk) for i in indices]  # solo le derivate del batch        i = 0
        
        # aggiorna solo gli elementi del batch
        for idx, g in zip(indices, grad_batch):
            xk[idx] = xk[idx] - alpha * g
            
        norma2_grad = math.sqrt(sum(g**2 for g in grad_batch))
        #controllo tolleranza sul gradiente
        if(norma2_grad < tol_grad): break
        #controllo tolleranza sulla norma della differenza del punto attuale e di quello precedentemente calcolato
        if (np.linalg.norm(xk - x0) < tol_diff_iter): break
    return xk, np.array(xk_arr), iter #torniamo la lista finale


if __name__ == "__main__":
    #esercizio a
    f = lambda x1, x2: (x1 - 5)**2 + (x2-2)**2
    df = [
        lambda x1, x2: 2 * (x1 - 5),  # df/dx1
        lambda x1, x2: 2 * (x2 - 2)   # df/dx2
    ]
    x0 = [4, 1]
    alphas = [0.01]
    for a in alphas:
        xk, xk_arr, iter = GD_fisso(f, df, x0, a, 4000)
        if not(np.any(np.isnan(xk))):
            print(f"a) GD_fisso (x0={x0}, a={a}): xk={xk}")
        else:
            print(f"a) Overflow, impossibile calcolare per x0={x0} e alpha={a}")
    print("\n")

    #esercizio b
    f = lambda x1, x2:(1-x1)**2 + 100*(x2-x1**2)**2
    df = [
        lambda x1, x2: 2*(x1 - 1) - 400*x1*(x2 - x1**2),
        lambda x1, x2: 200*(x2 - x1**2)
    ]
    x0 = [0, 2]
    alphas = [0.01, 0.005, 0.001]
    for a in alphas:
        xk, xk_arr, iter = GD_fisso(f, df, x0, a, 8000)
        if not(np.any(np.isnan(xk))):
            print(f"b) GD_fisso (x0={x0}, a={a}): {xk}")
        else:
            print(f"b) Overflow, impossibile calcolare per x0={x0} e alpha={a}")
    print("\n")

    #esercizio c
    f = lambda x1, x2:(x1**4 -x1**2+x2**2)
    df = [
        lambda x1, x2: 4*x1**3 - 2*x1,  # df/dx1
        lambda x1, x2: 2*x2             # df/dx2
    ]
    x0 = [0.5, 1], [-0.5,-1], [0.1,0.2]
    alphas = [0.01]
    for x0 in x0:
        for a in alphas: #1 sola iterazione per cordinata in questo caso
            xk, xk_arr, iter = GD_fisso(f, df, x0, a, 8000)
            if np.any(np.isnan(xk)):
                print(f"c) GD_fisso (x0={x0}, a={a}): {xk}")
            else:
                print(f"c) Overflow, impossibile calcolare per x0={x0} e alpha={a}")
        xk, a_finale, xk_arr, iter  = GD_backtracking(f, df, x0, 0.001)
        if np.any(np.isnan(xk)):
                print(f"c) GD_backtracking (x0={x0}, a={a_finale}): {xk}")
        else:
            print(f"c) Overflow, impossibile calcolare per x0={x0}")
    print("\n")

    #esercizio d
    n = 3
    A = np.random.random((n, n))  # n * n
    xstar = np.transpose(np.ones(n)) # x*
    b = np.dot(A, xstar)
    min_x, alpha, xk_arr, iter  = OLS(A, b, 0.5, 2)
    if not np.any(np.isnan(min_x)):
        print(f"d) OLS: x*={min_x}, a={alpha}")
    else:
        print(f"d) Overflow, impossibile calcolare per x0={x0}")
    print("\n")

    #esercizio e
    A = A #teniamo la stessa matrice
    b = b #teniamo lo stesso termine noto
    reg = 0.5 #valore davanti \| x \|_2^2
    t_norma = 2 #Ridge (L2)
    min_x, alpha, xk_arr, iter  = OLS(A, b, 0.5, 2, reg, t_norma) 
    if not np.any(np.isnan(min_x)):
        print(f"e) OLS: x*={min_x}, a={alpha}, reg={reg}, norma {t_norma}")
    else:
        print(f"e) Overflow, impossibile calcolare per x0={x0}")
    print("\n")

    #esercizio f
    n = 10
    x0 = np.full(n, 0.5)  # vettore iniziale positivo con tutti i valori 0.5F
    f = lambda *x: sum((xi - i)**2 - np.log(xi) for i, xi in enumerate(x, 1))
    df = numerical_df(f, n)  # lista delle derivate
    alphas = [0.01]
    for a in alphas:
        xk, a_finale, xk_arr, iter  = GD_backtracking(f, df, x0, a)
        if not (np.isnan(xk).any()):
            print(f"f) GD_backtracking (x0=vec(0.5), a={a_finale}), xk[5]={xk[5]} (valore atteso ∼6.082207)")
        else:
            print(f"f) Overflow, impossibile calcolare per x0={x0}")
    print("\n")

    #esercizio g
    n = 10
    c= 3
    b = np.linspace(1,10, 10)
    x0 = np.full(n, 2)
    f = lambda *x: sum((xi - b[i])**2 for i, xi in enumerate(x)) \
                - c*sum(np.log(xi) for xi in x)
    df = numerical_df(f, n)  
    alphas = [0.01]
    for a in alphas:
        xk, a_finale, xk_arr, iter  = GD_backtracking(f, df, x0, a)
        if not (np.isnan(xk).any()):
            if a_finale <= 10 * np.finfo(float).eps: #controlliamo se alpha e' a precisione di macchina
                print("g) GD_backtracking non converge")
                break
            print(f"g) GD_backtracking (x0=vec(1), a={a_finale}), xk[4]={xk[4]} (valore atteso ∼4.67949472)")
        else:
            print(f"g) Overflow, impossibile calcolare per x0={x0}")
    print("\n")

    #esercizio 2
    #prendiamo (f)
    n = 10
    x0 = np.full(n, 0.5)  # vettore iniziale positivo con tutti i valori 0.5F
    f = lambda *x: sum((xi - i)**2 - np.log(xi) for i, xi in enumerate(x, 1))
    df = numerical_df(f, n)  # lista delle derivate
    alphas = [0.01]
    batch_sizes = [0, 1, 5, 7, 10]
    for b in batch_sizes:
        for a in alphas:
            xk, xk_arr, iter  = SGD_fisso(f, df, x0, a, b)
            if not (np.isnan(xk).any()):
                print(f"2) SGD_fisso (x0=vec(0.5) b={b}, xk[5]={xk[5]} (valore atteso ∼6.082207)")
            else:
                print(f"2) Overflow, impossibile calcolare per x0={x0}")
    # Valore atteso
    xk5_true = 6.082207
    # Parametri
    x0 = np.full(10, 0.5)
    alpha = 0.01
    maxit = 8000
    tol_grad = 1e-6
    tol_diff_iter = 1e-5
    batch_sizes = [1, 2, 5, 7, 10]
    errore_relativo = []
    iterazioni = []
    # Calcolo SGD per diversi batch
    for b in batch_sizes:
        xk, xk_arr, iters = SGD_fisso(
            f=None,        # sostituire con la tua funzione f
            df=df,         # lista delle derivate
            x0=x0,
            alpha=alpha,
            batch_size=b,
            maxit=maxit,
            tol_grad=tol_grad,
            tol_diff_iter=tol_diff_iter
        )
        errore = abs(xk[5] - xk5_true) / xk5_true
        errore_relativo.append(errore)
        iterazioni.append(iters)

    # 1️⃣ Errore relativo vs batch size
    plt.figure()
    plt.plot(batch_sizes, errore_relativo, marker='o')
    plt.xlabel("Dimensione batch")
    plt.ylabel("Errore relativo su xk[5]")
    plt.title("Errore relativo vs dimensione batch")
    plt.grid(True)
    plt.savefig("img/ES2.errore_relativo_vs_batch.png")
    plt.close()

    # 2️⃣ Iterazioni vs batch size
    plt.figure()
    plt.plot(batch_sizes, iterazioni, marker='o', color='orange')
    plt.xlabel("Dimensione batch")
    plt.ylabel("Numero di iterazioni")
    plt.title("Iterazioni vs dimensione batch")
    plt.grid(True)
    plt.savefig("img/ES2.iterazioni_vs_batch.png")
    plt.close()
    print("\n")





