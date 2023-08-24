/***********************************************************************
 * UFA-ESPE
 * Autores: Ronny Ibarra-Jose Imbaquimga
 * Modificacion: Martes, 08 de nombre de 2022 21:17:59
 * Purpose: Areas de las figuras
 *Nivel: Tercero           
 *NRC:7999
 ***********************************************************************/
#include <iostream>
#include "ListaCircularDoble.cpp"
#include "validar.h"
int main() {
	ListaCircularDoble lst;
	int opc,contador, num, cantidad;
	char datoEntero[10];
	do{
		system("cls");
        cout << "MENU" << endl
             << endl; 
        cout << "1  Ingresar los elemntos de la lista " ;
        cout << "\t \t2  Mostrar lista " << endl;
        cout << "3  Buscar el numero" ;
        cout << "\t \t \t\t4 Eliminar numero" << endl;
        cout << " 5 Calcular el maximo comun multiplo";
        cout << " \t \t \t 6  Calcular el minimo comun multiplo" << endl;
        cout<<"\t\t\t 7 encriptar";
        cout << "0  Salir" << endl;
        cout << " " << endl;
        str_cpy(datoEntero,ingresarDatosOpcion("\nSelecciona una opcion \n"));
		opc=funcion_atoi(datoEntero,strlen(datoEntero));
		cout<<endl;
		while(true){
		
		{
			if(opc==1) {
			
				str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese la cantidad de elementos que desea introducir: \n "));
				cantidad=funcion_atoi(datoEntero,strlen(datoEntero));
				do{
					str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese el numero que esea introducir a la lista: \n "));
					num=funcion_atoi(datoEntero,strlen(datoEntero));
					lst.insertar(num);
					contador++;
				}while (contador<cantidad);
				cout<<endl;
				system("PAUSE");
				break;
		}
			else if(opc==2){
			
				lst.mostrarLista();
				cout<<endl;
				system("PAUSE");
				break;
			}
			else if(opc==3){
				cout<<endl;
				lst.mostrarLista();
				str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese el dato que desea buscar: \n "));
				num=funcion_atoi(datoEntero,strlen(datoEntero));
				cout<<endl;
				lst.buscar(num);
				system("PAUSE");
				break;
			}
			else if(opc==4){
			
				lst.mostrarLista();
				cout<<endl;
				str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese el dato que desea eliminar: \n "));
				num=funcion_atoi(datoEntero,strlen(datoEntero));
				lst.eliminar(num);
				cout<<endl;
				lst.mostrarLista();
				cout<<endl;
				system("PAUSE");
				break;
			}
				else if(opc==5){
				lst.maxiComun();
				system("PAUSE");
				break;
			}
			else if(opc==6){
				lst.MinimoComun();
				system("PAUSE");
				break;
			}
			else if(opc==7)
			{
				lst.mostrarLista();
				cout<<endl;
				
			}

			else
				system("cls");
            	cout << "Gracias por utilizar este programa." << endl;
            	system("PAUSE");
            	exit(0);
				break;
		}
}
	}while(opc != 1 || opc != 2|| opc != 3 || opc != 4||opc != 0 || opc !=5 || opc!=6 || opc!=7);
	return 0;
}
//void encriptar(char msj[])
