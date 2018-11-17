#ifndef LISTA_H
#define LISTA_H

#include<iostream>
using namespace std;


#include "Nodo_Lista.h"
class Lista
{
	
	
	private:
		Nodo_Lista* p;
		Nodo_Lista* primero;
		Nodo_Lista* ultimo;
		
	public:
		Lista();
		void insertarCabezaLista(float entrada);  //ROGER: Cambie de tipo float a float porque vas a guardar calificaciones con punto decimal.
		void insertarUltimo(float entrada); 															
		void insertarLista(Nodo_Lista* anterior, float entrada);
		Nodo_Lista* buscarLista(float destino);
		Nodo_Lista* buscarPosicion(int posicion);
		void eliminar(float entrada);
		void mostrar();
		
		
};

#endif
