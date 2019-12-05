#include "doble.h"

int main()
{
    int n, ch;
    do
    {
        printf("\n\nFunciones de la lista ligada doble");
        printf("\n1. Agregar al final \n2. Agregar al principio \n3. Eliminar\n4. Mostrar\n0. Salir\n");
        printf("\nEscoger opcion : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\nIngrese valor: ");
                scanf("%d", &n);
                agregarfinal(n);
                break;
            case 2:
                printf("\nIngrese valor: ");
                scanf("%d", &n);
                agregarprincipio(n);
                break;
            case 3:
            	printf("\nIngrese valor a eliminar: ");
                scanf("%d", &n);
                eliminar(n);
                break;
            case 4:
                mostrar();
                break;
        }
    }while (ch != 0);
}
