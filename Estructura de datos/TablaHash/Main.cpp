#include <iostream>
#include "HashTable.cpp"
using namespace std;

int main(){
	HashTable ht;
	
	int clave;
	string valor;
	
	int opcion_menu = 0;	
	do
	{
		cout << "\n|-----------------------------------------|";
		cout << "\n|              LISTA HASH TABLE           |";
		cout << "\n|-----------------------------------------|";
		cout << "\n|-----------------------------------------|";
		cout << "\n| 1. Insertar                             |";
		cout << "\n| 2. Buscar                               |";
		cout << "\n| 3. Eliminar                             |";
		cout << "\n| 4. Mostrar                              |";
		cout << "\n| 5. Salir                                |";
		cout << "\n|-----------------------------------------|";
		cout << "\n\n Escoja una Opcion: ";
		
		opcion_menu=ht.validarEntero();
		cout<<"\n";
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA NODO EN HASH TABLE \n\n";			
			cout<<"Ingrese clave<int> :";
			clave=ht.validarEntero();
			cout<<"\n";	
			valor=ht.ingresocaracteres("Ingrese el valor<string>: ");	
			ht.insertar(clave, valor);			
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN HASH TABLE \n\n";
			cout<<"Ingrese clave<int> :";
			clave=ht.validarEntero();
			cout<<"\n";
			ht.buscar(clave);			
			break;
		case 3:
			cout << "\n\n ELIMINAR UN NODO EN HASH TABLE \n\n";
			cout<<"Ingrese clave<int> :";
			clave=ht.validarEntero();
			cout<<"\n";
			ht.eliminar(clave);
			break;			
		case 4:
			cout << "\n\n DESPLEGAR ELEMENTOS HASH TABLE \n\n";			
			ht.imprimir();
			break;			
		case 5: 
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 5);
	
	
	return 0;
}




















