import calcolo_min_grad_multi

if __name__ == "__main__":
    #es 1
    f = lambda x1, x2 : (x1 - 5)**2 + (x2 -2)**2
    df1 = lambda x1, x2: 2*x1 - 10 + 0
    df2 = lambda x1, x2: 0 + 2*x2 - 4
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, 1, 1)
    print(f"1) Metodo del gradiente iterativo: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_error(f, df1, df2, 1, 1)
    print(f"1) Metodo del gradiente errore backtracking: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    print("\n")
    #es2
    f = lambda x1, x2 : (1 - x1)**2 + 100 * (x2 - (x1)**2 )**2
    df1 = lambda x1, x2: -2*(1 - x1) - 400*x1*(x2 - x1**2)
    df2 = lambda x1, x2: 200*(x2 - x1**2)
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, 2, 2, 0.01)
    print(f"2) Metodo del gradiente iterativo alpha={0.01}: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, 2, 2, 0.005)
    print(f"2) Metodo del gradiente iterativo alpha={0.005}: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, 2, 2, 0.001)
    print(f"2) Metodo del gradiente iterativo alpha={0.001}: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_error(f, df1, df2, 2, 2)
    print(f"2) Metodo del gradiente errore backtracking: ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    print("\n")
    
    #es3
    f = lambda x1, x2 : x1**4 - x1**2 + x2**2
    df1 = lambda x1, x2: 4*x1**3 - 2*x1 
    df2 = lambda x1, x2: 2*x2
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, 0.5, 1)
    print(f"3) Metodo del gradiente iterativo con iniziale (0.5, 1): ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, -0.5, -1)
    print(f"3) Metodo del gradiente iterativo con iniziale (-0.5, -1): ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_iter(f, df1, df2, 0.1, 0.2)
    print(f"3) Metodo del gradiente iterativo con iniziale (0.1, 0.2): ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_error(f, df1, df2, 0.5, 1)
    print(f"3) Metodo del gradiente errore backtracking con iniziale (0.5, 1): ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_error(f, df1, df2, -0.5, -1)
    print(f"3) Metodo del gradiente errore backtracking con iniziale (-0.5, -1): ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    sol = calcolo_min_grad_multi.gradiente_error(f, df1, df2, 0.1, 0.2)
    print(f"3) Metodo del gradiente errore backtracking con iniziale (0.1, 0.2): ({sol[0]}, {sol[1]}). Iterazioni: {sol[2]}")
    print("\n")

    #es4
