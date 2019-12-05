#include "listaligada.h"

int main () {
  int i, dato;
  while (1) {
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
