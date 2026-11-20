# Ciancarini 2026: argomenti nuovi rispetto agli anni passati

Modulo 1 del corso 2026-27 è del prof. Ciancarini (presentazione «0 presentazione 2026»; Modulo 2 Succi; esercitazioni Missiroli).
Metodo: "negli anni passati" = scritti 2015-2025, simulazione 2023 e esempi 2025 in `esami/quiz/ingegneria-del-software/`, controllati per parole chiave. Non avendo gli appunti degli anni passati, il criterio è questo: se il tema non compare nelle domande di quegli anni, è «nuovo».
Le domande aggiunte stanno in `banca-esercitazioni-ciancarini.md` (tag argomento: vedi build).

| Argomento | Fonte 2026 | Negli anni passati? | Domande aggiunte |
|---|---|---|---|
| Ciclo di vita, costi, manutenzione (Boehm) | L2 Ciancarini | no | sì (4 + aperta) |
| Produttività, Standish CHAOS, perché falliscono i progetti | L2 | no | sì (in 4 domande) |
| Miti e leggende, Brooks, «silver bullet» | L2 | no | sì (2) |
| Essence: kernel, 7 Alpha, aree, carte, checkpoint, Progress Poker | Essence (manuale, lezione 2 Alpha), L2 | no (una sola occorrenza come distrattore) | sì (9) |
| Futuro dell'ingegneria del software, SEMAT | pptx «Il futuro…» | no | sì (1) |
| Processi agili: MVP | L3 | parziale (1 riferimento) | sì (1, caso Dropbox) |
| XP: YAGNI, integrazione continua, pair programming, proprietà collettiva, user story | L3 | parziale (pair e story point già presenti) | sì (5 + aperta) |
| Scrum nell'era degli LLM (LLM come SM) | Scrum_v2 (attribuzione da verificare) | no | sì (3) |
| Qualità: errore, difetto, guasto | L14 | parziale (1 riferimento) | sì (2) |
| ISO/IEC 25010:2023, qualità interna/esterna/in uso | L14 | no | sì (2) |
| GQM, complessità ciclomatica, legge di Goodhart | L14 | no | sì (GQM 1 aperta, ciclomatica 2 numeriche, Goodhart 1 aperta) |
| Black-box/white-box, classi di equivalenza, valori limite, copertura | L14 | parziale (solo black/white box) | sì (3) |
| Piramide dei test | L14 | no | sì (1) |
| Analisi statica, SonarQube, quality gate, Clean as You Code | L14 | no | sì (2) |
| Debito tecnico | L14 | parziale (1 riferimento) | sì (1) |
| Codice generato da LLM: correttezza, sicurezza, manutenibilità, produttività | L14 | no | sì (5 + aperta) |
| Constructor Fabric (PRD, ADR, DESIGN, DECOMPOSE, cfs validate) | CF01, CF02 | no | sì (5 + aperta) |
| Produzione del software: aspetti economici, licenze, garanzie, rischi | L1 | parziale (licenze 1 riferimento) | sì (in `banca-verosimili-ciancarini-modulo1.md`, argomento `produzione`) |
| Agenti e orchestratori, AI e produttività (2025) | L1 | parziale (agenti LangChain nei 2025, non questo tema) | sì (1, orchestratore) |
| Forme dei requisiti: definizione IEEE 610.12, Humphrey/IKIWISI, funzionali/qualità/vincoli misurabili, livelli business/utente/software, SRS vs casi d'uso vs user story, job story, Gherkin, EARS, spec-driven development (Spec Kit, Kiro) | 6_requisiti_2026_v3 (Modulo 1, quindi Ciancarini: confermato dall'utente) | parziale (funzionali/non funzionali e INVEST già presenti; IEEE, vincoli, livelli, EARS, Gherkin, spec-driven no) | sì (7 + aperta), argomento `requisiti` |

Non sono di Ciancarini (quindi fuori da questa lista): Scrum intro, user story, testing/TDD/pair programming, Git, Retrospective (Missiroli; la retrospettiva era già nei quiz passati). Le user story compaiono però anche nella lezione di Ciancarini sulle forme dei requisiti (Connextra, job story, 3C, INVEST, Gherkin).

Non sono di Ciancarini nemmeno L05 Python (aggiornata: lambda Java vs Python, creazione/distruzione, descrittori, dataclass) e L05 bis Prolog: sono di Succi (Modulo 2). Python era già nei topic; Prolog è nuovo: argomento `prolog`, domande in `banca-succi-prolog.md`.

Domande in stile esame: `banca-verosimili-ciancarini-modulo1.md` (66 domande su tutto il Modulo 1, nella forma degli scritti 2023-2025: crocette da 3 punti, aperte da 3 punti con griglia 1/1/1, un contesto «bike sharing» con 4 aperte su requisiti, EARS, Gherkin e Alpha Requirements).
Lacune note: le slide di L1 sono state lette solo per titoli; le domande su L1 sono basate sugli appunti.
