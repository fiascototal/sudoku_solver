CFLAGS=-W -Wall -fPIC
LDFLAGS=-pie

all: sudoku

*.o: *.c
	$(CC) -c -o $@ $< $(CFLAGS)

sudoku: sudoku.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o sudoku
