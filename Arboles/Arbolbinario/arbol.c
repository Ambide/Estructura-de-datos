#include "stdio.h"
#include "stdlib.h"

struct nodo{
  int dato;
  struct nodo *izquierdo;
  struct nodo *derecho;
};

void insertar(struct nodo **miarbol, int num);

int main(int argc, char const *argv[]) {

  struct nodo *miarbol = NULL;
  miarbol = malloc(sizeof(struct nodo));

  insertar(&miarbol);
  return 0;
}

void insertar(struct nodo **miarbol, int num){

  if(*miarbol == NULL){

    *miarbol = malloc(sizeof(struct nodo));
    return;

  } else {

    struct nodo *temporal = malloc(sizeof(struct nodo));
    temporal -> dato = num;
    temporal -> izquierdo = NULL;
    temporal -> derecho = NULL;

    struct nodo *ultimo = *miarbol;
    if(miarbol -> )


  }
}



/*

  recibe los datos de un cliente (nombre, edad, si cuenta con tarjeta de descuentos y los items comprados).
  Devuelve un ticket que muestra el código y precio de cada elemento, el total de la compra, la fecha y hora de la compra.
  Lee códigos de elementos de un archivo de texto o los recibe

*/
