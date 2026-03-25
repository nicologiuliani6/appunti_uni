import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import hw2
#(a)
def a():
    #Scegliamo funzione 1)
    f = lambda x1, x2: (x1 - 5)**2 + (x2-2)**2
    df = [
        lambda x1, x2: 2 * (x1 - 5),  # df/dx1
        lambda x1, x2: 2 * (x2 - 2)   # df/dx2
    ]

    # griglia
    x1 = np.linspace(0, 10, 200)
    x2 = np.linspace(-2, 6, 200)
    X1, X2 = np.meshgrid(x1, x2)
    Z = f(X1, X2)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X1, X2, Z, cmap='viridis')

    ax.set_xlabel("x1")
    ax.set_ylabel("x2")
    ax.set_zlabel("f(x1,x2)")
    plt.title("Superficie della funzione (a)")

    plt.savefig("img/1.plot_funzione_a.png")
    plt.close()



    x0_list = [[0, 0], [1, 1], [-1, -1]]
    alphas = [0.001, 0.01, 0.05, 0.1]
    plt.figure(figsize=(10,5))
    # Grafico funzione vs iterazioni
    plt.subplot(1,2,1)
    results = []
    for x0 in x0_list:
        for a in alphas:
            xk, xk_arr, it = hw2.GD_fisso(f, df, x0, a, 4000)
            if not (np.isnan(xk[0]) or np.isnan(xk[1])):
                f_values = np.array([f(x[0], x[1]) for x in xk_arr])
                plt.plot(range(len(f_values)), f_values, marker="o", markersize=2,
                        label=f"x0={x0}, α={a}")
    plt.xlabel("Iterazioni")
    plt.ylabel("f(xk)")
    plt.title("Valore funzione vs Iterazioni")
    plt.grid(True)
    plt.legend()

    # Grafico norma gradiente vs iterazioni
    plt.subplot(1,2,2)
    for x0 in x0_list:
        for a in alphas:
            xk, xk_arr, it = hw2.GD_fisso(f, df, x0, a, 4000)
            if not (np.isnan(xk[0]) or np.isnan(xk[1])):
                grad_norms = np.array([np.linalg.norm([df[0](x[0], x[1]), df[1](x[0], x[1])]) for x in xk_arr])
                plt.plot(range(len(grad_norms)), grad_norms, marker="o", markersize=2,
                        label=f"x0={x0}, α={a}")
    plt.xlabel("Iterazioni")
    plt.ylabel("||grad f(xk)||")
    plt.title("Norma gradiente vs Iterazioni")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig("img/1.funzione_e_gradiente_vs_iter.png")

    results = []

    for x0 in x0_list:
        for a in alphas:
            xk, xk_arr, it = hw2.GD_fisso(f, df, x0, a, 4000)


            # norma gradiente finale
            grad_final = np.linalg.norm([
                df[0](xk[0], xk[1]),
                df[1](xk[0], xk[1])
            ])


            results.append({
                "x0": str(x0),
                "alpha": a,
                "iterazioni": it,
                "x_finale": f"[{xk[0]:.6f}, {xk[1]:.6f}]",
                "||grad|| finale": grad_final,
            })

    df_results = pd.DataFrame(results)

    # Salva tabella come immagine
    fig, ax = plt.subplots(figsize=(12, 4))
    ax.axis('off')
    table = ax.table(
        cellText=df_results.values,
        colLabels=df_results.columns,
        loc='center',
        cellLoc='center'
    )
    table.auto_set_font_size(False)
    table.set_fontsize(8)
    table.scale(1, 1.5)

    plt.savefig("img/1.tabella_risultati.png", dpi=300, bbox_inches='tight')
    plt.close()
def b():
    # Funzione di Rosenbrock
    f = lambda x1, x2: (1 - x1)**2 + 100*(x2 - x1**2)**2
    df = [
        lambda x1, x2: 2*(x1 - 1) - 400*x1*(x2 - x1**2),  # df/dx1
        lambda x1, x2: 200*(x2 - x1**2)                   # df/dx2
    ]

    # Griglia per il grafico 3D
    x1 = np.linspace(-2, 2, 200)
    x2 = np.linspace(-1, 3, 200)
    X1, X2 = np.meshgrid(x1, x2)
    Z = f(X1, X2)

    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X1, X2, Z, cmap='viridis')

    ax.set_xlabel("x1")
    ax.set_ylabel("x2")
    ax.set_zlabel("f(x1,x2)")
    plt.title("Superficie della funzione (b)")
    plt.savefig("img/2.plot_funzione_b.png")
    plt.close()

    # Punti iniziali e alpha
    x0_list = [[0, 2], [5, 5]]
    alphas = [0.01, 0.005, 0.001]

    plt.figure(figsize=(10,5))

    # Grafico funzione vs iterazioni
    plt.subplot(1,2,1)
    for x0 in x0_list:
        for a in alphas:
            xk, xk_arr, it = hw2.GD_fisso(f, df, x0, a, 4000)
            if not (np.isnan(xk[0]) or np.isnan(xk[1])):
                f_values = np.array([f(x[0], x[1]) for x in xk_arr])
                plt.plot(range(len(f_values)), f_values, marker="o", markersize=2,
                         label=f"x0={x0}, α={a}")
    plt.xlabel("Iterazioni")
    plt.ylabel("f(xk)")
    plt.title("Valore funzione vs Iterazioni")
    plt.grid(True)
    plt.legend()

    # Grafico norma gradiente vs iterazioni
    plt.subplot(1,2,2)
    for x0 in x0_list:
        for a in alphas:
            xk, xk_arr, it = hw2.GD_fisso(f, df, x0, a, 4000)
            if not (np.isnan(xk[0]) or np.isnan(xk[1])):
                grad_norms = np.array([np.linalg.norm([df[0](x[0], x[1]), df[1](x[0], x[1])]) for x in xk_arr])
                plt.plot(range(len(grad_norms)), grad_norms, marker="o", markersize=2,
                         label=f"x0={x0}, α={a}")
    plt.xlabel("Iterazioni")
    plt.ylabel("||grad f(xk)||")
    plt.title("Norma gradiente vs Iterazioni")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig("img/2.funzione_e_gradiente_vs_iter.png")

    # Preparazione tabella risultati
    results = []
    for x0 in x0_list:
        for a in alphas:
            xk, xk_arr, it = hw2.GD_fisso(f, df, x0, a, 4000)
            if not (np.isnan(xk[0]) or np.isnan(xk[1])):
                grad_final = np.linalg.norm([df[0](xk[0], xk[1]), df[1](xk[0], xk[1])])
                results.append({
                    "x0": str(x0),
                    "alpha": a,
                    "iterazioni": it,
                    "x_finale": f"[{xk[0]:.6f}, {xk[1]:.6f}]",
                    "||grad|| finale": grad_final,
                })
            else:
                results.append({
                    "x0": str(x0),
                    "alpha": a,
                    "iterazioni": it,
                    "x_finale": "NaN",
                    "||grad|| finale": np.nan,
                })

    df_results = pd.DataFrame(results)

    # Salva tabella come immagine
    fig, ax = plt.subplots(figsize=(12, 4))
    ax.axis('off')
    table = ax.table(
        cellText=df_results.values,
        colLabels=df_results.columns,
        loc='center',
        cellLoc='center'
    )
    table.auto_set_font_size(False)
    table.set_fontsize(8)
    table.scale(1, 1.5)

    plt.savefig("img/2.tabella_risultati.png", dpi=300, bbox_inches='tight')
    plt.close()
def c():
    # Esercizio d) OLS
    n = 3
    A = np.random.random((n, n))       # matrice n*n
    xstar = np.ones(n)                 # x* teorico
    b = np.dot(A, xstar)               # b = A*x*

    # Punti iniziali e alpha da testare
    x0_list = [np.zeros(n), np.ones(n), np.random.random(n)]
    alphas = [0.1, 0.5, 1.0]

    plt.figure(figsize=(10,5))

    # Grafico funzione obiettivo vs iterazioni
    plt.subplot(1,2,1)
    for x0 in x0_list:
        for a in alphas:
            xk, a, xk_arr, it = hw2.OLS(A, b, a, 2)   # usa la tua OLS con backtracking
            if not np.any(np.isnan(xk)):
                f_values = np.array([0.5 * np.linalg.norm(np.dot(A, x) - b)**2 for x in xk_arr])
                plt.plot(range(len(f_values)), f_values, marker="o", markersize=2,
                         label=f"x0={x0}, α={a}")
    plt.xlabel("Iterazioni")
    plt.ylabel("f(xk) = 1/2 ||Ax-b||^2")
    plt.title("Valore funzione obiettivo vs Iterazioni")
    plt.grid(True)
    plt.legend()

    # Grafico norma residuo vs iterazioni
    plt.subplot(1,2,2)
    for x0 in x0_list:
        for a in alphas:
            xk, a, xk_arr, it = hw2.OLS(A, b, a, 2)
            if not np.any(np.isnan(xk)):
                grad_norms = np.array([np.linalg.norm(np.dot(A, x) - b) for x in xk_arr])
                plt.plot(range(len(grad_norms)), grad_norms, marker="o", markersize=2,
                         label=f"x0={x0}, α={a}")
    plt.xlabel("Iterazioni")
    plt.ylabel("||Ax-b||")
    plt.title("Norma residuo vs Iterazioni")
    plt.grid(True)
    plt.legend()

    plt.tight_layout()
    plt.savefig("img/3.OLS_funzione_e_residuo_vs_iter.png")

    # Preparazione tabella risultati finali
    results = []
    for x0 in x0_list:
        for a in alphas:
            xk, a, xk_arr, it = hw2.OLS(A, b, a, 2)
            if not np.any(np.isnan(xk)):
                residuo_finale = np.linalg.norm(np.dot(A, xk) - b)
                results.append({
                    "x0": str(x0.round(3)),
                    "alpha": a,
                    "iterazioni": it,
                    "x_finale": str(np.round(xk,6)),
                    "||residuo|| finale": residuo_finale
                })
            else:
                results.append({
                    "x0": str(x0.round(3)),
                    "alpha": a,
                    "iterazioni": it,
                    "x_finale": "NaN",
                    "||residuo|| finale": np.nan
                })

    df_results = pd.DataFrame(results)

    # Salva tabella come immagine
    fig, ax = plt.subplots(figsize=(12, 4))
    ax.axis('off')
    table = ax.table(
        cellText=df_results.values,
        colLabels=df_results.columns,
        loc='center',
        cellLoc='center'
    )
    table.auto_set_font_size(False)
    table.set_fontsize(8)
    table.scale(1, 1.5)
    plt.savefig("img/3.OLS_tabella_risultati.png", dpi=300, bbox_inches='tight')
    plt.close()
def d():
    # Esercizio d) GD_backtracking su funzione multimodale
    n = 10
    x0 = np.full(n, 0.5)  # vettore iniziale positivo con tutti i valori 0.5
    f = lambda *x: sum((xi - i)**2 - np.log(xi) for i, xi in enumerate(x, 1))
    df = hw2.numerical_df(f, n)  # lista delle derivate
    alphas = [0.01]

    plt.figure(figsize=(10,5))

    # Grafico funzione obiettivo vs iterazioni
    plt.subplot(1,2,1)
    for a in alphas:
        xk, a_finale, xk_arr, it = hw2.GD_backtracking(f, df, x0, a)
        if not np.isnan(xk).any():
            f_values = np.array([f(*x) for x in xk_arr])
            plt.plot(range(len(f_values)), f_values, marker="o", markersize=2,
                     label=f"x0={x0}, α={a_finale}")
    plt.xlabel("Iterazioni")
    plt.ylabel("f(xk)")
    plt.title("Valore funzione obiettivo vs Iterazioni")
    plt.grid(True)
    plt.legend()

    # Grafico norma del gradiente vs iterazioni
    plt.subplot(1,2,2)
    for a in alphas:
        xk, a_finale, xk_arr, it = hw2.GD_backtracking(f, df, x0, a)
        if not np.isnan(xk).any():
            grad_norms = np.array([np.linalg.norm([g(*x) for g in df]) for x in xk_arr])
            plt.plot(range(len(grad_norms)), grad_norms, marker="o", markersize=2,
                     label=f"x0={x0}, α={a_finale}")
    plt.xlabel("Iterazioni")
    plt.ylabel("||gradiente||")
    plt.title("Norma gradiente vs Iterazioni")
    plt.grid(True)
    plt.legend()

    plt.tight_layout()
    plt.savefig("img/4.funzione_e_gradiente_vs_iter.png")

    # Preparazione tabella risultati finali
    results = []
    for a in alphas:
        xk, a_finale, xk_arr, it = hw2.GD_backtracking(f, df, x0, a)
        if not np.isnan(xk).any():
            grad_norm_finale = np.linalg.norm([g(*xk) for g in df])
            # Aggiungi una riga per ogni elemento di x0 e xk
            for i in range(len(x0)):
                results.append({
                    "indice": i,
                    "x0": x0[i],
                    "alpha": a_finale,
                    "iterazioni": it,
                    "x_finale": round(xk[i],6),
                    "||gradiente|| finale": grad_norm_finale
                })
        else:
            for i in range(len(x0)):
                results.append({
                    "indice": i,
                    "x0": x0[i],
                    "alpha": a_finale,
                    "iterazioni": it,
                    "x_finale": "NaN",
                    "||gradiente|| finale": np.nan
                })



    df_results = pd.DataFrame(results)

    # Salva tabella come immagine
    fig, ax = plt.subplots(figsize=(12, 4))
    ax.axis('off')
    table = ax.table(
        cellText=df_results.values,
        colLabels=df_results.columns,
        loc='center',
        cellLoc='center'
    )
    table.auto_set_font_size(False)
    table.set_fontsize(8)
    table.scale(1, 1.5)
    plt.savefig("img/4.tabella_risultati.png", dpi=300, bbox_inches='tight')
    plt.close()

#a()
#b()
#c()
d()
