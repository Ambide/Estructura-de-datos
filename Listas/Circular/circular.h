#ifndef __CIRCULAR_H__
#define __CIRCULAR_H__

#include <stdio.h>
#include <stdlib.h>

struct listaligada{
    int numero;
    struct listaligada *siguiente;
    struct listaligada *anterior;
};

void insertarprimero(int numero);
void insertaralultimo(int numero);
void insertarenmedio(int numero, int posicion);
void eliminarprimero();
void eliminarultimo();
void eliminarenmedio(int posicion);
void imprimirprincipio();
void imprimirultimo();
void imprimirlista();
int cuantoshay();
#endif
