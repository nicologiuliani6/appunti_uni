# Compilatore e flag
CC = gcc
CFLAGS = -Wall -Wextra -g -w

# File sorgenti e oggetto
SRCS = main.c misc.c stack.c
OBJS = $(SRCS:.c=.o)

# Nome dell'eseguibile
EXEC = VMtranslator

# Regola di default
all: $(EXEC)

# Regola per creare l'eseguibile
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regola per compilare i file oggetto
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia dei file generati
clean:
	rm -f $(OBJS) $(EXEC)

# Pulizia completa (anche file temporanei)
distclean: clean
	rm -f *~

# Phony targets
.PHONY: all clean distclean
