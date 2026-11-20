---
titolo: Banca esercitazioni · argomenti di Ciancarini non presenti negli anni passati
durata: 60
fonte: Domande scritte da Claude sugli appunti e sulle slide 2026 di Ciancarini (Modulo 1: L1 produzione, L2 ciclo di vita, L3 processi agili/XP, L14 qualità e codice LLM; Essence; Constructor Fabric CF01-CF02; Il futuro dell'ingegneria del software). Non sono domande ufficiali del docente. Gli argomenti non compaiono negli scritti 2015-2025 né nella simulazione 2023.
---

## [mcq 1] Quali fasi compongono il ciclo di vita del software secondo le slide di Ciancarini (L2)?
- [x] Requisiti, progettazione, codifica e debugging, testing e verifica, deployment, manutenzione.
- [ ] Requisiti, progettazione, codifica, integrazione continua, rilascio, ritiro del prodotto.
- [ ] Studio di fattibilità, analisi, progettazione, codifica, collaudo, dismissione.
- [ ] Pianificazione, sprint planning, sviluppo, sprint review, retrospettiva, rilascio.

### Soluzione
Le sei fasi delle slide di L2: requisiti (analisi e specifica), progettazione (architettura e componenti), codifica e debugging, testing e verifica, deployment (messa in opera), manutenzione. Le altre opzioni mescolano nomi di Scrum o fasi non previste.

## [mcq 1] Nella distribuzione storica dei costi (Boehm, citato da Schach) che quota dei costi di un software cade sulla manutenzione?
- [ ] circa 10%
- [ ] circa 30%
- [x] circa 67%
- [ ] circa 90%

### Soluzione
Storicamente la manutenzione assorbe circa il 67% del costo totale; le slide mostrano anche uno scenario ipotetico GenAI (75%), che però non è un dato empirico. Conclusione: il costo sta soprattutto dopo il rilascio.

## [mcq 1] Nel report Standish CHAOS 2003 citato a lezione, quale percentuale di progetti software supera i tempi previsti?
- [ ] 48%
- [ ] 55%
- [ ] 66%
- [x] 82%

### Soluzione
Dall'analisi di 13.522 progetti: 66% falliscono (non producono un risultato utile), 82% superano i tempi, 48% producono sistemi senza tutte le funzioni richieste. Il dato sullo spreco è separato: 55 miliardi di dollari nei soli progetti USA.

## [mcq 1] Come definisce le slide la produttività dello sviluppo software?
- [ ] Numero medio di story point completati in uno sprint.
- [ ] Numero di difetti corretti per giorno/persona.
- [x] Rapporto tra software prodotto in LoC e sforzo in giorni/persona.
- [ ] Rapporto tra costo di sviluppo e numero di funzioni consegnate.

### Soluzione
Output/input: LoC per persona-giorno (es. 50 LoC per giorno/persona). Le slide ricordano che LoC è una misura discutibile: va letta con giudizio, come ogni metrica (vedi la legge di Goodhart a L14).

## [aperta 5] Spiegate il «costo del cambiamento» come presentato a L2: perché da esso nasce il modello a cascata, e perché le slide mettono in dubbio questa conclusione?

### Soluzione
Il grafico storico dice che un cambiamento costa tanto più quanto più tardi avviene; ne segue la scelta di prendere tutte le decisioni importanti all'inizio (waterfall). Le slide chiedono «ma è davvero così?»: i metodi agili riducono il costo del cambiamento con sviluppo iterativo, feedback frequente e architetture modulari, quindi il costo non cresce in modo così netto con il tempo.

### Griglia
- 1 | enuncia la relazione costo del cambiamento / tempo
- 1 | collega la conclusione al modello a cascata (decisioni tutte all'inizio)
- 2 | spiega perché l'agile mette in dubbio la premessa (iterazioni, feedback, rischi emersi presto)
- 1 | cita un esempio o un meccanismo concreto (test, refactoring, architettura modulare)

### Griglia
- 1 | enuncia la relazione costo del cambiamento / tempo
- 1 | collega la conclusione al modello a cascata (decisioni tutte all'inizio)
- 2 | spiega perché l'agile mette in dubbio la premessa (iterazioni, feedback, rischi emersi presto)
- 1 | cita un esempio o un meccanismo concreto (test, refactoring, architettura modulare)

## [mcq 1] Che cosa intende la slide «Il nuovo silver bullet? Gli LLM» in continuità con Brooks?
- [x] Nessuno strumento da solo garantisce un salto di produttività: la complessità essenziale del problema resta.
- [ ] Gli LLM sono il primo strumento che elimina la complessità essenziale, come Brooks aveva previsto.
- [ ] Gli LLM rendono superflua la progettazione, perché il codice si può rigenerare a ogni modifica.
- [ ] Gli LLM eliminano la complessità accidentale, quindi i progetti software non sono più in ritardo.

### Soluzione
«No Silver Bullet» (Brooks): la complessità essenziale (capire e specificare il problema) non si elimina con uno strumento. Gli LLM riducono la complessità accidentale, ma non quella essenziale: il tema della lezione è distinguere le due cose.

## [mcq 1] Quali sono i sette Alpha del Kernel di Essence?
- [ ] Requisiti, codice, test, deployment, manutenzione, costi, team.
- [x] Opportunità, Stakeholder, Requisiti, Sistema software, Lavoro, Team, Modo di lavorare.
- [ ] Customer, Solution, Endeavor, Sprint, Backlog, Review, Retrospective.
- [ ] Idea, Prototipo, MVP, Release, Feedback, Stabilizzazione, Chiusura.

### Soluzione
I sette Alpha sono Opportunità e Stakeholder (area Customer), Requisiti e Sistema software (area Solution), Lavoro, Team e Modo di lavorare (area Endeavor). Gli Alpha sono elementi da far progredire, non fasi.

## [mcq 1] In quale area di interesse di Essence rientrano gli Alpha «Opportunità» e «Stakeholder»?
- [x] Customer
- [ ] Solution
- [ ] Endeavor
- [ ] Nessuna: sono Alpha trasversali alle tre aree

### Soluzione
Customer: valore per utenti e stakeholder, focus sui bisogni reali. Solution: requisiti e sistema software. Endeavor: lavoro, team e modo di lavorare.

## [mcq 1] Essence va inteso come…
- [ ] un metodo agile completo, da adottare in alternativa a Scrum e Kanban
- [x] un metamodello standard OMG che descrive la struttura di qualsiasi metodo e si integra con Scrum e Kanban
- [ ] un linguaggio di modellazione standard OMG che estende UML con i diagrammi degli Alpha
- [ ] un framework di scaling che coordina più team Scrum che lavorano sullo stesso prodotto

### Soluzione
Essence non impone un processo: fornisce un kernel comune di concetti e un linguaggio per descrivere, confrontare e integrare pratiche. Scrum e Kanban restano, e Essence aiuta a vedere cosa manca.

## [mcq 1] Come si svolge il «Progress Poker» con le carte Alpha?
- [ ] Il facilitatore propone lo stato di ogni Alpha e il team lo approva o lo corregge a voce.
- [x] Ognuno sceglie in privato lo stato supportato dalle evidenze, le carte si rivelano insieme e le differenze guidano la discussione.
- [ ] Ognuno vota a turno lo stato che desidera e si adotta quello che ottiene la maggioranza.
- [ ] Ognuno stima in privato i punti di ogni carta e si adotta la media delle stime.

### Soluzione
Scelta indipendente e rivelazione simultanea evitano che il primo a parlare orienti gli altri; le differenze (dove sta il disaccordo) sono l'input della discussione, e l'accordo raggiunto va registrato insieme ai dubbi residui.

## [aperta 4] Un team di progetto mostra questo quadro: il software è «Demonstrable» (prototipo che funziona in uno scenario), mentre «Requisiti» è solo «Bounded at best» (interviste e backlog, ma privacy non risolta). Qual è l'anomalia principale e quale passo è più urgente?

### Soluzione
L'anomalia è il disallineamento tra una soluzione dimostrabile e requisiti non stabilizzati (privacy). L'urgenza è stabilire l'accordo degli stakeholder sugli scenari sensibili alla privacy e sui criteri di accettazione, prima di estendere l'implementazione: una pipeline più forte non compensa un requisito non limitato.

### Griglia
- 1 | identifica l'anomalia (software avanzato, requisiti poco limitati)
- 1 | spiega perché il software «dimostrabile» non basta a un sistema usabile
- 1 | propone un passo concreto legato a un checkpoint verificabile (accordo con gli stakeholder, criteri di accettazione)
- 1 | distingue stato corrente e stato successivo, e cita le evidenze

## [mcq 1] Nel linguaggio di Essence, cos'è un checkpoint?
- [x] Un'affermazione verificabile, sostenuta da evidenze o da un accordo informato, che dice se uno stato è raggiunto.
- [ ] Una scadenza intermedia del progetto, fissata dal Product Owner nel piano di rilascio.
- [ ] Un test automatico eseguito a ogni integrazione per verificare lo stato del sistema.
- [ ] La riunione di fine sprint in cui il team aggiorna le carte degli Alpha.

### Soluzione
Un checkpoint trasforma un giudizio in una conversazione basata su evidenze. Una aspirazione vaga («il team è maturo») non può stabilire uno stato. Lo stato corrente è l'ultimo che il team riesce a sostenere, non quello in cui il piano dice di trovarsi.

## [mcq 1] Essence sostituisce Scrum?
- [ ] Sì: Essence definisce già ruoli ed eventi, quindi Scrum diventa superfluo.
- [x] No: Essence non sostituisce Scrum, Kanban o SAFe, ma li integra e aiuta a individuarne le lacune.
- [ ] Sì, ma solo nei progetti grandi, dove Scrum da solo non scala.
- [ ] No: Essence si usa solo prima del progetto, Scrum durante lo sviluppo.

### Soluzione
Le slide insistono su integrazione, non sostituzione: Essence fornisce un linguaggio comune per dire cosa fa uno Scrum, cosa manca e come combinarlo con altre pratiche.

## [mcq 1] Nella slide su Dropbox, cosa illustra il caso di MVP citato a L3?
- [ ] Il lancio di una versione con poche funzioni ma completa, per acquisire i primi clienti paganti.
- [x] Un video dimostrativo del prodotto, girato prima di costruire il sistema, per verificare l'interesse degli utenti.
- [ ] Una versione beta distribuita a pochi utenti per trovare i difetti prima del rilascio pubblico.
- [ ] Un prototipo usa-e-getta costruito per scegliere l'architettura del sistema di sincronizzazione.

### Soluzione
MVP: apprendere con il minimo sforzo. Dropbox ha mostrato il prodotto prima che fosse completo, per misurare l'interesse. Un MVP dà valore e permette di imparare dal mercato con il minimo rischio.

## [mcq 1] Cosa significa YAGNI, principio citato nelle slide XP (L3)?
- [ ] You Always Get New Iterations: ogni sprint porta nuove funzioni.
- [x] You Aren't Gonna Need It: non implementare ciò che non serve ora.
- [ ] Your Architecture Gets Naturally Integrated: l'architettura emerge.
- [ ] Yes, Always Go New Interfaces: si preferiscono le interfacce.

### Soluzione
YAGNI: si costruisce solo ciò che serve alla user story corrente. Un'astrazione prematura è un costo, non un investimento, e si aggiunge quando serve (con il refactoring).

## [mcq 1] La pratica XP di «integrazione continua» prevede:
- [ ] integrare ogni modifica nella linea principale al termine dello sprint, dopo la review
- [x] integrare spesso, più volte al giorno, con test automatici eseguiti a ogni integrazione
- [ ] sviluppare ogni funzionalità su un ramo dedicato e unirla alla linea principale quando è completa
- [ ] rilasciare automaticamente agli utenti ogni modifica che compila senza errori

### Soluzione
Integrazione frequente riduce i conflitti e rileva i problemi subito, con build e test automatici. È una pratica distinta dal deploy continuo, anche se si sostengono a vicenda.

## [mcq 1] Nella programmazione in coppia, cosa fa il «navigatore»?
- [ ] scrive il codice mentre il pilota lo rivede e pensa alla strategia
- [x] rivede ciò che il pilota scrive e pensa alla strategia e ai prossimi passi
- [ ] scrive i test mentre il pilota scrive il codice che li deve superare
- [ ] cerca documentazione ed esempi mentre il pilota scrive il codice

### Soluzione
Pilota e navigatore si alternano: chi scrive è concentrato sul dettaglio, chi guarda pensa alla direzione e alle possibili falle. Le slide mostrano che la coppia riduce i difetti, ma con costi di tempo da valutare.

## [mcq 1] Che cosa indica la «proprietà collettiva del codice» in XP?
- [ ] Ogni modulo ha un responsabile, che deve approvare le modifiche fatte dagli altri.
- [x] Chiunque nel team può modificare qualsiasi parte del codice, purché i test restino verdi.
- [ ] Il codice appartiene all'organizzazione e non ai singoli programmatori che lo scrivono.
- [ ] Il codice è condiviso con il cliente, che può proporre modifiche direttamente nel repository.

### Soluzione
Nessun collo di bottiglia su singole persone; la sicurezza viene dai test e dall'integrazione continua. È il contrario del «codice mio, non lo tocchi».

## [aperta 4] Descrivi una user story secondo il modello «scheda, conversazione, conferma» presentato in L3 e fai un esempio con il caso guida del parcheggio.

### Soluzione
La scheda è il promemoria breve (chi, cosa, perché); la conversazione è il dialogo con il cliente, dove il dettaglio emerge; la conferma sono i criteri di accettazione verificabili (test di accettazione). Esempio: «Come abbonato voglio pagare l'abbonamento annuale per avere lo stallo riservato»; conferma: «dato un abbonamento attivo, quando pago per un anno, il sistema assegna lo stallo e invia la ricevuta».

### Griglia
- 1 | scheda: formato breve, promemoria della storia
- 1 | conversazione: dettaglio costruito con il cliente
- 1 | conferma: criteri di accettazione verificabili (test)
- 1 | esempio coerente con il caso del parcheggio

## [mcq 1] Nella slide «LLM come Scrum Master», quale compito può ragionevolmente essere delegato a un LLM?
- [x] sintetizzare il Daily e proporre l'agenda della Retrospective
- [ ] decidere lo Sprint Goal e l'ordine del Product Backlog
- [ ] gestire i conflitti e la sicurezza psicologica nel team
- [ ] rimuovere gli impedimenti organizzativi e politici del team

### Soluzione
L'LLM supporta con sintesi e analisi. Le decisioni, le dinamiche di gruppo, i conflitti e la responsabilità restano alle persone: empatia, sicurezza psicologica e leadership non si delegano.

## [mcq 1] Quale limite è indicato per un LLM usato come Scrum Master?
- [ ] non sa analizzare metriche come lead time, WIP e burndown
- [x] non sa gestire empatia, dinamiche di gruppo e conflitti
- [ ] non sa preparare un'agenda per la Retrospective
- [ ] non sa riassumere quanto emerso nel Daily Scrum

### Soluzione
Il ruolo dello SM ha una parte tecnica (automatizzabile in parte) e una parte relazionale, che non si delega.

## [mcq 1] Nel caso Mars Climate Orbiter (1999), la perdita della sonda è:
- [ ] un errore (error)
- [x] un guasto (failure)
- [ ] un difetto (fault)
- [ ] una violazione (violation)

### Soluzione
Errore: l'interpretazione sbagliata (unità imperiali o metriche). Difetto: il codice che usa l'unità sbagliata. Guasto: il comportamento osservabile non previsto, cioè la perdita della sonda (IEEE 610.12).

## [mcq 1] Quale definizione descrive correttamente un «difetto» secondo le slide di L14?
- [ ] un'azione umana sbagliata nell'interpretare la specifica
- [x] un'imperfezione nel codice o in un documento, causa di un guasto
- [ ] il comportamento osservabile non previsto dalla specifica
- [ ] una richiesta di modifica non approvata

### Soluzione
Errore (azione umana), difetto (imperfezione nel prodotto, detto anche fault o bug), guasto (failure osservabile). Un difetto latente può restare silente finché non causa un guasto.

## [mcq 1] Qualità interna, esterna e in uso: quale si misura senza eseguire il sistema?
- [x] la qualità interna
- [ ] la qualità esterna
- [ ] la qualità in uso
- [ ] nessuna: ogni qualità richiede di eseguire il sistema

### Soluzione
Interna: si misura sul prodotto non eseguito. Esterna: si misura eseguendo (test). In uso: nel contesto reale con gli utenti, con la norma ISO/IEC 25019.

## [mcq 1] Quale caratteristica è stata aggiunta nel modello di qualità ISO/IEC 25010:2023 rispetto alla versione precedente?
- [ ] Usabilità
- [ ] Portabilità
- [x] Safety
- [ ] Manutenibilità

### Soluzione
Nel 2023 la Safety diventa una caratteristica di primo livello, accanto a Security. Usabilità, portabilità e manutenibilità esistevano già (con nomi o posizioni diversi).

## [mcq 1] Nel metodo Goal-Question-Metric, «Il codice rispetta lo standard di codifica?» è:
- [ ] un goal
- [ ] una metrica
- [ ] un modello di qualità
- [x] una question

### Soluzione
Goal (obiettivo, es. valutare l'affidabilità), Question (domanda operativa che verifica il goal), Metric (misura quantitativa, es. violazioni per modulo). La metrica sarebbe il numero di violazioni per modulo.

## [aperta 5] Costruisci un piano GQM per valutare la qualità di una funzione che gestisce i prestiti di una biblioteca: definisci un goal, due domande e per ciascuna una metrica.

### Soluzione
Esempio. Goal: valutare la correttezza della gestione prestiti dal punto di vista del team, nel prossimo semestre. Q1: quanti difetti emergono dopo il rilascio? Metrica: difetti post-rilascio per KLOC. Q2: il codice rispetta il limite di prestiti attivi? Metrica: casi di test di valore limite superati / casi totali. Attenzione alla legge di Goodhart: la metrica deve descrivere il goal, non diventarne l'obiettivo.

### Griglia
- 1 | goal chiaro, con prospettiva e periodo
- 1 | prima question operativa
- 1 | metrica quantitativa coerente con la question
- 1 | seconda question operativa
- 1 | metrica quantitativa coerente con la seconda question

## [num 2 = 3] Un programma ha un grafo di controllo con N = 6 nodi e E = 7 archi. Quale è la complessità ciclomatica V(G)? (inserire un numero intero)

### Soluzione
V(G) = E − N + 2 = 7 − 6 + 2 = 3. Corrisponde al numero di cammini linearmente indipendenti, e quindi a un limite inferiore di test per la copertura dei cammini.

## [num 2 = 5] Un grafo di controllo ha E = 10 archi e N = 7 nodi. Quale è la complessità ciclomatica V(G)? (inserire un numero intero)

### Soluzione
V(G) = 10 − 7 + 2 = 5.

## [mcq 1] Un requisito dice: «un iscritto può avere al massimo 5 prestiti attivi». Quali valori sono i candidati al test di valori limite?
- [ ] 0, 1, 2
- [ ] 3, 4, 5
- [x] −1, 0, 5, 6
- [ ] 10, 20, 50

### Soluzione
Valori limite: appena sotto il minimo (−1), il minimo (0), il massimo (5), appena sopra il massimo (6). Le classi di equivalenza aggiungono un rappresentante per ciascuna zona (es. 3, valido).

## [mcq 1] Per il programma «if (P+Q > 10) print …; if (P > 50) print …», quanti test minimi servono per la copertura delle decisioni?
- [ ] 1
- [x] 2
- [ ] 3
- [ ] 4

### Soluzione
Per i comandi basta 1 test (es. P = 60, Q = 0). Per le decisioni, ciascuna condizione deve essere vera e falsa almeno una volta: servono almeno 2 test, per esempio (60, 0) e (0, 0). Per i cammini ne servono 4.

## [mcq 1] Il «test esaustivo» di un sistema con 10 parametri e 5 valori ciascuno quanto costa, in casi?
- [ ] 50 casi (10 × 5)
- [ ] circa 100.000 casi (10 alla quinta)
- [x] circa 9,8 milioni di casi (5 alla decima)
- [ ] 1.024 casi (2 alla decima)

### Soluzione
5^10 ≈ 9,8 milioni: impossibile da eseguire in pratica. Per questo si scelgono classi di equivalenza e valori limite.

## [mcq 1] Qual è la forma della piramide dei test presentata a L14?
- [ ] molti test end-to-end, meno di integrazione, pochi di unità
- [x] molti test di unità, meno di integrazione, pochi end-to-end
- [ ] molti test di integrazione, meno di unità, pochi end-to-end
- [ ] lo stesso numero di test di unità, di integrazione ed end-to-end

### Soluzione
Più si sale verso E2E, più i test sono lenti, fragili e costosi. L'anti-pattern «cono gelato» (molti E2E manuali, pochi unitari) è il contrario della piramide.

## [mcq 1] Nel quadrante del debito tecnico, quale situazione è «prudente e consapevole»?
- [ ] «Non abbiamo tempo per il progetto»
- [x] «Rilasciamo ora e ne gestiamo le conseguenze»
- [ ] «Che cos'è la stratificazione?»
- [ ] «Ora sappiamo come avremmo dovuto farlo»

### Soluzione
Il debito tecnico (Cunningham, Fowler) ha capitale (la correzione rinviata) e interessi (le modifiche future costano di più). È prudente se consapevole: lo si decide e lo si ripaga con il refactoring protetto dai test.

## [mcq 1] Nel quality gate predefinito «Sonar way» presentato a L14, quali sono le condizioni sul codice nuovo?
- [ ] 0 bug totali, copertura 100%, duplicazione 0%, rating B
- [x] 0 nuovi problemi, copertura ≥ 80%, duplicazione ≤ 3%, security hotspot tutti rivisti
- [ ] 0 nuovi problemi, copertura ≥ 50%, duplicazione ≤ 10%, security hotspot facoltativi
- [ ] 0 vulnerabilità totali, copertura ≥ 80%, duplicazione ≤ 5%, rating C

### Soluzione
Il gate giudica il codice nuovo o modificato (Clean as You Code). Le soglie sono un esempio: vanno decise dal team, meglio con GQM.

## [mcq 1] Il principio «Clean as You Code» significa che:
- [ ] prima di ogni rilascio si elimina tutto il debito tecnico del codice esistente
- [x] chi tocca il codice lo lascia pulito e il debito pregresso si ripaga gradualmente
- [ ] l'analisi statica si applica solo al codice scritto da zero, mai a quello esistente
- [ ] ogni sviluppatore ripulisce il codice degli altri prima di aggiungere il proprio

### Soluzione
Il quality gate valuta il codice nuovo: così il miglioramento avviene a ogni modifica senza bloccare il progetto con un intervento massiccio.

## [aperta 4] Spiegate la legge di Goodhart («quando una misura diventa un obiettivo, smette di essere una buona misura») con un esempio legato ai test.

### Soluzione
Se la copertura diventa l'obiettivo, si scrivono test che eseguono il codice senza asserzioni: la copertura sale, ma nessun comportamento è verificato. Lo stesso vale per la velocity gonfiata o le righe di codice come «produttività». La metrica va usata per capire, non come premio.

### Griglia
- 1 | enuncia la legge
- 1 | esempio concreto con copertura o test
- 1 | spiega il meccanismo (la metrica diventa il bersaglio e perde significato)
- 1 | indica come limitarlo (metriche multiple, GQM, lettura umana)

## [mcq 1] Il motto «il testing illumina, non dimostra» (Dijkstra) significa che:
- [x] un test che passa non prova l'assenza di errori: i test possono solo mostrarne la presenza
- [ ] i test illuminano il comportamento del codice, ma solo la revisione dimostra la presenza di errori
- [ ] con una copertura del 100% i test dimostrano anche l'assenza di errori
- [ ] i test servono a documentare il comportamento del codice più che a trovare errori

### Soluzione
Il testing non dimostra la correttezza: serve a trovare errori. Per questo servono più filtri (unità, integrazione, analisi statica, quality gate) e test scritti con criterio.

## [mcq 1] Secondo lo studio Liu et al. (NeurIPS 2023), con test più rigorosi quante soluzioni «corrette» di codice generato da LLM risultano sbagliate?
- [ ] circa 1–3%
- [x] circa 19–29%
- [ ] circa 50–60%
- [ ] circa 80–90%

### Soluzione
Con HumanEval+ (circa 80 volte più test) le soluzioni che passavano il benchmark originale falliscono in una quota significativa. Test deboli sovrastimano la correttezza.

## [mcq 1] Nello studio GitClear 2025 sul codice assistito dall'IA, che cosa segna un cambiamento importante nel 2024?
- [ ] per la prima volta le righe spostate superano quelle copiate e incollate
- [x] per la prima volta le righe copiate e incollate superano quelle spostate
- [ ] per la prima volta i blocchi duplicati diminuiscono rispetto all'anno precedente
- [ ] per la prima volta le righe rifattorizzate superano quelle aggiunte

### Soluzione
Righe spostate = indicatore di refactoring e riuso; righe copiate = duplicazione e debito. Il dato è un rapporto industriale, correlazione e non esperimento controllato: va letto con cautela.

## [mcq 1] Nello studio METR 2025 su sviluppatori esperti, la velocità reale con l'IA rispetto a senza IA era:
- [ ] +24%
- [ ] +20%
- [x] −19%
- [ ] +55,8%

### Soluzione
Gli sviluppatori prevedevano un guadagno e percepivano un vantaggio, ma la misura mostrava un rallentamento: percezione e misura divergono. Il +55,8% riguarda un compito isolato (studio Peng et al.), non il lavoro esperto reale.

## [mcq 1] Un assistente IA propone di importare un pacchetto «fastjsonx» che nessuno conosce. Qual è il rischio principale?
- [ ] la licenza del pacchetto potrebbe essere incompatibile con quella del progetto
- [ ] il pacchetto potrebbe essere più lento della libreria standard
- [x] il pacchetto potrebbe essere inventato dal modello e registrato da un attaccante
- [ ] il pacchetto potrebbe non essere più mantenuto dai suoi autori

### Soluzione
Gli LLM allucinano nomi di pacchetti (Spracklen et al.). Verificare sempre le dipendenze: esistenza, autore, popolarità, licenza.

## [mcq 1] Quale metrica è da evitare per valutare il successo di un assistente IA nel team?
- [ ] difetti post-rilascio per KLOC
- [ ] nuove vulnerabilità per pull request
- [ ] lead time e tasso di rilasci falliti
- [x] numero di righe generate dall'IA

### Soluzione
Le righe generate misurano l'uso dello strumento, non la qualità: è un caso tipico di legge di Goodhart. Le metriche devono seguire le caratteristiche ISO 25010 (correttezza, sicurezza, manutenibilità, produttività).

## [aperta 4] Quali rischi specifici ha il codice generato da LLM, e quali domande di revisione farebbe prima di accettarlo in un progetto?

### Soluzione
Rischi: correttezza non verificata (test deboli), sicurezza (vulnerabilità ricorrenti, dipendenze inventate), manutenibilità (duplicazione, debito), produttività percepita ma non misurata. Domande: chi ha letto questo codice? i test sono stati scritti senza guardare il codice? le dipendenze esistono e sono affidabili? chi ne risponde? Quality gate e Definition of Done a valle.

### Griglia
- 1 | correttezza: test indipendenti e valori limite
- 1 | sicurezza: analisi statica, dipendenze, vulnerabilità tipiche
- 1 | manutenibilità: duplicazione e complessità
- 1 | almeno due domande di revisione (chi ha letto, test indipendenti, dipendenze, responsabilità)

## [mcq 1] Constructor Fabric, secondo le slide CF01, è:
- [ ] un IDE AI-native open source, alternativo a Cursor, con il comando cfs
- [x] una piattaforma open source AI-native che collega plan, build e run in un flusso tracciabile
- [ ] un modello linguistico open-weight specializzato nella generazione di codice tracciabile
- [ ] un servizio cloud che esegue build, test e deploy del codice generato dagli agenti

### Soluzione
Constructor Fabric (con Constructor Studio, comando cfs) mette un processo ingegneristico attorno agli strumenti di AI coding: dai requisiti alla produzione, con artefatti collegati e verificati.

## [mcq 1] Nella pipeline di Constructor Fabric, a che cosa serve il PRD?
- [ ] a registrare le decisioni architetturali con contesto, opzioni e conseguenze
- [x] a definire scopo e requisiti, ciascuno con un ID CPT e una priorità
- [ ] a descrivere architettura, componenti e data model del sistema
- [ ] a specificare flussi, stati e algoritmi di una singola feature

### Soluzione
Il PRD (scopo, attori, scope, requisiti funzionali e non, criteri di accettazione, rischi). Gli ID CPT permettono di seguire il requisito fino al codice.

## [mcq 1] Nella pipeline di Constructor Fabric, come deve comportarsi la skill DESIGN?
- [ ] proporre un'architettura a partire da una richiesta di una riga, senza documenti di input
- [x] trasformare documenti già approvati, PRD e ADR, in architettura, componenti e data model
- [ ] scrivere prima il codice e poi ricavarne l'architettura con il reverse engineering
- [ ] scegliere da sola, tra le opzioni dell'ADR, quella con meno rischi

### Soluzione
Gli input devono essere nominati e approvati: la skill trasforma, non inventa. Ogni driver porta il CPT ID del requisito a cui risponde.

## [mcq 1] Che cosa garantisce `cfs validate` (CF01/CF02)?
- [ ] che il software si comporta come richiesto dai criteri di accettazione
- [x] che i documenti hanno struttura, sezioni, riferimenti e ID corretti
- [ ] che il codice non contiene vulnerabilità note né dipendenze inventate
- [ ] che ogni requisito del PRD ha almeno un test che lo verifica

### Soluzione
Validate controlla forma e consistenza, in modo deterministico. Un validate verde non dice che il software funziona: resta necessaria la review umana.

## [mcq 1] Nella fase di Decompose di Constructor Fabric, quale regola di copertura vale?
- [ ] ogni componente, sequenza ed elemento dati può comparire in più feature
- [x] ogni componente, sequenza ed elemento dati appartiene a esattamente una feature
- [ ] ogni feature deve contenere almeno un componente, una sequenza e un elemento dati
- [ ] ogni componente appartiene a una sola feature, mentre sequenze e dati restano condivisi

### Soluzione
Esattamente una feature per elemento: niente sovrapposizioni né buchi. La lista è ordinata per dipendenze, così un lavoro grande diventa pezzi rivedibili.

## [aperta 4] Perché in Constructor Fabric la review del codice si fa in una chat nuova o con un sub-agent, e non nella stessa conversazione che ha scritto il codice?

### Soluzione
Il contesto di scrittura porta con sé le assunzioni di chi ha scritto: la review tende a confermarle. Una chat nuova o un sub-agent, che non vede il ragionamento precedente, guarda il codice con occhi più indipendenti. Resta comunque una review umana finale.

### Griglia
- 1 | identifica il problema delle assunzioni condivise (bias di conferma)
- 1 | spiega cosa cambia con una chat nuova o un sub-agent
- 2 | ricorda la necessità della review umana finale e la differenza tra chi scrive e chi revisiona

## [mcq 1] Il progetto SEMAT e l'Essence: quali date e fondatori sono citati nelle slide «Il futuro dell'ingegneria del software»?
- [x] 2009 nasce SEMAT con Jacobson, Meyer e Soley; 2014 Essence diventa standard OMG
- [ ] 2001 nasce SEMAT con gli autori del Manifesto agile; 2009 Essence diventa standard OMG
- [ ] 1968 nasce SEMAT alla conferenza NATO; 2012 Essence diventa standard IEEE
- [ ] 2009 nasce SEMAT con Beck, Fowler e Cunningham; 2014 Essence diventa standard ISO

### Soluzione
SEMAT (Software Engineering Method and Theory) nasce nel 2009; il Kernel viene specificato nel 2012; nel 2014 Essence diventa standard OMG. Jacobson è considerato il padre del framework.

## [mcq 1] Le forme dei requisiti (Ciancarini 2026): quale definizione di requisito dà lo standard IEEE 610.12?
- [x] Una condizione o capacità necessaria a un utente, o che un sistema deve possedere per soddisfare un contratto o una specifica.
- [ ] Una descrizione di come il sistema sarà realizzato, concordata tra il cliente e il team di sviluppo.
- [ ] Una funzionalità richiesta dal cliente, scritta come user story e accettata dal Product Owner.
- [ ] Un comportamento atteso del sistema, espresso come caso di test da superare prima del rilascio.

### Soluzione
IEEE 610.12 definisce il requisito come condizione o capacità, vista dal lato dell'utente (risolvere un problema) e dal lato contrattuale (rispettare contratto, standard, specifica). Dice *cosa*, non *come*.

## [mcq 1] Che cosa esprime la legge di Humphrey (e l'acronimo IKIWISI) citata nella lezione sulle forme dei requisiti?
- [ ] Il costo di correggere un requisito cresce di dieci volte a ogni fase.
- [x] Gli utenti non sanno cosa vogliono finché non vedono il sistema: «I'll Know It When I See It».
- [ ] Ogni requisito deve essere indipendente, negoziabile e testabile.
- [ ] Aggiungere persone a un progetto in ritardo lo ritarda ancora di più.

### Soluzione
Humphrey: per un nuovo sistema software i requisiti non saranno completamente noti finché gli utenti non lo usano. Da qui IKIWISI e il valore di prototipi, iterazioni brevi e feedback. La terza opzione è INVEST, la quarta è la legge di Brooks.

## [mcq 1] Nella classificazione delle slide, «Il sistema deve essere scritto in Python e girare su Linux» è un requisito:
- [ ] funzionale
- [ ] di qualità
- [x] di vincolo
- [ ] di business

### Soluzione
Tre tipi di requisiti: funzionali (cosa fa il sistema), di qualità (quanto bene lo fa, ISO/IEC 25010) e vincoli (limiti imposti alla soluzione: linguaggio, piattaforma, norme, budget). Linguaggio e sistema operativo sono vincoli tecnici.

## [mcq 1] Quale formulazione rende misurabile il requisito di qualità «il sistema deve essere veloce»?
- [ ] Il sistema deve essere molto veloce e reattivo in ogni situazione d'uso.
- [ ] Il sistema deve usare una cache e un indice per rispondere velocemente.
- [x] Il 95% delle ricerche deve rispondere entro 1 secondo con 500 utenti concorrenti.
- [ ] Il sistema deve rispondere più velocemente del sistema che sostituisce.

### Soluzione
Un requisito di qualità è utile solo se verificabile: serve una metrica, una soglia e le condizioni di misura. «Usare una cache» è una scelta di progetto (un *come*), non un requisito; «più veloce del precedente» manca di soglia.

## [mcq 1] Nella notazione EARS (Easy Approach to Requirements Syntax), quale schema corrisponde a un requisito guidato da un evento?
- [ ] The <system> shall <response>.
- [x] When <trigger>, the <system> shall <response>.
- [ ] While <state>, the <system> shall <response>.
- [ ] If <unwanted condition>, then the <system> shall <response>.

### Soluzione
EARS ha cinque schemi: ubiquo (sempre valido), event-driven (*When*), state-driven (*While*), unwanted behaviour (*If… then*), optional feature (*Where*). Riducono l'ambiguità del linguaggio naturale e sono adatti sia alle persone sia agli assistenti di programmazione.

## [mcq 1] Nello spec-driven development (es. GitHub Spec Kit, Kiro) che ruolo ha la specifica?
- [ ] È la documentazione scritta a fine progetto per descrivere al cliente il codice consegnato.
- [x] È l'artefatto primario: da essa derivano piano, task e codice, e si aggiorna prima del codice.
- [ ] È il prompt iniziale per l'agente, che viene scartato quando il codice è stato generato.
- [ ] È l'insieme dei test generati dall'agente, che prende il posto della user story.

### Soluzione
Nello spec-driven development la specifica (requisiti, spesso in EARS, più design e task) guida la generazione: un modello linguistico prende il testo alla lettera, quindi una specifica vaga produce codice sbagliato. Test e review umana restano necessari.

## [mcq 1] Che differenza c'è tra una user story in formato Connextra e una job story?
- [ ] Nessuna: sono due nomi diversi per lo stesso formato «Come… voglio… per…».
- [x] La Connextra parte dal ruolo dell'utente, la job story dalla situazione in cui si trova.
- [ ] La Connextra parte dalla situazione dell'utente, la job story dal ruolo che ricopre.
- [ ] La job story si scrive in Gherkin, la Connextra in linguaggio naturale.

### Soluzione
Connextra: *As a <role> I want <goal> so that <benefit>*. Job story (Jobs To Be Done): *When <situation>, I want to <motivation>, so I can <outcome>*; mette al centro il contesto invece della persona. I criteri di accettazione si scrivono poi in Gherkin (Given/When/Then).

## [aperta 4] Confronta specifica funzionale (SRS), casi d'uso e user story come forme dei requisiti: per ognuna indica a chi serve e un punto di forza e uno debole.

### Soluzione
SRS (elenco «il sistema deve…»): completa e contrattuale, adatta a committenti e verifica formale; debole su contesto e priorità, invecchia e si legge male. Casi d'uso: scenari attore-sistema con flusso principale e alternativi; buoni per capire l'interazione e derivare test; più costosi da scrivere e mantenere. User story: brevi, centrate sul valore per l'utente, negoziabili (3C: card, conversation, confirmation, INVEST); ottime per backlog agili, ma da sole sono incomplete e richiedono criteri di accettazione (Gherkin) e conversazione. Le forme si combinano: nessuna basta da sola.

### Griglia
- 1 | SRS: destinatari e pro/contro
- 1 | casi d'uso: destinatari e pro/contro
- 1 | user story: destinatari e pro/contro (3C/INVEST, criteri di accettazione)
- 1 | conclusione: le forme sono complementari e vanno scelte per lettore
