SRC = main.cpp griglia.cpp levels.cpp classifica.cpp sort.cpp plugin_interface.cpp
CXXFLAGS = -std=c++17 -O3 -fPIC
LDFLAGS = -shared -lncurses
TARGET_SO = snake_game.so

OBJ = ${SRC:.cpp=.o}

all: ${TARGET_SO}

${TARGET_SO}: ${OBJ}
	${CXX} ${CXXFLAGS} -o $@ ${OBJ} ${LDFLAGS}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ} ${TARGET_SO}

