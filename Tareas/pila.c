#include <stdio.h>
#include <stdlib.h>

struct nodo{
  int dato;
  struct nodo *siguiente;
};


void push(struct nodo **mipila, int num);
int pop(struct nodo **mipila);
int top(struct nodo **mipila);

int main(int argc, char const *argv[]) {

  struct nodo *mipila = NULL;

  push(&mipila, 10);
  push(&mipila, 20);
  push(&mipila, 30);
  push(&mipila, 40);
  push(&mipila, 50);

  printf("El elemento eliminado es: %d\n", pop(&mipila));
  printf("El elemento a la cima de la pila es: %d\n", top(&mipila));

  return 0;
}

void push(struct nodo **mipila, int num){

  if(mipila == NULL){
    return;
  }

  if(*mipila == NULL){ //si la mipila no cuenta con ningún nodo, se creará el primero.
    *mipila = malloc(sizeof(struct nodo));
    return;
  } else {

    struct nodo *temporal = malloc(sizeof(struct nodo));
    temporal -> dato = num;
    temporal -> siguiente = *mipila;
    *mipila = temporal;

  }

}

int pop(struct nodo **mipila){

  if(*mipila == NULL){
    return 0;
  }

  int valor = (**mipila).dato;

  struct nodo *temporal = *mipila;

  *mipila = temporal -> siguiente;

  free(temporal);


  return valor;
}

int top(struct nodo **mipila){
  int valor = (**mipila).dato;
  return valor;
}
