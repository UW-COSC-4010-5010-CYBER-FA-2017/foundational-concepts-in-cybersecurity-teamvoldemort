GCCOPT = -std=c++11

all: c0 c1 c2 c3 c4 c5 c6 c7 c8 c9

c0: c0good c0bad c0evil

c0good: C0/src/good.cpp
	g++ $(GCCOPT) -o c0good.o C0/src/good.cpp

c0bad: C0/src/bad.c
	cc -o c0bad.o C0/src/bad.c

c0evil: C0/src/evil.c
	cc -o c0evil.o C0/src/evil.c

c1: c1good c1bad c1evil

c1good: C1/src/good.cpp
	g++ $(GCCOPT) -o c1good.o C1/src/good.cpp

c1bad: C1/src/bad.c
	cc -o c1bad.o C1/src/bad.c

c1evil: C1/src/evil.c
	cc -o c1evil.o C1/src/evil.c

c2: c2good c2bad

c2good: C2/src/ex.cpp
	g++ $(GCCOPT) -o c2good.o C2/src/ex.cpp

c2bad: C2/src/bad.cpp
	g++ $(GCCOPT) -o c2bad.o C2/src/bad.cpp

c3: c3good c3bad

c3good: C3/src/good.cpp
	g++ $(GCCOPT) -o c3goodRUNME.o C3/src/good.cpp

c3bad: C3/src/bad.cpp
	g++ $(GCCOPT) -o c3badRUNME.o C3/src/bad.cpp

c4: c4example

c4example: C4/src/ex.cpp
	g++ $(GCCOPT) -o c4good.o C4/src/ex.cpp

c5: c5good c5bad

c5good: C5/src/ex.cpp
	g++ $(GCCOPT) -o c5good.o C5/src/ex.cpp

c5bad: C5/src/bad.cpp
	g++ $(GCCOPT) -o c5bad.o C5/src/bad.cpp

c6: c6good c6bad

c6good: C6/src/ex.cpp
	g++ $(GCCOPT) -o c6good.o C6/src/ex.cpp

c6bad: C6/src/bad.cpp
	g++ $(GCCOPT) -o c6bad.o C6/src/bad.cpp

c7: c7good

c7good: C7/src/ex.cpp
	g++ $(GCCOPT) -o c7good.o C7/src/ex.cpp

c8: c8good c8bad

c8good:
	cc C8/src/good.c -o c8good.o

c8bad:
	cc C8/src/bad.c -o c8bad.o

c9: c9good c9bad c9client

c9client: C9/src/client.c
	g++ $(GCCOPT) -o client.o C9/src/client.c

c9good: C9/src/ex.cpp
	g++ $(GCCOPT) -o c9good.o C9/src/ex.cpp

c9bad: C9/src/non.cpp
	g++ $(GCCOPT) -o c9bad.o C9/src/non.cpp

clean:
	rm -f *.o
