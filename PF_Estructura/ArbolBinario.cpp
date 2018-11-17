#include "ArbolBinario.h"

ArbolBinario::ArbolBinario(){
	raiz=0;
}

ArbolBinario::ArbolBinario(Nodo* r){
	raiz=r;
}

void ArbolBinario::PRaiz(Nodo* r){
	raiz=r;
}

Nodo* ArbolBinario::ORaiz(){
	return raiz;
}

Nodo ArbolBinario::raizArbol(){
	if(raiz)
		return *raiz;
	else{
		throw "Arbol vacio ";
		//return 0;
	}
}

bool ArbolBinario::esVacio(){
	return raiz==0;
}

Nodo* ArbolBinario::hijoIzdo(){
	if(raiz)
		return raiz->subArbolIzdo();
	else{
		throw "Arbol vacio";
		return 0;
	}
}

Nodo* ArbolBinario::hijoDcho(){
	if(raiz)
		return raiz->subArbolDcho();
	else{
		throw "Arbol vacio";
		return 0;
	}
}

Nodo* ArbolBinario::nuevoArbol(Nodo* ramaIzda, int dato, string name, float Calif, Nodo* ramaDrcha){
	return new Nodo(ramaIzda, dato, name, Calif, ramaDrcha);
}

void ArbolBinario::preorden(){
	preorden(raiz);
}

void ArbolBinario::inorden(){
	inorden(raiz);
}
void ArbolBinario::postorden(){
	postorden(raiz);
}

void ArbolBinario::amplitud(){
	amplitud(raiz);
}

void ArbolBinario::preorden(Nodo *r){
	if(r!=0){
		r->visitar();
		preorden(r->subArbolIzdo());
		preorden(r->subArbolDcho());
	}
}

void ArbolBinario::inorden(Nodo *r){
	if(r!=0){
		inorden(r->subArbolIzdo());
		r->visitar();
		inorden(r->subArbolDcho());
	}
}

void ArbolBinario::postorden(Nodo *r){
	if(r!=0){
		postorden(r->subArbolIzdo());
		postorden(r->subArbolDcho());
		r->visitar();
	}
}

void ArbolBinario::amplitud(Nodo *r){
	
	Cola q;
	Nodo *aux;
	
	if (r != NULL) {
    	//CrearCola(cola);
    	q.crearCola();
		//encolar(cola, a);
    	q.insertar(r);
		while (!q.estaVacia()) {
      		//desencolar(cola, aux);
      		aux=q.Remover();
			//visitar(aux);
      		aux->visitar();
			if (aux->subArbolIzdo() != 0) 
				//encolar(cola, aux->izq);
				q.insertar(aux->subArbolIzdo());
      		if (aux->subArbolDcho() != 0)
				//encolar(cola, aux->der);
				q.insertar(aux->subArbolDcho());
    	}
  	}
}



Nodo* ArbolBinario::buscar(int buscado){
	return buscar(raiz, buscado);
}

Nodo* ArbolBinario::buscar(Nodo* raizSub, int buscado){
	if (raizSub == NULL)
        return NULL;
    else if (buscado == raizSub->valorNodo())
        return raizSub;
    else if (buscado < raizSub->valorNodo())
        return buscar(raizSub->subArbolIzdo(), buscado);
    else
        return buscar (raizSub->subArbolDcho(), buscado);
}

void ArbolBinario::vaciar(){
	vaciar(raiz);
}

void ArbolBinario::vaciar(Nodo *r){
	
	if(r != 0){
		vaciar(r->subArbolIzdo());
		vaciar(r->subArbolDcho());
		
		r->ramaIzdo(0);
		r->ramaDcho(0);
		
		delete r;
		r=0;
	}
}

void ArbolBinario::insertar(int valor, string name, float Calif){
	raiz = insertar(raiz, valor, name, Calif);
}

Nodo* ArbolBinario::insertar(Nodo* raizSub, int dato, string nombre, float Calif){
	if (raizSub == NULL)
            raizSub = new Nodo(dato, nombre, Calif);
    else if (dato < raizSub->valorNodo()) {
        Nodo *iz; iz = insertar(raizSub->subArbolIzdo(), dato, nombre, Calif);
        raizSub->ramaIzdo(iz);
    }
    else if (dato > raizSub->valorNodo()) {
    	Nodo *dr; dr = insertar(raizSub->subArbolDcho(), dato, nombre, Calif);
        raizSub->ramaDcho(dr);
    }
    else
        throw "Nodo duplicado";
    
	return raizSub;
}

Nodo* ArbolBinario::reemplazar(Nodo* act){
	Nodo *a, *p = act;
        
    a = act->subArbolIzdo(); // rama de nodos menores
        
    while (a->subArbolDcho() != NULL) {
      p = a;
      a = a->subArbolDcho();
    } // copia en act el valor del nodo apuntado por a
        
    act->nuevoValor(a->valorNodo(), a->valorNombre(), a->valorCalificaciones()); ////////////////////////mandar las calificaciones
        
    if (p == act) // a es el hijo izquierdo de act
      p->ramaIzdo(a->subArbolIzdo()); // enlaza subArbol izq. Fig. 16.32b
    else
      p->ramaDcho(a->subArbolIzdo()); // se enlaza subArbol der. Fig. 16.32a
        
    return a; 

}


void ArbolBinario::eliminar(int dato){
	raiz = eliminar(raiz, dato);
}

Nodo* ArbolBinario::eliminar(Nodo* raizSub, int dato){
	if (raizSub == NULL)
        throw "No se ha encontrado el nodo con la clave";
    else if (dato < raizSub->valorNodo())    {
        Nodo* iz;
        iz = eliminar(raizSub->subArbolIzdo(), dato);
        raizSub->ramaIzdo(iz);
    }
    else if (dato > raizSub->valorNodo())   {
        Nodo *dr;
        dr = eliminar(raizSub->subArbolDcho(), dato);
        raizSub->ramaDcho(dr);
    }
    else {    // Nodo encontrado
        Nodo *q;
        q = raizSub;     // nodo a quitar del árbol
        if (q->subArbolIzdo() == NULL)
            raizSub = q->subArbolDcho(); 
        else if (q->subArbolDcho() == NULL)
            raizSub = q->subArbolIzdo();
        else   {     // tiene rama izquierda y derecha
            q = reemplazar(q);
        }
        q = NULL;
    }
    return raizSub;
}




/*
	void busquedaAplitud(Nodo* r){
    	cola q;
    	inicializaCola(q);
     	cout <<"\t";

	    if(r!=0){
         
		 encola(q, r);

         while(q.delante!=NULL){
            	
				arbol = desencola(q);
            	cout << arbol->nro << ' ';

            	if(arbol->izq!=NULL)
                	encola(q, arbol->izq);
             	if(arbol->der!=NULL)
                	encola(q, arbol->der);
         	}
     	}
	}


*/

