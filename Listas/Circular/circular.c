#include "circular.h"
struct listaligada *primero = NULL;
struct listaligada *ultimo=NULL;
// Insertar al frente de la lista circular
void insertarprimero(int numero)
{
    struct listaligada *nuevo = (struct listaligada *) malloc(sizeof(struct listaligada));

    nuevo->numero = numero;
    nuevo->siguiente = nuevo;
    nuevo->anterior = nuevo;printf("Hay %d elementos en la lista doble.\n",cuantoshay());

    if(primero==NULL)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        nuevo->siguiente = primero;
        nuevo->anterior = ultimo;
        primero->anterior = nuevo;
        ultimo->siguiente = nuevo;
        primero = nuevo;
    }

}

// Insertar un nodo al ultimo de una lista circular
void insertaralultimo(int numero)
{
    struct listaligada *nuevo = (struct listaligada *) malloc(sizeof(struct listaligada));

    nuevo->numero = numero;
    nuevo->siguiente = nuevo;
    nuevo->anterior = nuevo;

    if(primero==NULL)
    {
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = primero;
        nuevo->anterior = ultimo;
        ultimo = nuevo;
        primero->anterior = ultimo;
    }
}

// Insertar en medio de 2 nodos en una lista circular
void insertarenmedio(int numero, int posicion)
{
    if(posicion==1)
    {
        insertarprimero(numero);
        return;
    }
    else if(posicion>1 && primero!=NULL)
    {
        struct listaligada *actual = primero;
        struct listaligada *temporal = (struct listaligada *) malloc(sizeof(struct listaligada));
        int contador = 0;

        do
        {
            contador++;
            temporal = actual;
            actual = actual->siguiente;
        }   while(actual->siguiente != primero && contador<posicion-1);

        if(contador==posicion-1)
        {
            if(temporal==ultimo)
                insertaralultimo(numero);
            else
            {
                struct listaligada *nuevo = (struct listaligada *) malloc(sizeof(struct listaligada));
                nuevo->numero = numero;

                temporal->siguiente = nuevo;
                nuevo->siguiente = actual;
                nuevo->anterior = temporal;
                actual->anterior = nuevo;

            }
            return;
        }

    }

    printf("La posicion no existe!\n");
}

// Borra el primer nodo de la lista circular
void eliminarprimero()
{
    if(primero==NULL)
    return;

    struct listaligada *temporal = primero;

    ultimo->siguiente = primero->siguiente;
    primero = primero->siguiente;
    primero->anterior = ultimo;

    free(temporal);
}

// Borra el ultimo nodo de la lista circular
void eliminarultimo()
{
    if(primero==NULL)
    return;

    struct listaligada *temporal = primero;
    struct listaligada *actual = primero;

    while(actual->siguiente != primero)
    {
        temporal = actual;
        actual = actual->siguiente;
    }
    // Ahora, el nodo "actual" es el ultimo. Y el nodo "temporal" es el anterior nodo del ultimo.
    // "actual->siguiente" es primer nodo

    temporal->siguiente = primero; //Tambien se puede escribir de esta manera temporal->siguiente = actual->siguiente;
    ultimo = temporal;
    primero->anterior = ultimo;
    free(actual);
}

// Elimina un nodo con una posicion dada
void eliminarenmedio(int posicion)
{
    if(primero==NULL)
    return;

    if(posicion==1)
    {
        eliminarprimero();
        return;
    }

    struct listaligada *actual = primero;
    struct listaligada *temporal;
    int contador = 0;

    do
    {
        contador++;
        temporal = actual;
        actual = actual->siguiente;
    }while(actual->siguiente != primero && contador<posicion-1);

    if(contador==posicion-1)
    {
        if(actual==ultimo)
        {
            eliminarultimo();
            return;
        }

        temporal->siguiente = actual->siguiente;
        actual->siguiente->anterior = temporal;
        free(actual);
        return;
    }

    printf("la posicion (%d) no existe\n", posicion);
}

// Imprime las 2 maneras en que se pueden colocar los datos de la lista circular
void imprimirlista()
{
    printf("Imprimiendo de primero al ultimo nodo:\n");
    imprimirprincipio();

    printf("\nImprimiendo de ultimo al primer nodo:\n");
    imprimirultimo();
}

// Imprime los datos desde el primer nodo hasta el ultimo
void imprimirprincipio()
{
    if(primero==NULL)
    return;

    struct listaligada *actual = primero;

    do
    {
        printf("%d ", actual->numero);
        actual = actual->siguiente;
    }   while(actual != primero);


}

// Imprime los datos desde el ultimo nodo hasya el primer nodo
void imprimirultimo()
{
    if(primero==NULL)
    return; // Tambien se puede verificar con "ultimo==NULL". Los dos funcionand igual

    struct listaligada *actual = ultimo;

    do
    {
        printf("%d ", actual->numero);
        actual = actual->anterior;
    }   while(actual != ultimo);
    printf("\n");
}

//Determina el numero de nodos que hay en la lista circular.
int cuantoshay()
{
    if(primero==NULL)
    return 0;

    int contador = 0;
    struct listaligada *actual = primero;

    do
    {
        contador++;
        actual = actual->siguiente;
    }   while(actual != primero);
    return contador;
}
