#ifndef NODO_H
#define NODO_H

//typedef int TipoElemento;

//#include "Nodo_Lista.h"
#include "Lista.h"


class Nodo{
	private:
		int dato;
		string nombre;
		Lista calificaciones;
		
		Nodo* izdo;
		Nodo* dcho;
	public:
		Nodo(int valor, string name, float Calif);
		Nodo(Nodo* ramaIzdo, int valor, string name, float Calif, Nodo* ramaDcho);
		int valorNodo();
		string valorNombre();
		void nuevoValor(int d, string name, Lista calif);
		Nodo* subArbolIzdo();
		Nodo* subArbolDcho();
		void ramaIzdo(Nodo* n);
		void ramaDcho(Nodo* n);
		void agregaCalificacion(float Calif);
		Lista valorCalificaciones();
		
		void visitar();
};

#endif
