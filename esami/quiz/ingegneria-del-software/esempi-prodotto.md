---
titolo: Esempi di domande · chiuse sul prodotto
durata: 0
fonte: "Esempi di domande di ingegneria del software" (Ciancarini, Giannone, Succi, rev. 14/09/2025), §3. Risposte ufficiali del documento; spiegazioni di Claude.
---

## [mcq 1] Il decorator in Python
- [ ] implementa nel linguaggio il design pattern del decorator.
- [ ] permette la decorazione del codice con commenti necessari alla auto-documentazione.
- [x] è una funzione di ordine superiore.
- [ ] definisce l'interfaccia con il C++.

### Soluzione
`@d` sopra `def f` equivale a `f = d(f)`: un decorator è una funzione che prende una funzione e ne restituisce un'altra (ordine superiore). Somiglia al pattern Decorator ma non lo implementa (quello avvolge oggetti a runtime).

## [mcq 1] I template in C++
- [ ] sono una modalità corretta e completa di definire generici.
- [ ] simulano la presenza di generici tramite la definizione di puntatori a void.
- [ ] definiscono classi astratte che permettono di definire comportamenti analoghi ai generici.
- [x] producono una moltiplicazione di codice oggetto se istanziati su tipi multipli.

### Soluzione
Il compilatore genera una copia del codice per ogni tipo con cui il template è istanziato (`vector<int>`, `vector<double>`…): code bloat. I `void*` (b) sono il trucco del C.

## [mcq 1] Qual è lo scopo principale di un caso d'uso in un processo di sviluppo software?
- [ ] Descrivere come il sistema è implementato internamente.
- [ ] Fornire una rappresentazione grafica della struttura dei dati.
- [x] Rappresentare le interazioni tra gli attori e il sistema per soddisfare un obiettivo specifico.
- [ ] Valutare la performance del sistema in ambiente di produzione.

### Soluzione
Use case = scenario d'uso visto dall'esterno: attore, sistema e la sequenza di interazioni che porta a un risultato di valore. Non descrive l'implementazione.

## [mcq 1] Quale affermazione descrive meglio la specializzazione dei template in C++?
- [ ] I template sono modelli di codice precompilati da usare in fase di inclusione di header.
- [ ] I template in C++ funzionano esattamente come i generici in Java, con type erasure a runtime.
- [x] I template emulano il polimorfismo parametrico generando classi o funzioni specifiche durante la compilazione, sulla base di modelli esistenti.
- [ ] I template usano la specializzazione per creare gerarchie di classi simili all'ereditarietà in fase di esecuzione.

### Soluzione
Istanziazione/specializzazione avviene a compile time, una versione per tipo. Java invece ha un solo codice con type erasure (b descrive Java, non C++).

## [mcq 1] Una funzione virtuale in UML
- [ ] può limitare il numero di repliche di campi in una classe base.
- [x] permette l'overriding.
- [ ] permette l'overloading.
- [ ] è una forma di eredità che sembra esistere ma poi si dissolve.

### Soluzione
Virtuale = la sottoclasse può ridefinirla (overriding) e la chiamata si risolve a runtime sul tipo dinamico. (a) descrive l'ereditarietà *virtuale*, che è un'altra cosa.

## [mcq 1] Con quale strumento in C si può approssimare il polimorfismo parametrico?
- [x] Con le macro.
- [ ] Con l'inclusione.
- [ ] Con i puntatori a funzione.
- [ ] Non è mai possibile.

### Soluzione
Una macro `#define MAX(a,b) ((a)>(b)?(a):(b))` funziona con qualunque tipo: il preprocessore la espande come un "template" testuale (anche `_Generic`/`void*` aiutano, ma la risposta attesa sono le macro).

## [mcq 1] L'ereditarietà virtuale
- [ ] è la tipica forma di ereditarietà che implementa il late binding.
- [ ] è una forma di ereditarietà che non permette di istanziare oggetti della classe.
- [x] è una forma di ereditarietà che serve ad evitare la moltiplicazione di istanze della classe.
- [ ] non esiste.

### Soluzione
In C++ `class B : virtual public A`: nel diamante (D eredita da B e C, entrambe da A) D contiene una sola copia di A invece di due.

## [mcq 1] Un oggetto è
- [ ] un modello di una classe.
- [x] un'istanza di una classe.
- [ ] una classe.
- [ ] una metaclasse.

### Soluzione
La classe descrive struttura e comportamento; l'oggetto è un suo esemplare concreto, con identità e stato propri.

## [mcq 1] UML è l'acronimo per
- [ ] Universal Modeling Language.
- [x] Unified Modeling Language.
- [ ] Universal Modeling Level.
- [ ] Unified Modeling Level.

### Soluzione
*Unified*: nasce dall'unificazione dei metodi di Booch, Rumbaugh (OMT) e Jacobson (OOSE), standardizzato da OMG.

## [mcq 1] Qual è la principale differenza tra requisiti funzionali e requisiti non funzionali nel contesto dello sviluppo software?
- [ ] I requisiti funzionali descrivono come il software deve essere implementato, mentre i requisiti non funzionali descrivono cosa il software deve fare.
- [ ] I requisiti funzionali sono sempre obbligatori, mentre i requisiti non funzionali sono opzionali.
- [x] I requisiti funzionali definiscono i comportamenti e le operazioni del sistema, mentre i requisiti non funzionali specificano vincoli o caratteristiche di qualità del sistema.
- [ ] I requisiti funzionali riguardano solo l'interfaccia utente, mentre i requisiti non funzionali riguardano solo il backend del sistema.

### Soluzione
Funzionali = *cosa* fa il sistema (servizi, comportamento). Non funzionali = *come bene* lo fa: prestazioni, sicurezza, usabilità, affidabilità, vincoli.

## [mcq 1] Il late binding permette
- [ ] la definizione di modelli generici.
- [ ] la definizioni di più funzioni con nomi identici ma parametri diversi risolta durante la compilazione.
- [ ] la definizioni di più funzioni con nomi identici ma parametri diversi risolta durante l'esecuzione.
- [x] l'associazione del corpo di una funzione al suo nome durante l'esecuzione.

### Soluzione
Late (dynamic) binding: quale implementazione eseguire si decide a runtime in base al tipo dinamico dell'oggetto (metodi `virtual` in C++). (a) = template/generics, (b) = overloading.

## [mcq 1] L'overloading in Python
- [ ] dà un errore di compilazione.
- [ ] è strutturato come in C++.
- [ ] richiede una fase di preprocessamento.
- [x] è gestito tramite un decorator.

### Soluzione
Python non ha overloading nativo: ridefinire una funzione sovrascrive la precedente. Si simula con decorator come `functools.singledispatch`.

## [mcq 1] Qual è uno dei principi base di Python secondo il Zen of Python?
- [ ] La velocità è tutto.
- [ ] Complicato è meglio di complesso.
- [x] Esplicito è meglio che implicito.
- [ ] Più codice, meglio è.

### Soluzione
`import this`: "Explicit is better than implicit". L'originale dice "Complex is better than complicated" (b è invertita).

## [mcq 1] Quale tra questi NON è un paradigma supportato da Python?
- [ ] Scripting.
- [x] Logico.
- [ ] Imperativo.
- [ ] Funzionale.

### Soluzione
Python è multiparadigma (imperativo, OO, funzionale, scripting) ma non logico come Prolog.

## [mcq 1] Cosa succede se dimentichi l'indentazione dopo un'istruzione if in Python?
- [ ] Viene ignorata l'istruzione.
- [ ] Si esegue comunque.
- [ ] Si genera un SyntaxWarning.
- [x] Si genera un IndentationError.

### Soluzione
L'indentazione delimita i blocchi: dopo `if ...:` serve un blocco indentato, altrimenti `IndentationError: expected an indented block` (sottoclasse di SyntaxError).

## [mcq 1] Come viene gestito il typing in Python?
- [ ] Statico e forte.
- [ ] Dinamico e debole.
- [ ] Statico e debole.
- [x] Dinamico e forte.

### Soluzione
Dinamico: i tipi stanno sui valori e si controllano a runtime. Forte: niente conversioni implicite tra tipi incompatibili (`"1" + 1` → TypeError).

## [mcq 1] Qual è il risultato dell'operazione 9//4 in Python?
- [x] 2
- [ ] 2.25
- [ ] 3
- [ ] Errore.

### Soluzione
`//` è la divisione intera (floor): ⌊9/4⌋ = ⌊2.25⌋ = 2. `9/4` darebbe 2.25.

## [mcq 1] Quale tra queste affermazioni è corretta riguardo le stringhe in Python?
- [ ] Le stringhe sono mutevoli.
- [ ] Si può modificare un singolo carattere.
- [x] Le stringhe sono immutabili.
- [ ] Le stringhe supportano operatori di assegnamento.

### Soluzione
`str` è immutabile: ogni "modifica" (`replace`, `+`, slicing) crea una nuova stringa.

## [mcq 1] Cosa succede se si tenta di accedere all'indice 20 di una stringa lunga 20 caratteri?
- [ ] Restituisce il carattere finale.
- [x] Solleva un IndexError.
- [ ] Restituisce None.
- [ ] Solleva un ValueError.

### Soluzione
Gli indici vanno da 0 a 19: `s[20]` → `IndexError: string index out of range`. L'ultimo è `s[19]` o `s[-1]`.

## [mcq 1] Quale tra questi tipi di collezioni è immutabile in Python?
- [x] Tuple.
- [ ] Set.
- [ ] Dictionary.
- [ ] List.

### Soluzione
Tuple immutabili; list, set e dict sono mutabili (l'equivalente immutabile del set è `frozenset`).

## [mcq 1] Quale funzione viene usata per generare una sequenza di numeri interi in Python?
- [ ] list()
- [ ] seq()
- [x] range()
- [ ] series()

### Soluzione
`range(start, stop, step)` produce una sequenza lazy di interi, `stop` escluso.

## [mcq 1] Qual è la differenza tra pop() e remove() in una lista?
- [ ] pop() rimuove per valore, remove() per indice.
- [x] pop() rimuove per indice, remove() per valore.
- [ ] Entrambe rimuovono per indice.
- [ ] Nessuna differenza.

### Soluzione
`l.pop(i)` toglie e restituisce l'elemento in posizione i (default l'ultimo); `l.remove(x)` toglie la prima occorrenza del valore x (ValueError se manca).

## [mcq 1] Cosa ritorna range(2, 10, 3) una volta convertito in lista?
- [ ] [2, 4, 6, 8, 10]
- [x] [2, 5, 8]
- [ ] [2, 3, 4, 5, 6, 7, 8, 9]
- [ ] [2, 5, 7, 9]

### Soluzione
Parte da 2, passo 3: 2, 5, 8; 11 supererebbe lo stop 10 (escluso).

## [mcq 1] Cosa rappresenta l'eccezione StopIteration in un iteratore?
- [x] L'iteratore ha raggiunto la fine della sequenza.
- [ ] L'iteratore ha trovato un errore nei dati.
- [ ] L'iterazione non è mai iniziata.
- [ ] L'oggetto non è iterabile.

### Soluzione
`__next__()` solleva StopIteration quando non ci sono più elementi; il `for` la intercetta e termina il ciclo. Un oggetto non iterabile dà TypeError (d).

## [mcq 1] Come si chiama una funzione senza nome in Python?
- [ ] anon()
- [ ] ghost
- [x] lambda
- [ ] inline

### Soluzione
`lambda x: x * 2` è una funzione anonima limitata a una singola espressione.

## [mcq 1] Cosa fa il decoratore @staticmethod?
- [ ] Rende un metodo accessibile solo dalla classe.
- [x] Consente di chiamare il metodo senza passare self o cls.
- [ ] Rende il metodo protetto.
- [ ] Aggiunge il metodo al costruttore.

### Soluzione
Un metodo statico non riceve né l'istanza (`self`) né la classe (`cls`, quello è `@classmethod`): è una funzione normale nel namespace della classe, chiamabile da classe o istanza.

## [mcq 1] Qual è l'ordine delle regole di scoping in Python (LEGB)?
- [ ] Local, External, Global, Builtin
- [x] Local, Enclosing, Global, Builtin
- [ ] Last, Enclosing, Global, Builtin
- [ ] Last, External, Global, Builtin

### Soluzione
Un nome si cerca nell'ordine: Locale → funzioni Enclosing (chiusure) → Globale (modulo) → Built-in.

## [mcq 1] A cosa serve la parola chiave global in Python?
- [ ] A creare una variabile visibile solo localmente.
- [ ] A limitare l'uso di variabili globali in funzioni.
- [x] A riferirsi a una variabile definita fuori dal blocco corrente.
- [ ] A esportare variabili in altri moduli.

### Soluzione
`global x` dentro una funzione fa sì che gli assegnamenti a `x` agiscano sulla variabile del modulo invece di crearne una locale (per le funzioni annidate c'è `nonlocal`).

## [mcq 1] Cosa succede ai parametri con valori predefiniti mutabili in Python?
- [ ] Vengono copiati ogni volta.
- [x] Mantengono il loro stato tra chiamate successive.
- [ ] Generano un errore se modificati.
- [ ] Vengono convertiti in valori immutabili.

### Soluzione
Il default è valutato una sola volta, alla definizione: `def f(l=[]): l.append(1)` accumula elementi chiamata dopo chiamata. Idioma: `l=None` e `if l is None: l = []`.

## [mcq 1] Cosa rappresenta type(x) quando x è una funzione?
- [ ] method
- [ ] builtin_function_or_method
- [x] function
- [ ] lambda

### Soluzione
Una funzione definita con `def` (o `lambda`) ha tipo `<class 'function'>`. `builtin_function_or_method` è per quelle in C come `len`; `method` per metodi legati a un'istanza.

## [mcq 1] Dopo aver consumato un generatore in Python, cosa succede?
- [ ] Può essere riutilizzato infinite volte.
- [ ] Viene automaticamente rigenerato.
- [ ] Viene convertito in lista.
- [x] È esaurito e non può più essere usato.

### Soluzione
Un generatore è un iteratore monouso: una seconda iterazione non produce nulla. Per riusarlo bisogna richiamare la funzione generatrice.

## [mcq 1] Quale metodo magico permette di sovraccaricare l'operatore '+' ?
- [ ] `__sum__`
- [ ] `__plus__`
- [x] `__add__`
- [ ] `__concat__`

### Soluzione
`a + b` chiama `a.__add__(b)` (e se non gestito `b.__radd__(a)`).

## [mcq 1] Qual è il vantaggio dell'uso di una metaclasse Singleton generalizzata?
- [ ] Permette di creare oggetti da qualsiasi classe base.
- [x] Garantisce che esista solo un'istanza di qualsiasi classe che la usa.
- [ ] Migliora la velocità di esecuzione.
- [ ] Impedisce la modifica degli attributi.

### Soluzione
La metaclasse ridefinisce `__call__` e tiene un dizionario classe → istanza: ogni classe con `metaclass=Singleton` diventa singleton senza riscrivere la logica.

## [mcq 1] Cosa rappresenta il concetto di "interfaccia" in ambito di programmazione orientata agli oggetti?
- [ ] Una libreria esterna che estende le funzionalità.
- [x] Un contratto che specifica un insieme di metodi che una classe deve implementare.
- [ ] Una classe concreta astratta.
- [ ] Una classe che eredita da più superclassi.

### Soluzione
Interfaccia = insieme di firme di operazioni senza implementazione; chi la implementa si impegna a fornirle (`interface` in Java, ABC in Python, classi puramente virtuali in C++).

## [mcq 1] Qual è lo scopo principale della separazione tra interfaccia e implementazione?
- [ ] Rendere più difficile la manutenzione del codice.
- [ ] Migliorare le performance in compilazione.
- [x] Ridurre l'accoppiamento tra le componenti.
- [ ] Garantire la compatibilità con il sistema operativo.

### Soluzione
I client dipendono solo dall'interfaccia: l'implementazione può cambiare senza toccarli (information hiding, basso accoppiamento).

## [mcq 1] Quando si usa il principio di Dependency Inversion?
- [ ] Per implementare ricorsione.
- [ ] Per ereditare proprietà da una superclasse.
- [ ] Quando si devono ottimizzare cicli annidati.
- [x] Quando si vogliono dipendenze da astrazioni e non da classi concrete.

### Soluzione
La D di SOLID: i moduli di alto livello non dipendono da quelli di basso livello, entrambi dipendono da astrazioni (interfacce).

## [mcq 1] Perché è utile utilizzare il principio di Single Responsibility?
- [x] Ogni classe ha una sola ragione di cambiamento.
- [ ] Aumenta la velocità di compilazione.
- [ ] Riduce la quantità di codice scritto.
- [ ] Evita l'uso delle classi astratte.

### Soluzione
La S di SOLID: una classe = una responsabilità, quindi un solo motivo per modificarla (alta coesione, modifiche localizzate).

## [mcq 1] Qual è il risultato dell'operazione 7 // 3 in Python?
- [ ] 2.3333
- [ ] 3
- [ ] 1
- [x] 2

### Soluzione
Divisione intera: ⌊7/3⌋ = ⌊2.33⌋ = 2.

## [mcq 1] Cosa succede se si prova ad assegnare un nuovo carattere a un indice di una stringa in Python?
- [ ] La stringa viene modificata correttamente.
- [x] Viene sollevato un TypeError.
- [ ] La stringa viene copiata e modificata.
- [ ] Non succede nulla.

### Soluzione
`s[0] = "x"` → `TypeError: 'str' object does not support item assignment`, perché le stringhe sono immutabili.

## [mcq 1] Quale operatore in Python serve a concatenare due stringhe?
- [ ] *
- [x] +
- [ ] &
- [ ] //

### Soluzione
`"a" + "b"` == `"ab"`; `*` ripete (`"a" * 3`), `&` e `//` non sono definiti sulle stringhe.

## [mcq 1] Come si scrive una stringa multilinea in Python?
- [ ] Usando il carattere \n.
- [x] Usando triple virgolette '''...''' o """...""".
- [ ] Usando la funzione multistring().
- [ ] Con la concatenazione di più stringhe singole.

### Soluzione
Le triple virgolette permettono di andare a capo dentro il letterale. Anche `\n` (a) produce più righe, ma la sintassi della stringa multilinea è quella con le triple virgolette.

## [mcq 1] Cosa produce la slice [::-1] applicata a una stringa?
- [ ] Ritorna la stessa stringa.
- [ ] Ritorna una copia della stringa.
- [x] Ritorna la stringa invertita.
- [ ] Ritorna la stringa con solo caratteri pari.

### Soluzione
Start e stop omessi, step −1: si scorre dal fondo all'inizio. `"abc"[::-1]` == `"cba"`.

## [mcq 1] Quale errore viene sollevato quando si accede a un indice fuori dal range di una stringa?
- [ ] TypeError
- [ ] ValueError
- [x] IndexError
- [ ] KeyError

### Soluzione
Indice fuori range su sequenze → IndexError; KeyError è per chiavi mancanti nei dict. Lo slicing invece non dà mai errore.

## [mcq 1] Che differenza c'è tra gli operatori + e * usati con le stringhe?
- [ ] + ripete la stringa, * concatena.
- [x] + concatena le stringhe, * ripete la stringa un certo numero di volte.
- [ ] Entrambi concatenano.
- [ ] Entrambi ripetono la stringa.

### Soluzione
`"ab" + "c"` == `"abc"`, `"ab" * 3` == `"ababab"`.

## [mcq 1] Cosa succede con questo codice?
```python
c = 'Hello' ' ' 'World'
print(c)
```
- [ ] Errore di sintassi.
- [ ] Stampa "HelloWorld" senza spazio.
- [x] Stampa "Hello World" con spazio.
- [ ] Nessuna stampa.

### Soluzione
Letterali stringa adiacenti vengono concatenati dal compilatore: `'Hello' ' ' 'World'` == `'Hello World'` (lo spazio è il letterale in mezzo).

## [mcq 1] Come funziona la slice [start:end:step]?
- [x] Restituisce una sottostringa da start a end escluso, saltando step caratteri.
- [ ] Restituisce la stringa invertita.
- [ ] Restituisce una copia della stringa.
- [ ] Restituisce una lista di caratteri.

### Soluzione
Prende gli indici start, start+step, … fino a end escluso. `"abcdef"[0:5:2]` == `"ace"`.

## [mcq 1] Qual è la differenza principale tra una stringa e una lista in Python?
- [ ] Le stringhe sono mutabili, le liste sono immutabili.
- [x] Le stringhe sono immutabili, le liste sono mutabili.
- [ ] Nessuna differenza.
- [ ] Le liste contengono solo numeri, le stringhe solo caratteri.

### Soluzione
Entrambe sono sequenze, ma `str` è immutabile e contiene solo caratteri; `list` è mutabile e può contenere oggetti di qualunque tipo.

## [mcq 1] Quale tra le seguenti affermazioni è vera riguardo le liste in Python?
- [ ] Le liste sono immutabili e ordinate.
- [x] Le liste sono mutabili e ordinate.
- [ ] Le liste non supportano duplicati.
- [ ] Le liste sono immutabili e non ordinate.

### Soluzione
Ordinate = mantengono l'ordine di inserimento e si accede per indice; mutabili; ammettono duplicati.

## [mcq 1] Cosa succede assegnando una lista ad un'altra variabile in Python?
- [ ] Viene creata una copia profonda della lista.
- [ ] Viene creata una copia superficiale della lista.
- [x] Entrambe le variabili puntano alla stessa lista.
- [ ] Viene generato un errore.

### Soluzione
`b = a` copia il riferimento, non la lista: `b.append(1)` si vede anche da `a`. Per copiare: `a.copy()` / `a[:]` (superficiale) o `copy.deepcopy(a)`.

## [mcq 1] Quale metodo permette di aggiungere un elemento alla fine di una lista?
- [ ] add()
- [ ] insert()
- [x] append()
- [ ] extend()

### Soluzione
`append(x)` aggiunge x in fondo; `insert(i, x)` in posizione i; `extend(it)` aggiunge *tutti* gli elementi di un iterabile; `add` è dei set.

## [mcq 1] Cosa succede se si modifica un elemento interno (ad esempio una lista) contenuto in una tupla?
- [ ] La tupla diventa mutabile.
- [ ] La modifica genera un errore.
- [x] L'elemento interno si modifica ma la tupla resta immutabile.
- [ ] La tupla si copia automaticamente prima della modifica.

### Soluzione
La tupla è immutabile nei *riferimenti* che contiene: `t = ([1],); t[0].append(2)` funziona, `t[0] = [3]` no.

## [mcq 1] Quale tra le seguenti affermazioni sui set è corretta?
- [ ] I set sono ordinati e possono contenere duplicati.
- [x] I set sono non ordinati e non possono contenere duplicati.
- [ ] I set possono contenere liste come elementi.
- [ ] I set supportano l'operatore + per concatenazione.

### Soluzione
Set = insieme matematico: niente ordine, niente duplicati, elementi hashable. Si combinano con `|`, `&`, `-`, non con `+`.

## [mcq 1] Cosa succede se si prova ad aggiungere una lista come elemento di un set?
- [ ] La lista viene aggiunta correttamente.
- [ ] Il set diventa mutabile.
- [x] Si genera un errore di tipo "unhashable type".
- [ ] La lista viene convertita in tupla e aggiunta.

### Soluzione
Gli elementi di un set devono essere hashable (immutabili): `s.add([1])` → `TypeError: unhashable type: 'list'`. Si può aggiungere `tuple([1])`.

## [mcq 1] Come si crea una copia profonda (deep copy) di una lista annidata in Python?
- [ ] Usando il metodo copy() della lista.
- [ ] Usando l'operatore di assegnazione =.
- [x] Usando il modulo copy con copy.deepcopy().
- [ ] Non è possibile creare copie profonde di liste annidate.

### Soluzione
`list.copy()` è superficiale: le sottoliste restano condivise. `copy.deepcopy` copia ricorsivamente.

## [mcq 1] Qual è il risultato di questa operazione su una lista `aList = [1, 2, 3, 4]`: `aList.pop(2)` ?
- [ ] Rimuove e ritorna l'elemento con valore 2.
- [x] Rimuove e ritorna l'elemento all'indice 2.
- [ ] Rimuove l'elemento 2 senza ritornarlo.
- [ ] Genera un errore.

### Soluzione
`pop` lavora per indice: rimuove e restituisce `aList[2]` cioè 3; la lista diventa `[1, 2, 4]`.

## [mcq 1] Quale tra le seguenti affermazioni descrive correttamente la differenza tra tuple e liste?
- [ ] Tuple sono mutabili, liste sono immutabili.
- [x] Tuple sono immutabili, liste sono mutabili.
- [ ] Entrambe sono mutabili ma con sintassi diversa.
- [ ] Entrambe sono immutabili ma con sintassi diversa.

### Soluzione
Tuple `( )` immutabili (e quindi hashable se lo sono gli elementi), liste `[ ]` mutabili.

## [mcq 1] Cosa succede se si concatena una tupla con un intero in Python?
- [ ] L'intero viene aggiunto come elemento.
- [x] Viene generato un errore di tipo.
- [ ] L'intero viene convertito in tupla automaticamente.
- [ ] La tupla diventa mutabile.

### Soluzione
`(1, 2) + 3` → `TypeError: can only concatenate tuple (not "int") to tuple`. Si scrive `(1, 2) + (3,)`.

## [mcq 1] Nel contesto delle API di OpenAI, quale ruolo serve a definire le regole e il comportamento del modello?
- [ ] user
- [ ] assistant
- [x] system
- [ ] developer

### Soluzione
Il messaggio `system` dà le istruzioni generali (persona, regole); `user` sono le richieste, `assistant` le risposte del modello.

## [mcq 1] Quale informazione è contenuta nel campo usage della risposta API di OpenAI?
- [ ] Lo stile della risposta
- [x] Il numero di token utilizzati
- [ ] Il livello di temperatura
- [ ] Il modello usato

### Soluzione
`usage` riporta `prompt_tokens`, `completion_tokens` e `total_tokens` (base della fatturazione). Il modello è nel campo `model`.

## [mcq 1] A cosa serve un PromptTemplate in LangChain?
- [ ] Gestire la memoria conversazionale
- [ ] Definire una catena di agenti
- [x] Creare prompt strutturati e parametrizzati
- [ ] Collegare database esterni

### Soluzione
Un template con segnaposto (`"Traduci {testo} in {lingua}"`) che si riempie con le variabili a ogni chiamata.

## [mcq 1] Qual è la funzione principale della Memory in LangChain?
- [ ] Salvare lo stato del modello
- [x] Ricordare il contesto delle conversazioni precedenti
- [ ] Generare automaticamente prompt
- [ ] Aumentare la velocità di calcolo

### Soluzione
Il modello è senza stato: la Memory conserva lo storico (o un suo riassunto) e lo reinserisce nel prompt.

## [mcq 1] In CrewAI, quale elemento rappresenta una singola unità di lavoro assegnata a un agente?
- [ ] Crew
- [ ] Role
- [x] Task
- [ ] Goal

### Soluzione
Agent (con role, goal, backstory) esegue Task; una Crew è l'insieme coordinato di agenti e task.

## [mcq 1] Qual è la differenza principale tra LangChain e CrewAI?
- [x] LangChain si concentra su pipeline e strumenti, CrewAI sulla coordinazione multi-agente
- [ ] LangChain è solo per traduzioni, CrewAI per generazione di testo
- [ ] LangChain è un modello di linguaggio, CrewAI è un framework
- [ ] LangChain funziona senza API, CrewAI solo con API OpenAI

### Soluzione
LangChain: componenti per costruire catene (prompt, modelli, tool, memory, retrieval). CrewAI: squadre di agenti con ruoli che collaborano su task.

## [mcq 1] Cosa rappresenta il campo finish_reason in una risposta API di OpenAI?
- [ ] Il modello è andato in errore
- [x] Il motivo per cui il modello ha terminato la generazione
- [ ] La quantità di token generati
- [ ] La temperatura usata nella generazione

### Soluzione
Valori tipici: `stop` (fine naturale), `length` (limite di token), `tool_calls`, `content_filter`.

## [mcq 1] Per quale motivo può essere utile lo streaming delle risposte di un LLM?
- [ ] Per ridurre il costo dei token
- [ ] Per migliorare la sicurezza dei prompt
- [x] Per ridurre la latenza e visualizzare il testo man mano che viene generato
- [ ] Per salvare automaticamente le risposte nel database

### Soluzione
Con lo streaming i token arrivano appena generati: la latenza percepita (tempo al primo token) cala, il costo resta uguale.

## [mcq 1] In LangChain, cosa fa una LLMChain?
- [x] Collega un prompt a un modello e gestisce input e output
- [ ] Genera automaticamente nuove API
- [ ] Ottimizza l'uso dei token
- [ ] Traduce i messaggi in diverse lingue

### Soluzione
La catena base: PromptTemplate + LLM (+ parser dell'output), richiamabile con le variabili del template.

## [mcq 1] Qual è il vantaggio principale di usare Agents in LangChain?
- [ ] Consentono di ridurre i costi computazionali
- [ ] Eliminano la necessità di definire prompt
- [x] Consentono al modello di scegliere dinamicamente quali strumenti utilizzare
- [ ] Rendono l'LLM più veloce

### Soluzione
In una chain i passi sono fissi; un agente usa l'LLM per decidere a ogni passo quale tool chiamare (e quando fermarsi).

## [mcq 1] Qual è lo scopo dei Tools in LangChain?
- [x] Esporre funzioni esterne che il modello può invocare
- [ ] Memorizzare conversazioni precedenti
- [ ] Fornire dataset per il training
- [ ] Modificare la temperatura del modello

### Soluzione
Un tool è una funzione con nome e descrizione (ricerca web, calcolatrice, query DB…) che l'agente può chiamare.

## [mcq 1] In CrewAI, cosa definisce il parametro goal di un agente?
- [ ] Le API a cui l'agente può accedere
- [x] L'obiettivo esplicito che guida le decisioni dell'agente
- [ ] Il tipo di memoria utilizzata
- [ ] La sequenza dei task da eseguire

### Soluzione
Ogni agente ha `role`, `goal` (cosa deve ottenere) e `backstory`; i tool sono un parametro separato.

## [mcq 1] In CrewAI, come possono essere eseguiti i task?
- [x] In modo sequenziale o in parallelo
- [ ] Solo in ordine gerarchico
- [ ] Solo uno alla volta
- [ ] Sempre in background

### Soluzione
Il processo della crew può essere sequenziale o gerarchico (con un manager), e i task possono essere marcati come asincroni per girare in parallelo.

## [mcq 1] Cosa rappresenta un Crew in CrewAI?
- [ ] Un singolo agente specializzato
- [ ] Una memoria condivisa tra più task
- [x] Un insieme di agenti e task coordinati
- [ ] Un tool esterno integrato nel sistema

### Soluzione
La Crew raggruppa agenti e task e ne definisce il processo di esecuzione (`crew.kickoff()`).

## [mcq 1] Quali sono le tre fasi principali dell'esecuzione di un programma Python?
- [ ] Parsing, Ottimizzazione, Linking
- [x] Interpreter Initialization, Compilazione in bytecode, Bytecode Interpretation
- [ ] Preprocessing, Compilazione in Assembly, Esecuzione
- [ ] Traduzione in C, Compilazione, Runtime

### Soluzione
CPython: inizializza l'interprete, compila il sorgente in bytecode (eventualmente salvato in `.pyc`), poi la VM lo interpreta.

## [mcq 1] Qual è il compito principale della fase di Interpreter Initialization?
- [ ] Generare i file .pyc
- [x] Caricare moduli built-in, gestire memoria e creare il GIL
- [ ] Disassemblare il bytecode
- [ ] Avviare la compilazione JIT

### Soluzione
All'avvio CPython prepara runtime e allocatori, crea il GIL e lo stato dell'interprete, carica `builtins` e `sys`. I `.pyc` nascono nella fase di compilazione.

## [mcq 1] Cosa rappresenta un frame durante l'esecuzione del bytecode?
- [ ] Una struttura che contiene solo variabili globali
- [x] Un'unità di esecuzione con codice, scope e stack
- [ ] Una copia del sorgente .py
- [ ] Un dizionario temporaneo con i built-in

### Soluzione
Ogni chiamata crea un frame con: code object, variabili locali/globali/builtin, value stack, puntatore all'istruzione corrente e al frame chiamante.

## [mcq 1] Come funziona la call stack in Python?
- [x] Ogni funzione aggiunge un frame; al ritorno il frame viene rimosso
- [ ] Tutte le funzioni condividono un unico frame
- [ ] La call stack non esiste, si usano solo dizionari di contesto
- [ ] Le funzioni ricorsive sovrascrivono i frame precedenti

### Soluzione
Pila LIFO di frame: chiamata = push, return = pop. Troppa ricorsione → `RecursionError`.

## [mcq 1] Qual è la funzione del modulo dis in Python?
- [x] Disassemblare il bytecode in opcodes leggibili
- [ ] Ottimizzare la compilazione
- [ ] Mostrare i moduli built-in
- [ ] Gestire i riferimenti degli oggetti

### Soluzione
`import dis; dis.dis(f)` stampa le istruzioni bytecode di `f` (`LOAD_FAST`, `BINARY_OP`, `RETURN_VALUE`…).

## [mcq 1] Quale meccanismo di gestione memoria usa CPython?
- [ ] Garbage collection generazionale puro
- [x] Reference counting con garbage collector per cicli
- [ ] Manuale come in C
- [ ] Unicamente mark-and-sweep

### Soluzione
Ogni oggetto ha un contatore di riferimenti: a 0 viene liberato subito. I cicli (a→b→a) li raccoglie un GC generazionale aggiuntivo (modulo `gc`).

## [mcq 1] Perché esiste il Global Interpreter Lock (GIL)?
- [ ] Per velocizzare il calcolo parallelo
- [x] Per semplificare la gestione memoria, evitando race condition
- [ ] Per supportare librerie C esterne
- [ ] Per ridurre la latenza del bytecode

### Soluzione
Un solo thread alla volta esegue bytecode: così i reference count e le strutture interne non hanno bisogno di lock fini. Prezzo: niente parallelismo CPU tra thread Python.

## [mcq 1] Come fanno librerie come NumPy a ottenere parallelismo nonostante il GIL?
- [ ] Usano Python puro senza bytecode
- [x] Rilasciano temporaneamente il GIL in codice C esterno
- [ ] Compilano direttamente in Assembly
- [ ] Ignorano completamente la call stack

### Soluzione
Durante i calcoli in C che non toccano oggetti Python rilasciano il GIL (`Py_BEGIN_ALLOW_THREADS`), quindi altri thread possono girare in parallelo.

## [mcq 1] Qual è la caratteristica principale della Python Virtual Machine?
- [x] È un interprete stack-based che esegue bytecode
- [ ] È un compilatore che genera file eseguibili nativi
- [ ] È una macchina a registri per CPU multi-core
- [ ] Funziona solo come ottimizzatore di memoria

### Soluzione
Le istruzioni prendono gli operandi dal value stack e ci rimettono il risultato (`LOAD_FAST a; LOAD_FAST b; BINARY_OP +`).

## [mcq 1] Qual è lo scopo del value stack nella VM?
- [ ] Conservare moduli built-in
- [ ] Salvare costanti globali
- [x] Tenere operandi e risultati temporanei durante l'esecuzione
- [ ] Gestire i thread del GIL

### Soluzione
Ogni frame ha il suo value stack su cui le istruzioni fanno push/pop di operandi e risultati intermedi.
