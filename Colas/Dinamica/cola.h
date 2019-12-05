// Aquí van las cabeceras de las funciones declaradas

#ifndef __COLA_H__
#define __COLA_H__

#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *siguiente;
};

struct nodo *frente = NULL;
struct nodo *siguiente = NULL;

void mostrar();
void ponerencola(int);
void quitardelacola();

#endif
