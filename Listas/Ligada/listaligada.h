#ifndef __listaligada_H__
#define __listaligada_H__
#include <stdio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo* siguiente;
};

struct nodo* primero = NULL;
struct nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarLista();
#endif
