#include "stdio.h"
#include "stdlib.h"

struct nodo{
  int dato;
  struct nodo *siguiente;
};

void insertar_al_principio(struct nodo **milista, int num);
void mostrar(struct nodo *milista);


int main(int argc, char const *argv[]) {

  struct nodo *milista;

  insertar_al_principio(&milista, 10);
  insertar_al_principio(&milista, 20);
  insertar_al_principio(&milista, 30);
  insertar_al_principio(&milista, 40);
  insertar_al_principio(&milista, 50);

  mostrar(milista);

  return 0;
}

void insertar_al_principio(struct nodo **milista, int num){

  struct nodo *nodotemporal = malloc(sizeof(struct nodo));
  struct nodo *ultimo = *milista;

  nodotemporal -> dato = num;
  nodotemporal -> siguiente = NULL;

  if(milista == NULL){
    return;
  }

	// Sí la lista no cuenta con ningún nodo, se creará el primero.
  if (*milista == NULL) {
    *milista = nodotemporal;
	return;
} else {

  // Recorre toda la lista y liga el nodotemporal al final de la lista.
  while (ultimo -> siguiente != NULL){
    ultimo = ultimo -> siguiente; // el bueno
  }

  ultimo -> siguiente = nodotemporal;
}

}

void mostrar(struct nodo *milista){

  while (milista != NULL) {
    printf("%d\n", milista -> dato);
    milista = milista -> siguiente;
  }

}
