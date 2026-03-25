def salva_plot(f, radici, nome_file, x_range=(-5, 8)):
    x = np.linspace(x_range[0], x_range[1], 400)
    plt.figure()
    plt.axhline(0, color='k')  # linea y=0
    plt.plot(x, f(x), 'b', label='f(x)')

    # colori e label per i tre metodi
    colori = ['ro', 'go', 'yo']
    labels = ['Bisezione', 'Punto Fisso', 'Newton']

    for i, r in enumerate(radici):
        plt.plot(r, f(r), colori[i], markersize=8, label=labels[i])
        #plt.text(r, f(r)+0.05, f'{r:.4f}', ha='center', color=colori[i][0])

    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.title(nome_file)
    plt.legend()   # aggiunge la legenda
    plt.grid(True)
    plt.savefig(f"img/{nome_file}.png")
    plt.close()  # chiude la figura per non aprire finestre
def bisezione(f, a, b, ERROR_MARGIN=1e-5, k=0, iterazioni=None):
    if iterazioni is None:
        iterazioni = []

    x0 = (a + b) / 2
    iterazioni.append(x0)

    if abs(a - b) < ERROR_MARGIN:
        return x0, k, iterazioni

    if f(a) * f(b) > 0:
        print("ERRORE: i limiti non racchiudono una radice.")
        return None, None, iterazioni

    k += 1
    if f(a) * f(x0) <= 0:
        return bisezione(f, a, x0, ERROR_MARGIN, k, iterazioni)
    else:
        return bisezione(f, x0, b, ERROR_MARGIN, k, iterazioni)
def newton(f, df, x0, tol1=1e-6, tol2=1e-6, maxit=10000):
    iterazioni = [x0]
    k = 0
    while k < maxit:
        fx = f(x0)
        if abs(fx) < tol2:
            break
        dfx = df(x0)
        if dfx == 0:
            raise ValueError("Derivata nulla, non posso continuare")
        x_n = x0 - fx / dfx
        iterazioni.append(x_n)
        if abs(x_n - x0) < tol1:
            x0 = x_n
            break
        x0 = x_n
        k += 1
    return x0, k, iterazioni
def punto_fisso(g, a, b, x0=None, tol=1e-6, max_iter=100000):
    if x0 is None:
        x0 = (a + b) / 2

    x_prev = x0
    iterazioni = [x_prev]

    for i in range(max_iter):
        x_next = g(x_prev)

        if not (a <= x_next <= b):
            #print(f"PUNTO FISSO: Iterazione {i}: uscita dai limiti [{a}, {b}] con x={x_next}")
            return -1, i, iterazioni

        iterazioni.append(x_next)

        if abs(x_next - x_prev) < tol:
            return x_next, i + 1, iterazioni

        x_prev = x_next

    print("Raggiunto numero massimo di iterazioni senza convergenza.")
    return x_prev, max_iter, iterazioni



if __name__ == "__main__":
    import numpy as np
    import os
    import matplotlib.pyplot as plt
    np.seterr(over='ignore', invalid='ignore')

    def salva_plot(f, radici, nome_file, x_range=(-5, 8)):
        x = np.linspace(x_range[0], x_range[1], 400)
        plt.figure()
        plt.axhline(0, color='k')  # linea y=0
        plt.plot(x, f(x), 'b', label='f(x)')

        colori = ['ro', 'go', 'yo']
        labels = ['Bisezione', 'Punto Fisso', 'Newton']

        for i, r in enumerate(radici):
            plt.plot(r, f(r), colori[i], markersize=8, label=labels[i])

        plt.xlabel("x")
        plt.ylabel("f(x)")
        plt.title(nome_file)
        plt.legend()
        plt.grid(True)
        if not os.path.exists("img"):
            os.makedirs("img")
        plt.savefig(f"img/{nome_file}.png")
        plt.close()
    def plot_error_iterazioni(f, iter_b, iter_pf, iter_newton, nome_file):
        plt.figure()
        plt.semilogy(np.abs([f(x) for x in iter_b]), 'r-o', label='Bisezione')
        plt.semilogy(np.abs([f(x) for x in iter_pf]), 'g-o', label='Punto Fisso')
        plt.semilogy(np.abs([f(x) for x in iter_newton]), 'b-o', label='Newton')
        plt.xlabel('Iterazione k')
        plt.ylabel('|f(x_k)|')
        plt.title(nome_file + ' - Convergenza')
        plt.grid(True, which='both', ls='--')
        plt.legend()
        plt.savefig(f"img/{nome_file}_convergenza.png")
        plt.close()
    def plot_convergenza(f, iter_b, iter_pf, iter_n, nome):
        plt.figure()

        # Bisezione
        plt.semilogy(
            np.abs([f(x) for x in iter_b]),
            'r-o', label='Bisezione |f(x_k)|'
        )

        # Newton
        plt.semilogy(
            np.abs([f(x) for x in iter_n]),
            'b-o', label='Newton |f(x_k)|'
        )

        # Punto fisso (ERRORE GIUSTO)
        pf_err = [abs(iter_pf[k+1] - iter_pf[k])
                for k in range(len(iter_pf)-1)]
        plt.semilogy(
            pf_err,
            'g-o', label='Punto fisso |x_{k+1}-x_k|'
        )

        plt.xlabel("Iterazione k")
        plt.ylabel("Errore")
        plt.title(nome + " – Convergenza")
        plt.grid(True, which="both")
        plt.legend()
        plt.savefig(f"img/{nome}_convergenza.png")
        plt.close()

    # Lista di esercizi
    esercizi = [
        {
            "f": lambda x: np.log(x+1) - x*np.log(x+1),
            "g": lambda x: np.log(x+1),
            "df": lambda x: (1 - x)/(x+1) - np.log(x+1),
            "a": 0, "b": 2,
            "x0": 0.5,
            "nome": "es1"
        },
        {
            "f": lambda x: x**2 - np.cos(x)*np.sqrt(np.cos(x)),
            "g": lambda x: np.sqrt(np.cos(x)),
            "df": lambda x: 2*x + np.sin(x)*np.sqrt(np.cos(x)) + (np.cos(x)*np.sin(x))/(2*np.sqrt(np.cos(x))),
            "a": 0, "b": 1,
            "x0": 0.5,
            "nome": "es2",
            "x_range": (-1,2)
        },
        {
            "f": lambda x: np.sin(x) - x*np.sin(x),
            "g": lambda x: 2*np.sin(x),
            "df": lambda x: (1-x)*np.cos(x) - np.sin(x),
            "a": -1, "b": 1,
            "x0": 0.5,
            "nome": "es3"
        },
        {
            "f": lambda x: np.e**x - 3*x*(1/3*np.e**x),
            "g": lambda x: (1/3)*np.e**x,
            "df": lambda x: np.e**x - 3*( (1/3*np.e**x) + x*(1/3*np.e**x) ),
            "a": -1, "b": 1,
            "x0": 0.5,
            "nome": "es4"
        }
    ]

    for ex in esercizi:
        f = ex["f"]
        g = ex["g"]
        df = ex["df"]
        a = ex["a"]
        b = ex["b"]
        x0 = ex.get("x0", (a+b)/2)
        nome = ex["nome"]
        x_range = ex.get("x_range", (-5,8))

        # Bisezione
        r_b, i_b, iter_b = bisezione(f, a, b)
        # Punto fisso
        r_pf, i_pf, iter_pf = punto_fisso(g, a, b, x0=x0)
        # Newton
        r_n, i_n, iter_n = newton(f, df, x0=x0)

        print(f"{nome.upper()} BISEZIONE= {r_b:0.6f}, ITERAZIONI= {i_b}")
        print(f"{nome.upper()} PUNTO FISSO= {r_pf:0.6f}, ITERAZIONI= {i_pf}")
        print(f"{nome.upper()} NEWTON= {r_n:0.6f}, ITERAZIONI= {i_n}\n")

        salva_plot(f, [r_b, r_pf, r_n], nome, x_range=x_range)
        plot_convergenza(f, iter_b, iter_pf, iter_n, nome)

    def tabella_convergenza(
            metodo, f, df, g, a, b,
            x0_list, tol_list,
            nome_file, metodo_nome
            ):

        # La prima cella spiega cosa sono i numeri
        header = ["x0 / Iterazioni"] + [f"{tol:.0e}" for tol in tol_list]
        table_data = []

        for x0 in x0_list:
            row = [f"{x0:.2f}"]
            for tol in tol_list:
                try:
                    if metodo_nome == "Newton":
                        _, it, _ = metodo(f, df, x0, tol1=tol, tol2=tol)
                    else:  # Punto fisso
                        _, it, _ = metodo(g, a, b, x0=x0, tol=tol)
                    row.append(f"{it}")
                except:
                    row.append("FAIL")
            table_data.append(row)

        fig, ax = plt.subplots(figsize=(1.5*len(header), 0.6*len(table_data)))
        ax.axis('off')

        tabella = ax.table(
            cellText=table_data,
            colLabels=header,
            loc='center'
        )

        tabella.scale(1, 1.5)
        tabella.auto_set_font_size(False)
        tabella.set_fontsize(10)

        plt.title(f"{nome_file} – {metodo_nome}")
        plt.savefig(f"img/{nome_file}_{metodo_nome}_tabella.png", bbox_inches='tight')
        plt.close()

    # -------------------------------
    # TABELLE CONVERGENZA (ES3)
    # -------------------------------
    x0_list = [-0.5, 0.1, 0.5, 1.0]
    tol_list = [1e-3, 1e-6, 1e-9]

    tabella_convergenza(
        metodo=newton,
        f=esercizi[2]["f"],
        df=esercizi[2]["df"],
        g=None,
        a=esercizi[2]["a"],
        b=esercizi[2]["b"],
        x0_list=x0_list,
        tol_list=tol_list,
        nome_file="es3",
        metodo_nome="Newton"
    )

    tabella_convergenza(
        metodo=punto_fisso,
        f=None,
        df=None,
        g=esercizi[2]["g"],
        a=esercizi[2]["a"],
        b=esercizi[2]["b"],
        x0_list=x0_list,
        tol_list=tol_list,
        nome_file="es3",
        metodo_nome="PuntoFisso"
    )
