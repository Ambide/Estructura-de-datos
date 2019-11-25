#include "listacontigua.h"

int main(void) {
  
  struct nodo *lista = NULL;

  insertar (&lista, 1);
  insertar (&lista, 2);
  insertar (&lista, 3);
  insertar (&lista, 4);
  insertar (&lista, 5);

  mostrar (lista);

  eliminar (&lista, 4);
  eliminar (&lista, 5);

  mostrar (lista);

  return 0;
}
