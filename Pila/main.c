#include "pila.h"
	int main()
	{
	  int elemento, opcion;

	  while(1)
	  {
	    printf("Funciones de la pila.\n");
	    printf("1. Insertar en la pila (Push).\n");
	    printf("2. Sacar de la pila (Pop).\n");
	    printf("3. Imprimir el elemento tope de la pila.\n");
	    printf("4. Verificar si la pila esta vacia.\n");
	    printf("5. Mostrar pila.\n");
	    printf("6. Salir.\n");
	    printf("Escoge una opcion.\n");
	    scanf("%d",&opcion);

	    switch (opcion)
	    {
	      case 1:
	        if (tope == 5)
	          printf("Error: Desbordamiento\n\n");
	        else {
	          printf("Ingrese el valor a insertar.\n");
	          scanf("%d", &elemento);
	          push(elemento);
	        }
	        break;

	      case 2:
	        if (tope == 0)
	          printf("Error: Desbordamiento.\n\n");
	        else {
	          elemento = pop();
	          printf("el elemento sacado de la pila es %d.\n", elemento);
	        }
	        break;

	      case 3:
	        if (!estavacia()) {
	          elemento = elementotope();
	          printf("el elemento tope de la pila es %d\n\n", elemento);
	        }
	        else
	          printf("La pila esta vacia.\n\n");
	        break;

	      case 4:
	        if (estavacia())
	          printf("La pila esta vacia.\n\n");
	        else
	          printf("La pila contiene uno o mas elementos.\n\n");
	        break;

	      case 5:
	        mostrar();
	        break;

	      case 6:
	        exit(0);
	    }
	  }
	}
