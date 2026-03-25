CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJECTS = assemblatore.o symbol_table.o

assembler: $(OBJECTS)
	$(CC) -o assembler $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o assembler

