#include "Alfil.h"
#include <graphics.h>
#include <iostream>

using namespace std;



void Alfil::ModoGrafico(int filaAlfil,int columnaAlfil){
  initwindow(800, 800, "Tabla de Ajedrez");	
	int filaAlfil1=50,columnaAlfil1=50;
	for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            
			if ((i + j) % 2 == 0) {
                setfillstyle(SOLID_FILL, WHITE);
            }
            else {
                setfillstyle(SOLID_FILL, BLACK);
            }
        	
            bar(i * 100, j * 100, (i + 1) * 100, (j + 1) * 100);
	        }
        
    }
    
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if((i+j==(filaAlfil+columnaAlfil)||(i-j)==(filaAlfil-columnaAlfil))){
				setcolor(RED);
				circle(filaAlfil1, columnaAlfil1,40 );
			} 
		
            filaAlfil1=filaAlfil1+100;
	        }
        filaAlfil1=50;
            columnaAlfil1=columnaAlfil1+100;

    }        

		getch();
		
       	system("PAUSE");  
  	
}

