#include "pila.h"
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
