#include <iostream>
#include "Lista.cpp"
using namespace std;



int main(){
	Lista lst;

	int opcion_menu = 0;

	do
	{
		cout << "\n|----------------------------------------------|";
		cout << "\n|             ° LISTA SIMPLE °                 |";
		cout << "\n|---------------------|------------------------|";
		cout << "\n| 1. Insertar         | 5. Eliminar            |";
		cout << "\n| 2. Buscar           | 6. Desplegar           |";
		cout << "\n| 3. Modificar        | 7. Busqueda Secuencial |";
        cout << "\n| 4. Busqueda Binaria | 8. Salir               |";
		cout << "\n|---------------------|------------------------|";
		cout << "\n\n Escoja una Opcion: ";
		cin >> opcion_menu;
		switch(opcion_menu){
		case 1:
			cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
			lst.insertarNodo();
			break;
		case 2:
			cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
			lst.buscarNodo();
			break;
		case 3:
			cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
			lst.modificarNodo();
			break;
        case 4:
			cout << "\n\n BUSQUEDA BINARIA EN LISTA \n\n";
			lst.busquedaBinaria();
			break;
		case 5:
			cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
			lst.eliminarNodo();
			break;
		case 6:
			cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
			lst.desplegarLista();
			break;
        case 7:
			cout << "\n\n BUSQUEDA SECUENCIAL EN LISTA \n\n";
			lst.busquedaSecuencial();
			break;
		case 8:
			cout << "\n\n Programa finalizado...";
			break;
		default:
			cout << "\n\n Opcion No Valida \n\n";
		}
	} while (opcion_menu != 8);


	return 0;
}
















/*



*/





