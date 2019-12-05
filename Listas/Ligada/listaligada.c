#include "listaligada.h"

void insertaralprincipio(int x) {
  struct nodo *t;

  t = (struct nodo*)malloc(sizeof(struct nodo));
  t->dato = x;
  conteo++;

  if (primero == NULL) {
    primero = t;
    primero->siguiente = NULL;
    return;
  }

  t->siguiente = primero;
  primero = t;
}

void insertaralfinal(int x) {
  struct nodo *t, *temporal;

  t = (struct nodo*)malloc(sizeof(struct nodo));
  t->dato = x;
  conteo++;

  if (primero == NULL) {
    primero = t;
    primero->siguiente = NULL;
    return;
  }

  temporal = primero;

  while (temporal->siguiente != NULL)
    temporal = temporal->siguiente;

  temporal->siguiente = t;
  t->siguiente   = NULL;
}

void mostrar() {
  struct nodo *t;

  t = primero;

  if (t == NULL) {
    printf("La lista ligada esta vacia.\n");
    return;
  }

  printf("Hay %d elementos en la lista ligada.\n", conteo);

  while (t->siguiente != NULL) {
    printf("%d\n", t->dato);
    t = t->siguiente;
  }
  printf("%d\n", t->dato); // Imprime último nodo
}

void borrardesdeprincipio() {
  struct nodo *t;
  int n;

  if (primero == NULL) {
    printf("La lista ligada esta vacia.\n");
    return;
  }

  n = primero->dato;
  t = primero->siguiente;
  free(primero);
  primero = t;
  conteo--;

  printf("%d eliminado desde el principio con éxito.\n", n);
}

void borrardesdefinal() {
  struct nodo *t, *u;
  int n;

  if (primero == NULL) {
    printf("La lista ligada esta vacia.\n");
    return;
  }

  conteo--;

  if (primero->siguiente == NULL) {
    n = primero->dato;
    free(primero);
    primero = NULL;
    printf("%d eliminado del final con éxito.\n", n);
    return;
  }

  t = primero;

  while (t->siguiente != NULL) {
    u = t;
    t = t->siguiente;
  }

  n = t->dato;
  u->siguiente = NULL;
  free(t);

  printf("%d eliminado del final con éxito.\n", n);
}
