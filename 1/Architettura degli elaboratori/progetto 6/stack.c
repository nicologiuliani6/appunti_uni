#include "stack.h"
// Inizializza la struttura dello stack
void initialize(VMStack *stack) {
    stack->localTop = 0;
    stack->argumentTop = 0;
    stack->thisTop = 0;
    stack->thatTop = 0;
    stack->staticTop = 0;
    stack->tempTop = 0;
    stack->pointerTop = 0;
    for(int i=0; i<MAX_SIZE; i++){
        stack->local[i] = 0;      // Stack per variabili locali
        stack->argument[i]= 0;   // Stack per gli argomenti della funzione
        stack->this[i]= 0;       // Stack per variabili membro di un oggetto
        stack->that[i]= 0;       // Stack per altre variabili membro
        stack->static_var[i]= 0;
    }
    for(int i=0; i<8; i++){
        stack->temp[i] = 0;
    }
    stack->pointer[0] = 0;
    stack->pointer[1] = 0;
}

// Funzione per pushare un valore nello stack specifico
void push(VMStack *stack, const char* segment, int value) {
    if (strcmp(segment, "local") == 0) {
        if (stack->localTop >= MAX_SIZE) {
            printf("Errore: Overflow stack 'local'.\n");
            return;
        }
        stack->local[stack->localTop++] = value;
        //("Pushed %d to local stack.\n", value);
    }
    else if (strcmp(segment, "argument") == 0) {
        if (stack->argumentTop >= MAX_SIZE) {
            printf("Errore: Overflow stack 'argument'.\n");
            return;
        }
        stack->argument[stack->argumentTop++] = value;
        //printf("Pushed %d to argument stack.\n", value);
    }
    else if (strcmp(segment, "this") == 0) {
        if (stack->thisTop >= MAX_SIZE) {
            printf("Errore: Overflow stack 'this'.\n");
            return;
        }
        stack->this[stack->thisTop++] = value;
        //printf("Pushed %d to this stack.\n", value);
    }
    else if (strcmp(segment, "that") == 0) {
        if (stack->thatTop >= MAX_SIZE) {
            printf("Errore: Overflow stack 'that'.\n");
            return;
        }
        stack->that[stack->thatTop++] = value;
        //printf("Pushed %d to that stack.\n", value);
    }
    else if (strcmp(segment, "static") == 0) {
        if (stack->staticTop >= MAX_SIZE) {
            printf("Errore: Overflow stack 'static'.\n");
            return;
        }
        stack->static_var[stack->staticTop++] = value;
        //printf("Pushed %d to static stack.\n", value);
    }
    else if (strcmp(segment, "temp") == 0) {
        if (stack->tempTop >= 8) {
            printf("Errore: Overflow stack 'temp'.\n");
            return;
        }
        stack->temp[stack->tempTop++] = value;
        //printf("Pushed %d to temp stack.\n", value);
    }
    else if (strcmp(segment, "pointer") == 0) {
        if (stack->pointerTop >= 2) {
            printf("Errore: Overflow stack 'pointer'.\n");
            return;
        }
        stack->pointer[stack->pointerTop++] = value;
        //printf("Pushed %d to pointer stack.\n", value);
    }
    else {
        printf("Errore: Segmento non valido per 'push'.\n");
    }
}

// Funzione per poppare un valore dallo stack specifico
int pop(VMStack *stack, const char* segment) {
    if (strcmp(segment, "local") == 0) {
        /*
        if (stack->localTop <= 0) {
            printf("Errore: Stack 'local' vuoto.\n");
            return -1; // Errore
        }
        */
        return stack->local[--stack->localTop];
    }
    else if (strcmp(segment, "argument") == 0) {
        /*
        if (stack->argumentTop <= 0) {
            printf("Errore: Stack 'argument' vuoto.\n");
            return -1;
        }
        */
        return stack->argument[--stack->argumentTop];
    }
    else if (strcmp(segment, "this") == 0) {
        /*
        if (stack->thisTop <= 0) {
            printf("Errore: Stack 'this' vuoto.\n");
            return -1;
        }
        */
        return stack->this[--stack->thisTop];
    }
    else if (strcmp(segment, "that") == 0) {
        /*
        if (stack->thatTop <= 0) {
            printf("Errore: Stack 'that' vuoto.\n");
            return -1;
        }
        */
        return stack->that[--stack->thatTop];
    }
    else if (strcmp(segment, "static") == 0) {
        /*
        if (stack->staticTop <= 0) {
            printf("Errore: Stack 'static' vuoto.\n");
            return -1;
        }
        */
        return stack->static_var[--stack->staticTop];
    }
    else if (strcmp(segment, "temp") == 0) {
        /*
        if (stack->tempTop <= 0) {
            printf("Errore: Stack 'temp' vuoto.\n");
            return -1;
        }
        */
        return stack->temp[--stack->tempTop];
    }
    else if (strcmp(segment, "pointer") == 0) {
        /*
        if (stack->pointerTop <= 0) {
            printf("Errore: Stack 'pointer' vuoto.\n");
            return -1;
        }
        */
        return stack->pointer[--stack->pointerTop];
    }
    else {
        printf("Errore: Segmento non valido per 'pop'.\n");
        return -1;
    }
}

// Funzione per ottenere l'elemento in cima allo stack
int peek(VMStack *stack, const char* segment) {
    if (strcmp(segment, "local") == 0) {
        if (stack->localTop >= 0) {
            return stack->local[stack->localTop];
        }
    } else if (strcmp(segment, "argument") == 0) {
        if (stack->argumentTop >= 0) {
            return stack->argument[stack->argumentTop];
        }
    } else if (strcmp(segment, "this") == 0) {
        if (stack->thisTop >= 0) {
            return stack->this[stack->thisTop];
        }
    } else if (strcmp(segment, "that") == 0) {
        if (stack->thatTop >= 0) {
            return stack->that[stack->thatTop];
        }
    } else if (strcmp(segment, "static") == 0) {
        if (stack->staticTop >= 0) {
            return stack->static_var[stack->staticTop];
        }
    } else if (strcmp(segment, "temp") == 0) {
        if (stack->tempTop >= 0) {
            return stack->temp[stack->tempTop];
        }
    } else if (strcmp(segment, "pointer") == 0) {
        if (stack->pointerTop >= 0) {
            return stack->pointer[stack->pointerTop];
        }
    }
    return -1; // Errore se lo stack è vuoto
}

// Funzione per stampare un segmento dello stack
void printStack(VMStack *stack, const char* segment) {
    printf("Contenuto dello stack %s: ", segment);
    if (strcmp(segment, "local") == 0) {
        for (int i = 0; i <= stack->localTop; i++) {
            printf("%d ", stack->local[i]);
        }
    } else if (strcmp(segment, "argument") == 0) {
        for (int i = 0; i <= stack->argumentTop; i++) {
            printf("%d ", stack->argument[i]);
        }
    } else if (strcmp(segment, "this") == 0) {
        for (int i = 0; i <= stack->thisTop; i++) {
            printf("%d ", stack->this[i]);
        }
    } else if (strcmp(segment, "that") == 0) {
        for (int i = 0; i <= stack->thatTop; i++) {
            printf("%d ", stack->that[i]);
        }
    } else if (strcmp(segment, "static") == 0) {
        for (int i = 0; i <= stack->staticTop; i++) {
            printf("%d ", stack->static_var[i]);
        }
    } else if (strcmp(segment, "temp") == 0) {
        for (int i = 0; i <= stack->tempTop; i++) {
            printf("%d ", stack->temp[i]);
        }
    } else if (strcmp(segment, "pointer") == 0) {
        for (int i = 0; i <= stack->pointerTop; i++) {
            printf("%d ", stack->pointer[i]);
        }
    }
    printf("\n");
}

// Funzione per eseguire operazioni aritmetiche e logiche
void emulate_ARITHMETIC(VMStack *stack, const char* command) {
    int val1, val2, result;

    // Verifica se lo stack è abbastanza grande per eseguire l'operazione
    /*
    if (stack->localTop == 0) {
        printf("Errore: Stack vuoto.\n");
        return;
    }
    */
    // Operazioni: add, sub, neg, eq, gt, lt, and, or, not
    if (strcmp(command, "add") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'add'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = val1 + val2;
        stack->local[stack->localTop++] = result;
        printf("Add: %d + %d = %D", val1, val2, result);
    }
    else if (strcmp(command, "sub") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'sub'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = val1 - val2;
        stack->local[stack->localTop++] = result;
        printf("Sub: %d - %d = %D", val1, val2, result);
    }
    else if (strcmp(command, "neg") == 0) {
        if (stack->localTop < 1) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'neg'.\n");
            return;
        }
        val1 = stack->local[--stack->localTop];
        result = -val1;
        stack->local[stack->localTop++] = result;
        printf("Neg: -%d = %D", val1, result);
    }
    else if (strcmp(command, "eq") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'eq'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = (val1 == val2) ? -1 : 0;  // Hack VM usa -1 per vero, 0 per falso
        stack->local[stack->localTop++] = result;
        printf("Eq: %d == %d -> %D", val1, val2, result);
    }
    else if (strcmp(command, "gt") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'gt'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = (val1 > val2) ? -1 : 0;  // Hack VM usa -1 per vero, 0 per falso
        stack->local[stack->localTop++] = result;
        printf("Gt: %d > %d -> %D", val1, val2, result);
    }
    else if (strcmp(command, "lt") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'lt'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = (val1 < val2) ? -1 : 0;  // Hack VM usa -1 per vero, 0 per falso
        stack->local[stack->localTop++] = result;
        printf("Lt: %d < %d -> %D", val1, val2, result);
    }
    else if (strcmp(command, "and") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'and'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = val1 & val2;
        stack->local[stack->localTop++] = result;
        printf("And: %d & %d = %D", val1, val2, result);
    }
    else if (strcmp(command, "or") == 0) {
        if (stack->localTop < 2) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'or'.\n");
            return;
        }
        val2 = stack->local[--stack->localTop];
        val1 = stack->local[--stack->localTop];
        result = val1 | val2;
        stack->local[stack->localTop++] = result;
        printf("Or: %d | %d = %D", val1, val2, result);
    }
    else if (strcmp(command, "not") == 0) {
        if (stack->localTop < 1) {
            printf("Errore: Non ci sono abbastanza elementi nello stack per 'not'.\n");
            return;
        }
        val1 = stack->local[--stack->localTop];
        result = ~val1;  // Negazione bit a bit
        stack->local[stack->localTop++] = result;
        printf("Not: ~%d = %D", val1, result);
    }
    else {
        printf("Errore: Comando aritmetico non riconosciuto.\n");
    }
}
// Funzione per emulare le operazioni sullo stack (push, pop, ecc.)
void emulate_STACK(VMStack *stack, const char* command, const char* segment, int index) {
    if (strcmp(command, "push") == 0) {
        if (strcmp(segment, "local") == 0) {
            if (stack->localTop >= MAX_SIZE) {
                printf("Errore: Overflow stack 'local'.\n");
                return;
            }
            stack->local[stack->localTop++] = index;
            //printf("Pushed %d to local stack.\n", index);
        }
        else if (strcmp(segment, "argument") == 0) {
            if (stack->argumentTop >= MAX_SIZE) {
                printf("Errore: Overflow stack 'argument'.\n");
                return;
            }
            stack->argument[stack->argumentTop++] = index;
            //printf("Pushed %d to argument stack.\n", index);
        }
        else if (strcmp(segment, "constant") == 0) {
            if (stack->localTop >= MAX_SIZE) {
                printf("Errore: Overflow stack 'constant'.\n");
                return;
            }
            //printf("Pushed constant %d.\n", index);
        }
        else if (strcmp(segment, "static") == 0) {
            if (index < 0 || index >= MAX_SIZE) {
                printf("Errore: Indice non valido per static.\n");
                return;
            }
            stack->static_var[index] = index;  // Pusha nel segmento statico
            //printf("Pushed %d to static stack.\n", index);
        }
        else {
            printf("Errore: Segmento non valido per 'push'.\n");
        }
    }
    else if (strcmp(command, "pop") == 0) {
        if (strcmp(segment, "local") == 0) {
            /*
            if (stack->localTop <= 0) {
                printf("Errore: Stack 'local' vuoto.\n");
                return;
            }
            */
            stack->localTop--;
            //printf("Popped from local stack.\n");
        }
        else if (strcmp(segment, "argument") == 0) {
            /*
            if (stack->argumentTop <= 0) {
                printf("Errore: Stack 'argument' vuoto.\n");
                return;
            }
            */
            stack->argumentTop--;
            //printf("Popped from argument stack.\n");
        }
        else if (strcmp(segment, "static") == 0) {
            if (index < 0 || index >= MAX_SIZE) {
                printf("Errore: Indice non valido per static.\n");
                return;
            }
            stack->static_var[index] = 0;  // Pulisce il valore del segmento statico
            //printf("Popped from static stack.\n");
        }
        else {
            printf("Errore: Segmento non valido per 'pop'.\n");
        }
    }
}

static int label_counter = 0; // Contatore per generare etichette uniche
// Funzione per generare un'etichetta unica
char* generateLabel(const char* base_label) {
    char* label = (char*)malloc(BUFFER_SIZE * sizeof(char));  // Allocazione dinamica per l'etichetta
    if (label == NULL) {
        // Gestione errore in caso di fallimento nell'allocazione della memoria
        fprintf(stderr, "Errore nell'allocazione della memoria per l'etichetta.\n");
        exit(1);
    }
    snprintf(label, 100, "%s-%d", base_label, label_counter++);  // Genera l'etichetta unica
    return label;
}

// Funzione che genera il codice assembly per una determinata operazione
char* string_ASM(VMStack *stack, const char* command, const char* segment, int index, char *path_file_input) {
    char *result = malloc(BUFFER_SIZE);  // Allocazione dinamica per la stringa di risultato
    if (!result) {
        return "// Errore di allocazione della memoria per ASM\n";
    }

    // Se il comando è 'function'
    if (strcmp(command, "function") == 0) {
        // La sintassi della funzione è 'function nome 2', dove '2' è il numero di variabili locali
        snprintf(result, BUFFER_SIZE, "(%s)\n0", segment);  // Aggiungi il nome della funzione
        // Calcola lo spazio rimanente nel buffer
        int remaining_space = BUFFER_SIZE - strlen(result) - 1;

        for (int i = 0; i < index; i++) {
            // Per ogni variabile locale, aggiungi il codice per inizializzarla a 0
            // Assicurati che strncat non superi la dimensione disponibile
            if (remaining_space > strlen("\n@0\nD=A\n@SP\nM=M+1\nA=M-1\nM=D")) {
                strncat(result, "\n@0\nD=A\n@SP\nM=M+1\nA=M-1\nM=D", remaining_space);
                remaining_space -= strlen("\n@0\nD=A\n@SP\nM=M+1\nA=M-1\nM=D");
            } else {
                printf("Errore: spazio insufficiente nel buffer.\n");
                break;  // Esci dal ciclo se non c'è abbastanza spazio
            }
        }
    }
    else if (strcmp(command, "call") == 0) {
        // Creazione di una label di ritorno unica
        const char* returnLabel = generateLabel("RETURN_LABEL");

        // Inizializza la stringa 'result' con la chiamata della funzione
        snprintf(result, BUFFER_SIZE, 
            "// Chiamata della funzione %s con %d argomenti\n", segment, index);

        // Salva l'indirizzo di ritorno nello stack
        snprintf(result + strlen(result), BUFFER_SIZE - strlen(result), 
            "@%s\nD=A\n@SP\nM=M+1\nA=M-1\nM=D\n", returnLabel);

        // Salva i registri LCL, ARG, THIS, THAT nello stack
        const char* registers[] = {"LCL", "ARG", "THIS", "THAT"};
        for (int i = 0; i < 4; i++) {
            snprintf(result + strlen(result), BUFFER_SIZE - strlen(result), 
                "@%s\nD=M\n@SP\nM=M+1\nA=M-1\nM=D\n", registers[i]);
        }

        // Posiziona il parametro per la funzione nell'argomento
        snprintf(result + strlen(result), BUFFER_SIZE - strlen(result), 
            "@SP\nD=M\n@%d\nD=D-A\n@ARG\nM=D\n", index + 5);  // Gli argomenti si trovano dopo i 5 registri (LCL, ARG, THIS, THAT e l'indirizzo di ritorno)

        // Posiziona il valore di LCL per la funzione chiamata
        snprintf(result + strlen(result), BUFFER_SIZE - strlen(result), 
            "@SP\nD=M\n@LCL\nM=D\n");

        // Salta alla funzione
        snprintf(result + strlen(result), BUFFER_SIZE - strlen(result), 
            "@%s\n0;JMP\n", segment);    // Segment è il nome della funzione da chiamare

        // Etichetta di ritorno
        snprintf(result + strlen(result), BUFFER_SIZE - strlen(result), 
            "(%s)\n0", returnLabel);
    } 
    else if (strcmp(command, "label") == 0){
        //printf("CREATION LABEL: %s\n",segment);
        snprintf(result, BUFFER_SIZE, "// CREATION LABEL %s\n(%s)", segment, segment);
    }
    else if (strcmp(command, "if-goto") == 0){
        snprintf(result, BUFFER_SIZE, "// IF-GOTO LABEL %s\n@SP\nAM=M-1\nD=M\n@%s\nD;JNE", segment, segment);
    }
    else if (strcmp(command, "goto") == 0){
        snprintf(result, BUFFER_SIZE, "// GOTO LABEL %s\n@%s\n0;JMP", segment, segment);
    }
    else if (strcmp(command, "push") == 0) {
    if (strcmp(segment, "constant") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH CONSTANT %d\n@%d\nD=A\n@SP\nM=M+1\nA=M-1\nM=D", index, index);
    }
    else if (strcmp(segment, "local") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH LOCAL %d\n@LCL\nD=M\n@%d\nA=D+A\nD=M\n@SP\nM=M+1\nA=M-1\nM=D", 
                 index, index);
    }
    else if (strcmp(segment, "argument") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH ARGUMENT %d\n@ARG\nD=M\n@%d\nA=D+A\nD=M\n@SP\nM=M+1\nA=M-1\nM=D", 
                 index, index);
    }
    else if (strcmp(segment, "this") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH THIS %d\n@THIS\nD=M\n@%d\nA=D+A\nD=M\n@SP\nM=M+1\nA=M-1\nM=D", 
                 index, index);
    }
    else if (strcmp(segment, "that") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH THAT %d\n@THAT\nD=M\n@%d\nA=D+A\nD=M\n@SP\nM=M+1\nA=M-1\nM=D", 
                 index, index);
    }
    else if (strcmp(segment, "static") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH STATIC %d\n@%s.%d\nD=M\n@SP\nM=M+1\nA=M-1\nM=D", 
                 index, path_file_input,index);
    }

    else if (strcmp(segment, "pointer") == 0) {
        snprintf(result, BUFFER_SIZE, "// PUSH POINTER %d\n@3\nD=A\n@%d\nA=D+A\nD=M\n@SP\nM=M+1\nA=M-1\nM=D", 
                 index, index);
    }
    }
    // Se il comando è 'pop'
    else if (strcmp(command, "pop") == 0) {
        if (strcmp(segment, "local") == 0) {
            snprintf(result, BUFFER_SIZE, "// POP LOCAL %d\n@LCL\nD=M\n@%d\nD=D+A\n@R13\nM=D\n@SP\nAM=M-1\nD=M\n@R13\nA=M\nM=D", stack->local[index], index);
        }
        else if (strcmp(segment, "argument") == 0) {
            snprintf(result, BUFFER_SIZE, "// POP ARGUMENT %d\n@ARG\nD=M\n@%d\nD=D+A\n@R13\nM=D\n@SP\nAM=M-1\nD=M\n@R13\nA=M\nM=D", stack->argument[index], index);
        }
        else if (strcmp(segment, "static") == 0){
             snprintf(result, BUFFER_SIZE, "// POP STATIC %d\n@%s.%d\nD=A\n@R13\nM=D\n@SP\nAM=M-1\nD=M\n@R13\nA=M\nM=D",index,path_file_input,index);
        }
        else snprintf(result, BUFFER_SIZE, "//ERRORE: SEGMENTO NON VALIDO: %s\n",segment);
    }
    // Comandi aritmetici e logici
    else if (strcmp(command, "add") == 0) {
        snprintf(result, BUFFER_SIZE, "// ADD\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M+D");
    }
    else if (strcmp(command, "sub") == 0) {
        snprintf(result, BUFFER_SIZE, "// SUB\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M-D");
    }
    else if (strcmp(command, "neg") == 0) {
        snprintf(result, BUFFER_SIZE, "// NEG\n@SP\nA=M-1\nM=-M");
    }
    else if (strcmp(command, "eq") == 0) {
        char* label0 = generateLabel("TRUE_EQ");
        char* label1 = generateLabel("FALSE_EQ");
        snprintf(result, BUFFER_SIZE, "// EQ\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M-D\nD=M\n@%s\nD;JEQ\nD=0\n@%s\n0;JMP\n(%s)\nD=-1\n(%s)\n@SP\nA=M-1\nM=D", label0, label1,label0,label1);
    }
    else if (strcmp(command, "gt") == 0) {
        char* label0 = generateLabel("TRUE_GT");
        char* label1 = generateLabel("FALSE_GT");
        snprintf(result, BUFFER_SIZE, "// GT\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M-D\nD=M\n@%s\nD;JGT\nD=0\n@%s\n0;JMP\n(%s)\nD=-1\n(%s)\n@SP\nA=M-1\nM=D", label0, label1, label0,label1);
    }
    else if (strcmp(command, "lt") == 0) {
        char* label0 = generateLabel("TRUE_LT");
        char* label1 = generateLabel("FALSE_LT");
        snprintf(result, BUFFER_SIZE, "// LT\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M-D\nD=M\n@%s\nD;JLT\nD=0\n@%s\n0;JMP\n(%s)\nD=-1\n(%s)\n@SP\nA=M-1\nM=D", label0, label1, label0,label1);
    }
    else if (strcmp(command, "and") == 0) {
        snprintf(result, BUFFER_SIZE, "// AND\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M&D");
    }
    else if (strcmp(command, "or") == 0) {
        snprintf(result, BUFFER_SIZE, "// OR\n@SP\nMD=M-1\nA=D\nD=M\nA=A-1\nM=M|D");
    }
    else if (strcmp(command, "not") == 0) {
        snprintf(result, BUFFER_SIZE, "// NOT\n@SP\nA=M-1\nM=!M");
    }
    else if (strcmp(command, "return") == 0) {snprintf(result, BUFFER_SIZE, "// RETURN\n@LCL\nD=M\n@R14\nM=D\n@5\nA=D-A\nD=M\n@R15\nM=D\n@ARG\nD=M\n@R13\nM=D\n@SP\nAM=M-1\nD=M\n@R13\nA=M\nM=D\n@ARG\nD=M+1\n@SP\nM=D\n@R14\nD=M\n@1\nA=D-A\nD=M\n@THAT\nM=D\n@R14\nD=M\n@2\nA=D-A\nD=M\n@THIS\nM=D\n@R14\nD=M\n@3\nA=D-A\nD=M\n@ARG\nM=D\n@R14\nD=M\n@4\nA=D-A\nD=M\n@LCL\nM=D\n@R15\nA=M\n0;JMP");
    }
    return result;
}


// Funzione per tradurre una riga in codice ASM per VM
char* ASM(char *line, VMStack *stack, char *path_file_input) {
    static int isFirstLine = 1; // Variabile statica che tiene traccia della prima riga
    char command[BUFFER_SIZE], segment[BUFFER_SIZE];
    int index;

    char *line_trimmed = strtok(line, "\n");
    //printf("Riga ricevuta: %s\n", line);

    char *result = malloc(BUFFER_SIZE); // Buffer per il risultato
    if (!result) {
        return "// ERRORE: Memoria insufficiente\n";
    }
    result[0] = '\0'; // Inizializza la stringa

    // Se è la prima riga, aggiungi il codice di inizializzazione
    if (isFirstLine) {
        isFirstLine = 0; // Disabilita l'aggiunta del codice per le righe successive
        snprintf(result, BUFFER_SIZE, "// Initialization\n@256\nD=A\n@SP\nM=D\n");
    }

    // Trattamento della riga per i comandi VM
    if (sscanf(line_trimmed, "%s %s %d", command, segment, &index) == 3) {
        //printf("Comando: %s, Segmento: %s, Indice: %d\n", command, segment, index);
        if(strcmp(command, "label") != 0 || strcmp(command, "if-goto") != 0 || strcmp(command, "goto") != 0 || strcmp(command, "function") != 0)
            emulate_STACK(stack, command, segment, index);  // Esegui l'emulazione della stack per altre operazioni
        char *commandResult = string_ASM(stack, command, segment, index, path_file_input);
        // Calcola lo spazio rimanente nel buffer
        int remaining_space = BUFFER_SIZE - strlen(result) - 1;
        
        // Usa strncat in modo sicuro, solo se c'è abbastanza spazio
        if (remaining_space > strlen(commandResult)) {
            strncat(result, commandResult, remaining_space);
        } else {
            printf("Errore: spazio insufficiente per concatenare il comando.\n");
        }
        free(commandResult);
        
    } 
    else if (sscanf(line_trimmed, "%s %s", command, segment) == 2) {
        //printf("Comando: %s, Segmento: %s\n", command, segment);
        if(strcmp(command, "label") != 0 || strcmp(command, "if-goto") != 0 || strcmp(command, "goto") != 0 || strcmp(command, "function") != 0)
            emulate_STACK(stack, command, segment, -1);  // Non usiamo un indice, quindi mettiamo -1
        char *commandResult = string_ASM(stack, command, segment, -1, path_file_input);
        
        // Calcola lo spazio rimanente nel buffer
        int remaining_space = BUFFER_SIZE - strlen(result) - 1;
        
        // Usa strncat in modo sicuro
        if (remaining_space > strlen(commandResult)) {
            strncat(result, commandResult, remaining_space);
        } else {
            printf("Errore: spazio insufficiente per concatenare il comando.\n");
        }
        free(commandResult);
    } 
    else if (sscanf(line_trimmed, "%s", command) == 1) {
        //printf("Comando: %s\n", command);
        // Aggiungi il trattamento dei comandi aritmetici/logici
        char *commandResult = string_ASM(stack, command, NULL, -1, path_file_input);
        
        // Calcola lo spazio rimanente nel buffer
        int remaining_space = BUFFER_SIZE - strlen(result) - 1;
        
        // Usa strncat in modo sicuro
        if (remaining_space > strlen(commandResult)) {
            strncat(result, commandResult, remaining_space);
        } else {
            printf("Errore: spazio insufficiente per concatenare il comando.\n");
        }
        free(commandResult);
    } else {
        snprintf(result, BUFFER_SIZE, "// ERRORE: Riga non valida\n");
    }
    
    return result;
}












