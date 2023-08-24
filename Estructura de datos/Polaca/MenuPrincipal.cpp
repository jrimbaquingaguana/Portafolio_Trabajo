/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/

#include "MenuPrincipal.h"

#include "Postfija.cpp"
#include "Prefija.cpp"
#define Tecla_Arriba 72
#define Tecla_Abajo 80
#define Enter 13
using namespace std;

void Menu::menuPrincipal(){
	int opcMP=0, opcMN=0;
	bool repetir=true,repetir1=true;
	bool ecValida=false;
    char enteroC[10];
    //Postfija objPosFija;
    Prefija  objPreFija;
    string ecuacion;
    const char *ecuacionC[100];
   
    int entero;
	const char *titulo="Calculadora Polaca";
    const char *opciones[]={"Ecuacion.","Cerrar"};
    const char *titulo1="Notaciones";
    const char *opciones1[]={"Notacion prefija."};
    
  
    
    
	
	do{
    	opcMP = menu(titulo,opciones,2);
    	switch(opcMP){
    		case 1:{
    			
    			system("cls");
				cout<<"Ingrese la ecuacion-> "<<endl;
				cin>>ecuacion;
				
				
				cout<<"\nInfija: "<<ecuacion<<endl;
							 string input;
   							string *ecuacionPreFija =objPreFija.inAPre(ecuacion);
    						    

       							 cout << "\nPostifjo: " << Postfijo::infijoAPostfijo(ecuacion) << endl;
       						cout<<"\nPrefija"<<endl;
							for(int i=0;i<=objPreFija.getPosi();i++)
							{
							cout<<ecuacionPreFija[i];
							}
								cout<<"\nEl resultado es: "<<objPreFija.resuelve(ecuacion)<<endl;
								
							
								repetir1=false;
      							system("pause");
      							system("cls");
      						cout<<"\n\t  Gracias por usar el programa";
      						repetir=false; 
							system("cls");
    			cout<<"\n\t  Gracias por usar el programa";
                repetir=false; 
                

				break;
			}
		
			
			case 2:{
    			system("cls");
    			cout<<"\n\t  Gracias por usar el programa";
                repetir=false; 
                break;
		}
	}
	}while(repetir);
}


int Menu::menu(const char *titulo,const char *opciones[],int n){
    int opcSeleccionada=1;
    int tecla;
    bool repetir=true;
    do{
        system("cls");
        gotoxy(5,3+opcSeleccionada); cout<<"-->";
        gotoxy(25,2); cout<<titulo;
        for(int i=0;i<n;i++){
            gotoxy(10,4+i); cout<<i+1<<"."<<opciones[i];
        }

        do{
            tecla=getch();
        }while(tecla!=Tecla_Arriba && tecla!=Tecla_Abajo && tecla!=Enter);
        
        switch (tecla)
        {
        case Tecla_Arriba:
            opcSeleccionada--;
            if(opcSeleccionada<1){
               opcSeleccionada=n;
            }
            break;
        case Tecla_Abajo:
            opcSeleccionada++;
            if(opcSeleccionada>n){
               opcSeleccionada=1;
            }
            break;
        case Enter:
            repetir=false;
            break;
        
        }
    }while(repetir);


    return opcSeleccionada;

}


void Menu::gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
 


bool Menu::verificarCedula(const string &cedula){
	    int sumaAntigua{};

    for (int i{}; i < 9; i += 2) {
        int valorDetectar = (cedula[i] - '0') * 2;

        if (valorDetectar > 9)
            valorDetectar -= 9;

        sumaAntigua += valorDetectar;
    }

    int sumaNueva{};
    
    for (int i{1}; i < 8; i += 2) {
        sumaNueva += (cedula[i] - '0');
    }

    int digitoVerificar = ((sumaAntigua + sumaNueva) % 10 != 0) ? 10 - (sumaAntigua + sumaNueva) % 10 : 0;

    return digitoVerificar == (cedula[9] - '0');
	
}

