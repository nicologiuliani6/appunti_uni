---
titolo: Esempi di domande · chiuse sul processo
durata: 0
fonte: "Esempi di domande di ingegneria del software" (Ciancarini, Giannone, Succi, rev. 14/09/2025), §2. Risposte ufficiali del documento; spiegazioni di Claude.
---

## [mcq 1] Nel metodo MoSCoW utilizzato per la gestione dei requisiti, cosa rappresenta la categoria "Should Have"?
- [x] Requisiti importanti ma non critici, che possono essere posticipati se necessario.
- [ ] Funzionalità non essenziali ma che migliorano l'esperienza utente.
- [ ] Funzionalità opzionali che possono essere implementate se c'è tempo.
- [ ] Requisiti essenziali che devono essere soddisfatti per il successo del progetto.

### Soluzione
MoSCoW: **Must** (essenziali, d), **Should** (importanti ma rinviabili, a), **Could** (opzionali "se c'è tempo", b/c), **Won't** (esclusi per questa release).

## [mcq 1] Il "triangolo di ferro" del project management rappresenta i tre vincoli fondamentali di un progetto. Quali sono?
- [ ] Qualità, Comunicazione, Budget.
- [x] Tempo, Costo, Scopo.
- [ ] Team, Product Owner, Scrum Master.
- [ ] Customer, Solution, Endeavour.

### Soluzione
Tempo, costo e scopo (ambito): cambiarne uno impatta gli altri, la qualità sta "al centro". (c) sono i ruoli Scrum, (d) le aree di interesse di Essence.

## [mcq 1] Cos'è lo "scope" di un progetto agile?
- [ ] Gli stakeholder del progetto.
- [x] Il product backlog.
- [ ] Il numero finale degli sprint.
- [ ] L'architettura del prodotto.

### Soluzione
In agile lo scopo (ambito) del progetto è ciò che c'è da fare: il product backlog, che evolve nel tempo.

## [mcq 1] Quale ruolo è assente in Scrum?
- [ ] Product owner.
- [ ] Scrum master.
- [x] Project manager.
- [ ] Team member.

### Soluzione
Scrum prevede solo Product Owner, Scrum Master e Team (auto-organizzato). Le responsabilità del PM sono distribuite tra questi ruoli.

## [mcq 1] Cos'è il Minimal Viable Product?
- [x] Il prodotto con il più alto ritorno sugli investimenti rispetto al rischio.
- [ ] Il prodotto al termine del primo sprint
- [ ] Il prodotto al termine dell'ultimo sprint
- [ ] Il prodotto al termine dello sprint più recente

### Soluzione
MVP = la versione minima che dà già valore ai clienti e permette di imparare dal mercato col massimo ritorno rispetto al rischio; non è legato a uno sprint specifico.

## [mcq 1] Che cos'è la velocità di un team Scrum?
- [x] Il numero medio di story point "fatti" in uno sprint.
- [ ] Il numero medio di user story "fatti" in uno sprint.
- [ ] Il numero di story point "fatti" nell'ultimo sprint.
- [ ] Il numero di story point "fatti" nello sprint in corso.

### Soluzione
Velocità = media degli story point completati (Done) per sprint: si misura in punti, non in numero di storie, e su più sprint.

## [mcq 1] Come si calcola lo sforzo necessario allo sviluppo di un prodotto software?
- [ ] Il costo in euro di un prodotto software.
- [ ] La durata in giorni dello sviluppo.
- [ ] La durata dello sviluppo moltiplicata per le persone coinvolte nello sviluppo.
- [x] La somma dei tempi dedicati allo sviluppo da parte di ciascun sviluppatore.

### Soluzione
Sforzo (effort, es. in persona-mese) = somma del tempo effettivamente speso da ciascuno. (c) sovrastima se non tutti lavorano a tempo pieno per tutta la durata.

## [mcq 1] Come si chiama il testing in cui si usa il sorgente del programma?
- [ ] Blackbox.
- [x] Whitebox.
- [ ] Debugging.
- [ ] Validazione.

### Soluzione
White-box (strutturale): i test sono scritti guardando il codice (copertura di istruzioni, rami…). Black-box usa solo la specifica.

## [mcq 1] Quale delle seguenti affermazioni descrive meglio il compito principale del project manager di un prodotto software?
- [ ] Assicurarsi che ogni sviluppatore scriva il codice meno costoso possibile nel minor tempo possibile.
- [ ] Gestire i requisiti parlando con gli stakeholder e analizzandoli col team di sviluppo.
- [ ] Gestire il testing in modo automatico cercando di risparmiare tempo e diminuire effort.
- [x] Assicurarsi che il prodotto sia completato nei tempi previsti, rimanendo entro il budget e soddisfacendo i requisiti richiesti.

### Soluzione
Il PM governa il triangolo tempi–costi–ambito. La gestione dei requisiti con gli stakeholder (b) è compito del product owner / analista.

## [mcq 1] Quale delle seguenti caratteristiche identifica meglio un processo di sviluppo agile?
- [x] La suddivisione del lavoro in iterazioni brevi e incrementali con feedback frequenti dagli stakeholder.
- [ ] L'uso delle user story per definire completamente i requisiti di prodotto prima di iniziare lo sviluppo.
- [ ] La pianificazione accurata di tutte le attività necessarie al prodotto prima dell'avvio dello sviluppo.
- [ ] L'individuazione di un singolo responsabile che prenda tutte le decisioni tecniche e di progetto.

### Soluzione
Agile = iterativo e incrementale (sprint), feedback continuo. (b) e (c) descrivono un approccio a cascata (big design up front).

## [mcq 1] In un design orientato agli oggetti, cos'è un "componente riusabile"?
- [x] Una parte del codice progettata per essere facilmente integrabile in contesti diversi.
- [ ] Un template HTML collegato a un controller.
- [ ] Una classe che eredita da se stessa.
- [ ] Un modulo Python contenente solo costanti.

### Soluzione
Riusabile = con interfaccia chiara e poche dipendenze, così da poterlo inserire in sistemi diversi senza modificarlo.

## [mcq 1] Quale tra questi è un vantaggio dei test automatici?
- [ ] Aumentano il coupling tra i moduli.
- [ ] Rallentano il ciclo di sviluppo.
- [ ] Eliminano la necessità del debugging.
- [x] Permettono di individuare rapidamente regressioni nel codice.

### Soluzione
Rieseguibili a ogni modifica (anche in CI), segnalano subito se qualcosa che funzionava si è rotto (regressione). Non eliminano il debugging: dicono *che* c'è un errore, non *dove*.

## [mcq 1] Qual è l'obiettivo della tecnica del "Mocking" nei test?
- [ ] Creare ambienti virtuali.
- [ ] Misurare la copertura del codice.
- [x] Simulare comportamenti di componenti esterni.
- [ ] Gestire errori in tempo reale.

### Soluzione
Un mock sostituisce una dipendenza (DB, rete, servizio) con un oggetto finto dal comportamento controllato, per testare l'unità in isolamento.

## [mcq 1] Cosa caratterizza un buon design modulare?
- [ ] Moduli altamente accoppiati tra loro.
- [ ] Codice duplicato nei vari moduli.
- [ ] Assenza di interfacce.
- [x] Alta coesione e basso accoppiamento.

### Soluzione
Coesione alta = ogni modulo fa una cosa sola; accoppiamento basso = i moduli dipendono poco l'uno dall'altro (tramite interfacce).

## [mcq 1] A cosa serve un diagramma delle classi UML?
- [ ] A visualizzare l'output di un programma.
- [x] A rappresentare le relazioni tra classi e oggetti.
- [ ] A disegnare wireframe per interfacce grafiche.
- [ ] A testare il comportamento delle classi.

### Soluzione
È il diagramma strutturale (statico) centrale dei modelli OO: classi, attributi, operazioni e relazioni (associazione, aggregazione, generalizzazione, dipendenza).

## [mcq 1] Qual è lo scopo principale della progettazione guidata dai test (TDD)?
- [ ] Produrre test in ritardo rispetto allo sviluppo.
- [x] Guidare la scrittura del codice attraverso i test.
- [ ] Scrivere meno codice possibile.
- [ ] Testare l'usabilità dell'interfaccia utente.

### Soluzione
TDD (pratica XP): prima si scrive un test che fallisce, poi il codice minimo per farlo passare, poi si fa refactoring (red–green–refactor).

## [mcq 1] Qual è lo scopo principale della fase di analisi dei requisiti?
- [ ] Definire l'architettura del sistema.
- [x] Comprendere cosa il sistema deve fare.
- [ ] Scrivere i test di unità.
- [ ] Stimare il tempo di esecuzione del software.

### Soluzione
Analisi = *cosa* deve fare il sistema; il *come* (architettura, a) è progettazione.

## [mcq 1] Quale dei seguenti modelli di sviluppo è caratterizzato da fasi sequenziali e ben definite?
- [ ] Modello Incrementale.
- [ ] Modello a spirale.
- [x] Modello a cascata.
- [ ] Modello Agile.

### Soluzione
Cascata (waterfall): requisiti → progetto → codifica → test → manutenzione, una fase dopo l'altra. Spirale, incrementale e agile sono iterativi.

## [mcq 1] Perché è utile creare una documentazione dei requisiti?
- [ ] Per decidere il linguaggio di programmazione.
- [ ] Per generare automaticamente il codice sorgente.
- [ ] Per evitare l'uso di librerie esterne.
- [x] Per avere una base condivisa tra sviluppatori e stakeholder.

### Soluzione
Serve come riferimento comune (e contrattuale) su cosa va costruito, e come base per validazione e test.

## [mcq 1] Qual è l'obiettivo del testing nel processo di sviluppo software?
- [ ] Ridurre la dimensione del codice.
- [ ] Eliminare le dipendenze tra moduli.
- [ ] Produrre documentazione automatica.
- [x] Verificare che il software si comporti come atteso.

### Soluzione
Il testing confronta il comportamento reale con quello atteso (dalla specifica) per scoprire difetti.

## [mcq 1] In Scrum, cosa rappresenta il Product Backlog?
- [ ] L'elenco dei bug da correggere.
- [x] L'elenco ordinato delle funzionalità e modifiche richieste al prodotto.
- [ ] Il diario delle attività svolte dallo Scrum Master.
- [ ] Il piano di progetto iniziale.

### Soluzione
Lista ordinata per priorità (dal PO) di tutto ciò che serve al prodotto (US, epiche, bug, miglioramenti); evolve continuamente (backlog refinement).

## [mcq 1] Chi è responsabile della massimizzazione del valore del prodotto in Scrum?
- [ ] Il team di sviluppo.
- [ ] Il project manager.
- [x] Il Product Owner.
- [ ] Il cliente.

### Soluzione
Il PO rappresenta gli stakeholder, possiede e ordina il product backlog: è responsabile del valore prodotto.

## [mcq 1] Quale delle seguenti attività avviene tipicamente alla fine di uno Sprint in Scrum?
- [ ] Stima dei costi del progetto.
- [ ] Ridefinizione della visione del prodotto.
- [x] Sprint Review e Sprint Retrospective.
- [ ] Disegno dell'architettura del sistema.

### Soluzione
Review = riflessione sul *prodotto* (demo agli stakeholder); retrospective = riflessione sul *processo* del team.

## [mcq 1] In cosa consiste la Daily Scrum?
- [ ] Una revisione dettagliata del codice.
- [ ] Un incontro con gli stakeholder.
- [x] Una breve riunione quotidiana per pianificare il lavoro delle prossime 24 ore.
- [ ] Una presentazione dei risultati ottenuti al cliente.

### Soluzione
Stand-up di max 15 minuti, in piedi, senza problem solving: cosa ho fatto ieri, cosa farò oggi, quali impedimenti ho.

## [mcq 1] Quale delle seguenti non è una delle responsabilità dello Scrum Master?
- [x] Decidere quali funzionalità implementare.
- [ ] Facilitare le cerimonie Scrum.
- [ ] Aiutare a rimuovere gli impedimenti al lavoro del team.
- [ ] Promuovere la comprensione di Scrum nel team.

### Soluzione
Cosa implementare (e in che ordine) lo decide il Product Owner. Lo SM è un facilitatore / servant leader del processo.

## [mcq 1] Qual è la durata raccomandata per uno Sprint in Scrum?
- [ ] 1 giorno.
- [ ] 1 mese e mezzo.
- [x] Massimo 1 mese.
- [ ] Almeno 3 mesi.

### Soluzione
Sprint time-boxed di durata fissa, da 1 a 4 settimane (≤ 1 mese).

## [mcq 1] Qual è uno dei principali vantaggi dell'uso di Scrum?
- [ ] Riduzione automatica del debito tecnico.
- [x] Feedback frequente e continuo da parte degli stakeholder.
- [ ] Rimozione del bisogno di documentazione.
- [ ] Codice generato automaticamente ad ogni sprint.

### Soluzione
A ogni sprint review si mostra un incremento funzionante e si raccoglie feedback, quindi si può correggere la rotta presto.

## [mcq 1] Qual è l'obiettivo della Retrospective in Scrum?
- [ ] Pianificare le funzionalità dello sprint successivo.
- [x] Identificare miglioramenti nel processo di lavoro del team.
- [ ] Presentare il lavoro finito agli stakeholder.
- [ ] Raccogliere i bug segnalati dagli utenti.

### Soluzione
Retrospective = sul processo (cosa è andato bene/male, cosa cambiare). (a) è lo sprint planning, (c) la sprint review.

## [mcq 1] In Scrum, chi partecipa alla Sprint Planning?
- [ ] Solo lo Scrum Master e il Product Owner.
- [ ] Solo il team di sviluppo.
- [ ] Solo il cliente.
- [x] Scrum Master, Product Owner e team di sviluppo.

### Soluzione
Pianificazione di gruppo (PO, SM, Team): il PO porta le priorità, il team sceglie quanto può fare e lo scompone in task.

## [mcq 1] Quale delle seguenti è una caratteristica di un buon requisito software?
- [ ] Essere vago e aperto a interpretazioni.
- [x] Essere chiaro, misurabile e verificabile.
- [ ] Essere scritto in linguaggio tecnico.
- [ ] Essere modificabile solo dal team di sviluppo.

### Soluzione
Un requisito deve essere non ambiguo e testabile (vedi anche la T di INVEST per le user story).

## [mcq 1] Cosa si intende per 'prototipazione' nel contesto dello sviluppo software?
- [ ] Scrivere codice direttamente in produzione.
- [ ] Definire il piano economico del progetto.
- [x] Costruire versioni semplificate del software per raccogliere feedback.
- [ ] Creare la documentazione finale del sistema.

### Soluzione
Un prototipo (spesso usa e getta) serve a chiarire requisiti e validare idee con gli utenti prima di costruire il sistema vero.

## [mcq 1] Cosa rappresenta una 'user story' in Scrum?
- [ ] Un diagramma dei flussi di dati.
- [x] Una descrizione sintetica di una funzionalità dal punto di vista dell'utente.
- [ ] Un requisito funzionale formale.
- [ ] Un caso di test per l'integrazione.

### Soluzione
"Come <ruolo> voglio <funzionalità> per <beneficio>": breve, informale, promemoria di una conversazione (non un requisito formale).

## [mcq 1] Quale delle seguenti attività rientra nella gestione della qualità del software?
- [ ] Assegnare i task al team di sviluppo.
- [ ] Stimare i costi delle licenze software.
- [x] Definire metriche per valutare il codice.
- [ ] Scrivere la documentazione utente.

### Soluzione
La gestione della qualità definisce standard e metriche (complessità, copertura, difettosità…) e verifica che vengano rispettati.

## [mcq 1] Qual è un vantaggio dell'uso della modellazione UML nel processo di sviluppo?
- [ ] Elimina la necessità del testing.
- [x] Facilita la comunicazione tra membri del team e stakeholder.
- [ ] Riduce i tempi di compilazione.
- [ ] Permette di testare automaticamente il codice.

### Soluzione
UML è un linguaggio grafico standard: tutti leggono gli stessi diagrammi, quindi è uno strumento di comunicazione (e di documentazione).

## [mcq 1] La relazione include per un use case
- [ ] definisce un'estensione atomica del mio use case.
- [ ] definisce un use case che è una specializzazione atomica dello use case di partenza.
- [x] definisce una funzionalità coesa dello use case e quindi separata.
- [ ] definisce una relazione di ereditarietà tra use case.

### Soluzione
Include = una parte del comportamento (sempre eseguita) estratta in un use case a sé, tipicamente perché condivisa da più use case. Extend = comportamento opzionale aggiunto (a).

## [mcq 1] La relazione extend per un use case
- [x] definisce un'estensione atomica del mio use case.
- [ ] definisce un use case che è una specializzazione atomica dello use case di partenza.
- [ ] crea con lo use case di partenza un nuovo use case.
- [ ] definisce una relazione di ereditarietà tra use case.

### Soluzione
Extend aggiunge funzionalità opzionali (eseguite solo in certe condizioni) a un use case base, che resta completo anche da solo.

## [mcq 1] Un use case è
- [ ] un qualunque requisito.
- [ ] un caso di uso dell'interfaccia utente accettato dall'utente.
- [x] un caso di uso atomico che dà valore all'utente.
- [ ] un requisito semplice del sistema validato dall'utente.

### Soluzione
Use case = scenario d'uso del sistema da parte di un attore che produce un risultato di valore per l'attore stesso.
