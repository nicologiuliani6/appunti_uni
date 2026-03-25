#!/bin/bash

for vmfile in VM/*.vm; do
  # Estrai il nome del file senza l'estensione .vm
  filename=$(basename "$vmfile" .vm)

  # Compilazione e esecuzione del primo programma
  ./VMtranslator "$vmfile"
  ../nand2tetris/tools/CPUEmulator.sh VM/$filename.tst

  # Compilazione ed esecuzione del secondo programma
  #cd copia/ && gcc main.c codewriter.c parser.c && ./a.out "../$vmfile"

  # Torna indietro e esegui il programma C++ usando il nome del file senza estensione
  #cd ../ && g++ check_uguaglianza.cpp && ./a.out "VM/$filename.asm" "VM/$filename"_cp.asm
done

