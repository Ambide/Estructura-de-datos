#include <stdio.h>
#include <stdlib.h>
struct nodo{
	int dato;
	struct nodo* siguiente;
};

struct nodo* primero = NULL;
struct nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarLista();
int main(){
int opcionMenu = 0;
	do{
		printf("\nEstructura Lista");
		printf("\n1-insertar\n");
		printf("\n2-Buscar\n");
		printf("\n3-Modificar\n");
		printf("\n4-Eliminar\n");
		printf("\n5-Imprimir\n");
		printf("\n6-Salir");
		printf("\nEscoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				insertarNodo();
				break;
			case 2:
				buscarNodo();
				break;
			case 3:
				modificarNodo();
				break;
			case 4:
				eliminarNodo();
				break;
			case 5:
				desplegarLista();
				break;
			case 6:
			printf("\n\n Terminado.\n");
				break;
			default:
				printf("\n\n Opcion no Valida \n\n");
		}
	}while(opcionMenu != 6);
	return 0;
}

// primero = 7     ultimo = 9     actual = 2  anterior = 3   nodoBuscado = 2   encontrado = 0

/// Lista   7 -> 3 -> 2 -> 9 -> NULL

// 7, 5, 2, 9

void insertarNodo(){
	struct nodo* nuevo = (struct nodo*) malloc(sizeof(struct nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con Exito\n\n");
}

void buscarNodo(){
	struct nodo* actual = (struct nodo*) malloc(sizeof(struct nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
				
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void modificarNodo(){
	struct nodo* actual = (struct nodo*) malloc(sizeof(struct nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d", &actual->dato);
				printf("\n Nodo modificado con exito\n\n");
				encontrado = 1;
			}
				
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void eliminarNodo(){
	struct nodo* actual = (struct nodo*) malloc(sizeof(struct nodo));
	actual = primero;
	struct nodo* anterior = (struct nodo*) malloc(sizeof(struct nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
	
				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}
				
				printf("\n Nodo eliminado con exito");
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void desplegarLista(){
	struct nodo* actual = (struct nodo*) malloc(sizeof(struct nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}
