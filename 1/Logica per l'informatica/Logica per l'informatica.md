<div class="author">Nicolò Giuliani</div>
<div class="quote">Can machines think? -AT</div>

##### Indice
- Introduzione
- Le basi
	- 1- Sintassi
	- 2 - Ordine precedenza
	- 3 - Ordine di associazione
- La tecnica del maestro di sci
	- 1 - Introduzione ∀
	- 2 - Eliminazione ∀
	- 3 - Introduzione implicazione ⇒
	- 3.1 - Introduzione implicazione (variante) ⇒
	- 4 - Eliminazione implicazione ⇒
	- 5 - Abbreviazioni
- Teoria assiomatica degli insiemi
	- 1 - Teoria degli insiemi naive
		- Paradosso di Russell
	- 1.5 - Preliminari
	- 2.0 - Zermelo-Fraenkel Set Theory
		- Assioma di estensionalità
			- Definizione di essere sottoinsieme
			- Enunciati e prove
			-  Riflessività del  ⊆
		- Assioma di separazione
		- Assioma dell’insieme vuoto
			- Definizione di intersezione binaria
			- Definizione di intersezione
		- Assioma dell’unione


## INTRODUZIONE
Cos’e la logica? Una disciplina molto ampia con contributi e applicazioni in filosofia, matematica ed informatica. Per cercare di capire la correttezza di un ragionamento abbia bisogno di apprendere le dimostrazioni. Una dimostrazione può essere definita come sequenza di frasi che convincono il lettore che l’_enunciato_ (tesi) valga. 
Ma allora di cosa ci parla la logica? La logica ci parla di "cose" vere, ovvero degli _statement_
che valgono. Le key principali sono tre: correttezza, completezza delle regole e completezza delle ipotesi. Se si invertono questi tre concetti troviamo cosa non potremo mai sapere e il suo perché.
Per comprendere al meglio lo studio della logica usando la matematica e l'informatica dovremo basarci su una _meta-logica_, ovvero una logica che ne spiega un'altra.

## Le basi
Per confermare l'enunciato abbiamo bisogno di frasi che confermino la tesi, queste sono le _proposizioni_ ovvero frasi o vere o false che fungono da prova. Se la proposizione si conferma veritiera diventa un _Teorema_, questi possono essere categorizzanti in _lemma_, ovvero teoremi che servono a confermare un altro teorema, e _corollari_, ovvero teoremi più semplici che derivano da più complessi.
Quindi la conclusione è l'enunciato che stiamo dimostrando, mentre una premessa è l'enunciato che assumiamo già dimostrato o supposto.
I predicati possono avere valore o non avere valore, possono assumere forme differenti come: f(n)=4; 2<=x; 5 è pari; ecc.

#### 1) Sintassi
- T (Vero)
- ⊥ (Falso)
- ¬ (Negazione)
	- Esempio: 
		_¬(¬A) ⇔ A_ (è Vero)
		_x≠y  ⇔  ¬(x=y)_ (è Vero)
- ∧ (Congiunzione)
- ∨ (Disgiunzione)
- ⇒ (Implicazione)
	- Esempio: 
		_x=2  ⇒  x^2=4_ (è Vero)
		_x^2=4   ⇒  x=2_ (Falso, perché potrebbe essere x=-2)
- ⇔(Coimplicazione)
	- Esempio: 
		_x+5 = y+2  ⇔  x+ 3= y_ (è Vero)
- ∀ (Quantificatore universale)
	- Esempio:
		_∀n ∈ ℕ: n^2 ≥ n_ (è Vero)
- ∃ (Quantificatore esistenziale)
	- Esempio:
		_∃n ∈ ℕ : n è un numero naturale_ (è Vero)

#### 2) Ordine precedenza
Lo standard che seguiremo è il seguente:
¬ (Negazione) > ∧ (Congiunzione) > ∨ (Disgiunzione) > ⇒ (Implicazione)/⇔(Coimplicazione)

#### 3) Ordine di associazione
I seguenti connettori sono associativi a destra:
∧ (Congiunzione); ∨ (Disgiunzione);  ⇒ (Implicazione); ⇔(Coimplicazione); 

## La tecnica del maestro di sci
Le _dimostrazioni_ saranno oggetto di studio rigorosamente regolate da un linguaggio artificiale: le _prove informali_ sono approssimazioni meno verbose di quelle rigorose, con dettagli mancanti, a volte errate. Per studiarle logica useremo _meta-dimostrazioni_ informali nella meta-logica.

#### 1) Introduzione ∀
Per dimostrare _∀x.P(x)_ utilizzeremo sia: **x** (un insieme) **fissato; _prova di P(x)_*.

#### 2) Eliminazione ∀
Da un’ipotesi o un risultato intermedio _∀x.P(x)_ potete concludere che P valga per ciò che volete, tipo **P(3 + y)**.

#### 3) Introduzione implicazione ⇒
Per dimostrare P ⇒ Q: **“Assumo P (H).  _prova di Q_**"

#### 3.1) Introduzione implicazione ⇒
Da un’ipotesi o un risultato intermedio P ⇒ Q di nome H, se volete concludere Q, si può procedere: “_per H, per dimostrare Q mi posso ridurre a dimostrare P_”

#### 4) Eliminazione implicazione ⇒
Da un’ipotesi o un risultato intermedio P ⇒ Q e da un’ipotesi o un risultato intermedio P potete concludere che Q vale.

#### 5) Abbreviazioni
si può abbreviare "_sia x (un insieme) fissato; assumo P(x); . . ._" con "_“sia x tale che P(x)_; . . . _"


## Teoria assiomatica degli insiemi
Cosa è un insieme? Tutto. Gli insiemi contengono insiemi. La teoria è il  linguaggio macchina della matematica moderna: numeri, figure geometriche, funzioni, vengono descritti (implementati) come insiemi particolari; questo ci permette di capire a pieno il significato di infinto.
#### 1) Teoria degli insiemi naive
Si possono formare insiemi in qualunque modo si pensi, non devo essere _omogeni_ perché essi sono un mix di tutto. La sintassi è composta sono da ∈ (_Appartenenza_) e = (_Uguaglianza_).
Gli insiemi erano visti come scatole, se uno ne apre una vedo al suo interno gli elementi.
Se ho una scatola dentro un'altra quando andrò ad aprire la prima troverò al suo interno la seconda scatola e non gli elementi della seconda scatola.
- 1 ∈ {1, 2, 3} 
- {1, 2} ∉ {1, 2, 3} 
- 1∉ {{1, 2}, 3} 
- {1, 2} ∈ {{1, 2}, 3} 
- ∅ ∉ {1, 2, 3} 
- ∅ ∈ {∅, 1}
Quindi o vedi il singolo elemento o vedi una scatola, se questa non è identica a quella di riferimento queste non saranno uguali.

Dal punto di vista insiemistico se A è un sottoinsieme di B (_A ⊆ B_) se apro la scatola B vedrò gli elementi di A e di B.
- {1, 3} ⊆ {1, 2, 3} 
- {1, 3} ̸⊆ {{1, 3}, 2} 
- 1 ̸⊆ {1, 2, 3} 
- {1} ⊆ {1, 2, 3} 
- {1} ̸⊆ 1 
- 1 ⊆ 1
<div class="medium_title">Paradosso di Russell</div>
<div class="formule"><table align="center"><tr><td>Se X = {Y | Y∉ Y}</td></tr><tr><td>X ∈ X sse X ∉ X</td></tr></table> <br>
</div>

***Analisi della Formula:***

1. **Costruzione dell'Insieme**: L'insieme X include tutti gli insiemi Y che non contengono se stessi come elementi. Questo è un modo per definire X in base a una proprietà.
    
2. **Contraddizione**: Ora consideriamo se X appartiene a se stesso:
    - Se **X∈X**: Secondo la definizione, dovrebbe essere vero che **X∉X**. Qui nasce la contraddizione.
	- Se **X∉X**: Secondo la definizione, X dovrebbe appartenere a X perché soddisfa la condizione **Y∉Y**.

#### 1.5) Preliminari
I concetti di insieme, appartenenza e uguaglianza non vengono definiti, gli insiemi sono primitivi. Attraverso gli assiomi (_proposizione vera_) affermiamo l’esistenza di alcuni insiemi a partire da altri.

#### 2) Zermelo-Fraenkel Set Theory
- Assioma di **estensionalità**
	∀X, ∀Y,(X = Y ⇐⇒ ∀Z.(Z ∈ X ⇐⇒ Z ∈ Y))
	_Due insiemi sono uguali sse hanno gli stessi elementi._

	- Definizione di essere sottoinsieme
		X ⊆ Y def == ∀Z,(Z ∈ X ⇒ Z ∈ Y)
	_X e sottoinsieme di  Y se Y possiede tutti gli elementi di X_
	
	- Enunciati e prove
	L’enunciato di un teorema e ci  o che vogliamo dimostrare. Si compone di un insieme di ipotesi e di una conclusione
	
	-  Riflessività del  **⊆**.
		- Teorema: 
			***X ⊆ X***. 
		- Dimostrazione: 
			Sia X un insieme. 
			Dobbiamo dimostrare X ⊆ X, ovvero *∀Y. Y ∈ X ⇒ Y ∈ X*. 
				Sia Y un insieme tale che Y ∈ X (as H). 
			Debbo dimostrare Y ∈ X. 
			Ovvio per l’ipotesi H. 
			Qed.
			
- Assioma di **separazione**
	Dato un insieme, possiamo formare il sottoinsieme dei suoi elementi che soddisfano una proprietà: ∀X , ∃Y , ∀Z , (Z ∈ Y ⇐⇒ Z ∈ X ∧ P(Z ))
	Indicando tale Y come {Z ∈ X | P(Z )} scriviamo:
		∀X , ∀Z , (Z ∈ {W ∈ X | P(W )} ⇐⇒ Z ∈ X ∧ P(Z ))

- Assioma dell’**insieme vuoto**: ∀Z , Z̸ ∈ ∅ ()

	 - Definizione di intersezione binaria: A ∩ B def == {X ∈ A | X ∈ B}
		Teorema:  X ∈ A ∩ B ⇐⇒ X ∈ A ∧ X ∈ B

	- Definizione di intersezione:  
		Dato un insieme di insiemi, esiste l’insieme che ne è l’intersezione. 
		∩F def == ∅ se F = ∅
		ovvero:
		∩F def == {X ∈ A | ∀Y , (Y ∈ F ⇒ X ∈ Y )} dove A ∈ F

- Assioma dell’unione
	Dato un insieme di insiemi, esiste l’insieme che ne è l’unione.
	∀F , ∃X , ∀Z , (Z ∈ X ⇐⇒ ∃Y , (Y ∈ F ∧ Z ∈ Y ))
	L’insieme X viene indicato con  UF o UF_y∈f Y.






