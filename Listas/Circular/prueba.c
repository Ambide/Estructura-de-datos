#include <stdio.h>
#include <stdlib.h>

struct listaligada{
    int numero;
    struct listaligada *siguiente;
    struct listaligada *anterior;
};

struct listaligada *primero = NULL;
struct listaligada *ultimo=NULL;

void insertarprimero(int numero);
void insertaralultimo(int numero);
void insertarenmedio(int numero, int posicion);
void eliminarprimero();
void eliminarultimo();
void eliminarenmedio(int posicion);
void imprimirprincipio();
void imprimirultimo();
void imprimirlista();
int cuantoshay();

int main()
{
    int n, opcion,pos;
    do
    {
        printf("\n\nFunciones de la lista circular");
        printf("\n1. Agregar al principio \n");
        printf("2. Agregar al ultimo\n");
        printf("3. Agregar a una posicion\n");
        printf("4. Eliminar primero\n");
        printf("5. Eliminar ultimo\n");
        printf("6. Eliminar con una posicion\n");
        printf("7. Imprimir desde el principio\n");
        printf("8. Imprimir desde el ultimo\n");
        printf("9. Imprimir lista\n");
        printf("10. Contar\n");
        printf("0. Salir\n");
        printf("\nEscoger opcion : ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("Ingrese el valor a insertar:\n");
                scanf("%d",&n);
                insertarprimero(n);
                break;
            case 2:
                printf("Ingrese el valor a insertar:\n");
                scanf("%d",&n);
                insertaralultimo(n);
                break;
            case 3:
              printf("Ingrese el valor a insertar:\n");
              scanf("%d",&n);
              printf("Ingrese la posicion:\n");
              scanf("%d",&pos);
              insertarenmedio(n,pos);
                break;
            case 4:
                printf("Eliminando primer elemento de la lista\n");
                eliminarprimero();
                break;
            case 5:
                printf("Eliminando ultimo elemento de la lista\n");
                eliminarultimo();
                break;
            case 6:
                printf("Dame la posicion que deseas eliminar\n");
                scanf("%d\n",&pos);
                eliminarenmedio(pos);
                break;
            case 7:
                printf("Imprimiendo desde el principio\n");
                imprimirprincipio();
                break;
            case 8:
                printf("Imprimiendo desde el ultimo\n");
                imprimirultimo();
                break;
            case 9:
                printf("Imprimiendo lista\n");
                imprimirlista();
                break;
            case 10:
                printf("Contando lista.\n");
                printf("\nHay %d elemento(s) en la lista doble\n", cuantoshay());
                break;
        }
    }while (opcion != 0);
    return 0;
}

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

    printf("\Imprimiendo de ultimo al primer nodo:\n");
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
