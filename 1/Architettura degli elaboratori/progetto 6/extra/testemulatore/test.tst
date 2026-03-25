// non inizializziamo LCL e ARG: dal momento che usiamo
// una funzione in Miocodice.vm (chiamata da Sys.vm), l'emulatore inizializza
// questi segmenti per noi. SP è già inizializzato.

load,

set RAM[0] 256, //SP

repeat 600 {
 vmstep;
}

