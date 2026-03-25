// Initialization
@256
D=A
@SP
M=D
// BasicTest
// instruction: u constant 10
@10
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: o local 0
@LCL
D=M
@0
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: u constant 21
@21
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: u constant 22
@22
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: o argument 2
@ARG
D=M
@2
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: o argument 1
@ARG
D=M
@1
D=D+A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: u constant 36
@36
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: o static 4
@BasicTest.4
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: u constant 42
@42
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: u constant 45
@45
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: o static 7
@BasicTest.7
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: o static 1
@BasicTest.1
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: u constant 510
@510
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: o static 0
@BasicTest.0
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: u local 0
@LCL
D=M
@0
A=D+A
D=M
@SP
M=M+1
A=M-1
M=D
// instruction: u static 7
@BasicTest.7
D=M
@SP
M=M+1
A=M-1
M=D
// instruction: A add 0
@SP
MD=M-1
A=D
D=M
A=A-1
M=M+D
// instruction: u argument 1
@ARG
D=M
@1
A=D+A
D=M
@SP
M=M+1
A=M-1
M=D
// instruction: A sub 0
@SP
MD=M-1
A=D
D=M
A=A-1
M=M-D
// instruction: u static 4
@BasicTest.4
D=M
@SP
M=M+1
A=M-1
M=D
// instruction: u static 4
@BasicTest.4
D=M
@SP
M=M+1
A=M-1
M=D
// instruction: A add 0
@SP
MD=M-1
A=D
D=M
A=A-1
M=M+D
// instruction: A sub 0
@SP
MD=M-1
A=D
D=M
A=A-1
M=M-D
// instruction: u static 0
@BasicTest.0
D=M
@SP
M=M+1
A=M-1
M=D
// instruction: A add 0
@SP
MD=M-1
A=D
D=M
A=A-1
M=M+D
