OPT = -std=c++11

all: good bad

good: good.cpp
	g++ $(OPT) -o goodRUNME.o good.cpp

bad: bad.cpp
	g++ $(OPT) -o badRUNME.o bad.cpp

run: example
	./goodRUNME.o && ./badRUNME.o

clean:
	rm -f *.o
