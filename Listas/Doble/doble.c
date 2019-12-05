/* adds a new node at the end of the doubly linked list */
#include "doble.h"
void agregarfinal(int num)
{
    struct doblenodo *nuevo,  *temporal = primero;

    /*create a new node */
    nuevo = malloc(sizeof(struct doblenodo));
    nuevo->dato = num;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    /* if the linked list is empty */
    if (primero == NULL)
    {
        primero = nuevo;
    }
    else
    {
        /* traverse the linked list till the last node is reached */
        while (temporal->siguiente != NULL)
            temporal = temporal->siguiente;

        nuevo->anterior = temporal;
        temporal->siguiente = nuevo;
    }
}

/* adds a new node at the begining of the linked list */
void agregarprincipio(int num)
{
    struct doblenodo *nuevo;

    /* create a new node */
    nuevo = malloc(sizeof(struct doblenodo));

    /* assign dato and pointer to the new node */
    nuevo->anterior = NULL;
    nuevo->dato = num;
    nuevo->siguiente = primero;

    if (primero != NULL)
        primero->anterior = nuevo;
    primero = nuevo;
}


/* deletes the specified node from the doubly linked list */
void eliminar(int num)
{
    struct doblenodo *temporal = primero;

    /* traverse the entire linked list */
    while (temporal != NULL)
    {
        /* if node to be deleted is found */
        if (temporal->dato == num)
        {
            /* if node to be deleted is the first node */
            if (temporal == primero)
            {
                primero = primero->siguiente;
                primero->anterior = NULL;
            }
            else
            {
                /* if node to be deleted is the last node */
                if (temporal->siguiente == NULL)
                    temporal->anterior->siguiente = NULL;
                else
                /* if node to be deleted is any intermediate node */
                {
                    temporal->anterior->siguiente = temporal->siguiente;
                    temporal->siguiente->anterior = temporal->anterior;
                }
                free(temporal);
            }
            return ; /* return back after deletion */
        }
        temporal = temporal->siguiente; /* go to siguiente node */
    }
    printf("\n%d no encontrado.", num);
}

/* mostrars the contents of the linked list */
void mostrar()
{
	struct doblenodo *temporal = primero;
    printf("\n");

    /* traverse the entire linked list */
    while (temporal != NULL)
    {
        printf("%d\t", temporal->dato);
        temporal = temporal->siguiente;
    }
}
