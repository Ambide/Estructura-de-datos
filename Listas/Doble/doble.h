// Aquí van las cabeceras de las funciones declaradas

#ifndef __DOBLE_H__
#define __DOBLE_H__

#include <stdio.h>
#include <stdlib.h>

/* Estructura que representa la lista doble */
struct doblenodo
{
    struct doblenodo *anterior;
    int dato;
    struct doblenodo *siguiente;
};
void agregarfinal(int);
void agregarprincipio(int);
void eliminar(int);
void mostrar();

#endif
