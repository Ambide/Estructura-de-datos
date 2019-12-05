#include <stdio.h>
#include <stdlib.h>
struct nodo{
  int dato;
  struct nodo *siguiente;
};

struct nodo *primero = NULL;
void insertaralprincipio(int);
void insertaralfinal(int);
void mostrar();
void borrardesdeprincipio();
void borrardesdefinal();
int conteo = 0;

void insertaralprincipio(int x) {
  struct nodo *t;int main () {
  int i, dato;
  for (;;) {
    printf("1. Insertar un elemento al comienzo de la lista ligada.\n");
    printf("2. Inserte un elemento al final de la lista ligada.\n");
    printf("3. mostrar lista ligada.\n");
    printf("4. Eliminar un elemento desde el principio.\n");
    printf("5. Eliminar un elemento del final.\n");
    printf("6. Salir\n");
    scanf("%d", &i);

    if (i == 1) {
      printf("Ingrese el valor del elemento\n");
      scanf("%d", &dato);
      insertaralprincipio(dato);
    }
    else if (i == 2) {
      printf("Ingrese el valor del elemento\n");
      scanf("%d", &dato);
      insertaralfinal(dato);
    }
    else if (i == 3)
      mostrar();
    else if (i == 4)
      borrardesdeprincipio();
    else if (i == 5)
      borrardesdefinal();
    else if (i == 6)
      break;
    else
      printf("Por favor, introduzca una opcion valida.\n");
  }
  return 0;
}

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

int main () {
  int i, dato;
  while (1) {
    printf("1. Insertar un elemento al comienzo de la lista ligada.\n");
    printf("2. Inserte un elemento al final de la lista ligada.\n");
    printf("3. Mostrar lista ligada.\n");
    printf("4. Eliminar un elemento desde el principio.\n");
    printf("5. Eliminar un elemento del final.\n");
    printf("6. Salir\n");
    scanf("%d", &i);

    if (i == 1) {
      printf("Ingrese el valor del elemento\n");
      scanf("%d", &dato);
      insertaralprincipio(dato);
    }
    else if (i == 2) {
      printf("Ingrese el valor del elemento\n");
      scanf("%d", &dato);
      insertaralfinal(dato);
    }
    else if (i == 3)
      mostrar();
    else if (i == 4)
      borrardesdeprincipio();
    else if (i == 5)
      borrardesdefinal();
    else if (i == 6)
      break;
    else
      printf("Por favor, introduzca una opcion valida.\n");
  }
  return 0;
}
