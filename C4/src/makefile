OPT = -std=c++11

all: example

example: ex.cpp
	g++ $(OPT) -o RUNME.o ex.cpp

run: example
	./RUNME.o

clean:
	rm -f RUNME.o
