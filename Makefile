all: estoque biblioteca

estoque: estoque.o AVL.o
	gcc estoque.o AVL.o -o estoque

biblioteca: biblioteca.o AVL.o
	gcc biblioteca.o AVL.o -o biblioteca

estoque.o: estoque.c estoque.h AVL.h
	gcc -c estoque.c -Wall -Wextra -std=c99

biblioteca.o: biblioteca.c biblioteca.h AVL.h
	gcc -c biblioteca.c -Wall -Wextra -std=c99

AVL.o: AVL.c AVL.h
	gcc -c AVL.c -Wall -Wextra -std=c99

run_estoque: estoque
	./estoque

run_biblioteca: biblioteca
	./biblioteca

clean:
	rm -rf *.o estoque biblioteca