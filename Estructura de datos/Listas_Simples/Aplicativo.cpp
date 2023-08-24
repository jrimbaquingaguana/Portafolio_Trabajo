/***********************************************************************
 * UFA-ESPE
 * Autores: Ronny Ibarra-Jose Imbaquinga
 * Modificacion: Martes, 13 de noviembre 
 * Purpose: Listas, realizar el buscar, eliminar, inserta cola, mostrar cola
 *Nivel: Tercero           
 *NRC:7999
 ***********************************************************************/
#include <iostream>
#include "validar.h"
#include "Mc.cpp"
int main() {
	Lista lst;
	int opc,contar, num, cantidad;
	char datoEntero[10];
	do{
		system("cls");
        cout << "LISTAS SIMPLES" << endl
             << endl; 
        cout << "1  Ingresar elementos de la lista " ;
        cout << "\t \t \t 2  Mostrar la lista simple" <<endl;
        cout << "3  Buscar el numero" ;
        cout << "\t \t \t \t \t 4  Eliminar numero" << endl;
        cout << "5  Ingreso de elementos por la cola";
        cout << " \t \t \t 6  Mostrar elementos por la cola" << endl;
        cout << " 7 Calcular el maximo comun multiplo";
        cout << " \t \t \t 8  Calcular el minimo comun multiplo" << endl;

        cout << "9 Salir del programa" << endl;
        cout << " " << endl;
        cout<<"Escoga una opcion"<<endl;
        str_cpy(datoEntero,ingresarDatosOpcion(""));
		opc=funcion_atoi(datoEntero,strlen(datoEntero));
		cout<<endl;
		while(opc)
		{
			if(opc==1){
				cout<<"\nIngresar la cantidad de datos:"<<endl;
				str_cpy(datoEntero,ingresarDatosEnteros(""));
				cantidad=funcion_atoi(datoEntero,strlen(datoEntero));
				Lista lista;
				lista.setResultado(cantidad);
				do{
					contar++;
					cout<<"\nIngresar el numero que quierte introducir a la lista"<<endl;
					str_cpy(datoEntero,ingresarDatosEnteros(""));
					num=funcion_atoi(datoEntero,strlen(datoEntero));
					lst.insertar(num);
				}while (contar<cantidad);
				cout<<endl;
				cout<<"Se a ingresado los datos correctamente"<<endl;
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
				str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese el dato que quiere buscar: \n "));
				num=funcion_atoi(datoEntero,strlen(datoEntero));
				cout<<endl;
				lst.buscar(num);
				system("PAUSE");
				break;
		}
			else if(opc==4){
			
					lst.mostrarLista();
				cout<<endl;
				str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese el numero que desea eliminar: \n "));
				num=funcion_atoi(datoEntero,strlen(datoEntero));
				lst.eliminar(num);
				cout<<endl;
				cout<<"El numero se a elimninado con exito"<<endl;

				lst.mostrarLista();
				cout<<endl;
				system("PAUSE");
				break;
			}
			else if(opc==5){
				
			
				
				char respuesta,datoCaracter[10];
				
				str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese el numero que desea introducir a la lista: \n "));
				num=funcion_atoi(datoEntero,strlen(datoEntero));
				lst.insertarCola(num);
				
				cout<<endl;
				system("PAUSE");
				break;
		}
			else if(opc==6){
				
			
				lst.mostrarLista();
				lst.imprimirCola(lst,cantidad);
				cout<<endl;
				system("PAUSE");
				break;
			}
			else if(opc==7){
				lst.maxiComun();
				system("PAUSE");
				break;
			}
			else if(opc==8){
				lst.MinimoComun();
				system("PAUSE");
				break;
			}
			
			else if(opc==9){
			
			
			
				system("cls");
            	cout << "Gracias por utilizar este programa." << endl;
            	system("PAUSE");
            	exit(0);
				break;
			}
			else
				cout<<"Escoga bien la opcion"<<endl;
			}
		
		

	}while(opc != 1 || opc != 2|| opc != 3 || opc != 4||opc != 5|| opc != 6||opc !=7 || opc!=8 || opc != 9 );
	return 0;
}
