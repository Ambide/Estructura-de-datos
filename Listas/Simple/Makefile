a.out: main.o listaligada.o
	gcc main.o listaligada.o
main.o: main.c
	gcc -c main.c
arbol.o: listaligada.c
	gcc -c listaligada.c
run: a.out
	./a.out
clear:
	rm a.out main.o listaligada.o 
