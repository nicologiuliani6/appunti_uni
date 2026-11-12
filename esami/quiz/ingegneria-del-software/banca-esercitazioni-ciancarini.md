---
titolo: Banca esercitazioni · argomenti di Ciancarini non presenti negli anni passati
durata: 60
fonte: Domande scritte da Claude sugli appunti e sulle slide 2026 di Ciancarini (Modulo 1: L1 produzione, L2 ciclo di vita, L3 processi agili/XP, L14 qualità e codice LLM; Essence; Constructor Fabric CF01-CF02; Il futuro dell'ingegneria del software). Non sono domande ufficiali del docente. Gli argomenti non compaiono negli scritti 2015-2025 né nella simulazione 2023.
---

## [mcq 1] Quali fasi compongono il ciclo di vita del software secondo le slide di Ciancarini (L2)?
- [x] Requisiti, progettazione, codifica e debugging, testing e verifica, deployment, manutenzione.
- [ ] Analisi, codifica, collaudo, ritiro del prodotto.
- [ ] Pianificazione, sprint, review, retrospettiva.
- [ ] Requisiti, codifica, test, release, marketing.

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
- [ ] Numero di sprint completati per team.
- [ ] Numero di bug chiusi per giorno.
- [x] Rapporto tra software prodotto (LoC) e sforzo (giorni/persona).
- [ ] Ore di lavoro per ogni release.

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
- [x] Nessuno strumento singolo garantisce, da solo, un salto di produttività: resta la complessità essenziale del problema.
- [ ] Gli LLM eliminano la complessità essenziale del software.
- [ ] Gli LLM sostituiscono completamente la fase di progettazione.
- [ ] Brooks prevedeva già che gli LLM avrebbero fatto il lavoro di manutenzione.

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
- [x] Customer (il valore per utenti e stakeholder)
- [ ] Solution (lo sviluppo e la specifica del sistema)
- [ ] Endeavor (la gestione del team)
- [ ] Nessuna: sono Alpha a parte

### Soluzione
Customer: valore per utenti e stakeholder, focus sui bisogni reali. Solution: requisiti e sistema software. Endeavor: lavoro, team e modo di lavorare.

## [mcq 1] Essence va inteso come…
- [ ] un metodo agile alternativo a Scrum, da adottare in alternativa
- [x] un metamodello standard (OMG, 2014) che descrive la struttura di qualsiasi metodo, integrabile con Scrum e Kanban
- [ ] un linguaggio di modellazione UML per il codice
- [ ] un tool per il deployment continuo

### Soluzione
Essence non impone un processo: fornisce un kernel comune di concetti e un linguaggio per descrivere, confrontare e integrare pratiche. Scrum e Kanban restano, e Essence aiuta a vedere cosa manca.

## [mcq 1] Come si svolge il «Progress Poker» con le carte Alpha?
- [ ] Il facilitatore assegna lo stato a ciascun Alpha.
- [x] Ognuno sceglie in privato lo stato supportato dalle evidenze; le scelte si rivelano insieme; le differenze maggiori guidano la discussione.
- [ ] Si vota per alzata di mano lo stato desiderato.
- [ ] Si sommano i punti di ogni carta e si sceglie la media.

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
- [x] Un'affermazione verificabile, che si può sostenere con evidenze o con un accordo informato.
- [ ] Una scadenza del progetto.
- [ ] Un test automatico di integrazione.
- [ ] La riunione di fine sprint.

### Soluzione
Un checkpoint trasforma un giudizio in una conversazione basata su evidenze. Una aspirazione vaga («il team è maturo») non può stabilire uno stato. Lo stato corrente è l'ultimo che il team riesce a sostenere, non quello in cui il piano dice di trovarsi.

## [mcq 1] Essence sostituisce Scrum?
- [ ] Sì, Scrum è obsoleto e Essence lo rimpiazza.
- [x] No: Essence non sostituisce Scrum, Kanban o SAFe, ma le integra e aiuta a individuare lacune.
- [ ] Sì, ma solo nei progetti con più di 10 sviluppatori.
- [ ] No, perché Essence è solo una notazione grafica senza utilità pratica.

### Soluzione
Le slide insistono su integrazione, non sostituzione: Essence fornisce un linguaggio comune per dire cosa fa uno Scrum, cosa manca e come combinarlo con altre pratiche.

## [mcq 1] Nella slide su Dropbox, cosa illustra il caso di MVP citato a L3?
- [ ] Una piattaforma completa lanciata senza test.
- [x] Una dimostrazione (video) del prodotto prima di costruire il sistema completo, per verificare l'interesse.
- [ ] Un refactoring che elimina il debito tecnico.
- [ ] Un piano GQM per la qualità.

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
- [ ] integrare il codice una volta al mese, dopo il collaudo
- [x] integrare spesso (più volte al giorno), con test automatici che girano a ogni integrazione
- [ ] sviluppare ogni funzionalità in un branch separato per sei mesi
- [ ] nessun test, perché l'integrazione è automatica

### Soluzione
Integrazione frequente riduce i conflitti e rileva i problemi subito, con build e test automatici. È una pratica distinta dal deploy continuo, anche se si sostengono a vicenda.

## [mcq 1] Nella programmazione in coppia, cosa fa il «navigatore»?
- [ ] scrive il codice mentre il pilota fa solo da osservatore
- [x] guarda la strategia, rivede ciò che il pilota scrive e pensa ai prossimi passi
- [ ] gestisce la pianificazione dello sprint
- [ ] esegue i test di accettazione con il cliente

### Soluzione
Pilota e navigatore si alternano: chi scrive è concentrato sul dettaglio, chi guarda pensa alla direzione e alle possibili falle. Le slide mostrano che la coppia riduce i difetti, ma con costi di tempo da valutare.

## [mcq 1] Che cosa indica la «proprietà collettiva del codice» in XP?
- [ ] Ogni file ha un solo proprietario che decide le modifiche.
- [x] Chiunque nel team può modificare qualsiasi parte del codice, purché i test restino verdi.
- [ ] Il codice appartiene all'azienda, non ai programmatori.
- [ ] Solo il Product Owner può modificare il codice.

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
- [x] sintetizzare il Daily, proporre agende per la Retrospective, analizzare metriche come lead time e WIP
- [ ] decidere lo Sprint Goal al posto del Product Owner
- [ ] gestire i conflitti interni al team
- [ ] assumere la responsabilità della qualità del prodotto

### Soluzione
L'LLM supporta con sintesi e analisi. Le decisioni, le dinamiche di gruppo, i conflitti e la responsabilità restano alle persone: empatia, sicurezza psicologica e leadership non si delegano.

## [mcq 1] Quale limite è indicato per un LLM usato come Scrum Master?
- [ ] non sa leggere le metriche
- [x] non gestisce empatia, dinamiche di gruppo, conflitti e ostacoli politici
- [ ] non può scrivere un'agenda
- [ ] non può sintetizzare un Daily

### Soluzione
Il ruolo dello SM ha una parte tecnica (automatizzabile in parte) e una parte relazionale, che non si delega.

## [mcq 1] Nel caso Mars Climate Orbiter (1999), la perdita della sonda è:
- [ ] un errore (error)
- [x] un guasto (failure)
- [ ] un difetto (fault)
- [ ] un vincolo non rispettato

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
- [x] la qualità interna (ispezioni, analisi statica, complessità)
- [ ] la qualità esterna (test in esecuzione)
- [ ] la qualità in uso (utenti reali)
- [ ] nessuna: la qualità si misura sempre eseguendo

### Soluzione
Interna: si misura sul prodotto non eseguito. Esterna: si misura eseguendo (test). In uso: nel contesto reale con gli utenti, con la norma ISO/IEC 25019.

## [mcq 1] Quale caratteristica è stata aggiunta nel modello di qualità ISO/IEC 25010:2023 rispetto alla versione precedente?
- [ ] Usabilità
- [ ] Portabilità
- [x] Safety (sicurezza fisica e del sistema verso danni)
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
- [ ] 50 casi
- [ ] 1.000 casi
- [x] circa 9,8 milioni (5 alla decima)
- [ ] 10 casi, un test per parametro

### Soluzione
5^10 ≈ 9,8 milioni: impossibile da eseguire in pratica. Per questo si scelgono classi di equivalenza e valori limite.

## [mcq 1] Qual è la forma della piramide dei test presentata a L14?
- [ ] molti test end-to-end, pochi test di unità
- [x] molti test di unità veloci e economici, meno di integrazione, pochi end-to-end
- [ ] tutti i test a mano, nessuna automazione
- [ ] solo test di accettazione del cliente

### Soluzione
Più si sale verso E2E, più i test sono lenti, fragili e costosi. L'anti-pattern «cono gelato» (molti E2E manuali, pochi unitari) è il contrario della piramide.

## [mcq 1] Nel quadrante del debito tecnico, quale situazione è «prudente e consapevole»?
- [ ] «Non abbiamo tempo per il progetto»
- [x] «Rilasciamo ora e ne gestiamo le conseguenze»
- [ ] «Che cos'è la stratificazione?»
- [ ] «Ora sappiamo come avremmo dovuto farlo» (involontario)

### Soluzione
Il debito tecnico (Cunningham, Fowler) ha capitale (la correzione rinviata) e interessi (le modifiche future costano di più). È prudente se consapevole: lo si decide e lo si ripaga con il refactoring protetto dai test.

## [mcq 1] Nel quality gate predefinito «Sonar way» presentato a L14, quali sono le condizioni sul codice nuovo?
- [ ] 0 bug totali, copertura 100%, duplicazione 0%, rating B
- [x] 0 nuovi problemi, almeno 80% di copertura, al più 3% di righe duplicate, rating A e revisione dei security hotspot
- [ ] nessuna condizione: il gate è solo informativo
- [ ] 50% di copertura, 10% di duplicazione, rating C

### Soluzione
Il gate giudica il codice nuovo o modificato (Clean as You Code). Le soglie sono un esempio: vanno decise dal team, meglio con GQM.

## [mcq 1] Il principio «Clean as You Code» significa che:
- [ ] il codice vecchio va riscritto tutto prima di ogni rilascio
- [x] chi tocca il codice lo lascia pulito; il debito pregresso si ripaga gradualmente
- [ ] ogni commit deve avere almeno 100 righe di test
- [ ] l'analisi statica va disattivata sul codice esistente

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
- [x] un test che passa non prova l'assenza di errori; i test possono solo mostrarne la presenza
- [ ] i test non servono a nulla
- [ ] la copertura del 100% garantisce la correttezza
- [ ] i test si fanno solo alla fine del progetto

### Soluzione
Il testing non dimostra la correttezza: serve a trovare errori. Per questo servono più filtri (unità, integrazione, analisi statica, quality gate) e test scritti con criterio.

## [mcq 1] Secondo lo studio Liu et al. (NeurIPS 2023), con test più rigorosi quante soluzioni «corrette» di codice generato da LLM risultano sbagliate?
- [ ] 1–3%
- [x] circa 19–29%
- [ ] 50–60%
- [ ] nessuna: il benchmark originale è sufficiente

### Soluzione
Con HumanEval+ (circa 80 volte più test) le soluzioni che passavano il benchmark originale falliscono in una quota significativa. Test deboli sovrastimano la correttezza.

## [mcq 1] Nello studio GitClear 2025 sul codice assistito dall'IA, che cosa segna un cambiamento importante nel 2024?
- [ ] le righe spostate superano quelle copiate
- [x] per la prima volta le righe copiate e incollate superano quelle spostate
- [ ] nessun blocco duplicato
- [ ] il refactoring cresce del 40%

### Soluzione
Righe spostate = indicatore di refactoring e riuso; righe copiate = duplicazione e debito. Il dato è un rapporto industriale, correlazione e non esperimento controllato: va letto con cautela.

## [mcq 1] Nello studio METR 2025 su sviluppatori esperti, la velocità reale con l'IA rispetto a senza IA era:
- [ ] +24%
- [ ] +20%
- [x] −19% (più lenta)
- [ ] +55,8%

### Soluzione
Gli sviluppatori prevedevano un guadagno e percepivano un vantaggio, ma la misura mostrava un rallentamento: percezione e misura divergono. Il +55,8% riguarda un compito isolato (studio Peng et al.), non il lavoro esperto reale.

## [mcq 1] Un assistente IA propone di importare un pacchetto «fastjsonx» che nessuno conosce. Qual è il rischio principale?
- [ ] licenza incompatibile
- [ ] prestazioni peggiori della libreria standard
- [x] pacchetto inventato dal modello, che un attaccante può registrare con quel nome (slopsquatting)
- [ ] nessun rischio se i test passano

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
- [ ] un IDE per scrivere codice Java
- [x] una piattaforma open source AI-native che collega plan, build e run in un flusso tracciabile, con il comando cfs
- [ ] un servizio cloud per il deployment di container
- [ ] un linguaggio di programmazione per agenti

### Soluzione
Constructor Fabric (con Constructor Studio, comando cfs) mette un processo ingegneristico attorno agli strumenti di AI coding: dai requisiti alla produzione, con artefatti collegati e verificati.

## [mcq 1] Nella pipeline di Constructor Fabric, a che cosa serve il PRD?
- [ ] a eseguire i test automatici
- [x] a definire lo scopo e i requisiti, dove ogni requisito ha un ID CPT e una priorità
- [ ] a pubblicare il codice in produzione
- [ ] a registrare le ore di lavoro dei membri

### Soluzione
Il PRD (scopo, attori, scope, requisiti funzionali e non, criteri di accettazione, rischi). Gli ID CPT permettono di seguire il requisito fino al codice.

## [mcq 1] Nella pipeline di Constructor Fabric, come deve comportarsi la skill DESIGN?
- [ ] inventare l'architettura partendo da una sola riga di richiesta
- [x] trasformare documenti già approvati (PRD e ADR) in architettura, componenti e data model
- [ ] scrivere direttamente il codice senza documenti
- [ ] sostituire la review umana

### Soluzione
Gli input devono essere nominati e approvati: la skill trasforma, non inventa. Ogni driver porta il CPT ID del requisito a cui risponde.

## [mcq 1] Che cosa garantisce `cfs validate` (CF01/CF02)?
- [ ] che il software funziona correttamente
- [x] che la struttura dei documenti è corretta (sezioni, riferimenti, forma degli ID): un risultato deterministico, non una prova di correttezza
- [ ] che il codice è sicuro
- [ ] che il team ha rispettato i tempi

### Soluzione
Validate controlla forma e consistenza, in modo deterministico. Un validate verde non dice che il software funziona: resta necessaria la review umana.

## [mcq 1] Nella fase di Decompose di Constructor Fabric, quale regola di copertura vale?
- [ ] ogni componente può comparire in più feature
- [x] ogni componente, sequenza ed elemento dati appartiene a esattamente una feature
- [ ] le feature non devono avere dipendenze
- [ ] basta una feature per l'intero design

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
- [x] 2009, SEMAT fondata da Jacobson, Meyer e Soley; 2012 prima specifica del Kernel; 2014 standard OMG
- [ ] 1968, nascita della disciplina alla conferenza NATO
- [ ] 2001, Manifesto Agile firmato da 17 autori
- [ ] 2020, pubblicazione di Essence come libro

### Soluzione
SEMAT (Software Engineering Method and Theory) nasce nel 2009; il Kernel viene specificato nel 2012; nel 2014 Essence diventa standard OMG. Jacobson è considerato il padre del framework.
