/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#pragma once
#include <conio.h>
#include<cstring>

class ValidaDatos{
	private:
		char dato[10];
		char *ingresarDatosEnteros(char const *);
		char *ingresarDatosFloat(char const *);
		char *ingresarDatosReal(char const *);
		int suma (int verif2[9]);

	public:
		int devuelveInt(char *);
		float devuelveFloat(char *);
		double devuelveDouble(char *);
		char * devuelveChar(char const *);
		char * devuelveCharNumeros(char const *);
		char * devuelveUnSoloChar(char const *msj);

		int validarCedula(char * cedulav);
};

char * ValidaDatos::ingresarDatosEnteros(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}

char * ValidaDatos::ingresarDatosFloat(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	int contador = 0;
	int contadorf = 0;
	printf("%s",msj);
	while((c=getch())!=13){
		if((c>='0'&& c<='9') || c == '.' || c == 'f') {

			if (c == '.' && contador == 0){
				printf("%c",c);
				dato[i++]=c;
			}else if (c == 'f' && contadorf == 0){
				printf("%c",c);
				dato[i++]=c;
			}else if (c != '.' && c != 'f') {
				printf("%c",c);
				dato[i++]=c;
			}

			if (c == 'f'){
				contadorf++;
			}
			if (c == '.'){
				contador++;
			}
		}
	}
	dato[i]='\0';
	return dato;
}

char * ValidaDatos::ingresarDatosReal(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	int contador = 0;
	printf("%s",msj);
	while((c=getch())!=13){
		if((c>='0'&& c<='9') || c == '.') {

			if (c == '.' && contador == 0){
				printf("%c",c);
				dato[i++]=c;
			}else if (c != '.'){
				printf("%c",c);
				dato[i++]=c;
			}

			if (c == '.'){
				contador++;
			}
		}
	}
	dato[i]='\0';
	return dato;
}

char * ValidaDatos::devuelveChar(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9') {
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}

char * ValidaDatos::devuelveUnSoloChar(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9') {
			printf("%c",c);
			dato[i++]=c;
		}
		if (i == 1){
			break;
		}
	}
	dato[i]='\0';
	return dato;
}


char * ValidaDatos::devuelveCharNumeros(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	return dato;
}

int ValidaDatos::devuelveInt(char *cadena){
	strcpy(dato,ingresarDatosEnteros(cadena));
	int x;
  	sscanf(dato, "%d", &x);
	return x;
}

float ValidaDatos::devuelveFloat(char *cadena){
	strcpy(dato,ingresarDatosFloat(cadena));
	float x;
  	sscanf(dato, "%f", &x);
	return x;
}

double ValidaDatos::devuelveDouble(char *cadena){
	strcpy(dato,ingresarDatosReal(cadena));
	double x;
  	sscanf(dato, "%lf", &x);
	return x;
}

int ValidaDatos::validarCedula(char * cedulav) {

    int cedula[9];
	for (int i = 0; i < strlen(cedulav);i++){
		cedula[i] = (int)cedulav[i] - 48;
	}


	int verif[9],num,i;
	if(cedula[2]<0 || cedula[2]>6) {
		printf("Error en el tercer digito.\n");
		return 0;
	}
	if(cedula[0]<0 || cedula[0]>2) {
		printf("Error en el codigo de provincia.\n");
		return 0;
	}
	if(cedula[0]==2 && (cedula[1]<1 || cedula[1]>4)) {
		printf("Error en el codigo de provincia.\n");
		return 0;
	}
	for(i=0; i<=8; i++) {
		if(i%2==0) {
			verif[i]=cedula[i]*2;
			if(verif[i]>=10) {
				verif[i]=verif[i]-9;

			}
		} else {
			verif[i]=cedula[i]*1;
			if(verif[i]>=10) {
				verif[i]=verif[i]-9;

			}
		}
	}

	verif[9]=90 - suma(verif);
	num=verif[9]%10;

	if(cedula[9]==num) {
		//printf("Digito verificador obtenido: %d.\n",num);
		return 1;
	} else {
		printf("Digito verificador obtenido: %d. Error en el digito verificador.\n",num);
		return 0;
	}
}

int ValidaDatos::suma (int verif2[9]) {
	int i,suma=0;
	for (i=0; i<=8; i++) {
		suma =suma + verif2[i];
	}
	return suma;
}




