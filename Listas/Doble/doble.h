// Aquí van las cabeceras de las funciones declaradas

#ifndef __DOBLE_H__
#define __DOBLE_H__

#include <stdio.h>
#include <stdlib.h>

/* structure representing a node of the doubly linked list */
struct doblenodo
{
    struct doblenodo *anterior;
    int dato;
    struct doblenodo *siguiente;
};

struct doblenodo *primero = NULL;

void agregarfinal(int);
void agregarprincipio(int);
void eliminar(int);
void mostrar();

#endif
