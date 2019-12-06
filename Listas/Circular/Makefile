a.out: main.o circular.o
	gcc main.o circular.o
main.o: main.c
	gcc -c main.c
arbol.o: circular.c
	gcc -c circular.c
run: a.out
	./a.out
clear:
	rm a.out main.o circular.o
