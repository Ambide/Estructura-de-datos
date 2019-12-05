#include "simple.h"

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
