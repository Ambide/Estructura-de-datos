#include "doble.h"

/* añade un nuevo nodo al final de la lista doble */
struct doblenodo *primero = NULL;
void agregarfinal(int num)
{
    struct doblenodo *nuevo,  *temporal = primero;
    /*Crea un nuevo nodo */
    nuevo = malloc(sizeof(struct doblenodo));
    nuevo->dato = num;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    /* Si la lista esta vacia */
    if (primero == NULL)
    {
        primero = nuevo;
    }
    else
    {
        /* Recorre la lista doble hasta llegar al ultimo nodo */
        while (temporal->siguiente != NULL)
            temporal = temporal->siguiente;

        nuevo->anterior = temporal;
        temporal->siguiente = nuevo;
    }
}

/* Añade un nuevo nodo al principio de la lista doble */
void agregarprincipio(int num)
{
    struct doblenodo *nuevo;

    /* Crea un nuevo nodo */
    nuevo = malloc(sizeof(struct doblenodo));

    /* Asigna el dato y apunta al siguiente nodo */
    nuevo->anterior = NULL;
    nuevo->dato = num;
    nuevo->siguiente = primero;

    if (primero != NULL)
        primero->anterior = nuevo;
    primero = nuevo;
}


/* Borra un nodo especifico a traves del dato que contiene este. */
void eliminar(int num)
{
    struct doblenodo *temporal = primero;

    /* Recorre toda la lista doble */
    while (temporal != NULL)
    {
        /* Si se encuentra el nodo a eliminar*/
        if (temporal->dato == num)
        {
            /* Si el nodo a eliminar es el primero de la lista */
            if (temporal == primero)
            {
                primero = primero->siguiente;
                primero->anterior = NULL;
            }
            else
            {
                /* Si el nodo a eliminar es el ultimo de la lista */
                if (temporal->siguiente == NULL)
                    temporal->anterior->siguiente = NULL;
                else
                /* Si el nodo a eliminar se encuentra entre 2 nodos */
                {
                    temporal->anterior->siguiente = temporal->siguiente;
                    temporal->siguiente->anterior = temporal->anterior;
                }
                free(temporal);
            }
            return ; /* Regresa despues de eliminar el nodo. */
        }
        temporal = temporal->siguiente; /* Pasa al siguiente nodo */
    }
    printf("\n%d no encontrado.", num);
}

/* Muestra la lista doble */
void mostrar()
{
	struct doblenodo *temporal = primero;
    printf("\n");

    /* Recorre la lista doble */
    while (temporal != NULL)
    {
        printf("%d\t", temporal->dato);
        temporal = temporal->siguiente;
    }
}
