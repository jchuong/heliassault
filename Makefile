CXX = g++
CXXFLAGS = -Wall -g -std=c++11
EXEC = heli
OBJECTS = heli.o game.o

all: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -lsfml-graphics -lsfml-window -lsfml-system -o ${EXEC}

clean:
	echo "Cleaning up build"
	rm ${OBJECTS} ${EXEC}
