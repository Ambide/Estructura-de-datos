#include "pila.h"
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
