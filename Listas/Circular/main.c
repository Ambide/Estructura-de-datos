#include "circular.h"
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
