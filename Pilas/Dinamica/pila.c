#include "pila.h"

void push(int valor) {
  pila[tope] = valor;
  tope++;
}

int pop() {
  tope--;
  return pila[tope];
}

void mostrar() {
  int d;

  if (tope == 0) {
    printf("La pila esta vacia.\n\n");
    return;
  }

  printf("Hay %d elementos en la pila.\n", tope);

  for (d = tope - 1; d >= 0; d--)
    printf("%d\n", pila[d]);
  printf("\n");
}

int estavacia() {
  if (tope == 0)
    return 1;
  else
    return 0;
}

int elementotope() {
  return pila[tope-1];
}
