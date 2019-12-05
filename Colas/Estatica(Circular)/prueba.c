/*Cola circular estatica*/
#include <stdio.h>
#define tamanio 5

void agregar(int[], int);
void quitar(int[]);
void mostrar(int[]);

int frente =  - 1;
int siguiente =  - 1;

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
