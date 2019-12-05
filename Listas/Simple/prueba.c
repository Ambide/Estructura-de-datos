#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *siguiente;
};

struct nodo *primero = NULL;

void agregaralfinal(int);
void mostrar();
void agregaralprincipio(int);
void sum();
int buscar(int);
void eliminar(int);
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
int main()
{
    int n, opcion;
    do
    {
        printf("\nFunciones de lista ligada");
        printf("\n1. Agregar al final\n2. Agregar al principio\n3. Mostrar\n4. Sumar la lista\n5. Buscar \n6. Eliminar \n0. Salir");
        printf("\nEscoger opcion : ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("\nIngrese un numero ");
                scanf("%d", &n);
                agregaralfinal(n);
                break;
            case 2:
                printf("\nIngrese un numero ");
                scanf("%d", &n);
                agregaralprincipio(n);
                break;
            case 3:
                mostrar();
                break;
            case 4:
                sum();
                break;
            case 5:
                {
                    int x, posicion;
                    printf("\nIngrese el numero que desea buscar ");
                    scanf("%d", &x);
                    posicion = buscar(x);
                    if (posicion ==  - 1)
                    {
                        printf("\nValor no encontrado");
                    }
                    else
                    {
                        printf("Valor encontrado en la posicion %d", posicion);
                    }
                    break;
                }
            case 6:
                {
                    int x;
                    printf("\nIngrese el numero que desea eliminar ");
                    scanf("%d", &x);
                    eliminar(x);
                }
        }
    }while (opcion != 0);
}
