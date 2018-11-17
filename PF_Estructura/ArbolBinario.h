#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "Nodo.h"
#include "Cola.h"



class ArbolBinario{
	private:
		Nodo* raiz;
		void vaciar(Nodo *r);
		
		void preorden(Nodo *r);
		void inorden(Nodo *r);
		void postorden(Nodo *r);
		void amplitud(Nodo *r);
		
		Nodo* buscar(Nodo* raizSub, int buscado);
		
		Nodo* insertar(Nodo* raizSub, int dato, string nombre, float Calif);
		Nodo* eliminar(Nodo* raizSub, int dato);
		Nodo* reemplazar(Nodo* act);
		
	public:
		ArbolBinario();
		ArbolBinario(Nodo* r);
		void PRaiz( Nodo *r);
		Nodo* ORaiz();
		Nodo raizArbol();
		bool esVacio();
		Nodo* hijoIzdo();
		Nodo* hijoDcho();
		Nodo* nuevoArbol(Nodo* ramaIzda, int dato, string name, float Calif, Nodo* Drcha);
		
		void preorden();
		void inorden();
		void postorden();
		void amplitud();
		
		void vaciar();
		
		Nodo* buscar(int buscado);
		void insertar(int valor, string name, float Calif);
		void eliminar(int dato);
		
		
};

#endif
