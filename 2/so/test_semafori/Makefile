# Nome dell'eseguibile
TARGET = main

# File sorgenti
SRCS = main.c BinarySemaphore.c Semaphore.c

# Compilatore e flags
CC = cc
CFLAGS = -Wall -Wextra -pthread -g

# Regola di default
all: $(TARGET)

# Compilazione dell'eseguibile
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Pulizia dei file oggetto e dell'eseguibile
clean:
	rm -f $(TARGET) *.o

# Compilazione e esecuzione
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run

