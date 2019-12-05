#include"cola.h"
struct nodo *frente = NULL;
struct nodo *siguiente = NULL;
void ponerencola(int valor)
{
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if (siguiente == NULL)
    {
        frente = nuevo;
        siguiente = nuevo;
    }
    else
    {
        siguiente->siguiente = nuevo;
        siguiente = siguiente->siguiente;
    }
}

void mostrar()
{
    struct nodo *temporal;
    temporal = frente;
    printf("\n");
    while (temporal != NULL)
    {
        printf("%d\t", temporal->dato);
        temporal = temporal->siguiente;
    }
}

void quitardelacola()
{
    if (frente == NULL)
    {
        printf("\n\nla cola esta vacia \n");
    }
    else
    {
        struct nodo *temporal;
        temporal = frente;
        frente = frente->siguiente;
        printf("\n\n%d quitado de la cola", temporal->dato);
        free(temporal);
    }
}
