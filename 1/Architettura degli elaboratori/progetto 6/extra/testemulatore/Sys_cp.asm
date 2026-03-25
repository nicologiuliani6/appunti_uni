// Initialization
@256
D=A
@SP
M=D
// ../testemulatore/Sys
// instruction: F Sys.init 0
(Sys.init)
0
// instruction: u constant 7
@7
D=A
@SP
M=M+1
A=M-1
M=D
// instruction: C Miocodice.test 1
@$0
D=A
@SP
M=M+1
A=M-1
M=D
@LCL
D=M
@SP
M=M+1
A=M-1
M=D
@ARG
D=M
@SP
M=M+1
A=M-1
M=D
@THIS
D=M
@SP
M=M+1
A=M-1
M=D
@THAT
D=M
@SP
M=M+1
A=M-1
M=D
@SP
D=M
@6
D=D-A
@ARG
M=D
@SP
D=M
@LCL
M=D
@Miocodice.test
0;JMP
($0)
0
// instruction: o static 0
@../testemulatore/Sys.0
D=A
@R13
M=D
@SP
AM=M-1
D=M
@R13
A=M
M=D
// instruction: L END 0
(Sys.init$END)
// instruction: G END 0
@Sys.init$END
0;JMP
