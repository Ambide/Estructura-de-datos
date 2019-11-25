#include "stdio.h"
#include "stdlib.h"

struct nodo{
  int dato;
  struct nodo *anterior;
  struct nodo *siguiente;
};

void insertaralprincipio(struct nodo **milista, int num);
void insertaralprincipio(struct nodo **milista, int num);
void mostrar(struct nodo *milista);

int main(void) {

  struct nodo *milista = NULL;

  insertaralprincipio(&milista, 10);
  insertaralprincipio(&milista, 20);
  insertaralprincipio(&milista, 30);
  insertaralprincipio(&milista, 40);
  insertaralprincipio(&milista, 50);
  insertaralprincipio(&milista, 60);

  mostrar(milista);

  return 0;
}

void insertaralprincipio(struct nodo **milista, int num){

  struct nodo *temporal = malloc(sizeof(struct nodo));
  temporal -> dato = num;
  temporal -> anterior = NULL;
  temporal -> siguiente = *milista;

  struct nodo *primero = *milista;

  if(milista == NULL){
    return;
  }

  if(*milista == NULL){
    temporal -> anterior = NULL;
    temporal -> siguiente = NULL;
    *milista = temporal;
  } else {

    while(primero -> anterior != NULL){
      primero = primero -> anterior;
    }

    primero -> anterior = temporal;
    temporal -> siguiente = primero;

  }

}


void mostrar(struct nodo *milista){

  struct nodo *ultimo;

  printf("Recorrido al reves. \n");
  while(ultimo != NULL){
    printf("%d\n", ultimo -> dato);
    ultimo = ultimo -> anterior;
  }

}
