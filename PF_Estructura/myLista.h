#ifndef MYLISTA_H
#define MYLISTA_H

#include "Nodo_Lista.h"

#include<iostream>
using namespace std;


class myLista
{
	private:
		Nodo_Lista* p;
		Nodo_Lista* primero;
		Nodo_Lista* ultimo;
		
	public:
		myLista();
		void insertarCabezaLista(float entrada);  //ROGER: Cambie de tipo float a float porque vas a guardar calificaciones con punto decimal.
		void insertarUltimo(float entrada); 															
		void insertarLista(Nodo_Lista* anterior, float entrada);
		Nodo_Lista* buscarLista(float destino);
		Nodo_Lista* buscarPosicion(int posicion);
		void eliminar(float entrada);
		void mostrar();
		
};

#endif
