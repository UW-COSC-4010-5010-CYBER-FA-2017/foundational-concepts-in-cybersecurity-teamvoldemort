OPT = -std=c++11

all: good bad evil

good: good.cpp
	g++ $(OPT) -o goodRUNME.o good.cpp

bad: bad.c
	cc -o badRUNME.o bad.c

evil: evil.c
	cc -o evil.o evil.c

run: all
	./goodRUNME.o && ./badRUNME.o

clean:
	rm -f *.o
