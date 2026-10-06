---
titolo: Banca domande per argomento (91 quiz storici)
durata: 0
fonte: Raccolta di studenti delle domande 2023 divise per categoria (senza soluzioni). Risposte e spiegazioni di Claude, verificate con i quiz ufficiali dove la domanda ricorre.
---

## [mcq 1] [Alberi di decisione] Selezionare l’affermazione corretta sugli alberi di decisione:
- [ ] Possono essere utilizzati solo con features discrete
- [x] Possono esprimere qualunque funzione di classificazione
- [ ] Non presentano problemi di overfitting
- [ ] Il costo computazionale della produzione è piuttosto elevato

### Soluzione
Un albero abbastanza profondo esprime qualunque funzione di classificazione (e per questo va in overfitting); usa anche features continue con soglie; predizione economica.

## [mcq 1] [Alberi di decisione] Selezionare la sentenza erronea riguardo gli alberi di decisione
- [x] Possono essere utilizzati solo con features discrete
- [ ] Il costo computazionale è molto basso
- [ ] Hanno una forte tendenza all’overfitting
- [ ] Possono esprimere qualunque funzione di classificazione

### Soluzione
Gli alberi gestiscono anche features continue (test $x_j < t$).

## [mcq 1] [Alberi di decisione] Nel caso di un albero di decisione con features discrete, cosa si può dire della profondità dell’albero?
- [x] È minore o uguale al numero delle features
- [ ] Non si può dire nulla
- [ ] È minore o uguale al numero delle classe
- [ ] È sicuramente maggiore del logaritmo in base due del numero dei dati

### Soluzione
Con features discrete ogni feature si testa al più una volta per cammino (dopo il test il valore è fissato), quindi la profondità ≤ numero di features.

## [mcq 1] [Random forest] Selezionare la sentenza errata relativa alle random forest (foreste di alberi decisionali)
- [ ] Richiedono tecniche opportune per la creazione di alberi di decisione diversi relativi ad uno stesso dataset
- [x] Tendono a migliorare l’explainability (spiegabilità) degli alberi di decisione riducendo l’instabilità nella selezione degli attributi
- [ ] Tentano di mitigare il fenomeno dell’overfitting tipico degli alberi di decisione
- [ ] È una tecnica di apprendimento ad “ensemble” basata su una combinazione di alberi di decisione

### Soluzione
Le random forest peggiorano la spiegabilità (ensemble di molti alberi) ma riducono l'overfitting.

## [mcq 1] [AlexNet] AlexNet, la prima rete convoluzionale profonda vincitrice della ImageNet competition è stata realizzata in quale anno:
- [x] 2012
- [ ] 1993
- [ ] 1971
- [ ] 2019

### Soluzione
AlexNet (Krizhevsky, Sutskever, Hinton) vinse ImageNet nel 2012, avviando l'era del deep learning.

## [mcq 1] [apprendimento supervisionato] Selezionare la sentenza errata riguardo all’apprendimento supervisionato
- [x] Richiede la costante supervisione di un esperto durante il training
- [ ] Può comprendere sia problemi di regressione che di classificazione
- [ ] Si riferisce all’apprendimento di funzioni basato su esempi di training composti da coppie di input-output
- [ ] La definizione della ground truth può richiedere l’intervento umano ed essere onerosa

### Soluzione
Supervisionato = dati etichettati, non un esperto che supervisiona il training.

## [mcq 1] [apprendimento supervisionato] Che cosa si intende con apprendimento supervisionato?
- [ ] Apprendimento sotto la supervisione diretta di un esperto
- [ ] Apprendimento che tende ad imitare il comportamento di un esperto
- [ ] Apprendimento che non fa uso di tecniche statistiche o probabilistiche
- [x] Apprendimento di funzioni basato su esempi di training composti da coppie input-output

### Soluzione
Apprendere una funzione da coppie (input, output) etichettate.

## [mcq 1] [apprendimento supervisionato] In che situazioni si parla di apprendimento auto-supervisionato? (self supervised)
- [ ] Quando il modello è in grado di configurare in modo automatico la propria architettura
- [ ] Quando il modello è supposto contribuire alla creazione di nuovi dati di training
- [x] Qualora i dati di input possano essere considerati come annotazioni (labels) per guidare l’apprendimento, come nel caso degli autoencoders
- [ ] Quando l’apprendimento prevede una sinergia tra l’uomo e la macchina

### Soluzione
Self-supervised: le etichette si ricavano dai dati stessi (es. l'autoencoder ricostruisce il proprio input, i language model predicono la parola successiva).

## [mcq 1] [Autoencoders] Quale delle seguenti sentenze relative agli autoencoders è scorretta?
- [x] Gli autoencoders richiedono l’uso di livelli densi
- [ ] Possono essere utilizzate per la rimozione di rumore (denoising)
- [ ] L’encoder e il decoder non devono essere necessariamente simmetrici
- [ ] La rappresentazione interne prodotta dall’encoder abitualmente ha una dimensione ridotta rispetto a quella di partenza

### Soluzione
Esistono autoencoder completamente convoluzionali: i layer densi non sono necessari.

## [mcq 1] [Autoencoders] Quale delle seguenti sentenze relative agli autoencoders è corretta?
- [ ] Gli autoencoders richiedono l’uso di livelli densi
- [ ] L’encoder e il decoder devono essere strettamente simmetrici
- [x] La rappresentazione interna prodotta abitualmente ha una dimensione ridotta rispetto a quella di partenza
- [ ] È una rete neurale che codifica se stessa

### Soluzione
L'autoencoder comprime l'input in un codice (bottleneck) di dimensione ridotta e lo ricostruisce; encoder/decoder non devono essere simmetrici né densi.

## [mcq 1] [Autoencoders] Quale delle seguenti non è una applicazione tipica degli autoencoders?
- [x] Segmentazione di immagini (semantic segmentation)
- [ ] Rimozione del rumore (denoising)
- [ ] Riduzione delle dimensioni (dimensionality reduction)
- [ ] Rilevamento di anomalie ( anomaly detection)

### Soluzione
Segmentazione semantica = task supervisionato (U-Net); gli autoencoder servono per denoising, riduzione dimensionale, anomaly detection.

## [mcq 1] [backpropagation per reti neurali] Selezionare la sentenza scorretta relativa alla backpropagation per reti neurali
- [ ] Richiede la memorizzazione delle attivazioni di tutti i neuroni della rete durante la forward pass
- [ ] Ha un costo computazionale paragonabile a quello del calcolo “in avanti” (inference) lungo la rete
- [x] Si basa tipicamente su algoritmi di tipo generico
- [ ] Tipicamente, si effettua solo durante la fase di “training” della rete

### Soluzione
Il gradiente non viene 'rinforzato' artificialmente: il vanishing si combatte con ReLU, inizializzazione, normalizzazione, skip connection.

## [mcq 1] [backpropagation per reti neurali] Quale delle seguenti affermazioni relative alla backpropagation è corretta?
- [x] Si effettua solo durante il “training”
- [ ] Viene fatta sia durante la fase di “inference” (calcolo in avanti) che in quella di “training”
- [ ] È molto più costosa, in termini di tempo, del calcolo in avanti lungo la rete
- [ ] Viene effettuata unicamente lungo le skip connections delle reti residuali, per evitare perdita del gradiente

### Soluzione
La backprop serve a calcolare i gradienti per aggiornare i pesi: solo in training. Costo paragonabile al forward.

## [mcq 1] [backpropagation per reti neurali] Selezionare la sentenza scorretta relativa alla backpropagation per reti neurali
- [ ] È l’algoritmo per il calcolo della derivata parziale della loss rispetto a ogni parametro della rete
- [x] Tipicamente, il gradiente viene artificialmente rinforzato ad ogni layer attraversato per contrastare il fenomeno della sua scomparsa (vanishing)
- [ ] Si riduce a semplici calcoli algebrici facilmente parallelizzabili in strutture di calcolo tipo GPU
- [ ] L’algoritmo calcola il gradiente un layer alla volta, sfruttando la regola matematica per la derivazione di funzioni composte

### Soluzione
Il gradiente non viene 'rinforzato' artificialmente: il vanishing si combatte con ReLU, inizializzazione, normalizzazione, skip connection.

## [mcq 1] [Learning rate] Selezionare la sentenza errata relativa al learning rate
- [x] È una metrica che misura la capacità di apprendimento del modello
- [ ] Un learning rate alto tipicamente velocizza il training ma potrebbe saltare sopra al minimo
- [ ] È un iper-parametro che definisce la lunghezza del passo durante la discesa del gradiente
- [ ] Il learning rate può variare durante il training

### Soluzione
Il learning rate è un **iperparametro** (passo del gradiente), non una metrica.

## [mcq 1] [campo recettivo (receptive field) di un neurone di una CNN] Selezionare la sentenza scorretta relativa al campo ricettivo di un neurone di una CNN:
- [ ] Definisce la porzione dell’input che influenza l’attivazione di un determinato neurone
- [ ] Dipende dalla profondità del layer in cui si trova il neurone e dalle dimensioni e gli striders dei kernel dei layers precedenti
- [x] È sempre almeno pari alla dimensione spaziale del dato di input
- [ ] Aumenta rapidamente con l’attraversamento di livelli con downsampling

### Soluzione
Nei primi layer il campo ricettivo è piccolo (es. 3×3): non è 'sempre almeno' l'input.

## [mcq 1] [campo recettivo (receptive field) di un neurone di una CNN] Il campo ricettivo (receptive field) di un neurone di una CNN dipende da:
- [x] La profondità del layer in cui si trova il neurone e le dimensioni e gli striders dei kernel dei layers precedenti
- [ ] La profondità del layer in cui si trova il neurone e le dimensioni dei kernel dei layers precedenti, ma non dai loro striders
- [ ] La dimensione del kernel e il numero dei canali del layer in cui si trova il neurone
- [ ] Unicamente dalla profondità del layer a cui si trova il neurone

### Soluzione
Dipende dalla profondità e da dimensioni **e stride** dei kernel precedenti (lo stride moltiplica la crescita).

## [mcq 1] [campo recettivo (receptive field) di un neurone di una CNN] Componendo due layer Conv2D con stride 1, il primo con kernel 5x5 e il secondo con kernel 3x3 quale sarà il campo ricettivo dei neuroni finali?
- [x] 7
- [ ] 8
- [ ] Dipende dal padding
- [ ] 3

### Soluzione
Con stride 1: $5 + 3 - 1 = 7$. Il padding non cambia il campo ricettivo.

## [mcq 1] [classificazione lineare] In quale di questi casi una tecnica di classificazione lineare potrebbe non fornire risultati soddisfacenti?
- [ ] Quando le features sono indipendenti tra loro, data la classe
- [ ] Quando non tutte le features di input sono rilevanti ai fini della classificazione
- [x] Quando la classificazione dipende da un confronto tra features
- [ ] Quando esiste una elevata correlazione tra le features

### Soluzione
Un modello lineare non cattura relazioni tra features (confronti, XOR); correlazione o features irrilevanti non sono un problema.

## [mcq 1] [Dadi / monete / probabilità] Ci sono due dadi, uno normale e uno truccato che restituisce 6 con probabilità 0.5 e gli altri valori con probabilità 0.1. Faccio tre lanci con lo stesso dado e osservo un 3, un 6 e un 2, cosa posso concludere?
- [ ] La probabilità di usare uno o l’altro dei dadi è esattamente la stessa
- [ ] Nulla
- [ ] È più probabile che il dado sia normale
- [x] È più probabile che il dado sia truccato

### Soluzione
Verosimiglianze: normale $(1/6)^3\approx0.00463$; truccato $0.1\cdot0.5\cdot0.1=0.005$ → più probabile il truccato.

## [mcq 1] [Dadi / monete / probabilità] Ci sono due dadi, uno normale e uno truccato che restituisce 6 con probabilità 0.5 e gli altri valori con probabilità 0.1. Faccio tre lanci con lo stesso dado e osservo un 3 e un 6 cosa posso concludere?
- [ ] La probabilità di usare uno o l’altro dei dadi è esattamente la stessa
- [ ] Nulla
- [ ] È più probabile che il dado sia normale
- [x] È più probabile che il dado sia truccato

### Soluzione
Normale $(1/6)^2\approx0.028$; truccato $0.1\cdot0.5 = 0.05$ → più probabile il truccato.

## [mcq 1] [Dadi / monete / probabilità] Ci sono due monete, una normale e una che restituisce testa con probabilità ¾ e croce con probabilità ¼. Faccio due lanci con la stessa moneta e osservo una testa e una croce. Che cosa posso concludere?
- [ ] Nulla
- [x] È più probabile che la moneta sia normale
- [ ] È più probabile che la moneta sia truccata
- [ ] La probabilità di usare uno o l’altra moneta è esattamente la stessa

### Soluzione
Verosimiglianze per (T,C): normale $\tfrac12\cdot\tfrac12 = 0.25$; truccata $\tfrac34\cdot\tfrac14 = 0.1875$ → più probabile la normale.

## [mcq 1] [TP+ FN] Un dataset contiene 1/3 di positivi e 2/3 di negativi. La recall del modello è di 2/3. Che percentuale dei dati sono i falsi positivi?
- [ ] 2/9
- [ ] 1/9
- [ ] 1/3
- [x] Non può essere stabilito

### Soluzione
Recall riguarda i positivi: TP = 2/9, FN = 1/9. I FP dipendono da come vengono classificati i negativi: non determinabile.

## [mcq 1] [TP+ FN] Un dataset contiene 1/3 di positivi e 2/3 di negativi. La recall del modello è di 2/3. Che percentuale dei dati sono i falsi negativi?
- [ ] 2/9
- [x] 1/9
- [ ] 1/3
- [ ] Non può essere stabilito

### Soluzione
Positivi = 1/3, recall = TP/P = 2/3 ⇒ TP = 2/9 e FN = 1/3 − 2/9 = **1/9**.

## [mcq 1] [TP+ FN] Un dataset contiene 2/3 di positivi e 1/3 di negativi. La precisione del modello è 9/10. Che percentuale dei dati totali sono falsi positivi?
- [ ] 1/9
- [x] Non può essere stabilito
- [ ] 2/27
- [ ] 1/10

### Soluzione
Precision $= TP/(TP+FP)$: dà il rapporto FP/(TP+FP), ma non sappiamo quanti esempi sono predetti positivi → non determinabile.

## [mcq 1] [deep features] Cosa si intende con “deep” features?
- [x] Features sintetizzate in modo automatico a partire da altre features
- [ ] Features ottenute mediante utilizzo di sensori ottici di profondità
- [ ] Features relative a dati in 2 o più dimensioni
- [ ] Features soggette a una approfondita supervisione da parte umana

### Soluzione
Rappresentazioni sintetizzate automaticamente dai livelli interni di una rete a partire da features più semplici.

## [mcq 1] [distribuzione congiunta di probabilità] Selezionare la sentenza corretta relativa alla distribuzione congiunta di probabilità
- [ ] Non permette il calcolo di eventi condizionali
- [ ] Non permette di fare nessun tipo di predizione
- [ ] Non consente una visione distinta delle singole features
- [x] Il suo calcolo presenta problemi di scalabilità all’aumentare delle features

### Soluzione
Dalla congiunta si ricava tutto (marginali, condizionate), ma il numero di valori cresce esponenzialmente con le features.

## [mcq 1] [distribuzione congiunta di probabilità] Selezionare la sentenza errata relativa alla distribuzione congiunta di probabilità per N variabili aleatorie discrete
- [ ] È la distribuzione di probabilità di tutte le possibili tuple di valori per le variabili
- [x] Richiede il calcolo di un numero esponenziale di parametri
- [x] Non permette il calcolo di probabilità condizionali tra le features
- [ ] Consente il calcolo delle probabilità marginali delle singole features

### Soluzione
Domanda a risposta multipla secondo Virtuale. 'Non permette il calcolo di probabilità condizionali' è certamente errata: dalla congiunta si ricava qualunque marginale o condizionata. Il quiz segna come errata anche 'richiede un numero esponenziale di parametri', il che è discutibile (servono $\prod_i|X_i|-1$ valori, esponenziale in N): memorizza la risposta ufficiale ma sappi che è contestabile.

## [mcq 1] [Probabilità condizionata] Selezionare le sentenza corretta relativa alla probabilità condizionata P(A|B) tra due eventi A e B
- [x] P(A|B) è sicuramente maggiore o uguale di P(A and B)
- [ ] P(A|B) è sicuramente maggiore o uguale di P(A)
- [ ] P(A|B) è sicuramente minore o uguale di P(A and B)
- [ ] P(A|B) è sicuramente minore o uguale a P(A)

### Soluzione
$P(A|B)=P(A\wedge B)/P(B) \ge P(A\wedge B)$ perché $P(B)\le 1$; rispetto a $P(A)$ può essere maggiore o minore.

## [mcq 1] [entropia / crossentropy] Se un modello calcola una distribuzione di probabilità, aggiungere alla funzione obiettivo una componente tesa a diminuire l’entropia avrà l’effetto di:
- [ ] Nessun effetto concreto
- [x] Focalizzare le scelte sui casi più probabili
- [ ] Ridistribuire le probabilità in bodo più bilanciato tra tutti i casi
- [ ] Favorire l’uscita da minimi locali

### Soluzione
Meno entropia = distribuzione più concentrata: le scelte si focalizzano sui casi più probabili.

## [mcq 1] [entropia / crossentropy] Se un modello calcola una distribuzione di probabilità, aggiungere alla funzione obiettivo una componente tesa ad aumentare l’entropia avrà l’effetto di:
- [ ] Nessun effetto concreto
- [ ] Focalizzare le scelte sui casi più probabili
- [x] Ridistribuire le probabilità in bodo più bilanciato tra tutti i casi
- [ ] Favorire l’uscita da minimi locali

### Soluzione
Aumentare l'entropia appiattisce la distribuzione: probabilità più bilanciate (regolarizzazione / esplorazione).

## [mcq 1] [entropia / crossentropy] Selezionare la sentenza corretta relativa alla crossentropy H(P,Q) tra P e Q
- [x] È uguale alla divergenza di kullback-Leibler KL(P,Q) più l’entropia H(P) di P
- [ ] Misura la logilikelihood di P data la distribuzione di Q
- [ ] Ha un valore massimo quando P=Q
- [ ] È una funzione simmetrica H(P,Q)=H(Q,P)

### Soluzione
$H(P,Q) = H(P) + KL(P\|Q)$; minima quando $P=Q$; non simmetrica.

## [mcq 1] [entropia / crossentropy] Selezionare la sentenza erronea relativa alla crossentropy H(P,Q) tra P e Q
- [ ] È uguale alla divergenza di kullback-Leibler KL(P,Q) più l’entropia H(P) di P
- [ ] Misura la logilikelihood di Q data la distribuzione di P
- [ ] Ha un valore minimo quando P=Q
- [x] È una funzione simmetrica H(P,Q)=H(Q,P)

### Soluzione
$H(P,Q)\ne H(Q,P)$ in generale: non è simmetrica (come la KL).

## [mcq 1] [entropia / crossentropy] Selezionare la sentenza errata relativa all’entropia per la distribuzione di probabilità di una variabile aleatoria discreta
- [ ] Il suo valore è minimo (e uguale a 0) quando la probabilità è tutta concentrata in una classe
- [ ] Il range del suo valore è tra 0 e log n dove n sono i possibili valori di X
- [ ] È una misura del grado di disordine della variabile aleatoria
- [x] Il suo valore è minimo (e uguale a 0) quando la probabilità è equamente distribuita tra tutte le classi

### Soluzione
Entropia massima ($\log n$) con distribuzione uniforme, minima (0) quando concentrata.

## [mcq 1] [entropia / crossentropy] Il range dell’entropia per la distribuzione di probabilità di una variabile aleatoria discreta è
- [ ] Tra 0 e 1
- [x] Tra 0 e log n dove n sono i possibili valori di x
- [ ] Tra 0 e infinito
- [ ] Tra -1 e 1

### Soluzione
$0 \le H(X) \le \log n$, con il massimo per la distribuzione uniforme.

## [mcq 1] [entropia / crossentropy] Una variabile aleatoria discreta con valori a,b e c ha la seguente distribuzione di probabilità: P(a)=1/4, P(b)=1/2, P(c)=1/4. Qual è la sua entropia?
- [x] 3/2
- [ ] Log(3)
- [ ] 4/5
- [ ] 5/4

### Soluzione
$H = -\sum p\log_2 p = \tfrac14\cdot2 + \tfrac12\cdot1 + \tfrac14\cdot2 = 3/2$ bit.

## [mcq 1] [entropia / crossentropy] Siano date le seguenti distribuzioni di probabilità P e Q: P(0)=3/8, P(1)=1/2, P(2)=1/8 and Q(0)=1/2, Q(1)=1/4, Q(2)=1/4. Quanto vale la crossentropy H(P|Q) tra P e Q?
- [x] 13/8
- [ ] 3/2+log(3)
- [ ] 5/2-log(3)/2
- [ ] 2

### Soluzione
$H(P,Q) = -\sum P\log_2 Q = \tfrac38\cdot1 + \tfrac12\cdot2 + \tfrac18\cdot2 = \tfrac38+1+\tfrac14 = 13/8$.

## [mcq 1] [funzione logistica] Selezionare la sentenza errata relativa alla derivata della funzione logistica
- [x] È una funzione monotona
- [ ] Tende a 0 quando x tende a -inf
- [ ] Ha il suo massimo in corrispondenza dello 0
- [ ] È una funzione simmetrica

### Soluzione
$\sigma'=\sigma(1-\sigma)$: campana simmetrica con massimo 1/4 in 0, tende a 0 ai due estremi → non monotona.

## [mcq 1] [funzione logistica] La derivata della funzione logistica δ(x) è
- [ ] δ(x)/ δ(1-x)
- [x] δ(x) * (1 – δ(x))
- [ ] δ(x) / (1 – δ(x))
- [ ] δ(x) * δ(1-x)

### Soluzione
$\sigma'=\sigma(1-\sigma)$: campana simmetrica con massimo 1/4 in 0, tende a 0 ai due estremi → non monotona.

## [mcq 1] [funzione loss in rete neurale] Quale funzione di loss è tipicamente utilizzata in una rete neurale per classificazione binaria che utilizza una sigmoid come attivazione finale?
- [ ] Categorical crossentropy
- [ ] Absolute error
- [x] Binary crossentropy
- [ ] Mean squared error

### Soluzione
Sigmoide + binary crossentropy per classificazione binaria.

## [mcq 1] [funzione loss in rete neurale] Quale funzione di loss è tipicamente utilizzata in una rete neurale per classificazione a categorie multiple che utilizza softmax come attivazione finale?
- [ ] Binary crossentropy
- [x] Categorical crossentropy
- [ ] Absolute error
- [ ] Mean squared error

### Soluzione
Softmax + categorical crossentropy per classificazione multiclasse.

## [mcq 1] [GAN] Selezionare la sentenza corretta:
- [ ] Una GAN è una rete che permette di generare attacchi per un qualunque modello predittivo
- [ ] Le GAN hanno una struttura encoder-decoder simile a quella di un autoencoder
- [x] Le GAN possono soffrire del fenomeno di “mode collapse” cioè la tendenza a focalizzare la generazione su un unico o pochi esempi
- [ ] Le GAN basano il loro training su una funzione di logilikelihood relativa ai dati generali

### Soluzione
Mode collapse: il generatore produce sempre pochi esempi simili che ingannano il discriminatore. Le GAN non sono encoder-decoder e non usano la log-likelihood.

## [mcq 1] [The formula for the output shape is given as] Il tensore di input di un layer convolutivo 2D ha dimensione (16,16,32). Sintetizzo 8 kernel con dimensione spaziale (3,3), stride 2, nessun padding (valid mode). Quale sarà la dimensione dell’output?
- [ ] (7,7,15)
- [ ] (8,8,8)
- [x] (7,7,8)
- [ ] (8,8,32)

### Soluzione
$\lfloor(16-3)/2\rfloor+1 = 7$, canali = 8 kernel → (7,7,8).

## [mcq 1] [The formula for the output shape is given as] Il tensore di input di un layer convolutivo 2D ha dimensione (32,32,8). Sintetizzo un unico kernel con dimensione spaziale (4,4), stride 2, nessun padding (valid mode). Quale sarà la dimensione dell’output?
- [ ] (16,16,1)
- [ ] (16,16,8)
- [ ] (15,15,8)
- [x] (15,15,1)

### Soluzione
$\lfloor(32-4)/2\rfloor+1 = 15$; un solo kernel → 1 canale: (15,15,1). Ogni kernel attraversa tutti i canali di input.

## [mcq 1] [The formula for the output shape is given as] Il tensore di input di un layer convolutivo 2D ha dimensione (16,16,8). Sintetizzo 4 kernel con dimensione spaziale (5,5), stride 2, nessun padding (valid mode). Quale sarà la dimensione dell’output?
- [x] (6,6,4)
- [ ] (8,8,8)
- [ ] (7,7,4)
- [ ] (7,7,8)

### Soluzione
$\lfloor(16-5)/2\rfloor+1 = 6$, canali = numero kernel = 4 → (6,6,4).

## [mcq 1] [The formula for the output shape is given as] Un layer convolutivo 2D con stride 1, kernel size 3x3, e senza padding prende in input un layer con dimensioni (32,32,3) e restituisce un layer di dimensione (32,32,16). Quanti sono i suoi parametri?
- [ ] 160
- [ ] 28
- [ ] 432
- [x] 448

### Soluzione
Parametri = $16\cdot(3\cdot3\cdot3+1) = 448$ (kernel × canali in × canali out + bias).

## [mcq 1] [The formula for the output shape is given as] Il numero dei parametri di un layer convolutivo dipende da:
- [ ] Unicamente dalle dimensioni dei layer di input e di output
- [ ] Lo stride dei kernel e di tutte le dimensioni di input e output, compresi i canali
- [x] La dimensione spaziale dei kernel e il numero dei canali di input e output
- [ ] Lo stride dei kernel e le dimensioni spaziali di input e output

### Soluzione
Parametri = $k_h k_w C_{in} C_{out} + C_{out}$: non dipendono da stride né dalle dimensioni spaziali dell'input.

## [mcq 1] [The formula for the output shape is given as] Un layer convolutivo 2D con stride 1, kernel size 1x1, e senza padding prende in input un layer con dimensioni (32,32,16) e restituisce un layer di dimensione (32,32,4). Quanti sono i suoi parametri?
- [ ] 2
- [x] 68
- [ ] 8
- [ ] 64

### Soluzione
Parametri = $1\cdot1\cdot16\cdot4 + 4$ bias = 68.

## [mcq 1] [Long-short term memory models (LSTMs)] Selezionare la sentenza scorretta relativa ai Long-Short Term Memory Models (LSTMs):
- [ ] Utilizzano delle particolari porte (gates) per gestire l’evoluzione della cella di memoria durante l’elaborazione di una sequenza di dati
- [ ] Sono una particolare tipologia di Rete Ricorrente
- [ ] Sono prevalentemente utilizzati per l’elaborazione di sequenze di dati
- [x] Sono prevalentemente utilizzati per la segmentazione di immagini mediche

### Soluzione
LSTM: reti ricorrenti con gate (input, forget, output) per sequenze (testo, audio, serie temporali).

## [mcq 1] [Long-short term memory models (LSTMs)] I long-short term memory models (LSTMs) sono modelli utilizzati prevalentemente per:
- [ ] Segmentazione per immagini mediche
- [x] Elaborazione di sequenze di dati
- [ ] Predirre traiettorie per agenti a guida autonoma
- [ ] Elaborazione di immagini

### Soluzione
LSTM: reti ricorrenti con gate (input, forget, output) per sequenze (testo, audio, serie temporali).

## [mcq 1] [MaxPooling (derivata)] Qual è la derivata della funzione di MaxPooling?
- [ ] L’identità
- [ ] Non è una funzione derivabile
- [x] 1 in corrispondenza del massimo e 0 altrove
- [ ] 1 ovunque

### Soluzione
Il gradiente passa solo all'elemento che era il massimo (derivata 1), 0 agli altri.

## [mcq 1] [Minibatch] Qual è l’effetto tipico dell’aumento della dimensione del minibatch durante il training?
- [ ] La backpropagation è effettuata più frequentemente e l'aggiornamento dei parametri è più accurato
- [ ] La backpropagation è effettuata più frequentemente ma l'aggiornamento dei parametri è meno accurato
- [ ] La backpropagation è effettuata meno frequentemente e l'aggiornamento dei parametri è meno accurato
- [x] La backpropagation è effettuata meno frequentemente ma l'aggiornamento dei parametri è più accurato

### Soluzione
Minibatch più grande → meno aggiornamenti per epoca ma gradiente meno rumoroso (più accurato).

## [mcq 1] [Minibatch] Qual è l’effetto tipico della riduzione della dimensione del minibatch durante il training?
- [ ] La backpropagation è effettuata più frequentemente e l'aggiornamento dei parametri è più accurato
- [x] La backpropagation è effettuata più frequentemente ma l'aggiornamento dei parametri è meno accurato
- [ ] La backpropagation è effettuata meno frequentemente e l'aggiornamento dei parametri è meno accurato
- [ ] La backpropagation è effettuata meno frequentemente ma l'aggiornamento dei parametri è più accurato

### Soluzione
Minibatch più piccolo → più aggiornamenti per epoca, gradiente più rumoroso (meno accurato).

## [mcq 1] [modelli generativi] Selezionare la sentenza scorretta riguardo i modelli generativi
- [ ] Un tipico esempio di tecnica generativa è Naive Bayes
- [ ] Sono modelli che cercano di apprendere la distribuzione di probabilità dei dati
- [ ] Generative adversarial networks, variational autoencoders e diffusion models sono esempi di tecniche generative profonde
- [x] Sono modelli meta-teorici rivolti alla automatizzazione della generazione di reti neurali

### Soluzione
Generativi: apprendono la distribuzione dei dati (Naive Bayes, GAN, VAE, diffusion). Non c'entra la generazione automatica di reti.

## [mcq 1] [modelli generativi] Con modelli generativi si intende:
- [ ] Il processo di automatizzazione della generazione di reti neurali
- [x] Modelli che cercano di apprendere la distribuzione di probabilità dei dati
- [ ] L’uso di attacchi avversariali allo scopo di aumentare la robustezza di modelli
- [ ] L’applicazione di tecniche genetiche al deep learning

### Soluzione
Generativi: apprendono la distribuzione dei dati (Naive Bayes, GAN, VAE, diffusion). Non c'entra la generazione automatica di reti.

## [mcq 1] [mutua informazione (information gain)] Selezionare la risposta scorretta relativa alla mutua informazione I(X,Y) tra due variabili aleatorie X e Y (anche detta Information Gain nel contesto degli alberi di decisione)
- [ ] È una funzione simmetrica I(X,Y)=I(Y,X)
- [x] Coincide con l’entropia H(Y|X) di Y dato X
- [ ] Può essere utilizzata per guidare la selezione degli attributi durante la costituzione di un albero di decisione
- [ ] Misura il guadagno di informazione su Y dopo aver osservato X

### Soluzione
$I(X;Y) = H(Y) - H(Y|X)$: è la *riduzione* di entropia, non $H(Y|X)$ stessa. È simmetrica.

## [mcq 1] [Naive Bayes] Selezionare la sentenza errata relativa alla tecnica Naive Bayes
- [ ] È una tecnica di tipo generativo in quanto cerca di determinare la distribuzione delle varie categorie dei dati
- [ ] Deriva dall’ipotesi teorica semplificativa che le features sono indipendenti tra loro, date le classi
- [x] Non può essere utilizzata se le features non sono tra loro indipendenti, date le classi
- [ ] Fornisce un modo computazionalmente efficiente per approssimare la distribuzione congiunta di probabilità delle features

### Soluzione
L'indipendenza è un'ipotesi semplificativa: Naive Bayes si usa (e funziona) anche quando non vale.

## [mcq 1] [Naive Bayes] Perché la tecnica Naive Bayes è detta “Naive” (ingenua)?
- [x] Perché suppone ingenuamente che le features siano indipendenti tra loro, date le classi
- [ ] Perché suppone ingenuamente che i dati di training rispecchino i dati reali
- [ ] Perché fornisce un modo semplice ma preciso di calcolare la distribuzione congiunta di probabilità delle features
- [ ] Perché suppone ingenuamente che la teoria possa avere applicazioni pratiche

### Soluzione
Assume l'indipendenza delle features data la classe: $P(x|c)=\prod_j P(x_j|c)$.

## [mcq 1] [Naive Bayes] Avendo 5 categorie di dati e 3 features di input booleane, quanti parametri indipendenti devono essere stimati secondo la tecnica Naive Bayes (compresi i priors)
- [ ] 15
- [ ] 16
- [x] 19
- [ ] 20

### Soluzione
Prior: 5 classi → 4 parametri liberi. Per ogni classe e feature booleana serve $P(x_j=1|c)$: 5·3 = 15. Totale **19**.

## [mcq 1] [neuroni artificiali] Selezionare la sentenza scorretta relativa ai neuroni artificiali
- [ ] Un neurone artificiale tipicamente calcola una combinazione lineare dei suoi input, seguita dalla applicazione di una funzione di attivazione non lineare
- [ ] Il numero dei parametri di un neurone artificiale è lineare nel numero dei suoi input
- [ ] Un neurone artificiale definisce un semplice modello matematico che simula il neurone biologico
- [x] Un neurone artificiale può apprendere qualunque funzione dei suoi input

### Soluzione
Un singolo neurone definisce un iperpiano: non può apprendere funzioni non linearmente separabili (es. XOR).

## [mcq 1] [neuroni artificiali] Selezionare la sentenza corretta
- [ ] Il numero dei parametri di un neurone artificiale è quadratico nella dimensione dei suoi input
- [x] Un neurone artificiale tipicamente calcola una combinazione lineare dei suoi input, seguita dalla applicazione di una funzione di attivazione non lineare
- [ ] Un neurone artificiale può apprendere qualunque funzione dei suoi input
- [ ] Un neurone artificiale può apprendere solo funzioni lineari

### Soluzione
Neurone = combinazione lineare + attivazione non lineare; parametri lineari negli input; da solo separa solo linearmente.

## [mcq 1] [Overfitting] Quale delle seguenti tecniche non può essere utilizzata per contrastare l’overfitting?
- [ ] Early stopping
- [ ] Data augmentation
- [ ] Introduzione di dropout layers
- [x] Aggiunta di skip connections

### Soluzione
Le skip connections aiutano il flusso del gradiente (reti profonde), non sono una regolarizzazione.

## [mcq 1] [Overfitting] Quale delle seguenti situazioni non è particolarmente problematica dal punto di vista dell’overfitting?
- [ ] Avere pochi dati di training
- [x] Avere dati molto rumorosi
- [ ] Disporre di un modello molto espressivo
- [ ] Effettuare un training molto prolungato

### Soluzione
Risposta ufficiale: 'dati molto rumorosi'. (Discutibile: il rumore favorisce l'overfitting; il prof la considera un problema di qualità dei dati più che di overfitting.)

## [mcq 1] [regressione logistica] Selezionare la sentenza scorretta riguardo alla regressione logistica
- [ ] Permette di associare una probabilità alla predizione della classe
- [ ] Il calcolo della predizione si basa sulla logilikelihood dei dati di training
- [ ] La predizione dipende dal bilanciamento dei dati di training rispetto alle classi
- [x] I parametri del modello possono essere tipicamente calcolati in forma chiusa, mediante una forma esplicita

### Soluzione
Nessuna forma chiusa: si minimizza la log-loss con discesa del gradiente. La predizione dipende dal bilanciamento delle classi (bias) e il training massimizza la log-likelihood.

## [mcq 1] [regressione logistica] Selezionare la sentenza errata riguardo alla regressione logistica
- [ ] Si basa su una combinazione lineare delle features in input
- [ ] La probabilità della predizione cresce se ci si allontana dalla superficie di confine tra le classi
- [x] Non dipende dal bilanciamento dei dati di training rispetto alle classi
- [ ] Nel caso di classificazione binaria la superficie di confine tra le classi è un iperpiano

### Soluzione
La logistica dipende dal bilanciamento delle classi (il bias assorbe i prior).

## [mcq 1] [regressione logistica] In quali di questi casi la regressione logistica potrebbe essere in difficoltà?
- [ ] Quando non tutte le features di input sono rilevanti ai fini della classificazione
- [ ] Quando esiste una elevata correlazione tra le features
- [x] Quando la classificazione dipende da un confronto tra le features
- [ ] Quando le features sono indipendenti tra loro, data la classe

### Soluzione
Modello lineare: non cattura relazioni tra features (es. XOR, $x_1 = x_2$).

## [mcq 1] [regressione logistica] Selezionare la sentenza corretta riguardo la regressione logistica
- [x] I parametri del modello sono tipicamente calcolati mediante discesa del gradiente
- [ ] La predizione non dipende dal bilanciamento dei dati di training rispetto alle classi
- [ ] I parametri del modello possono essere tipicamente calcolati in forma chiusa, mediante una formula esplicita
- [ ] Il calcolo della predizione non si basa sulla logilikelihood dei dati di training, in quanto si tratta di una tecnica discriminativa

### Soluzione
Si applica a qualunque funzione differenziabile; non serve convessità (si rischiano minimi locali).

## [mcq 1] [regressione multinomiale] Riguardo alla regressione multinomiale , selezionare la sentenza corretta tra le seguenti:
- [ ] Per n features di input e m classi, il numero dei parametri del modello cresce come O(n+m)
- [x] Il peso con cui è valutata ogni feature è tipicamente diverso per ogni classe
- [ ] I pesi delle features sono sempre tutti positivi, i bias possono essere negativi
- [ ] Per ogni input, esiste almeno una classe con probabilità >0.5

### Soluzione
Matrice di pesi $n\times m$: ogni classe pesa le features in modo diverso; $O(nm)$ parametri.

## [mcq 1] [regressione multinomiale] Riguardo alla regressione multinomiale , selezionare la sentenza errata tra le seguenti:
- [ ] Per n features di input e m classi, il numero dei parametri del modello è n xm+m
- [ ] Il peso con cui è valutata ogni feature è tipicamente diverso per ogni classe
- [ ] Il peso delle features indica la loro importanza ai fini della classificazione
- [x] Per ogni input, esiste almeno una classe con probabilità >0.5

### Soluzione
Con molte classi la probabilità massima può essere < 0.5 (es. 3 classi a 0.4/0.3/0.3).

## [mcq 1] [Regressione lineare] Selezionare la sentenza errata relativa alla regressione lineare
- [x] Cerca di determinare un iperpiano di separazione tra due categorie di dati
- [ ] Il problema di ottimizzazione ammette una soluzione in forma chiusa
- [ ] La funzione di loss è tipicamente una distanza quadratica tra i valori predetti e quelli osservati
- [ ] cerca di stabilire una relazione tra i valori di una variabile di output e i valori di una o più features di input

### Soluzione
La regressione lineare predice un valore continuo; l'iperpiano di separazione tra classi è un problema di classificazione.

## [mcq 1] [reti per classificazione di immagini] Quale di queste reti non è stata progettata per classificare immagini?
- [ ] Inception – v3
- [x] U-Net
- [ ] VGG19
- [ ] ResNet

### Soluzione
U-Net nasce per la segmentazione; Inception, VGG, ResNet sono classificatori.

## [mcq 1] [reti per classificazione di immagini] Quale è la tipica struttura per una rete neurale di classificazione delle immagini?
- [ ] Solo livelli densi
- [ ] Un encoder seguito da un decoder
- [x] Una sequenza alternata di convoluzioni e downsampling seguita da flattening e pochi livelli densi finali
- [ ] Una sequenza di convoluzioni che preservano la dimensione spaziale dell’input

### Soluzione
Convoluzioni + downsampling (pooling/stride) per estrarre features, poi flatten e pochi livelli densi.

## [mcq 1] [ReLU(x) (Rectified linear unit)] Selezionare la sentenza errata relativa alla funzione ReLU(x) (rectified linear unit)
- [ ] Lei o le sue varianti sono tipicamente utilizzate per i livelli interni delle reti neurali profonde
- [ ] La sua derivata è una funzione a gradino
- [ ] È una funzione monotona non decrescente
- [x] Non può essere usata per layer convoluzionali

### Soluzione
ReLU è l'attivazione standard anche nei layer convoluzionali.

## [mcq 1] [scomparsa del gradiente (vanishing gradient)] Selezionare la sentenza scorretta relativa al problema della scomparsa del gradiente (vanishing gradient)
- [x] Se il gradiente tende a zero anche i parametri e le attivazioni dei neuroni tendono a zero
- [ ] Se il gradiente tende a zero i parametri non sono più aggiornati e la rete smette di apprendere
- [ ] Il problema è mitigato dall’uso di link residuali all’interno della rete
- [ ] Il problema è fortemente attenuato dall’uso di ReLU (o sue varianti) come funzione di attivazione per i livelli nascosti della rete

### Soluzione
ReLU è l'attivazione standard anche nei layer convoluzionali.

## [mcq 1] [scomparsa del gradiente (vanishing gradient)] Il problema della scomparsa del gradiente (vanishing gradient) si riferisce ad una progressiva diminuzione dell’intensità del gradiente dovuta a
- [x] Backpropagation in reti profonde
- [ ] Dati troppo rumorosi o malamente processati
- [ ] Troppi pochi dati di training a disposizione
- [ ] Training eccessivamente lungo

### Soluzione
Nella backprop il gradiente si moltiplica per le derivate di ogni layer: in reti profonde (sigmoidi, derivata ≤ 1/4) si attenua esponenzialmente.

## [mcq 1] [Softmax] Selezionare la sentenza corretta relativa alla funzione softmax
- [ ] Non può essere utilizzata nel caso di una classificazione binaria
- [x] Restituisce una distribuzione di probabilità sulle classi
- [ ] Per una data classe, la somma dei valori su tutti gli input di un minibatch è sempre 1
- [ ] Produce valori compresi nell’intervallo [-1,1]

### Soluzione
Softmax restituisce una distribuzione sulle classi (valori in (0,1) che sommano a 1 per ogni input); con 2 classi equivale alla sigmoide.

## [mcq 1] [Softmax] Selezionare la sentenza errata relativa alla funzione softmax
- [ ] Generalizza la funzione logistica al caso multiclasse
- [ ] Permette di calcolare una distribuzione di probabilità sulle classi
- [ ] Per una dato input, la somma dei suoi valori su tutte le classi è sempre 1
- [x] Produce valori compresi nell’intervallo [-1,1]

### Soluzione
Softmax produce valori in (0,1) che sommano a 1, non in [-1,1].

## [mcq 1] [stride in un layer convolutivo] Qual è l’effetto di uno stride non unitario (>1) in un layer convolutivo?
- [x] La dimensione spaziale diminuisce
- [ ] Nessun effetto spaziale, il numero dei canali decresce
- [ ] La dimensione spaziale aumenta
- [ ] Nessun effetto spaziale, il numero dei canali aumenta

### Soluzione
Stride s > 1 riduce la dimensione spaziale di circa un fattore s.

## [mcq 1] [tecniche discriminative] Selezionare la sentenza corretta relativa alle tecniche discriminative
- [ ] Cercano di determinare le distribuzioni di probabilità delle varie classi di dati
- [x] Si focalizzano sulla definizione delle frontiere di decisione (decision boundaries)
- [ ] Si applicano per lo più in ambito di apprendimento non supervisionato
- [ ] Sono tipicamente meno espressive delle tecniche generative

### Soluzione
Discriminative: modellano il decision boundary / $P(y|x)$; le generative modellano $P(x|y)$.

## [mcq 1] [tecniche discriminative] Cosa si intende con tecniche discriminative?
- [ ] Tecniche tipiche di unsupervised learning che tentano di separare dati in cluster distinti
- [x] Tecniche di classificazione che si focalizzano sulla definizione delle frontiere di decisione (decision boundaries)
- [ ] Tecniche che cercano di discriminare i dati in base alle diverse distribuzioni di probabilità delle varie classi
- [ ] tecniche che cercano di identificare gli outliers all’interno dei data set

### Soluzione
Modellano direttamente $P(y|x)$ / il decision boundary (es. regressione logistica, SVM).

## [mcq 1] [tecnica a discesa del gradiente] selezionare la sentenza corretta relativa alla tecnica a discesa del gradiente
- [ ] permette sempre di individuare il minimo globale, se questo esiste
- [ ] il risultato non dipende dalla inizializzazione dei parametri del modello
- [ ] può essere applicata solo se la funzione da minimizzare ha una superficie concava
- [x] potrebbe convergere ad un minimo locale

### Soluzione
Non garantisce il minimo globale e dipende dall'inizializzazione: può fermarsi in un minimo locale.

## [mcq 1] [tecnica a discesa del gradiente] Selezionare la sentenza scorretta relativa alla tecnica a discesa del gradiente
- [ ] Potrebbe convergere ad un minimo locale
- [x] Può essere applicata solo se la funzione da minimizzare ha una superficie concava
- [ ] Il risultato può dipendere dalla inizializzazione dei parametri del modello
- [ ] È opportuno decrementare il learning rate verso la fine dell’apprendimento

### Soluzione
Non garantisce il minimo globale e dipende dall'inizializzazione: può fermarsi in un minimo locale.

## [mcq 1] [transposed convolutions] Selezionare la sentenza errata relativa alle transposed convolutions
- [ ] Possono essere interpretate come convoluzioni normali con stride sub- unitario
- [ ] Sono prevalentemente utilizzate in architetture per Image-to-Image processing, come autoencoders o U-Nets
- [ ] Sono essenzialmente equivalenti alla applicazione di un livello di upsampling seguito da una convoluzione normale
- [x] Richiedono la trasposizione dell’input prima di calcolare la convoluzione dei kernel

### Soluzione
'Trasposta' si riferisce alla matrice dell'operatore di convoluzione, non all'input.

## [mcq 1] [U-net] Selezionare la sentenza scorretta relativa alla U-Net
- [ ] È un componente tipico dei modelli generativi a diffusione
- [ ] È spesso impiegata per problemi di segmentazione semantica di immagini
- [ ] Può essere usata per la rimozione del rumore (denoising) di immagini
- [x] Viene spesso utilizzata nell’ambito della classificazione dei generi musicali

### Soluzione
Generativi: apprendono la distribuzione dei dati (Naive Bayes, GAN, VAE, diffusion). Non c'entra la generazione automatica di reti.

## [mcq 1] [U-net] Quale tra i seguenti è un tipico campo di applicazione della U-Net?
- [x] Segmentazione semantica
- [ ] Generazione musicale
- [ ] Object detection
- [ ] Natural Language Processing

### Soluzione
Segmentazione semantica (nata per immagini biomediche).

## [mcq 1] [Inception module] Selezionare la sentenza errata relativa all’ “inception module”
- [ ] Sfrutta kernel di dimensione diversa
- [ ] Tende a ridurre il costo computazionale sfruttando convoluzioni unitarie per diminuire il numero dei canali
- [x] Utilizza al proprio interno delle skip-connections per bypassare l’applicazione di parte dei kernel
- [ ] È un componente tipico della rete Inception-v3

### Soluzione
L'inception module usa kernel 1×1, 3×3, 5×5 in parallelo e convoluzioni 1×1 per ridurre i canali; le skip connections sono di ResNet.

## [mcq 1] [Minimi locali – fase training] Quale delle seguenti tecniche non può aiutare ad uscire dai minimi locali durante la fase di training?
- [ ] Ridurre la dimensione del minibatch
- [x] Fare clipping del gradiente in un range prefissato
- [ ] Aumentare il learning rate
- [ ] Aggiungere un “momento” al gradiente, cioè parte del gradiente del passo precedente

### Soluzione
Il clipping limita l'ampiezza del gradiente (contro l'exploding) ma non aiuta a uscire dai minimi; rumore (minibatch piccoli), learning rate alto e momento sì.

## [mcq 1] [Intersection over Union (IoU)] Selezionare la sentenza SCORRETTA relativa alla Intersection overUnion (IoU)
- [ ] E' frequentemente utilizzata come misura di similitudine tra bounding boxes
- [ ] Restituisce un valore nel range [0,1]
- [x] Non è una funzione simmetrica dei suoi input
- [ ] E' una metrica principalmente utilizzata nel campo della Object Detection

### Soluzione
IoU $=|A\cap B|/|A\cup B|$: simmetrica, in [0,1], tipica dell'object detection.
