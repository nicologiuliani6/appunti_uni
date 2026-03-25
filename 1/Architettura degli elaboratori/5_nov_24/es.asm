Esercizio: per ciascuno dei seguenti semplici “programmi” scritti in pseudocodice
qui sotto, scrivere un possibile programma in Assembly Hack corrispondente.
1. // D=0
D=0

2. // A=0
@0

3. // A=1
   // D=1
@1
D=A

4. // D=3
@3
D=A

5. // D=RAM[3]+3
@3
D=M
D=D+A

6. // D=3+4
@3
D=A
@4
D=D+A

7. // RAM[3]=7
@7
D=A
@3
M=D




ES 2
1. // D=D-1
D=D-1

2. // D=D-3
@-3
D=D-A
3. // D=10-RAM[5]
@10
D=A
@5
D=D-M

4. // RAM[0]=RAM[0]+1
@0
M=M+1

6. // D=RAM[RAM[0]]
@0
A=M
D=M
7. // RAM[RAM[0]] = RAM[0]
@0
D=M
A=M
M=D

