#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *siguiente;
};

struct nodo *frente = NULL;
struct nodo *siguiente = NULL;

void mostrar();
void ponerencola(int);
void quitardelacola();
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
int main()
{
    int n, eleccion;
    do
    {
        printf("\n\nFunciones de cola\n1. Añadir a la cola \n2. Quitar de la cola\n3. Mostrar\n0. Salir");
        printf("\nEscoger opcion: ");
        scanf("%d", &eleccion);
        switch(eleccion)
        {
            case 1:
                printf("\nIngrese valor ");
                scanf("%d", &n);
                ponerencola(n);
                break;
            case 2:
                quitardelacola();
                break;
            case 3:
                mostrar();
                break;
        }
    }while (eleccion != 0);
}
