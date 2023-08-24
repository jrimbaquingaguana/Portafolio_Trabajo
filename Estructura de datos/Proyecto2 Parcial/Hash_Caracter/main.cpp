/*********
UFA - ESPE
AUTORES: José Imbaquinga, Alexander Bedón, Ronny Ibarra
FECHA DE CREACIÓN: 14/01/2023
FECHA DE MODIFICACIÓN: 15/01/2023 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#include <cstdlib>
#include <iostream>
#include <iostream>
#include <conio.h>
#include "Hash.cpp"
#include "Input.cpp"
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
    Input *input = new Input();
    Hash h(11);
    int opc;
    int a;
    char c;
    char f;
    string d;
    do{
        system("cls");
        h.displayHash();
        cout<<"1.Ingrese Elemento"<<endl;
        cout<<"2.Elimine Elemento"<<endl;
        cout<<"3.Busque Elemento"<<endl;
        cout<<"0.Salir"<<endl;
        opc=input->integerNumber("",10);
        switch(opc){
        case 1:
			c=*ingresocaracteres("\nIngrese el caracter:");		
			a=int(c);
			h.insertItem(a);
            break;
        case 2:
            
			c=*ingresocaracteres("\nIngrese el caracter:");		
			a=int(c);     
			h.deleteItem(a);
            break;
        case 3:
            
            c=*ingresocaracteres("\nIngrese el caracter:");		
			a=int(c);
            h.BuscaHash(a);
            getch();
            break;
        case 0:
            break;
        default:
            break;
        }
    }while(opc!=0);

  return 0;
}
