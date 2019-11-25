listacontigua.o: listacontigua.c
	gcc listacontigua.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o listacontigua.o
	gcc main.o listacontigua.o

run: a.out
	./a.out

clean:
	rm -f *.o a.out
