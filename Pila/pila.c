#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "errno.h"

struct nodo{
  int dato;
  struct nodo *siguiente;
};


void push(struct nodo **mipila, int num);
int pop(struct nodo **mipila);
int top(struct nodo *mipila);
void mostrarpila(struct nodo **mipila);

int main(void) {

  struct nodo *mipila = NULL;

  push(&mipila, 10);
  push(&mipila, 20);
  push(&mipila, 30);
  push(&mipila, 40);
  push(&mipila, 50);

  printf("El elemento eliminado es: %d\n", pop(&mipila));
  printf("El elemento eliminado es: %d\n", pop(&mipila));
  printf("El elemento eliminado es: %d\n", pop(&mipila));
  printf("El elemento eliminado es: %d\n", pop(&mipila));


  printf("El elemento a la cima de la pila es: %d\n", top(mipila));

  mostrarpila(&mipila);

  return 0;
}

void push(struct nodo **mipila, int num){

  struct nodo *temporal = malloc(sizeof(struct nodo));
  temporal -> dato = num;
  temporal -> siguiente = *mipila;

  if(mipila == NULL){
    return;
  }

  if(*mipila == NULL){
    *mipila = temporal;
    return;
  } else {

    *mipila = temporal;

  }

}

int pop(struct nodo **mipila){

  if(*mipila == NULL){
    exit(1);
  }

  int valor = (**mipila).dato;

  struct nodo *temporal = *mipila;

  *mipila = temporal -> siguiente;

  free(temporal);


  return valor;
}

int top(struct nodo *mipila){

  if(mipila == NULL){
    exit(1);
  }

  int valor = (*mipila).dato;
  return valor;
}

void mostrarpila(struct nodo **mipila){
  while(mipila != NULL){
    printf("%d\n", pop(mipila) );
  }
}
