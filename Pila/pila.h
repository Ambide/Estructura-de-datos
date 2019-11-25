#ifndef __Pila_H__
#define __Pila_H__
#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo* siguiente;
};

struct nodo* primero = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarPila();
#endif
