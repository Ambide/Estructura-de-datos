#ifndef __LISTACONTIGUA_H__
#define __LISTACONTIGUA_H__

#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int *datos;
  int actual;
  int cuantos;
};

void insertar (struct nodo **, int);
void eliminar (struct nodo **, int);
void mostrar (struct nodo *);

#endif
