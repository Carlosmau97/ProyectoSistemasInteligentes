#ifndef NODO_LISTA_H
#define NODO_LISTA_H

typedef float Dato;

class Nodo_Lista {
	private:
		float dato;
		Nodo_Lista* enlace;
	public:
		Nodo_Lista(float t);
		Nodo_Lista(float p, Nodo_Lista* n);
		float datoNodo();
		Nodo_Lista* enlaceNodo();
		void ponerEnlace(Nodo_Lista* sgte);
};

#endif


