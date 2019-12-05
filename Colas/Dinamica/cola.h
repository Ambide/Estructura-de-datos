// Aquí van las cabeceras de las funciones declaradas

#ifndef __COLA_H__
#define __COLA_H__

#include<stdlib.h>
#include<stdio.h>

struct nodo
{
    int dato;
    struct nodo *siguiente;
};

void mostrar();
void ponerencola(int);
void quitardelacola();

#endif
