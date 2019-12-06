#include "cola.h"
int frente =  - 1;
int siguiente =  - 1;
void agregar(int cola[], int item)
{
    if ((frente == 0 && siguiente == tamanio - 1) || (frente == siguiente + 1))
    {
        printf("La cola esta llena");
        return;
    }
    else if (siguiente ==  - 1)
    {
        siguiente++;
        frente++;
    }
    else if (siguiente == tamanio - 1 && frente > 0)
    {
        siguiente = 0;
    }
    else
    {
        siguiente++;
    }
    cola[siguiente] = item;
}

void mostrar(int cola[])
{
    int i;
    printf("\n");
    if (frente > siguiente)
    {
        for (i = frente; i < tamanio; i++)
        {
            printf("%d ", cola[i]);
        }
        for (i = 0; i <= siguiente; i++)
            printf("%d ", cola[i]);
    }
    else
    {
        for (i = frente; i <= siguiente; i++)
            printf("%d ", cola[i]);
    }
}

void quitar(int cola[])
{
    if (frente ==  - 1)
    {
        printf("La cola esta vacia ");
    }
    else if (frente == siguiente)
    {
        printf("\n %d borrado", cola[frente]);
        frente =  - 1;
        siguiente =  - 1;
    }
    else
    {
        printf("\n %d borrado", cola[frente]);
        frente++;
    }
}
