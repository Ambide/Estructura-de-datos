#include "simple.h"

void agregaralfinal(int valor)
{
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if (primero == NULL)
    {
        primero = nuevo;
    }
    else
    {
        struct nodo *temporal;
        temporal = primero;
        while (temporal->siguiente != NULL)
        {
            temporal = temporal->siguiente;
        } temporal->siguiente = nuevo;
    }
}


void agregaralprincipio(int valor)
{
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = valor;
    nuevo->siguiente = primero;
    primero = nuevo;
}


void mostrar()
{
    struct nodo *temporal;
    temporal = primero;
    if (temporal == NULL)
    {
        printf("La lista simple esta vacia");
    }
    while (temporal != NULL)
    {
        printf("%d : ", temporal->dato);
        temporal = temporal->siguiente;
    }
}

void sum()
{
    int sum = 0;
    struct nodo *temporal;
    temporal = primero;
    while (temporal != NULL)
    {
        sum = sum + temporal->dato;
        temporal = temporal->siguiente;
    } printf("La suma de todos los valores de los nodos es :%d", sum);
}

int buscar(int valor)
{
    int loc = 0;
    struct nodo *temporal;
    temporal = primero;
    while (temporal != NULL)
    {
        loc++;
        if (temporal->dato == valor)
        {
            return loc;
        } temporal = temporal->siguiente;
    }
    return  - 1;
}



void eliminar(int valor)
{
    struct nodo *temporal,  *old;
    temporal = primero;
    while (temporal != NULL)
    {
        if (temporal->dato == valor)
        {
            if (temporal == primero)
            {
                primero = temporal->siguiente;
            }
            else
                old->siguiente = temporal->siguiente;
            printf("\n%d ttem Eliminard\n",temporal->dato);
            free(temporal);
            return ;
        }
        else
        {
            old = temporal;
            temporal = temporal->siguiente;
        }
    }
    printf("Valor no encontrado ");
}
