#include "Nodo_Lista.h"

Nodo_Lista::Nodo_Lista(float t){
	dato = t;
	enlace = 0; 
}

Nodo_Lista::Nodo_Lista(float p, Nodo_Lista* n){
	dato = p;
	enlace = n;	
}

float Nodo_Lista::datoNodo(){
	return dato;
}

Nodo_Lista* Nodo_Lista::enlaceNodo(){
	return enlace;
}

void Nodo_Lista::ponerEnlace(Nodo_Lista* sgte){
	enlace = sgte;
}

