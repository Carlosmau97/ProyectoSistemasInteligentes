#ifndef COLA_H
#define COLA_H
#include<iostream>
#include "Nodo.h" 
using namespace std;

typedef Nodo* TIPO_DE_DATO;
const int MAXTAMQ = 20;

class Cola {
	private:
		int frente;
		int final;
		int numElementos;
		TIPO_DE_DATO Arreglo[MAXTAMQ];
		//Nodo* ab;
		
	public:
		void crearCola();
		int siguiente(int r);
		bool estaVacia();
		bool estaLlena();
		bool insertar(TIPO_DE_DATO x);
		int totalElementos();
		void imprimir();
		TIPO_DE_DATO Remover();
		TIPO_DE_DATO Frente();
};

#endif

