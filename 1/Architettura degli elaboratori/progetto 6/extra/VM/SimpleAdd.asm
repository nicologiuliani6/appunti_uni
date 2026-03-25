// Initialization
@256
D=A
@SP
M=D
// PUSH CONSTANT 7
@7
D=A
@SP
M=M+1
A=M-1
M=D
// PUSH CONSTANT 8
@8
D=A
@SP
M=M+1
A=M-1
M=D
// ADD
@SP
MD=M-1
A=D
D=M
A=A-1
M=M+D
