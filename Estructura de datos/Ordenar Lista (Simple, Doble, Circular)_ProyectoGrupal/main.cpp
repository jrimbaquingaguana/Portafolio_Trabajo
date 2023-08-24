/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#include <iostream>
#include <conio.h>
#include "Datos.cpp"
#include "Lista.hpp"
#include "ValidaDatos.cpp"

using namespace std;

int main(){

	ValidaDatos * valida = new ValidaDatos();
	Lista<Datos> * lista = new Lista<Datos>();

	int opcion = 0;
	do{
		system("cls");
		cout<<"1. Ingreso de datos"<<endl;
		cout<<"2. Leer archivo"<<endl;
		cout<<"3. Escribir archivo"<<endl;
		cout<<"4. Eliminar datos (cedula)"<<endl;
		cout<<"5. Eliminar datos (nombre)"<<endl;
		cout<<"6. Mostrar datos"<<endl;
		cout<<"7. Shell Sort (cedula)"<<endl;
		cout<<"8. Shell Sort (nombre)"<<endl;
		cout<<"9. Salir"<<endl;

		opcion = valida->devuelveInt("Ingrese opcion:");
		cout<<endl;

		system("cls");
		switch(opcion){
			case 1:
				lista->insertar(NULL);
				break;
			case 2:
				lista->leerArchivo();
				break;
			case 3:
				lista->escribirArchivo();
				break;
			case 4:
				lista->borrar();
				break;
			case 5:
				lista->borrarInicial();
				break;
			case 6:
				lista->listar();
				break;
            case 7:
				lista->shellSort(true);
				break;
            case 8:
				lista->shellSort(false);
				break;
            case 9:
                cout<<"Fin del programa"<<endl;
                break;
            default:
                cout<<"Opcion no contemplada"<<endl;
                break;
		}
		getch();
	}while(opcion != 9);

	return 0;
}
