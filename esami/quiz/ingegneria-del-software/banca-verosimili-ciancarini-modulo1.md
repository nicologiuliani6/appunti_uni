---
titolo: Domande verosimili · Modulo 1 (Ciancarini)
durata: 0
fonte: Domande scritte da Claude sugli appunti del Modulo 1 (3/ing_sfw/ing_sfw.tex: produzione del software, ciclo di vita, agile/XP, Scrum, qualità, forme dei requisiti, Essence, Constructor Fabric), imitando la forma degli scritti 2023-2025 e degli «Esempi di domande» (Ciancarini, Giannone, Succi 2025): crocette brevi con distrattori presi da concetti vicini, aperte da 3 punti del tipo «Si descriva… / Si dettagli la differenza tra…», un testo di contesto seguito da domande aperte. Non sono domande ufficiali del docente.
---

## [mcq 3] Il software libero
- [ ] è software distribuito gratuitamente, anche senza fornire il codice sorgente
- [ ] è software di pubblico dominio, su cui l'autore ha rinunciato a ogni diritto
- [x] garantisce le libertà di eseguirlo, studiarlo e modificarlo, ridistribuirlo e migliorarlo
- [ ] è software modificabile e ridistribuibile, ma solo per scopi non commerciali

### Soluzione
«Libero» non significa «gratis»: il software libero garantisce le quattro libertà (0: eseguire per qualsiasi scopo; 1: studiare e modificare; 2: ridistribuire; 3: migliorare e distribuire i miglioramenti). Il pubblico dominio (b) è un'altra forma di licenza. Una restrizione «solo non commerciale» (d) viola la libertà 0.

## [mcq 3] In Europa il software
- [x] è protetto dal diritto d'autore come opera dell'ingegno, ma non è brevettabile
- [ ] è brevettabile come invenzione industriale, ma non è protetto dal diritto d'autore
- [ ] non è né protetto né brevettabile, se viene distribuito liberamente in rete
- [ ] è protetto dal diritto d'autore solo se distribuito con licenza proprietaria

### Soluzione
Il software è un'opera dell'ingegno: è tutelato dal diritto d'autore (in Italia la L. 248/2000 punisce la duplicazione abusiva), ma in Europa non è brevettabile. Anche il software open source è protetto: la licenza è proprio l'esercizio di quel diritto.

## [mcq 3] Verifica, validazione e certificazione di un prodotto software garantiscono rispettivamente
- [ ] l'accettazione da parte del cliente, l'aderenza alla specifica, l'aderenza a norme di legge
- [x] l'aderenza alla specifica, l'accettazione da parte del cliente, l'aderenza a specifiche definite dalla legge
- [ ] l'assenza di difetti, l'aderenza alla specifica, l'accettazione da parte del cliente
- [ ] l'aderenza al contratto di licenza, l'assenza di difetti, l'aderenza alla specifica

### Soluzione
Verifica = «stiamo costruendo il prodotto nel modo giusto?» (conforme alla specifica). Validazione = «stiamo costruendo il prodotto giusto?» (lo accetta il cliente). Certificazione = aderenza a specifiche imposte dalla legge. Nessuna delle tre garantisce l'assenza di difetti (Dijkstra).

## [mcq 3] Il software di consumo (es. un'applicazione acquistata in un negozio online) di norma
- [ ] è garantito per due anni come ogni bene di consumo
- [ ] è garantito privo di difetti solo se certificato
- [x] è venduto «as is», senza garanzie, come dichiarato nel contratto di licenza
- [ ] è garantito dal produttore dell'hardware su cui gira

### Soluzione
Il software commerciale si acquisisce su licenza e di solito viene venduto *as is*: il contratto mostrato al primo uso esclude le garanzie. È una delle ragioni per cui il software è un prodotto «speciale».

## [mcq 3] Il portale web dell'Università, sviluppato apposta da un fornitore per l'Ateneo, è un esempio di
- [ ] prodotto generico (off the shelf)
- [x] sistema commissionato
- [ ] servizio in perpetuo sviluppo
- [ ] ecosistema software

### Soluzione
Prodotti generici (OTS): venduti a molti clienti (un videogioco). Sistemi commissionati: sviluppati per un cliente specifico (il portale dell'Università). Servizi in perpetuo sviluppo: 24/7 e in continuo cambiamento (Amazon, Facebook). Ecosistema: mercato di prodotti su una piattaforma (AppStore).

## [mcq 3] Nel software AI-native, un orchestratore
- [ ] è un agente autonomo specializzato in un singolo compito
- [x] coordina, monitora e gestisce il flusso di lavoro di più agenti o strumenti
- [ ] è il modello linguistico che genera il codice
- [ ] è il componente che compila e distribuisce il software in produzione

### Soluzione
L'agente prende decisioni ed esegue un compito specifico (lavora «in verticale»); l'orchestratore ha la visione d'insieme: coordina più agenti e strumenti e ne allinea gli obiettivi.

## [mcq 3] Qual è la differenza tra requisito e feature di un prodotto software?
- [x] Il requisito è una funzione o qualità verificabile che interessa al cliente; la feature è un insieme di funzioni che interessa al fornitore
- [ ] Il requisito descrive cosa deve fare il sistema; la feature descrive come il team lo realizza tecnicamente
- [ ] Il requisito è scritto dal cliente nel contratto; la feature è scritta dal team come user story nel backlog
- [ ] Il requisito riguarda il comportamento interno; la feature riguarda solo l'interfaccia grafica del prodotto

### Soluzione
Requisito: funzione o qualità *controllabile (testabile)* che l'implementazione deve possedere, importante per il cliente. Feature: insieme di funzioni che permettono di usare il prodotto in un servizio, importante per il fornitore. Es. requisiti: registrarsi, gestire il carrello, pagare; feature: il carrello per negozio elettronico.

## [mcq 3] La legge di Brooks afferma che
- [ ] non esiste una tecnica in grado di rendere facile la costruzione del software
- [x] aggiungere personale a un progetto in ritardo lo fa ritardare ancora di più
- [ ] il software diventa lento più rapidamente di quanto l'hardware diventi veloce
- [ ] il codice non rivisto da sei mesi sembra scritto da qualcun altro

### Soluzione
(b) è la legge di Brooks (*The Mythical Man-Month*). (a) è sempre Brooks ma è il «No Silver Bullet» (1987); (c) è la legge di Wirth; (d) la legge di Eagleson.

## [mcq 3] Nell'intero ciclo di vita di un sistema software longevo, l'attività che costa di più è
- [ ] la codifica
- [ ] il testing e l'integrazione
- [ ] l'analisi dei requisiti
- [x] la manutenzione

### Soluzione
Mantenere costa più che sviluppare: nella distribuzione storica citata da Boehm/Schach la manutenzione vale circa due terzi del costo totale. Nello scenario ipotetico con GenAI la sua quota sale ancora, perché la codifica costa quasi zero.

## [mcq 3] Adattare un programma a una nuova versione del sistema operativo è manutenzione
- [ ] correttiva
- [ ] perfettiva
- [x] adattiva
- [ ] evolutiva preventiva

### Soluzione
Correttiva: corregge errori trovati dopo la consegna. Adattiva: risponde a cambiamenti dell'ambiente (nuovo SO, nuove norme). Perfettiva (o preventiva): migliora un prodotto già corretto, per esempio le prestazioni; è la quota più grande.

## [mcq 3] Al crescere delle dimensioni di un sistema software, il costo di sviluppo
- [ ] cresce linearmente, perché ogni riga di codice ha lo stesso costo
- [x] cresce più che linearmente, circa col quadrato delle dimensioni
- [ ] cresce in modo logaritmico, grazie al riuso dei componenti
- [ ] diventa quasi indipendente dalle dimensioni con gli assistenti AI

### Soluzione
Con le dimensioni crescono il costo per riga e la durata e cala la produttività. Gli assistenti AI abbassano il costo della singola riga, non quello di capire, integrare e mantenere un sistema: la curva quadratica dipende dalle interazioni tra le parti.

## [mcq 3] Quale dei seguenti è un attributo interno di un prodotto software?
- [ ] Il tipo di licenza
- [ ] Le prestazioni
- [ ] La garanzia
- [x] La modularità

### Soluzione
Attributi esterni (visibili all'utente): costo e tipo di licenza, prestazioni, garanzia. Attributi interni (visibili ai progettisti): dimensione, sforzo, durata, mantenibilità, modularità.

## [mcq 3] Un processo software è
- [ ] la sequenza di istruzioni eseguite dal programma
- [ ] il diagramma di Gantt del progetto
- [x] l'insieme di ruoli, attività e documenti necessari per creare un sistema software
- [ ] lo standard IEEE che descrive le fasi del ciclo di vita

### Soluzione
Ruoli (stakeholder, progettista, sviluppatore, tester, manutentore), attività (programmare, testare, documentare…) e documenti (sorgente, eseguibile, specifica, risultati dei test). Il Gantt (b) è uno strumento per gestire le attività, non il processo.

## [mcq 3] Gli LLM sono il nuovo «silver bullet»?
- [ ] Sì: eliminano il costo della codifica, che è la parte più costosa del software
- [x] No: aiutano a scrivere codice, test e documentazione, ma non risolvono requisiti, architettura e qualità
- [ ] Sì, purché il codice generato superi i test generati dallo stesso modello
- [ ] No: il codice che generano non è ancora abbastanza corretto da compilare

### Soluzione
Brooks: nessuna tecnica rende facile costruire software, perché la difficoltà essenziale sta nel capire il problema. Gli LLM aggiungono rischi propri: codice plausibile ma errato, debito tecnico nascosto, dipendenza dal fornitore, proprietà intellettuale. (c) è un errore classico: codice e test dalla stessa fonte condividono le stesse assunzioni.

## [mcq 3] Quale delle seguenti NON è una preferenza dichiarata dal Manifesto agile?
- [ ] Individui e interazioni più che processi e strumenti
- [ ] Software funzionante più che documentazione esaustiva
- [x] Seguire un piano più che rispondere al cambiamento
- [ ] Collaborazione col cliente più che negoziazione dei contratti

### Soluzione
Il Manifesto preferisce *rispondere al cambiamento* rispetto a *seguire un piano*, pur riconoscendo il valore delle voci a destra.

## [mcq 3] In un Minimum Viable Product, l'aggettivo «minimo» si riferisce
- [ ] al numero minimo di funzionalità del prodotto
- [x] allo sforzo minimo necessario per ottenere un riscontro utile su un'ipotesi
- [ ] al costo minimo di produzione del prodotto finale
- [ ] alla durata minima di uno sprint

### Soluzione
L'MVP (Lean Startup) mette alla prova un'ipotesi sul prodotto e sugli utenti; il riscontro serve a decidere se proseguire, cambiare direzione o fermarsi. Il numero di funzionalità non lo definisce: la demo video di Dropbox era un MVP senza prodotto.

## [mcq 3] Il principio YAGNI di XP
- [ ] vieta di usare astrazioni e gerarchie di classi
- [x] invita a non implementare generalizzazioni speculative finché un requisito concreto non le richiede
- [ ] impone di scrivere i test prima del codice
- [ ] stabilisce che ogni modifica sia integrata almeno una volta al giorno

### Soluzione
«You Aren't Gonna Need It»: il design sostiene i requisiti noti; l'astrazione non è vietata ma rinviata, e quando serve si fa refactoring protetto dai test. (c) è il TDD, (d) l'integrazione continua.

## [mcq 3] Il refactoring
- [ ] è la correzione di un difetto segnalato dal cliente
- [ ] è l'aggiunta di una funzionalità senza cambiare l'architettura
- [x] migliora la struttura interna del codice preservandone il comportamento osservabile
- [ ] è la riscrittura completa di un modulo in un altro linguaggio

### Soluzione
I «due cappelli»: in un passo si cambia la struttura *oppure* il comportamento, mai entrambi. Correggere un difetto o aggiungere una funzione non è refactoring. Si procede a piccoli passi eseguendo i test dopo ciascuno.

## [mcq 3] Nella consegna continua (continuous delivery)
- [ ] ogni modifica che supera i controlli raggiunge automaticamente gli utenti
- [x] il software è sempre in uno stato rilasciabile, ma il rilascio resta una decisione
- [ ] ogni sviluppatore integra il proprio ramo una volta ogni due settimane
- [ ] i test vengono eseguiti manualmente prima di ogni rilascio

### Soluzione
Integrazione continua: ogni modifica è integrata spesso (almeno ogni giorno) e verificata automaticamente. Consegna continua: sempre rilasciabile, rilascio deciso. Rilascio continuo (a): ogni modifica che passa i controlli va in produzione da sola. (c) non è nemmeno integrazione continua.

## [mcq 3] Secondo la meta-analisi presentata a lezione, rispetto alla programmazione individuale il pair programming
- [ ] riduce sia la durata sia lo sforzo totale in ore-persona
- [x] riduce la durata del compito, migliora un po' la qualità, ma aumenta lo sforzo totale
- [ ] aumenta la durata ma azzera i difetti
- [ ] non ha effetti misurabili su qualità e durata

### Soluzione
Hannay et al. (2009), 18 studi: qualità migliore (effetto piccolo), durata minore (effetto medio), sforzo totale maggiore (effetto medio). Conviene dove il beneficio giustifica il costo, per esempio sui compiti complessi.

## [mcq 3] Quale affermazione su XP e Scrum è corretta?
- [ ] XP e Scrum sono alternativi e non possono essere usati nello stesso team
- [ ] Scrum impone TDD e pair programming, XP lascia libera la scelta delle pratiche
- [x] XP è orientato alla qualità del codice, Scrum alla gestione del progetto; spesso coesistono
- [ ] In XP i requisiti si modificano solo a fine iterazione, in Scrum in ogni momento

### Soluzione
Scrum non impone pratiche di sviluppo: molti team usano quelle di XP. In XP i requisiti sono sempre modificabili e il cliente ordina le storie; in Scrum si cambiano a fine sprint (d è invertita).

## [mcq 3] Secondo lo Scrum Guide Expansion Pack, in un team che usa l'IA
- [ ] tutti i ruoli possono essere ricoperti da agenti automatici, purché supervisionati
- [x] Product Owner e Scrum Master devono essere umani; tra i Developers almeno uno umano
- [ ] lo Scrum Master può essere un LLM, mentre il Product Owner deve essere umano
- [ ] il Product Owner può essere un LLM, mentre lo Scrum Master deve essere umano

### Soluzione
Principio di responsabilità umana (*human in the loop*): l'IA è un partner decisionale supervisionato. Un LLM può aiutare il PO (bozze di storie, sintesi del feedback) e l'SM (sintesi del Daily, metriche), ma non sostituirne responsabilità, negoziazione, empatia.

## [mcq 3] Un guasto (failure) è
- [ ] un'azione umana sbagliata, per esempio un'errata interpretazione della specifica
- [ ] un'imperfezione nel codice o in un documento
- [x] un comportamento osservabile del sistema diverso da quello previsto
- [ ] una vulnerabilità di sicurezza rilevata dall'analisi statica

### Soluzione
Catena IEEE 610.12: errore (azione umana, a) → difetto/fault, il «bug» (b) → guasto/failure (c). Mars Climate Orbiter: libbre invece di newton (errore), modulo che calcola nell'unità sbagliata (difetto), sonda persa (guasto).

## [mcq 3] La qualità interna di un prodotto software
- [x] si misura senza eseguire il sistema, per esempio con l'analisi statica
- [ ] si misura eseguendo il sistema, per esempio con i test di sistema
- [ ] si misura con utenti reali, per esempio con test di usabilità
- [ ] si misura sul processo, per esempio con la percentuale di codice revisionato

### Soluzione
Processo → interna (senza eseguire: complessità, duplicazione) → esterna (eseguendo: tempi di risposta, guasti) → in uso (utenti reali). Ognuna influenza la successiva.

## [mcq 3] La legge di Goodhart dice che
- [ ] non si può controllare ciò che non si può misurare
- [x] quando una misura diventa un obiettivo smette di essere una buona misura
- [ ] il testing può mostrare la presenza di errori, mai la loro assenza
- [ ] aggiungere persone a un progetto in ritardo lo ritarda ulteriormente

### Soluzione
Esempi: copertura gonfiata con test senza asserzioni, velocity gonfiata, righe di codice (o «righe generate dall'IA») come produttività. (a) è DeMarco, (c) Dijkstra, (d) Brooks.

## [mcq 3] La complessità ciclomatica di McCabe si calcola sul grafo di flusso del codice come
- [ ] V(G) = E + N − 2
- [x] V(G) = E − N + 2
- [ ] V(G) = N − E + 2
- [ ] V(G) = E · N / 2

### Soluzione
E archi, N nodi: V(G) = E − N + 2, cioè il numero di cammini linearmente indipendenti. Per un grafo con un solo cammino (E = N − 1) vale 1. Esempio a lezione: N = 6, E = 7 → V(G) = 3.

## [num 3 = 4] Una funzione contiene tre istruzioni if in sequenza, non annidate e senza else. Qual è la sua complessità ciclomatica? (numero intero)

### Soluzione
Ogni if aggiunge una decisione: V(G) = numero di decisioni + 1 = 4. Sul grafo: per ogni if un nodo di decisione e un nodo «then», più un nodo iniziale e uno finale: N = 3·2 + 2 = 8; archi: 1 (start→if₁) + 3·3 (if→then, if→prossimo, then→prossimo) = 10; V(G) = 10 − 8 + 2 = 4.

## [mcq 3] Nel metodo Goal-Question-Metric (Basili)
- [ ] si parte dalle metriche già disponibili e si ricavano gli obiettivi che possono misurare
- [x] un goal si raffina in domande, a ciascuna delle quali rispondono una o più metriche
- [ ] ogni metrica si collega a un solo goal, senza passare per domande intermedie
- [ ] le domande sono quelle poste dal cliente alla sprint review, le metriche le risposte

### Soluzione
Top-down: goal (es. valutare l'affidabilità) → question (qual è la distribuzione dei guasti?) → metric (guasti per modulo). Partire dalle metriche disponibili (a) è proprio l'errore che GQM evita.

## [mcq 3] La copertura delle decisioni richiede che
- [ ] ogni comando sia eseguito almeno una volta, comprese le decisioni
- [x] ogni decisione sia valutata almeno una volta vera e almeno una volta falsa
- [ ] ogni cammino del grafo di flusso, attraverso tutte le decisioni, sia percorso
- [ ] ogni decisione sia valutata almeno una volta vera

### Soluzione
Copertura dei comandi (a) < decisioni (b) < cammini (c). (d) è un criterio black-box. Per il teorema di Weyuker è indecidibile, in generale, se esista un input che copre un dato comando, decisione o cammino.

## [mcq 3] Nella piramide dei test
- [x] alla base ci sono molti test di unità, veloci ed economici; in cima pochi test end-to-end, lenti e fragili
- [ ] alla base ci sono i test di accettazione, perché sono i più vicini all'utente
- [ ] ci sono tanti test end-to-end quanti test di unità
- [ ] i test manuali sono la base, quelli automatici la cima

### Soluzione
Salendo crescono costo, tempo e fragilità. L'anti-pattern opposto è il «cono gelato»: molti test manuali ed E2E, pochi test di unità.

## [mcq 3] Nel modello a V, i test di accettazione verificano
- [ ] il codice dei singoli moduli
- [ ] le interfacce tra i moduli
- [ ] l'architettura del sistema
- [x] i requisiti

### Soluzione
Ogni livello di specifica definisce i test corrispondenti: requisiti ↔ accettazione, architettura ↔ sistema, progetto dei moduli ↔ integrazione, codice ↔ unità.

## [mcq 3] Nella metafora del debito tecnico, gli «interessi» sono
- [ ] il tempo necessario per scrivere il codice la prima volta
- [ ] il numero di difetti trovati in produzione
- [x] il costo aggiuntivo che ogni modifica futura paga a causa della correzione rinviata
- [ ] il costo delle licenze delle librerie usate

### Soluzione
Cunningham (1992): il capitale è la correzione rinviata, gli interessi il sovrapprezzo di ogni modifica successiva. Si ripaga con il refactoring protetto dai test.

## [mcq 3] Il principio «Clean as You Code» applicato a un quality gate significa che
- [ ] prima di ogni rilascio si elimina tutto il debito tecnico pregresso
- [x] il gate giudica il codice nuovo o modificato, e il debito pregresso si ripaga gradualmente
- [ ] il codice viene ripulito automaticamente dallo strumento di analisi statica
- [ ] ogni sviluppatore è responsabile solo del codice che ha scritto lui

### Soluzione
Chi tocca il codice lo lascia pulito. Il gate «Sonar way» mette condizioni sul codice nuovo (nessun nuovo problema, hotspot rivisti, copertura ≥ 80%, duplicazioni ≤ 3%), ma non garantisce la correttezza funzionale.

## [mcq 3] Un LLM genera la funzione prezzo(mesi) e, nella stessa risposta, i test che la verificano. Tutti i test passano. Che cosa si può concludere?
- [ ] La funzione è corretta, perché codice e test sono coerenti tra loro
- [ ] La funzione è corretta se la copertura dei test supera l'80%
- [x] Nulla di certo: il risultato atteso deve venire da una fonte indipendente dal codice
- [ ] La funzione è corretta se lo stesso modello, rileggendola, non trova errori

### Soluzione
Esempio della lezione: prezzo(mesi) = 30·mesi·0,9 con test prezzo(2) == 54 passa, ma il criterio concordato vuole 60. Né un'alta copertura né l'autorevisione dello stesso modello rimediano.

## [mcq 3] Lo «slopsquatting» è
- [ ] la duplicazione di codice prodotta dagli assistenti AI
- [x] la registrazione, da parte di un attaccante, di un pacchetto con il nome inventato da un LLM
- [ ] l'abitudine di accettare il codice generato senza leggerlo
- [ ] un attacco che inietta istruzioni malevole nel prompt

### Soluzione
Gli LLM suggeriscono pacchetti inesistenti (*package hallucination*); se un attaccante registra quel nome, chi installa il suggerimento esegue codice malevolo. Per questo il codice generato è codice non fidato e la DoD include la verifica delle dipendenze.

## [mcq 3] Lo standard IEEE 610.12 definisce un requisito come
- [ ] la descrizione dell'interfaccia e del comportamento concordata con il cliente
- [x] una condizione o capacità necessaria a un utente, o che un sistema deve possedere per un contratto o una specifica
- [ ] una funzione del sistema scritta come user story e accettata dal Product Owner
- [ ] un vincolo tecnologico imposto dal committente e riportato nel contratto

### Soluzione
Due facce: il *bisogno* dell'utente e l'*impegno* del sistema (verso contratto, standard, specifica).

## [mcq 3] «L'acquisto del biglietto deve avvenire su smartphone Android» è un requisito
- [ ] funzionale
- [ ] di qualità
- [x] di vincolo
- [ ] di business

### Soluzione
Funzionale: cosa fa il sistema («permette di comprare un biglietto»). Di qualità: quanto bene, in modo misurabile («in non più di un minuto»). Vincolo: limita come o dove lo si realizza (la piattaforma).

## [mcq 3] Quale delle seguenti frasi è un requisito e non una scelta di progetto?
- [ ] I prestiti sono salvati in una tabella Prestiti con chiave ISBN
- [ ] Le notifiche sono inviate tramite Firebase
- [x] L'iscritto viene avvisato quando il volume prenotato rientra
- [ ] La ricerca usa un indice full-text Elasticsearch

### Soluzione
Il requisito descrive lo scopo (cosa), non la soluzione (come). Una scelta tecnica entra nei requisiti solo come vincolo motivato (dal cliente, da norme, da sistemi esistenti).

## [mcq 3] Il principio IKIWISI («I'll Know It When I See It») porta a concludere che
- [ ] i requisiti vanno congelati prima di iniziare lo sviluppo
- [x] i requisiti emergono per iterazioni, con prototipi e rilasci frequenti
- [ ] il cliente non va coinvolto finché il prodotto non è finito
- [ ] i requisiti di qualità non sono verificabili

### Soluzione
Legge di Humphrey: i requisiti di un nuovo prodotto non sono chiari finché gli utenti non iniziano a usarlo. Sviluppare software è imparare.

## [mcq 3] In EARS, «Mentre un iscritto ha un prestito scaduto, il sistema deve impedirgli nuovi prestiti» è un requisito
- [ ] ubiquo
- [ ] guidato da un evento
- [x] guidato da uno stato
- [ ] di comportamento indesiderato

### Soluzione
Ubiquo: «Il sistema deve…». Evento: «Quando…». Stato: «Mentre…». Indesiderato: «Se… allora…». Opzione: «Dove…».

## [mcq 3] Nelle «3C» di una user story (Jeffries), la Confirmation è
- [ ] la firma del cliente sul contratto
- [ ] l'approvazione della storia da parte dello Scrum Master
- [x] l'insieme dei criteri di accettazione che verificano il comportamento
- [ ] la stima in story point concordata dal team

### Soluzione
Card (la frase sul cartoncino), Conversation (il dialogo che chiarisce i dettagli), Confirmation (i criteri sul retro, es. in Gherkin). Una storia senza Conversation e Confirmation è solo la Card: incompleta per un collega come per un LLM.

## [mcq 3] Nello spec-driven development (es. GitHub Spec Kit)
- [ ] si chiede all'agente di generare l'intera applicazione a partire da una frase
- [x] la specifica guida piano, task e implementazione, e l'umano revisiona il risultato
- [ ] il codice è la fonte di verità e la specifica si ricava dal codice generato
- [ ] la specifica si scrive alla fine, come documentazione per il cliente

### Soluzione
Specify → Plan → Tasks → Implement: «l'intento è la fonte di verità». (a) è il *vibe coding*, all'altro estremo dello spettro.

## [mcq 3] In Essence un Alpha è
- [ ] una versione preliminare del software, da mostrare agli stakeholder per avere feedback
- [ ] un ruolo del team con responsabilità definite, come il Product Owner in Scrum
- [x] un elemento essenziale del progetto, con stati e checkpoint per valutarne l'avanzamento
- [ ] un work product del progetto, come il documento dei requisiti o il piano di rilascio

### Soluzione
Alpha = Abstract-Level Progress Health Attribute. Il kernel ne ha sette, ognuno con stati e checklist, rappresentati da carte. Un Alpha non è un documento (d) né uno strumento.

## [mcq 3] In Essence, quale Alpha appartiene all'area Endeavor?
- [ ] Stakeholders
- [ ] Requirements
- [ ] Opportunity
- [x] Way of Working

### Soluzione
Customer: Stakeholders, Opportunity. Solution: Requirements, Software System. Endeavor: Team, Work, Way of Working.

## [mcq 3] Gli stati dell'Alpha Requirements, in ordine, sono
- [x] Conceived, Bounded, Coherent, Acceptable, Addressed, Fulfilled
- [ ] Identified, Solution Needed, Value Established, Viable, Addressed, Benefit Accrued
- [ ] Bounded, Conceived, Acceptable, Coherent, Fulfilled, Addressed
- [ ] Architecture Selected, Demonstrable, Usable, Ready, Operational, Retired

### Soluzione
(b) sono gli stati di Opportunity, (d) di Software System. Gli stati 1-4 di Requirements riguardano comprensione e accordo, 5-6 la realizzazione. Si avanza quando è soddisfatta la checklist dello stato.

## [mcq 3] Nel kernel di Essence
- [ ] il Software System produce il Team
- [x] il Team produce il Software System, che soddisfa i Requirements
- [ ] il Way of Working delimita i Requirements
- [ ] l'Opportunity esegue il Work

### Soluzione
Gli Stakeholders forniscono l'Opportunity e usano il Software System, che soddisfa i Requirements; i Requirements delimitano il Work; il Team produce il Software System ed esegue il Work, guidato dal Way of Working.

## [mcq 3] Constructor Fabric
- [ ] un modello linguistico open source specializzato nella generazione di codice tracciabile
- [ ] un IDE per l'AI coding, alternativo a Cursor e Copilot, con il comando cfs
- [x] uno strato di processo che gira dentro un tool di AI coding, il quale porta il modello
- [ ] un servizio cloud che ospita modelli open-weight per gli agenti di programmazione

### Soluzione
«Il tool host porta il modello, Constructor Fabric porta il processo»: non ha chiave API né modello proprio. I quattro pezzi: `cfs` (terminale), le skill `cf-*` (chat), i kit (SDLC di default), i CPT ID.

## [mcq 3] In Constructor Fabric un `cfs validate` senza errori garantisce che
- [ ] il software si comporta come richiesto dai criteri di accettazione
- [x] gli artefatti hanno struttura, sezioni, riferimenti e ID corretti
- [ ] tutti i requisiti del PRD sono stati implementati e coperti da test
- [ ] la review del codice è stata fatta da un revisore umano

### Soluzione
Il controllo è deterministico ma formale: un check verde o un lungo giro di fix non provano la correttezza. Resta necessaria la review umana finale.

## [mcq 3] Un Architecture Decision Record (ADR)
- [ ] elenca i requisiti funzionali e non funzionali del prodotto, ciascuno con la sua priorità
- [x] registra una scelta architetturale con contesto, opzioni considerate, esito e conseguenze
- [ ] descrive flussi, stati e algoritmi di una singola feature prima della sua implementazione
- [ ] raccoglie i risultati dell'analisi statica e le soglie del quality gate di ogni rilascio

### Soluzione
Una decisione, un record. Nella pipeline (PRD → ADR → DESIGN → DECOMPOSE → FEATURE → codice → test) si scrive prima del design, che così ha su cosa poggiare; tra sei mesi risponde a «perché l'abbiamo fatto così?». (a) è il PRD, (c) la FEATURE spec.

## [aperta 3] Si descrivano le differenze tra errore, difetto e guasto e si fornisca un esempio della catena che li lega.

### Soluzione
Secondo IEEE 610.12:
- **errore** (*error*): azione umana sbagliata, es. interpretare male la specifica;
- **difetto** (*fault*, bug): imperfezione nel codice o in un documento, conseguenza dell'errore;
- **guasto** (*failure*): comportamento osservabile diverso da quello previsto, prodotto dal difetto quando il codice difettoso viene eseguito.

Un difetto può restare latente senza mai causare guasti; un errore può non produrre difetti. Esempio: Mars Climate Orbiter (1999): il team usa libbre-forza·s invece di newton·s (errore), il modulo calcola gli impulsi nell'unità sbagliata (difetto), la sonda va persa (guasto). Altri esempi: Ariane 5 (overflow in codice riusato), Therac-25 (race condition).

### Griglia
- 1 | Definizioni corrette dei tre concetti
- 1 | Relazione causale errore → difetto → guasto (e difetto latente)
- 1 | Esempio concreto coerente

## [aperta 3] Si dettagli la differenza tra verifica e validazione e si mostri come il modello a V collega i livelli di specifica ai livelli di test.

### Soluzione
- **Verifica**: «stiamo costruendo il prodotto nel modo giusto?»: conformità alla specifica. Può essere statica (ispezioni, analisi statica) o dinamica (test).
- **Validazione**: «stiamo costruendo il prodotto giusto?»: accettazione del cliente, rispetto ai suoi bisogni reali.

**Modello a V** (Boehm): il ramo sinistro scende nella specifica, quello destro risale nei test; ogni livello di specifica definisce i test del livello corrispondente:
- requisiti ↔ test di accettazione (validazione);
- architettura ↔ test di sistema;
- progetto dei moduli ↔ test di integrazione;
- codice ↔ test di unità.

### Griglia
- 1 | Distinzione verifica / validazione con le due domande
- 1 | Verifica statica e dinamica
- 1 | Corrispondenze del modello a V

## [aperta 3] Si descriva la differenza tra testing black-box e white-box, indicando per ciascuno almeno due tecniche o criteri.

### Soluzione
- **Black-box (funzionale)**: i casi si derivano dalla specifica, senza guardare il codice. Tecniche: classi di equivalenza, valori limite, tabelle di decisione, test dai casi d'uso. Esempio: «al massimo 5 prestiti attivi» → valori −1, 0, 5, 6 più un rappresentante (3).
- **White-box (strutturale)**: i casi si derivano dal codice. Criteri di copertura: comandi (ogni comando eseguito), decisioni (ogni decisione vera e falsa), cammini (ogni cammino percorso).

Limiti: il test esaustivo è impossibile; la copertura non misura la qualità dei test (un test senza asserzioni copre senza verificare: il mutation testing aiuta); per Weyuker è indecidibile se un dato cammino sia percorribile. «Il testing illumina, non dimostra» (Dijkstra).

### Griglia
- 1 | Definizioni (specifica vs codice)
- 1 | Tecniche black-box (equivalenza, valori limite…)
- 1 | Criteri white-box di copertura e loro limiti

## [aperta 3] Si descriva la piramide dei test e si spieghi perché il «cono gelato» è considerato un anti-pattern.

### Soluzione
**Piramide**: alla base molti test di unità (veloci, economici, isolati: JUnit, pytest); al centro test di integrazione e di sistema (interfacce tra componenti); in cima pochi test end-to-end e di accettazione (lenti, fragili, vicini all'utente: Selenium, Playwright). Salendo crescono costo, tempo di esecuzione e fragilità, ma anche la vicinanza all'esperienza dell'utente.

**Cono gelato**: la piramide rovesciata, con molti test manuali ed E2E e pochi test di unità. È un anti-pattern perché il feedback diventa lento e costoso, i test si rompono per motivi non legati a difetti (fragilità) e un guasto E2E non localizza il difetto; di conseguenza si testa meno spesso e il refactoring diventa rischioso.

### Griglia
- 1 | Livelli della piramide nell'ordine giusto
- 1 | Motivazione (costo, velocità, fragilità crescono salendo)
- 1 | Cono gelato e perché è dannoso

## [aperta 3] Si descriva il debito tecnico e si illustri il quadrante di Fowler.

### Soluzione
**Debito tecnico** (Cunningham, 1992): come un debito finanziario. Il *capitale* è la correzione (di design, codice, test) rinviata; gli *interessi* sono il costo aggiuntivo di ogni modifica futura. Si misura come tempo stimato di correzione (SonarQube ne ricava il rating di manutenibilità) e si ripaga con refactoring protetto dai test, gradualmente («Clean as You Code»).

**Quadrante** (sconsiderato/prudente × consapevole/involontario):
- sconsiderato e consapevole: «non abbiamo tempo per il progetto»;
- prudente e consapevole: «rilasciamo ora e ne gestiamo le conseguenze»;
- sconsiderato e involontario: «che cos'è la stratificazione?»;
- prudente e involontario: «ora sappiamo come avremmo dovuto farlo».

### Griglia
- 1 | Metafora capitale / interessi
- 1 | Come si misura e si ripaga
- 1 | I quattro quadranti con esempio

## [aperta 3] Si descriva il metodo Goal-Question-Metric e lo si applichi alla valutazione dell'effetto di un assistente di programmazione AI sulla qualità del codice di un team.

### Soluzione
**GQM** (Basili): approccio top-down su tre livelli. *Goal* (livello concettuale: cosa si vuole valutare, per chi), *Question* (livello operativo: domande che caratterizzano il goal), *Metric* (livello quantitativo: dati che rispondono alle domande). Evita di misurare ciò che è comodo invece di ciò che serve.

Esempio:
- **Goal**: valutare l'effetto dell'assistente AI sulla qualità del prodotto, dal punto di vista del team.
- **Q1**: i difetti in produzione sono aumentati? → M1: difetti post-rilascio per KLOC, prima e dopo l'adozione.
- **Q2**: il codice è più difficile da mantenere? → M2: % di righe duplicate, complessità ciclomatica media, debito tecnico stimato.
- **Q3**: la sicurezza è peggiorata? → M3: nuove vulnerabilità per pull request.

Da evitare come metrica di successo: «righe generate dall'IA» (Goodhart: diventerebbe un obiettivo da gonfiare).

### Griglia
- 1 | Tre livelli del GQM descritti correttamente
- 1 | Goal e domande pertinenti
- 1 | Metriche quantitative coerenti con le domande (bonus: cenno a Goodhart)

## [aperta 3] Si descrivano i tre tipi di requisito (funzionale, di qualità, vincolo) e si mostri come rendere verificabile un requisito di qualità vago.

### Soluzione
Su una stessa funzione (acquisto di un biglietto del treno):
- **funzionale**, cosa fa il sistema: «il sistema permette di comprare un biglietto»;
- **di qualità**, quanto bene lo fa: «l'acquisto richiede non più di un minuto»;
- **vincolo**, limite su come o dove si realizza: «l'acquisto avviene su smartphone Android».

Un requisito di qualità diventa verificabile con **metrica + soglia + condizioni di misura**; ISO/IEC 25010 fa da checklist (efficienza, capacità di interazione, affidabilità, sicurezza…). Esempio: «la ricerca deve essere veloce» → «con 100.000 volumi e 200 utenti contemporanei, il 95% delle ricerche risponde in meno di 1 s». «L'app deve essere facile» → «un nuovo iscritto completa il primo prestito senza aiuto in meno di 3 minuti; su 10 utenti di prova almeno 9 ci riescono».

### Griglia
- 1 | Tre tipi definiti con esempio
- 1 | Regola metrica + soglia + condizioni
- 1 | Riscrittura misurabile corretta di un requisito vago

## [aperta 3] Si confrontino SRS, casi d'uso e user story come forme dei requisiti, indicando per ciascuna lettori, punti di forza e limiti.

### Soluzione
| Forma | Per chi | Forza | Limite |
|---|---|---|---|
| SRS («il sistema deve…») | contratto, certificazione, appalti | completo, contrattuale, tracciabile | costoso da mantenere, invecchia in fretta |
| Casi d'uso e scenari | chi progetta l'interazione | flussi principali ed eccezioni espliciti | verbosi, poco centrati sul valore |
| User story | cliente, utenti, backlog agile | valore e utente al centro, leggere | ambigue senza conversazione e criteri |

Forme diverse servono lettori diversi; per uno sviluppatore o un LLM la sola storia non basta: servono criteri verificabili (Gherkin, EARS) e un modello di dominio.

### Griglia
- 1 | SRS: lettori, forza, limite
- 1 | Casi d'uso: lettori, forza, limite
- 1 | User story: lettori, forza, limite

## [aperta 3] Si descriva Essence: che cosa sono kernel, Alpha, aree di interesse e stati, e a che cosa servono in un progetto.

### Soluzione
**Essence** (standard OMG, nato dall'iniziativa SEMAT) definisce un **kernel** di concetti comuni a qualunque progetto software, indipendente dal metodo (Scrum, XP, cascata…); le pratiche si descrivono sopra il kernel.

Gli **Alpha** sono gli elementi essenziali da tenere sotto controllo. Sono sette, in tre **aree di interesse**:
- *Customer*: Stakeholders, Opportunity;
- *Solution*: Requirements, Software System;
- *Endeavor*: Team, Work, Way of Working.

Ogni Alpha attraversa una sequenza di **stati** (es. Requirements: Conceived → Bounded → Coherent → Acceptable → Addressed → Fulfilled), ciascuno con una **checklist** di checkpoint. Le carte degli Alpha permettono al team di valutare insieme dove si trova (es. Progress Poker) e quale passo è più urgente: misurano avanzamento e salute del progetto, non solo del codice.

### Griglia
- 1 | Kernel e indipendenza dal metodo
- 1 | Sette Alpha nelle tre aree
- 1 | Stati con checklist e uso per valutare l'avanzamento

## [aperta 3] Si descrivano i valori e almeno quattro pratiche di Extreme Programming, mostrando come le pratiche si sostengono a vicenda.

### Soluzione
**Valori**: comunicazione, semplicità, feedback, coraggio, rispetto.

**Pratiche** (12 classiche): Planning Game, piccoli rilasci, cliente on-site; metafora, progettazione semplice (YAGNI), refactoring; testing (TDD), pair programming, proprietà collettiva del codice; integrazione continua, settimana di 40 ore, standard di codifica.

**Sostegno reciproco**: il refactoring è sicuro solo con test automatici e passi piccoli; la proprietà collettiva richiede standard di codifica, revisione (la coppia) e integrazione continua; i piccoli rilasci richiedono storie piccole e un cliente disponibile; la pianificazione adattiva richiede stime del team e feedback frequente. Prese da sole, molte pratiche sono rischiose.

### Griglia
- 1 | Valori di XP
- 1 | Almeno quattro pratiche descritte correttamente
- 1 | Dipendenze tra pratiche con esempi

## [aperta 3] Si dettagli la differenza tra integrazione continua, consegna continua e rilascio continuo.

### Soluzione
- **Integrazione continua** (pratica XP): ogni modifica, piccola, è integrata nella linea principale spesso (almeno ogni giorno); build e test automatici partono a ogni integrazione e gli errori si correggono subito. Testare rami separati integrati ogni due settimane *non* è integrazione continua.
- **Consegna continua** (*continuous delivery*): il software è sempre in uno stato rilasciabile, ma il rilascio resta una decisione (del PO, del business).
- **Rilascio continuo** (*continuous deployment*): ogni modifica che supera i controlli raggiunge automaticamente gli utenti.

Ogni livello presuppone il precedente: per rilasciare in automatico serve una pipeline di test affidabile.

### Griglia
- 1 | Integrazione continua: frequenza e verifica automatica
- 1 | Consegna continua: rilasciabile, rilascio deciso
- 1 | Rilascio continuo: automatico verso gli utenti

## [aperta 3] Si discutano i rischi del codice generato da LLM e si indichino le condizioni che dovrebbe soddisfare per essere considerato «Done».

### Soluzione
**Rischi** (quattro lenti):
- *correttezza*: con test deboli si sovrastima; codice plausibile ma sbagliato;
- *sicurezza*: vulnerabilità frequenti, dipendenze inventate (*package hallucination*, slopsquatting); il codice generato è codice non fidato;
- *manutenibilità*: più copia-incolla e meno refactoring, debito tecnico nascosto;
- *produttività*: la percezione di velocità non coincide con la misura; il costo di revisione cresce.

**Definition of Done per il codice generato**: revisione umana (letto e capito da almeno un developer); test indipendenti, non generati dallo stesso prompt; analisi statica, di sicurezza e dei segreti, dipendenze verificate; licenze e provenienza; nessun dato riservato nei prompt; tracciabilità (uso dell'IA dichiarato nella pull request). Quality gate in pipeline.

### Griglia
- 1 | Rischi di correttezza e sicurezza
- 1 | Rischi di manutenibilità / produttività percepita
- 1 | Condizioni concrete di DoD (revisione umana, test indipendenti, dipendenze)

## [aperta 3] Si descriva la pipeline di Constructor Fabric e il ruolo degli identificatori CPT nella tracciabilità.

### Soluzione
**Pipeline**: esplorazione (`cf-explore`) e opzioni (`cf-brainstorm`) → **PRD** (scopo, attori, requisiti funzionali e non, criteri di accettazione; ogni requisito ha ID e priorità) → **ADR** (una decisione per record, scritta prima del design) → **DESIGN** (trasforma PRD e ADR approvati in architettura, componenti, data model) → **DECOMPOSE** (feature ordinate con dipendenze; ogni elemento del design appartiene a esattamente una feature) → **FEATURE spec** (flussi, stati, algoritmi, DoD) → codice e test → review in una chat nuova o con un sub-agent. A ogni passo: review, approvazione dei finding, `cfs validate`.

**CPT ID** (*Canonical Provenance Trace*): stringhe stabili che compaiono nel PRD, nel DESIGN, nella decomposizione, nella FEATURE e nel codice come marker nei commenti (`@cpt-begin`/`@cpt-end`). Così alla domanda «quale codice implementa questo requisito?» risponde il repository; i riferimenti pendenti (`cfs map`) mostrano requisiti non implementati.

Limite: la validazione controlla la forma, non la correttezza; serve comunque la review umana.

### Griglia
- 1 | Sequenza degli artefatti nella pipeline
- 1 | CPT ID e tracciabilità requisito → codice
- 1 | Validazione deterministica e suoi limiti

## Contesto
Si consideri la seguente descrizione, fornita dall'Ateneo:

> L'Università vuole un'app per il bike sharing tra i suoi campus. Lo studente si registra con le credenziali d'Ateneo, cerca una bicicletta libera nella rastrelliera più vicina, la prenota per 15 minuti e la sblocca inquadrando un QR code. Al termine la riconsegna in una qualunque rastrelliera dell'Ateneo; il costo dipende dalla durata del noleggio e viene addebitato sul badge universitario. Il personale tecnico segnala le biciclette guaste e le mette fuori servizio. L'app deve essere veloce e facile da usare e deve funzionare su Android e iOS. Il Rettore vuole che entro un anno il 20% degli spostamenti tra i campus avvenga in bicicletta.

## [aperta 3] Si classifichino i requisiti presenti nella descrizione in funzionali, di qualità e vincoli, e si indichi a quale livello (business, utente, software) appartiene l'obiettivo del Rettore.

### Soluzione
- **Funzionali**: registrazione con credenziali d'Ateneo; ricerca di una bici libera vicina; prenotazione per 15 minuti; sblocco con QR code; riconsegna in qualunque rastrelliera; calcolo del costo in base alla durata e addebito sul badge; segnalazione di bici guaste e messa fuori servizio (personale tecnico).
- **Di qualità**: «veloce» (efficienza prestazionale), «facile da usare» (capacità di interazione). Così come sono scritti non sono verificabili.
- **Vincoli**: piattaforme Android e iOS; autenticazione con le credenziali d'Ateneo (sistema esistente); pagamento tramite badge universitario.

L'obiettivo del Rettore è un **requisito di business**: risponde a «perché serve il prodotto?» e va nella visione. È già misurabile (20% in un anno).

Cosa manca (domande per il cliente): cosa succede se la prenotazione scade, tariffe, bici danneggiata dallo studente, dati personali conservati (GDPR).

### Griglia
- 1 | Requisiti funzionali individuati
- 1 | Qualità e vincoli distinti correttamente
- 1 | Obiettivo del Rettore come requisito di business

## [aperta 3] Si riscrivano in forma misurabile i requisiti «veloce» e «facile da usare», e si scrivano due requisiti in notazione EARS, uno guidato da un evento e uno di comportamento indesiderato.

### Soluzione
**Misurabili** (metrica + soglia + condizioni):
- veloce → «con 500 utenti contemporanei, nel 95% dei casi la mappa delle bici libere compare in meno di 2 s dall'apertura dell'app»;
- facile → «uno studente al primo utilizzo prenota e sblocca una bici senza aiuto in meno di 2 minuti; su 10 studenti di prova almeno 9 ci riescono».

**EARS**:
- evento: «*Quando* una bici viene agganciata a una rastrelliera dell'Ateneo, il sistema deve chiudere il noleggio e addebitare il costo sul badge»;
- indesiderato: «*Se* la prenotazione non viene usata entro 15 minuti, *allora* il sistema deve annullarla e rendere di nuovo libera la bici».

(Altri schemi: stato «Mentre una bici è fuori servizio, il sistema deve impedirne la prenotazione»; ubiquo «Il sistema deve identificare ogni bici con un codice univoco».)

### Griglia
- 1 | Riscrittura misurabile di «veloce»
- 1 | Riscrittura misurabile di «facile da usare»
- 1 | Due requisiti EARS corretti negli schemi richiesti

## [aperta 3] Si scriva una user story relativa alla descrizione, completa delle «3C», con almeno due criteri di accettazione in forma Given/When/Then.

### Soluzione
**Card**: «Come studente voglio prenotare una bicicletta nella rastrelliera più vicina, per essere sicuro di trovarla quando arrivo».

**Conversation** (dettagli chiariti col cliente): la prenotazione dura 15 minuti; si può avere una sola prenotazione attiva; uno studente con un noleggio in corso non può prenotare.

**Confirmation** (criteri in Gherkin):
```
Scenario: prenotazione riuscita
  Given una bici libera nella rastrelliera "Via Zamboni"
  When lo studente la prenota
  Then la bici risulta prenotata per 15 minuti
  And non è prenotabile da altri studenti

Scenario: prenotazione scaduta
  Given una bici prenotata da 15 minuti e non sbloccata
  When scade il tempo
  Then la prenotazione è annullata
  And la bici torna libera
```
La storia rispetta INVEST: indipendente, negoziabile, di valore, stimabile, piccola (sta in uno sprint), testabile.

### Griglia
- 1 | Card nel formato ruolo / funzione / beneficio, storia atomica
- 1 | Conversation con dettagli concreti
- 1 | Almeno due criteri Given/When/Then verificabili

## [aperta 3] Usando l'Alpha Requirements di Essence, si indichi in quale stato si trova il progetto descritto e che cosa manca per passare allo stato successivo.

### Soluzione
Il progetto è in stato **Conceived**: gli stakeholder (Ateneo, Rettore) concordano che il sistema va prodotto, gli utenti (studenti, personale tecnico) e il finanziatore (l'Università) sono identificati, l'opportunità è chiara.

Per passare a **Bounded** la checklist chiede: stakeholder dello sviluppo identificati; scopo del sistema concordato (es. sono incluse le bici elettriche? i docenti?); criterio di successo chiaro (c'è già: 20% in un anno); formato dei requisiti concordato (es. user story con criteri Gherkin); gestione dei requisiti attiva e schema di priorità (es. MoSCoW); vincoli identificati (Android/iOS, credenziali e badge d'Ateneo, GDPR) e assunzioni esplicite.

Non è ancora **Coherent**: i requisiti di qualità sono vaghi e molti casi (scadenza, guasti, tariffe) non sono stati discussi.

### Griglia
- 1 | Stato corretto (Conceived) motivato con la checklist
- 1 | Elementi mancanti per Bounded
- 1 | Riferimento concreto alla descrizione (vincoli, criterio di successo, ambiguità)
