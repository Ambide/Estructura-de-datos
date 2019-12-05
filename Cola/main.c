#include "cola.h"

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
