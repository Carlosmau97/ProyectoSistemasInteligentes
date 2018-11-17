#include <iostream>
#include"ArbolBinario.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	ArbolBinario Estudiante;
	
	char opc;
	int mat;
	string nom;
	float cal;
	
	do{
		cout<<"Opciones: \n";
		cout<<" 1.- Agregar un nuevo estudiante \n"
			<<" 2.- Agregar una calificaci"<<char(162)<<"n a un estudiante \n"
			<<" 3.- Eliminar el registro de un estudiante \n"
			<<" 4.- Buscar la direccion de memoria de un estudiante \n"
			<<" 5.- Recorrido INORDEN \n"
			<<" 6.- Recorrido ENORDDEN \n"
			<<" 7.- Recorrido POSTORDEN \n"
			<<" 8.- Recorrido AMPLITUD \n"
			<<" 0.- SALIR. \n\n";
		cout<<" Elija una opci"<<char(162)<<"n: ";
		
		cin>>opc;
		
		system("cls");
		
		cout<<endl<<endl;
		switch(opc){
			case '1': 
				cout<<" -> Agregar un estudiante: \n\n";
				cout<<" Ingrese la matr"<<char(161)<<"cula del estudiante: ";
				cin>>mat;
				cout<<" Ingrese el nombre del estudiante (sin espacios): ";
				cin>>nom;
				cout<<" Ingrese la calificaci"<<char(162)<<"n del estudiante: ";
				cin>>cal;
				Estudiante.insertar(mat, nom, cal);
				cout<<"\n\n *** Estudiante agregado *** \n\n";
				system("pause");
				break;
			case '2':
				cout<<" -> Agregar calificaci"<<char(162)<<"n a un estudiante: \n\n";
				cout<<" Ingrese la matr"<<char(161)<<"cula del estudiante: ";
				cin>>mat;
				if(Estudiante.buscar(mat)!=0){
					cout<<" Ingrese la calificaci"<<char(162)<<"n del estudiante: ";
					cin>>cal;
					Estudiante.buscar(mat)->agregaCalificacion(cal);
					cout<<"\n\n *** Calificaci"<<char(162)<<"n agregada *** \n\n";	
				}
				else cout<<" No existe un registro con la matr"<<char(161)<<"cula "<<mat<<endl<<endl;
				
				system("pause");
				break;
				
			case '3':
				cout<<" -> Eliminar el registro de un estudiante: \n";
				cout<<" Ingrese la matricula del estudiante a eliminar: ";
				cin>>mat;
				if(Estudiante.buscar(mat)!=0){
					Estudiante.eliminar(mat);
					cout<<"\n\n *** Registro eliminado *** \n\n";	
				}
				else cout<<" No existe un registro con la matr"<<char(161)<<"cula "<<mat<<endl<<endl;
				
				system("pause");
				break;
				
			case '4':
				cout<<" -> Buscar la direcci"<<char(162)<<"n de memoria de un estudiante: \n\n";
				cout<<" Ingrese la matricula del estudiante a buscar: ";
				cin>>mat;
				cout<<endl<<endl<<" Direccion de memoria: "<<Estudiante.buscar(mat)<<endl;
				system("pause");
				break;
			case '5': 
				cout<<" Recorrido INORDEN: \n\n";
				Estudiante.inorden();
				cout<<endl<<endl;
				system("pause");
				break;
			case '6': 
				cout<<" Recorrido PREORDEN: \n\n";
				Estudiante.preorden();
				cout<<endl<<endl;
				system("pause");
				break;
			case '7': 
				cout<<" Recorrido POSTORDEN: \n\n";
				Estudiante.postorden();
				cout<<endl<<endl;
				system("pause");
				break;
			case '8': 
				cout<<" Recorrido en AMPLITUD: \n\n";
				Estudiante.amplitud();
				cout<<endl<<endl;
				system("pause");
				break;
			case '0':
				cout<<" ***** FIN DEL PROGRAMA ***** \n\n\n";
				system("pause");
				break;
			
			default:
				cout<<" ***** OPCION INEXISTENTE *****\n\n";
				system("pause");
				break;
		}
		system("cls");
	}while(opc!='0');
	
		
	return 0;
}


	/*Estudiante.insertar(150374, "Luis Tena", 10);
	Estudiante.insertar(150385, "Ivan Manriquez", 9);
	Estudiante.insertar(150354, "Rosa Zuniga", 8);
	Estudiante.insertar(150345, "Carlos Mauricio", 7);
	Estudiante.insertar(150390, "Bryan Berumen", 6);
	
	
	Estudiante.inorden();
	cout<<endl<<endl;
	
	Estudiante.eliminar(150385);
	Estudiante.inorden();
	cout<<endl<<endl;
	
	
	//Agregue una calificación
	Estudiante.buscar(150374)->agregaCalificacion(9.9);
	Estudiante.buscar(150374)->agregaCalificacion(9);
	Estudiante.buscar(150374)->agregaCalificacion(8);
	Estudiante.buscar(150374)->agregaCalificacion(7);
	Estudiante.inorden();
	
	
	cout<<Estudiante.buscar(150390)<<endl;
	cout<<Estudiante.buscar(150385);
	*/
