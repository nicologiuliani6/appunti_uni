# 🌐 Tecnologie Web — Esercitazione C  
**Studente:** Nicolò Giuliani  
**Matricola:** 0001171301
**Anno accademico:** 2025/2026  

---

## 📁 Struttura del progetto

```
/
├── index.html              → Pagina principale con griglia dei macro-temi
├── html.html               → Esercizi relativi al tema HTML
├── css.html                → Esercizi relativi al tema CSS
├── js.html                 → Esercizi relativi al tema JavaScript
├── chat.html               → Mockup interfaccia chat (solo design, senza JS)
├── risorse.html            → Box "Materiali" e link utili (MDN, W3Schools, template)
├── glossario.html          → Glossario dei termini principali (facoltativo)
├── 404.html                → Pagina di errore 404 personalizzata
│
├── /css/                   → Cartella degli stili
│   ├── variables.css       → Definizione variabili CSS (colori, spazi, radius)
│   ├── style.css           → Stili generali, layout e animazioni
│   └── html.css            → Stile timeline e layout esercizi
│
├── /img/                   → Immagini e icone royalty-free o di mia creazione
│
└── README.md               → Documentazione del progetto
```

---

## 🎨 Scelte di design

- **Approccio mobile-first** → layout ottimizzato per smartphone, con successivi breakpoint per tablet e desktop
- **Color palette coerente** → definita tramite variabili CSS (`--brand`, `--bg`, `--text`) in `variables.css` per garantire coerenza visiva
- **Font scelto** → `Montserrat` per un'estetica moderna e leggibile
- **Animazioni leggere** → `fadeInUp` e transizioni hover sui link per una UX fluida
- **Layout ibrido** → combinazione di **Bootstrap** e **Tailwind CSS** per rapidità e controllo fine del design
- **Timeline esercizi** → impaginazione alternata sinistra/destra con colori dinamici (verde → rosso) in base alla difficoltà
- **Accessibilità (A11y)** → uso corretto di tag semantici (`<main>`, `<header>`, `<nav>`, `<section>`, `<footer>`), testi alternativi, focus visibile, contrasto WCAG-AA
- **Footer coerente** → presente su tutte le pagine, con nome autore e anno accademico

---

## 🧰 Librerie e strumenti utilizzati

- **Bootstrap 5.3.8** — griglie responsive e componenti base  
- **Tailwind CSS (via CDN)** — utility classes per styling rapido  
- **Google Fonts: Montserrat**  
- **Nessun JavaScript** (come richiesto nella consegna)  
- **HTML5 + CSS3** puri

---

## 🖼️ Crediti immagini e licenze

- Icone ed emoji standard Unicode ✅  
- Immagini e grafiche (se presenti) → fonti **royalty-free** (Unsplash, unDraw) o di mia creazione  
- Licenza: **Creative Commons CC BY-NC-SA 4.0** *(uso educativo e non commerciale)*

---

## ✅ Checklist di conformità

| Requisito | Soddisfatto | Dettagli |
|-----------|-------------|----------|
| Nessun JavaScript | ✅ | Tutte le interazioni sono puramente CSS |
| Layout con Flex/Bootstrap/Tailwind | ✅ | Bootstrap + Tailwind combinati |
| Variabili CSS + `calc()` | ✅ | Presenti in `variables.css` e usate in `style.css` |
| Almeno 2 animazioni | ✅ | `fadeInUp` + effetto hover link |
| 3 breakpoint mobile-first | ✅ | 768px / 1024px / desktop |
| A11y (semantica, alt, contrasto) | ✅ | Verificata con Lighthouse e validatore W3C |
| Sidebar o breadcrumb | ✅ | Navigazione sticky coerente |
| Glossario (facoltativo) | ✅ | Implementato in `glossario.html` |
| Pagina 404 personalizzata | ✅ | Presente in `404.html` |
| Footer con crediti | ✅ | Uniforme su tutte le pagine |

---

## 📌 Note finali

Il progetto rispetta integralmente la richiesta di **assenza di JavaScript**, adotta un approccio **mobile-first**, e utilizza **CSS moderni** (variabili, animazioni, media query, calc).  

È pienamente accessibile, coerente e facilmente estendibile come **template per le future edizioni del corso**.

---

✍️ *Realizzato con cura da*  
**Nicolò Giuliani — Tecnologie Web 2025/2026**