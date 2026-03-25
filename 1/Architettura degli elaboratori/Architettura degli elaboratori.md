<div class="author">Nicolò Giuliani</div>


##### Indice
- Introduzione
- Breve storia dei calcolatori
	- Generazione 0 - Computer meccanici
	- Generazione 1 - Computer basati su valvole
	- Generazione 3 - Computer basati su circuiti integrati
	- Generazione 4 - Computer basati su VSLI
	- Generazione 5 - Computer ubiqui e invisibili
- Struttura dei calcolatori
	- Bus oriented
	- CPU
		- Componenti del processore
	- Esecuzione di una tipica istruzione
	- Ciclo di clock
	- Parallelismi
		- Pipelining
		- Multicore
		- Array computer
		- Multiprocessori
		- Multicomputer
	- //continuare//
 - Porte logiche e circuiti combinatori
	 - Algebra di Boole
	 - Proprietà dell’algebra di Boole
	 - Funzione booleana
		 - Tabella di verità
		 - Mintermini
	- Array logico programmabili
	- Transistor
	- Porte logiche
	- Mappa di Karnaugh
	- Creazione 
		- AND
 

## INTRODUZIONE
L’architettura degli elaboratori consiste nello studio della progettazione delle parti di un computer visibili ai programmatori.

## Breve storia dei calcolatori
All’inizio capire come far svolgere cose, dopo riuscire a ridurre i tempi, aumentare l’efficienza e il costo.

#### Generazione 0 - Computer meccanici

1642 - Computer Pascalina, macchina per i calcoli matematici di tipo somma e sottrazione.
1672 - nuova macchina che includeva anche le moltiplicazioni e divisioni

#### Generazione 1 - Computer basati su valvole

Architettura di Von Neumann, sulla quale si baseranno quasi tutti gli elaboratori che verranno utilizzati in seguito

![[Pasted image 20240928164140.png]]

#### Generazione 2 - Computer basati su transistor
Creazione delle prime macchine parallele con diverse unità funzionali preposte a compiti diversi.

#### Generazione 3 - Computer basati su circuiti integrati
Utilizzo della multiprogrammazione: mentre si aspetta l’input/output di un programma se ne può eseguire un altro. 
Utilizzo della microprogrammazione per emulare dei modelli precedenti di pc (utilizzato da IBM per i suoi computer)

#### Generazione 4 - Computer basati su VSLI
VSLI (Very Large Scale Integration): possibilità di inserire una grande mole di transistor in un unico chip.
L'evoluzione secondo la legge di Moore indica un aumento di transistor del 60% ogni anno, questo evidenzia un aumento esponenziale.

#### Generazione 5 - Computer ubiqui e invisibili
Computer ubiqui: dispositivi economici ma con una grande potenza di calcolo (smartphone, tablet ecc.). 
Computer invisibili: dispositivi conosciuti per le loro funzionalità piuttosto che per le loro architetture di calcolo.

## Struttura dei calcolatori
Un calcolatore è un sistema composto da processori, memorie e dispositivi di input/output (I/O).
L'organizzazione è basata sul modello di Von Neumann con la sola differenza del bus.

#### Bus oriented
Un bus è un insieme di connessioni elettriche (fili) parallele utilizzati per trasportare informazioni da un componente all’altro
![[Pasted image 20240928164206.png]]

#### CPU
La CPU (Central Processing Unit) è il componente di un elaboratore in grado di leggere ed eseguire le istruzioni dei programmi presenti nella memoria centrale

##### Componenti del processore
**ALU** (_Arithmetic Logic Unit_): esegue le istruzioni decodificate dalla CU (_AND, OR, addizione, ecc._)

**CU** (_Control Unit_): legge e interpreta le istruzioni per farle eseguire alla ALU.

**Registri**: memorizzano le informazioni necessarie al funzionamento e i risultati temporanei.

<table align=center>
<tr>
<td>PC (Program Counter)</td>
<td>Indica la prossima istruzione in memoria</td>
</tr>
<tr>
<td>IR (Instruction Register)</td>
<td>Memorizza l’istruzione che si sta per eseguire</td>
</tr>
<tr>
<td>MAR (Memory Address Register) </td>
<td>Indirizzo della prossima cella di memoria da utilizzare nella prossimo lettura/scrittura</td>
</tr>
<tr>
<td>MDR (Memory Data Register)</td>
<td>Registro che contiene i dati che devono essere scritti o letti in memoria principale</td>
</tr>
<tr>
<td>PSW (Program Status Word)</td>
<td>Contiene informazioni di vario genere sull’ultima operazione eseguita, in questo modo consente una corretta esecuzione del programma in quanto permette al processore di prendere decisioni su come eseguire le istruzioni</td>
</tr>
</table>


#### Esecuzione di una tipica istruzione
Tipicamente la CPU opera tramite un ciclo di esecuzione chiamato **Fetch** - **Decode** - **Execute** (*FDE*):
- Fetch: Caricamento 
	1. Contenuto di PC posto su MAR e attivazione della linea Leggi. 
	2. Il contenuto in memoria all’indirizzo indicato da MAR viene scritto su MDR attraverso il bus dati. 
- Decode: Decodifica
	3. Il contenuto di MDR viene copiato in IR e decodificato.
- Execute: Esecuzione
	4.  L’istruzione passa in esecuzione nella ALU. 
	5. Se ci sono operandi da prelevare in memoria, si collocano in registri tramite MAR e MDR al fine di velocizzare l’acceso al loro valore. 
	6. Terminata l’esecuzione il risultato va su registro destinazione; se occorre salvarlo in memoria vengono utilizzati MAR e MDR. 
	7. Viene aggiornato il valore di PC e si ritorna al punto 1.

#### Ciclo di clock
Il ciclo di clock indica l’intervallo temporale tra due clock consecutivi, ovvero tra l’esecuzione di due distinte operazioni, è dunque fondamentale fare in modo che non vengano iniziate operazioni prima che quelle precedenti finiscano.
Il processo che prevede il flusso di dati dai registri alla ALU, l’esecuzione delle operazioni e la riscrittura del risultato nei registri viene chiamato _ciclo di data path_, il quale viene governato dal ciclo di clock.

#### Parallelismi
- Pipelining
	Tramite il pipelining è possibile aumentare le prestazioni di un processore utilizzando diverse sezioni della CPU per effettuare contemporaneamente più cicli FDE.
	
- Multicore
	 All’interno della stessa CPU vengono replicate CU e ALU al fine di eseguire operazioni in parallelo.
	
- Array computer
	All’interno della stessa CPU vengono replicate ALU e memorie al fine di eseguire la stessa operazione in parallelo su dati diversi (Es. modifica di una foto: su ogni pixel deve essere eseguita la stessa operazione). La CU invece viene condivisa.
	
- Multiprocessori
	Più CPU condividono la stessa memoria, senza eseguire necessariamente la stessa operazione.
	
- Multicomputer
	Più CPU che non condividono la stessa memoria e che comunicano tramite dei messaggi; rappresenta la forma più estrema di parallelismo
	![[Pasted image 20240928170859.png]]
	

#### Porte logiche e circuiti combinatori
![[Pasted image 20240928171200.png]]
##### Algebra di Boole
L’algebra di Boole definisce un’aritmetica tra i due valori binari 0 e 1, utilizzati dall’elaboratore. 
Gli operatori base di tale algebra sono 3: 
*Addizione* ( oppure **OR**) 
*Moltiplicazione* ( oppure **AND**) 
*Negazione* ( oppure **NOT**)

##### Proprietà dell’algebra di Boole
![[Pasted image 20240928171352.png]]
**RICORDA!**
- le leggi di De Morgan valgono anche su più di 2 variabili.
- le leggi da ricordare sono le 2 leggi distributive e le 2 leggi di De Morgan, in quanto le altre si ricavano da queste

##### Funzione booleana
Una funzione booleana associa a delle variabili booleane in input un valore booleano in output.

- **Tabella di verità**
	Le funzioni booleane possono essere descritte in modo completo tramite una tabella di verità, la quale mostra tutte le combinazioni booleane tra le variabili e i rispettivi output.
	![[Pasted image 20240928171932.png]]

- **Mintermini**
	Un mintermine su n variabili corrisponde ad un AND logico tra n letterali corrispondenti alle n variabili. 
	I mintermini sono le combinazioni dei valori delle variabili che forniscono come risultato 1
	![[Pasted image 20240928172148.png]]

- **Forma canonica**
	Ogni funzione booleana può essere descritta tramite una funzione creata con il solo utilizzo degli operatori base (AND, OR e NOT). 
	In particolare esiste una funzione detta canonica la quale è molto facile da trovare partendo dalla tabella di verità ma non sempre corrisponde alla forma minima. 
	Per costruirla occorre trovare i mintermini della funzione nei casi in cui essa assume valore 1 ed effettuare l’operazione OR tra di loro
	![[Pasted image 20240928172440.png]]
##### Array logico programmabili
Siccome tutte le funzioni booleane si possono definire tramite una forma canonica vista in precedenza, è possibile realizzare ogni tipo di circuito avente n input tramite un array logico programmabile, il quale prevede porte AND per tutte le possibili combinazioni degli n input, e una porta OR finale tra gli output di tutti i mintermini.
![[Pasted image 20240928173204.png]]

##### Transistor
Un transistor rappresenta un componente elettronico alla base delle architetture di ogni elaboratore in quanto permette di creare porte logiche. Esso è composto da 3 connessioni: base (dove viene dato il valore di input), collettore e emettitore e funziona in questo modo:
- Se non c’è tensione sulla base, si comporta come una resistenza infinita tra collettore e emettitore.
- Se c’è tensione sulla base, si comporta da conduttore ideale tra collettore e emettitore.

_NOT con transistor_
- Se non viene fornita tensione a V_in (input = 0), allora la tensione V_cc (1) viene trasmessa a V_out (output = 1).
- Se viene fornita tensione a V_in (input = 0), allora la tensione V_cc (1) passa dal collettore all’emettitore e viene trasmessa a terra, e non ci sarà tensione su V_out (output = 0).


![[Pasted image 20240928173810.png]]
_NAND con transistor_
- La tensione va a terra (0) solo se a entrambe le basi (V_1 e V_2) viene data tensione, altrimenti V_cc (1) viene trasmessa in output a V_out.
![[Pasted image 20240928173957.png]]

##### Porte logiche
È possibile implementare circuiti tramite l’utilizzo di porte logiche. Noi utilizzeremo la porta NAND per rappresentare ogni tipo di circuito.

![[Pasted image 20240928174414.png]]



##### Mappa di Karnaugh
Le funzioni, dette minimali, sono realizzabili tramite la creazione preventiva di una tabella bidimensionale simile alla tabella di verità, chiamata mappa di Karnaugh. Essa è realizzabile nel seguente modo:
1. Creare una tabella bidimensionale il quale numero di righe e colonne è 2^n, con n il numero di letterali presenti nella riga o nella colonna. Quali letterali vanno inseriti nelle righe e nelle colonne della mappa non ha importanza, basta che il successivo riempimento della mappa con gli 0 e gli 1 venga fatto nella maniera corretta rispettando la tabella di verità.
2. Scrivere a lato di ogni riga e colonna ogni possibile combinazione dei letterali seguendo il codice gray, il quale permette di realizzare una tabella in cui due celle adiacenti differiscono per un solo letterale.
3. Riempire la tabella inserendo 0 e 1 a seconda delle combinazioni dei letterali
![[Pasted image 20240928174949.png]]
###### Come ricavare la formula minimale dalla mappa di Karnaugh?
All’interno della mappa di Karnaugh appaiono gruppi adiacenti di 1 formati dagli stessi letterali. Per ricavare la formula minimale occorre individuare questi gruppi rispettando alcune regole: 
1. Tutte le celle dei raggruppamenti contengono 1 
2. Il numero di celle in un raggruppamento deve essere in potenza di 2 (1, 2, 4 …) 
3. I raggruppamenti non devono essere potenzialmente inclusi in raggruppamenti più grandi (altrimenti si otterrebbe una formula corretta ma non minimale) 
4. I raggruppamenti possono essere fatti anche continuando oltre la fine della mappa (effetto pacman). 
A questo punto occorre considerare l’OR tra i mintermini costituiti dai letterali che formano il raggruppamento, come nell’esempio.
![[Pasted image 20240928175141.png]]


#### Creazione
##### AND
![[Pasted image 20241004172557.png]]
<table align=center><tr><td>And.hdl</td><td>And.tst</td></tr>
<tr><td>CHIP And 
{
IN a, b; 
OUT out; 
// implementation missing 
}</td><td>load And.hdl, 
output-file And.out, 
compare-to And.cmp, 
output-list a b out; 
set a 0, set b 0, eval, output;
set a 0, set b 1, eval, output; 
set a 1, set b 0, eval, output; 
set a 1, set b 1, eval, output;
</td></tr></table>

