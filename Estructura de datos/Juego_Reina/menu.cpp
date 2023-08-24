#include "Alfil.cpp"
#include "Reina.cpp"
#include "IngresoDatos.cpp"
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <windows.h>
#include <stdlib.h>
#include <fstream>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_ENTER 13

int menu(const char *titulo, const char *opciones[], int n);

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void MenuIngreso(){
   bool repite = true;
   int opcion, longitud;   
   std::string op;
   std::string cadena;
   const char *titulo = "Escoja un ingreso";
   const char *opciones[] = {"Reina", "Alfil","Retornar"};
   int n = 3;  
   do 
   {
      opcion = menu(titulo, opciones, n);
		
		switch(opcion)
		{
			case 1:{
				system("cls");
				int n;
    			IngresoDatos in;
				n= in.IngresarDatosEntero();
    			std::cout<<'\n';
				Reina *obj=new Reina(n);
				obj->solucionReinas();
    			//obj->mostrarPantalla();
    			obj->mostrarEnConsola();
				std::cout<<"\nSe creo el archivo txt"<<std::endl;
				system ("pause");
				break;
			}		
			case 2:{
				system("cls");
					Alfil b;
					IngresoDatos in;
    				int alfiles;
    				std::fstream archivoA;
    				archivoA.open("alfil.txt", std::fstream::out);
    				std::cout << "Ingrese el numero de alfiles (1-8):";
    				alfiles = in.IngresarDatosEntero();

    			if (alfiles < 1 || alfiles > 8)
    			{		
        		std::cout << "\nInvalido!. El numero de alfiles debe estar entre 1 y 8." << std::endl;
        		// return 0;
    			}

    			for (int i = 0; i < DIMENSION; i++)
    			{
        		for (int j = 0; j < DIMENSION; j++)
        		{
        		//(*(*b.tableroAlfil+i)+j) = 0 ;
            	b.tableroAlfil[i][j] = 0;
        		}
    			}

    			if (b.solucionAlfil(0, 8, alfiles))
    			{			
        		std::cout << "\nSolucion: " << std::endl;
        		for (int i = 0; i < DIMENSION; i++)
        		{
            		for (int j = 0; j < DIMENSION; j++)
            		{
                		if (b.tableroAlfil[i][j] == 1)
                		{
                    		archivoA << "A  ";
                   			std::cout << "A  ";
                		}
                		else
                		{
                    		archivoA << "** ";
                    		std::cout << "** ";
                		}
            		}
            		std::cout << std::endl;
            		archivoA << std::endl;
        		}
    			}
    			else
    			{	
        		std::cout << "\nSolucion no encontrada" <<std::endl;
    			}	
				system ("pause");
				break;
			}					
			case 3:{
				system("cls");
				std::cout<<std::endl;
				std::cout<<"Regresando..."<<std::endl;
				repite=false;
				break;
			}											
		}
	}while(repite);
}

void MenuPrincipal(){

	bool repite = true;
	int opcion;   
   
    const char *titulo = "****Tablero de Ajedrez (Reina - Alfil)****";
    const char *opciones[] = {"Tablero","Salir del programa"};
    int n =2;  
 
    do {
        opcion = menu(titulo, opciones, n); 	
		switch(opcion){
			case 1:{
				system("cls");
				MenuIngreso();
				break;
			}				
			case 2:{
				std::cout<<std::endl;
				printf("\n\n\n");
				std::cout<<"Saliendo del programa..."<<std::endl;
				repite=false;
				break;
			}										
	}
	printf("\n\n\n");
	system("pause");
	}while(repite);
}

int menu(const char titulo[], const char *opciones[], int n){
   int opcionSeleccionada = 1;  
 
   int tecla;
 
   bool repite = true; 
 
   do {
      system("cls");
      //system("Color 8B");
      gotoxy(5, 3 + opcionSeleccionada); std::cout << "->" << std::endl;
 
      
      gotoxy(15, 2); std::cout << titulo;
 
      
      for (int i = 0; i < n; ++i) {
         gotoxy(10, 4 + i); std::cout <<"["<< i + 1 << "] | " << opciones[i];
      }
 
      
 
      do {
         tecla = getch();
         
      } while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != TECLA_ENTER);
 
      switch (tecla) {
 
         case TECLA_ARRIBA:   
 
            opcionSeleccionada--;
 
            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }
 
            break;
 
         case TECLA_ABAJO:
            opcionSeleccionada++;
 
            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }
 
            break;
 
         case TECLA_ENTER:
            repite = false;
            break;
      }
 
   } while (repite);
 
   return opcionSeleccionada;
}