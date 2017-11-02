CC=cc
CFLAGS=

all: good bad

good:
	$(CC) $(CFLAGS) good.c -o runGoodEx.o

bad:
	$(CC) $(CFLAGS) bad.c -o runBadEx.o

run: good bad
	./runGoodEx.o && ./runBadEx.o

clean:
	rm -f *.o
