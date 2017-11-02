OPT = -std=c++11

all: good bad client

client: client.c
	g++ $(OPT) -o client.o client.c

good: ex.cpp
	g++ $(OPT) -o goodRUNME.o ex.cpp

bad: non.cpp
	g++ $(OPT) -o badRUNME.o non.cpp

run: example
	./goodRUNME.o && ./badRUNME.o

clean:
	rm -f *.o
