
#include "Nodo.h"


Nodo::Nodo(int valor, string name, float Calif){
	dato=valor;
	nombre = name;
	this->calificaciones.insertarUltimo(Calif);
	izdo=dcho=0;
}

Nodo::Nodo(Nodo* ramaIzdo, int valor, string name, float Calif, Nodo* ramaDcho){
	dato = valor;
	nombre = name;
	izdo = ramaIzdo;
	dcho = ramaDcho;
	calificaciones.insertarUltimo(Calif);
}

int Nodo::valorNodo(){
	return dato;
}

string Nodo::valorNombre(){
	return nombre;
}

Lista Nodo::valorCalificaciones(){
	return calificaciones;
}

Nodo* Nodo::subArbolIzdo(){
	return izdo;
}

Nodo* Nodo::subArbolDcho(){
	return dcho;
}

void Nodo::agregaCalificacion(float Calif){
	this->calificaciones.insertarUltimo(Calif);
}

void Nodo::ramaIzdo(Nodo* n){
	izdo=n;
}

void Nodo::ramaDcho(Nodo* n){
	dcho=n;
}

void Nodo::visitar(){
	cout<<dato<<" "<<nombre<< " ";
	
	calificaciones.mostrar() ;
	
	cout<<endl << endl;
}

void Nodo::nuevoValor(int d, string name, Lista calif){
	dato=d;
	nombre = name;
	calificaciones = calif;
}
