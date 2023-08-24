/*********
 * UFA - ESPE
 * Students:  Ronny Ibarra - José Imbaquinga
 * Created: jueves, 24 de febrero de 2023 19:00:40
 * Modified: viernes, 25 de febrero de 2023 2:02:48
 * Problem: Reina
 * Level: Level three
 * NRC: 7999
 *********/

#include "Reina.h"
#include "time.h"
#include <graphics.h>

void Reina:: encerarTablero(){
			for(int i=0;i<DIMENSION;i++){
				validar[i]=new bool[DIMENSION];
				tablero[i]=new char[DIMENSION];
				for(int j=0;j<DIMENSION;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
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
	       		 int a,b;



    	a=150;
		b=50;
		setcolor(RED);
		circle(a, b,40 );
		readimagefile("Reina.jpg",a-50,b-50,0,100);

        a=50;
		b=250;
setcolor(RED);
	circle(a, b,40 );
	readimagefile("Reina.jpg",a-50,b-50,100,100);

			a=550;
		b=150;
setcolor(RED);
	circle(a, b,40 );
	readimagefile("Reina.jpg",a-50,b-50,400,0);
			a=650;
		b=350;
setcolor(RED);
		circle(a, b,40 );
		readimagefile("Reina.jpg",a-50,b-50,500,200);
			a=350;
		b=450;
setcolor(RED);
		circle(a, b,40 );
		readimagefile("Reina.jpg",a-50,b-50,200,300);
			a=750;
		b=550;
setcolor(RED);
	circle(a, b,40 );
	readimagefile("Reina.jpg",a-50,b-50,600,400);
			a=250;
		b=650;
setcolor(RED);
		circle(a, b,40 );
		readimagefile("Reina.jpg",a-50,b-50,100,500);
			a=450;
		b=750;
setcolor(RED);
		circle(a, b,40 );
		readimagefile("Reina.jpg",a-50,b-50,300,600);

    }
		}

void Reina:: crearArchivo(){
		archivo.open("exaustivo.txt",std::fstream::out);
		archivo<<"solucion"<<DIMENSION<<"*"<<DIMENSION<<std::endl<<std::endl;
		contador=0;
	}

 Reina::Reina(int n1){
		n=n1;
		validar=new bool *[DIMENSION];
		tablero=new char *[DIMENSION];
		encerarTablero();
		crearArchivo();
	}

void Reina::bloquear(int x, int y){
		int aux1,aux2;
		aux2=y;
		aux1=0;
		while(aux1<DIMENSION){//vertical
			*(*(validar+aux1)+aux2)=true;
			aux1++;
		}
		aux2=0;
		aux1=x;
		while(aux2<DIMENSION){ //horizontal
			*(*(validar+aux1)+aux2)=true;
			aux2++;
		}
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		while (aux1 < DIMENSION && aux2 < DIMENSION) { //FALTABA
        *(*(validar + aux1) + aux2) = true; //FALTABA
        aux1++; //FALTABA
        aux2++; //FALTABA
    	}
		aux2=y;
		aux1=x;
		while(aux1<DIMENSION && aux2>0){
			aux1++;
			aux2--;
		}
		if (x + y >= DIMENSION) { //FALTABA
            aux1--;
            aux2++;
        } //FALTABA
		while(aux1>=0 && aux2<DIMENSION){
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}

void Reina:: mostrar(){
		contador++;
		archivo<<"solucion N "<<contador <<std::endl;
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				archivo<<*(*(tablero+i)+j)<<" ";
			}
			archivo<<std::endl;
		}
		archivo<<std::endl;
	}

void Reina:: quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<DIMENSION;i++){
			for(int j=0;j<DIMENSION;j++){
				if(*(*(tablero +i)+j)=='R')
				bloquear(i,j);
			}
		}
	}

void Reina::mostrarPantalla(int n){



	}


void Reina::mostrarEnConsola(){
	std::ifstream archivoResp;
	std::string texto;

	archivoResp.open("exaustivo.txt",std::ios::in);

	if(archivoResp.fail()){
		std::cout<<"No se encontro el archivo "<<std::endl;
		exit(1);
	}
	while(!archivoResp.eof()){
		getline(archivoResp,texto);
		std::cout<<texto<<std::endl;
	}

	archivoResp.close();
}

void Reina::solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='R';
		bloquear(x,y);
		if(n1==n){
			mostrar();
		}else{
			for(int i=0;i<n;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}

void Reina::solucionReinas(){
		for(int i=2;i<DIMENSION;i++){ //AQUI ES !!
			for(int j=0;j<DIMENSION;j++){
				solucion(i,j,1);	//AQUI ES !!!
			}
		}
		archivo.close();
	}


