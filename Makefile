CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: estoque biblioteca

estoque: estoque.o AVL.o
	$(CC) estoque.o AVL.o -o estoque

biblioteca: biblioteca.o AVL.o
	$(CC) biblioteca.o AVL.o -o biblioteca

estoque.o: estoque.c estoque.h AVL.h
	$(CC) -c estoque.c $(CFLAGS)

biblioteca.o: biblioteca.c biblioteca.h AVL.h
	$(CC) -c biblioteca.c $(CFLAGS)

AVL.o: AVL.c AVL.h
	$(CC) -c AVL.c $(CFLAGS)

run_estoque: estoque
	./estoque

run_biblioteca: biblioteca
	./biblioteca

clean:
	rm -rf *.o estoque biblioteca
