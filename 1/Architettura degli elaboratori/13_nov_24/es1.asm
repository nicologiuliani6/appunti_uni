@5
D=M //D=RAM[5]
@0
M=D //RAM[0]=RAM[5]

@5
D=A //D=5
@11
M=D//RAM[11]=i =5


@WHILE
@11
D=M //D=i
A=D
D=M //D=RAM[i]
A=A+1 //i++
D=M-D //D=RAM[i+1]-RAM[i]

D=A //D=i++
@11
M=D //RAM[11]=i++

@IF
D; JGT //if D>0 goto IF
//ELSE
@11
D=M //D=i
@10
D=D-A //D=i-10
@EXIT
D; JEQ //if i==0 goto EXIT
(WHILE)
0; JMP

(IF)
@11
A=M //A=i
A=A+1 //A++
D=M //D=RAM[1+i]
@0
M=D //RAM[0]=RAM[i+1]
(WHILE)
0; JMP

(EXIT)
@EXIT
0; JMP
