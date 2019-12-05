#include <stdio.h>
#include <stdlib.h>

#define size 5

void push(int pila[], int numero, int *tope);
int pop(int pila[], int *tope);
void mostrar(int pila[], int *tope);

int main()
{
    int pila[size], tope =  - 1, dato;
    int opcion;
    do
    {
      printf("Funciones de la pila.\n");
      printf("1. Insertar en la pila (Push).\n");
      printf("2. Sacar de la pila (Pop).\n");
      printf("3. Imprimir el elemento tope de la pila.\n");
      printf("0. Salir.\n");
      printf("Escoge una opcion.\n");
      scanf("%d",&opcion);
      switch (opcion)
        {
            case 1:
                printf("\nIngrese un numero : ");
                scanf("%d", &dato);
                push(pila, dato, &tope);
                break;
            case 2:
                dato = pop(pila, &tope);
                if (dato !=  - 1)
                    printf("\n%d eliminado\n", dato);
                else
                    printf("\nLa pila esta vacia");
                break;
            case 3:
                mostrar(pila, &tope);
                break;
        }
    }
    while (opcion != 0 );

    return 0;
}
void push(int pila[], int numero, int *tope)
{
    if (*tope == size - 1)
    {
        printf("La pila esta llena");
    }
    else
    {
        (*tope)++;
        pila[ *tope] = numero;
    }
}

int pop(int pila[], int *tope)
{
    int valor;
    if (*tope ==  - 1)
    {
        return  - 1;
    }
    else
    {
        valor = pila[ *tope];
        (*tope)--;
        return valor;
    }

}

void mostrar(int pila[], int *tope)
{
    int i;
    for (i =  *tope; i >= 0; i--)
    {
        printf("\n%d", pila[i]);
    }
}
