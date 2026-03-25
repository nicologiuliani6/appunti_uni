m = int(input("inserisci m: "))
n = int(input ("inserisci n: "))

def prodotto(m, n):    
    prodotto = 0
    i = 0
    
    while n > 0:
        cifra_n = n % 10 #ULTIMA CIFRA DI N
        prodotto = prodotto + (m * cifra_n) * (10 ** i) #MOLTIPLICA M PER LA CIFRA IN QUESTIONE DI N E PER LA RELATIVA POSIZIONE
        n = int(n/10) #RIMUOVI L'ULTIMA CIFRA DI N
        i = i+1
    
    print("Prodotto: "+ str(prodotto))

if m > 0 and n > 0:
    prodotto(m, n)
