//Esercizio: RAM[2] = max(RAM[0],RAM[1])
@0
D=M //D=RAM[0]
@1
D=D-M //D=RAM[0]-RAM[1]
@ELSE //else if: RAM[0]<RAM[1]
D; JLE //goto 13
//if RAM[0]>=RAM[1]
@0
D=M
@max
M=D

(ELSE)
@1
D=M //D=RAM[1]
@max
M=D
@EXIT
0; JMP

(EXIT)
@max
D=M
@2
M=D //RAM[2]=max(RAM[0],RAM[1])

(END)
//loop end
@END
0; JMP














