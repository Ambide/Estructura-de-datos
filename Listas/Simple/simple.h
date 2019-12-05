#ifndef __listaligada_h__
#define __listaligada_h__
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *siguiente;
};

struct nodo *primero = NULL;

void agregaralfinal(int);
void mostrar();
void agregaralprincipio(int);
void sum();
int buscar(int);
void eliminar(int);

#endif
