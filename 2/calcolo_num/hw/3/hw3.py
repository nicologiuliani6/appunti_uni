import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.metrics import mean_squared_error, r2_score


def genera_dati(n, d, coeff, sigma):
    x = np.linspace(0, 1, n)
    e = np.random.normal(loc=0, scale=sigma, size=n)
    y = sum(coeff[k] * x**k for k in range(d+1)) + e
    return x, y

def LSQ_with_SVD(X, y):
    U, s, Vt = np.linalg.svd(X, full_matrices=False)
    V = Vt.T
    r = len(s)
    xstar = np.zeros(V.shape[1])
    for i in range(r):
        xstar += (np.dot(U[:, i], y) / s[i]) * V[:, i]
    return xstar

if __name__ == "__main__":
    #esercizio 1
    #Generazione del dataset 
    d_true = 3
    a_true = np.array([1.0, -2.0, 3.0, 0.5])
    sigma = 0.1
    configs = [
        (5, [1, 2, 4]),      
        (15, [1, 3, 6]),     
        (50, [3, 5, 8])      
    ]
    plt.figure(figsize=(12, 6))
    for idx, (n_points, degrees) in enumerate(configs):
        x, y = genera_dati(n_points, d_true, a_true, sigma)
        plt.subplot(1, len(configs), idx+1)
        plt.scatter(x, y, color='red', label='dati rumorosi')
        
        x_dense = np.linspace(0, 1, 200)
        for d_fit in degrees:
            X_fit = np.vander(x, N=d_fit+1, increasing=True)
            coeffs = LSQ_with_SVD(X_fit, y)
            y_fit = np.dot(np.vander(x_dense, N=d_fit+1, increasing=True), coeffs)
            plt.plot(x_dense, y_fit, label=f'grado {d_fit}')
        
        plt.title(f'n={n_points} punti')
        plt.xlabel('x')
        plt.ylabel('y')
        plt.legend()
    plt.tight_layout()
    plt.savefig('img/fit_polynomial.png', dpi=300)
    plt.close() 

    #esercizio 2
    # carica CSV
    df = pd.read_csv('vento.csv')
    df_subset = df.iloc[:20]  # primi 20 giorni
    x = np.arange(len(df_subset), dtype=np.float64)
    y = df_subset['Velocità media (m/s)'].values.astype(np.float64)
    # gradi dei polinomi da testare
    x_norm = (x - x.min()) / (x.max() - x.min())
    x_dense_norm = np.linspace(0, 1, 200)  # per il grafico liscio


    degrees = [1, 2, 3, 4, 5, 6]
    colors = ['blue', 'green', 'orange', 'purple', 'brown', 'cyan']

    plt.figure(figsize=(10,6))
    plt.scatter(x, y, color='red', label='dati')

    for i, d in enumerate(degrees):
        # costruisci Vandermonde sul x normalizzato
        X_fit = np.vander(x_norm, N=d+1, increasing=True)
        coeffs = LSQ_with_SVD(X_fit, y)
        #print(coeffs)
        # predizioni sul grafico liscio
        y_fit = np.dot(np.vander(x_dense_norm, N=d+1, increasing=True), coeffs)
        plt.plot(np.linspace(x.min(), x.max(), 200), y_fit, 
                label=f'grado {d}', color=colors[i], linewidth=2)

    plt.xlabel('Giorno (indice)')
    plt.ylabel('Velocità media (m/s)')
    plt.title('Regressione polinomiale su vento.csv (dati normalizzati)')
    plt.legend()
    plt.tight_layout()
    plt.savefig('img/vento_fit.png', dpi=300)
    plt.close() 


    #esercizio 3
    df = pd.read_csv("train.csv")
    target_col = 'SalePrice'  
    y = df[target_col].to_numpy(dtype=np.float64)

    # prendiamo solo colonne numeriche diverse dal target
    X = df.drop(columns=[target_col]).select_dtypes(include=np.number).to_numpy(dtype=np.float64)
    feature_names = df.drop(columns=[target_col]).select_dtypes(include=np.number).columns.tolist()

    #Pulizia dati: NaN, Inf
    X = np.nan_to_num(X, nan=0.0, posinf=1e10, neginf=-1e10)
    y = np.nan_to_num(y, nan=0.0, posinf=1e10, neginf=-1e10)

    #normalizziamo X
    X_mean = X.mean(axis=0)
    X_std = X.std(axis=0)
    X_scaled = (X - X_mean) / X_std

    #LSQ su pseudoinversa
    def LSQ(X, y):
        coef = np.linalg.pinv(X) @ y
        return coef

    #funzione MSE e R2
    def evaluate_model(X, y, coef):
        y_pred = X @ coef
        mse = np.mean((y - y_pred)**2)
        r2 = 1 - mse / np.var(y)
        #Errore quadratico medio 
        return mse, r2

    coef_full = LSQ(X_scaled, y)
    mse_full, r2_full = evaluate_model(X_scaled, y, coef_full)
    print("Tutte le feature:")
    print("MSE:", mse_full, "R2:", r2_full)
    print("Coefficienti:", coef_full)

    # eliminazione a turno delle feature per valutarne l'importanza
    n_features = X_scaled.shape[1]

    r2_drop = []
    for i in range(n_features):
        X_test = np.delete(X_scaled, i, axis=1)
        coef = LSQ(X_test, y)
        mse, r2 = evaluate_model(X_test, y, coef)
        r2_drop.append(r2)

    # calcolo "impatto" delle feature come differenza R2 completa - R2 senza feature
    r2_impact = r2_full - np.array(r2_drop)

    # Grafico
    plt.figure(figsize=(12,6))
    plt.barh(feature_names, r2_impact, color='skyblue')
    plt.xlabel("Riduzione di R² togliendo la feature")
    plt.title("Importanza delle feature sul modello di regressione")
    plt.gca().invert_yaxis()  
    plt.tight_layout()
    plt.savefig("img/ES2.reg_lin_mult.png")
    plt.close()
