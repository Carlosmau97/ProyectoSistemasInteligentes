#include "Lista.h"

Lista::Lista(){
	primero=0;
	ultimo=0;
}

void Lista::insertarCabezaLista(float entrada){
	Nodo_Lista* nuevo;
	nuevo = new Nodo_Lista(entrada);
	nuevo -> ponerEnlace(primero);
	primero = nuevo;
	if(ultimo==0)
		ultimo=nuevo;
}

void Lista::mostrar(){
	Nodo_Lista* aux;
	
	aux=primero;
	while(aux != 0){
		cout<< aux->datoNodo()<< ", ";
		aux = aux->enlaceNodo();
	}
	cout << endl;
}

Nodo_Lista* Lista::buscarLista(float destino){
	Nodo_Lista* aux;
	
	aux=primero;
	while(aux != 0){
		if(aux->datoNodo()==destino)
		return aux;
		aux=aux->enlaceNodo();
	}
	
	return 0;
}

void Lista::insertarUltimo(float entrada){
	Nodo_Lista* p=primero;
	if(p == 0){
		insertarCabezaLista(entrada);
		return;
	}
	
	Nodo_Lista* nuevo = new Nodo_Lista(entrada);
	ultimo->ponerEnlace(nuevo);
	ultimo=nuevo;
}

void Lista::insertarLista(Nodo_Lista* anterior, float entrada){
	
	Nodo_Lista* nuevo;
	nuevo=new Nodo_Lista(entrada);
	nuevo->ponerEnlace(anterior->enlaceNodo());
	if(anterior->enlaceNodo()==0)
		ultimo=nuevo;
	anterior->ponerEnlace(nuevo);
}

