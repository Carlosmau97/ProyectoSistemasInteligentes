#include "Cola.h"

void Cola::crearCola(){
	frente=0;
	final=MAXTAMQ-1;
	numElementos = 0;	
}

int Cola::siguiente(int r){
	return (r+1) % MAXTAMQ;
}

bool Cola::estaVacia(){
	return frente == siguiente(final);
}

bool Cola::estaLlena(){
	return frente == siguiente(siguiente(final));
}

bool Cola::insertar(TIPO_DE_DATO x){
	if(!estaLlena()){
		final = siguiente(final);
		Arreglo[final] = x;
		numElementos++;
		return true;
	}
	return false;
}

int Cola::totalElementos(){
	return numElementos;
}

void Cola::imprimir(){
	if(estaVacia())
		return;
	
	int f;
	
	cout<<"[";
	
	for(f = frente; f != final; f=siguiente(f)){
		cout<<Arreglo[f]<<", ";
	}
	cout<<Arreglo[f]<<"]: Total de elementos: " <<totalElementos() << "\n";
	cout<<"Frente: " << frente << "\t";
	cout<<"Final: "<<final << "\n\n";
	
}

TIPO_DE_DATO Cola::Remover(){
	if(estaVacia())
		return 0;
		
	TIPO_DE_DATO tm = Arreglo[frente];
	frente = siguiente(frente);
	numElementos--;
	return tm;
}

TIPO_DE_DATO Cola::Frente(){
	if(estaVacia())
		return 0;
	
	return Arreglo[frente];
}
