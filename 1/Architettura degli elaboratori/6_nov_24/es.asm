Due modi per salvare in RAM[2] la somma RAM[0]+RAM[1]
1)
D=0
@0
D=D+M
@1
D=D+M
@2
M=D

2)
@2
M=0
@0
D=M
@2
M=M+D
@1
D=M
@2
M=M+D


Altri semplici esercizi con salti.
1.        // Se RAM[0]>0, goto istruzione con indirizzo memorizzato in RAM[1]
@0
D=M       //D=RAM[0]
@1 
A=M       //A=RAM[1]
D; JGT    //if(D>0){ goto RAM[1]}

2.        // D=D+1; successivamente, se D=0 goto istruzione 3
D=D+1
@3
D; JEQ    //if(D==0){goto 3}

//o anche:
@3
D=D+1; JEQ

3.        // RAM[0] = RAM[5] e se RAM[5]<>0 goto istruzione 3
@5
D=M       //D=RAM[5]
@0
M=D       //RAM[0]=RAM[5]
@3
D; JNE



ETICHETTE
0: @2
1: D=A
(BACK) //BACK è uguale a ROM[2] quindi vale @4
2: @4
3: D=M
4: D=D+M
5: @2
6: D=D+A
7: @BACK //si può anche scrivere @2, ma con le etichette è più facile, varrà il valore @4
8: D; JGE



ES:
//C
if(D-1>0){
  comando 1
  }
else{
  comando 2
  }
comando 3

//ASM
D=D-1

@FALSE //@82 
D JLE //if D<0 goto 82

comando 1 //else

@END //@84 
0 JMP //goto 84

(FALSE) //ROM[82]
comando 2

(END) //ROM[84]
comando 3




ES CICLI:
//C
while(D>0){
  codice 1
  }
codice 2

//ASM
(LOOP)
  @EXIT
  D JLE //se D<0 goto 109
  
  codice 1

@LOOP 
0 JMP // start cicle, goto 103

(EXIT)
codice 2


Esempio: RAM[2] = RAM[0] × RAM[1]
@2      // inizializzo:
M=0     // RAM[2]=0

(LOOP)
  @0
  D=M     // D=RAM[0]
  @2
  M=D+M   // RAM[2] += D, ovvero RAM[2] += RAM[0]
  @1
  MD=M-1  // RAM[1]=RAM[1]-1 : usiamo RAM[1] come contatore dei cicli
@LOOP
D JGT   // ricomincio il ciclo se RAM[1]>0


ES:
Esercizio difficile: RAM[0..9] = [10, 9, 8,…, 1] ovvero RAM[0]=10, RAM[1]=9, ecc

//C
int length=10 
int RAM[length];
for(int i=0, i<length-1,i++){
  RAM[i]=length-i-1;
  }


//ASM

@11
M=10 //...M=9

@12
M=0 //...M=1

(LOOP)
  @11
  D=M //D=10...

  @12
  A=M //A=0
  M=D //RAM[0]=10
  
  @12
  M=M+1 //M=1
  
  @11
  M=D-1 // M=9

  @11
  D=M //D=9...D=0

  @LOOP
  D, JEQ  //if D==0 goto 148
  



