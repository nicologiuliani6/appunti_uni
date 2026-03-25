@i // variabile i (salvata in qualche indirizzo)
M=1 // i=1
@sum // variabile sum (come sopra)
M=0 // sum=0
(LOOP)
@i
D=M // D = i
@100
D=D-A // D = i - 100
@END
D;JGT // se (i-100) > 0 salta ad END
@i
D=M // D = i
@sum
M=D+M // sum += i
@i
M=M+1 // i++
@LOOP
0;JMP // ricomincio il ciclo
(END)
@END
0;JMP 
