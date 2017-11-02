OPT = -std=c++11

all: good bad

good: ex.cpp
	g++ $(OPT) -o goodRUNME.o ex.cpp

bad: bad.cpp
	g++ $(OPT) -o badRUNME.o bad.cpp

run: example
	./goodRUNME.o && ./badRUNME.o

clean:
	rm -f *.o
