#include "cola.h"
int main()
{
    int n, opcion;
    int cola[tamanio];
    do
    {
        printf("\n\n Cola circular estatica:\n1. Agregar a cola \n2. Quitar de cola\n3. Mostrar\n0. Salir");
        printf("\nEscoger opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("\nIngrese un numero: ");
                scanf("%d", &n);
                agregar(cola, n);
                break;
            case 2:
                quitar(cola);
                break;
            case 3:
                mostrar(cola);
                break;
        }
    }while (opcion != 0);
}
