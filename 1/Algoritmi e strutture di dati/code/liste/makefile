# Nome dell'eseguibile
TARGET = liste

# File sorgenti
SRCS = liste.cpp

# Compilatore e flag
CXX = g++
CXXFLAGS = -Wall -O3

# Regola di default
all: $(TARGET)

# Regola per costruire l'eseguibile
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Regola per eseguire il programma
run: $(TARGET)
	./$(TARGET)

# Pulizia dei file generati
clean:
	rm -f $(TARGET)