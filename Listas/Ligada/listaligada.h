#ifndef __listaligada_h__
#define __listaligada_h__
#include <stdio.h>
#include <stdlib.h>
struct nodo{
  int dato;
  struct nodo *siguiente;
};
int conteo = 0;
struct nodo *primero = NULL;
void insertaralprincipio(int x);
void insertaralfinal(int x);
void mostrar();
void borrardesdeprincipio();
void borrardesdefinal();

#endif
