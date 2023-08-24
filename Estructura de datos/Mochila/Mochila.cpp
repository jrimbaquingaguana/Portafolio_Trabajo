/*************************
 * UFA - ESPE
 * Students:  Ronny Ibarra - José Imbaquinga
 * Created: jueves, 24 de febrero de 2023 19:00:40
 * Modified: viernes, 25 de febrero de 2023 2:02:48
 * Problem: Mochila
 * Level: Level three
 * NRC: 7999
 *************************/

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Mochila.h"
using namespace std;

struct mochila
{
	float valor; 
	float peso; 
	float indice;
};

void Mochila :: FuncionMochila()
{
	int numero, max, j , cont;
	cout<<"Ingresar el numero de elementos de la mochila"<<endl;
	numero=validarEntero();
	cout<<endl;
	mochila elemento[numero], aux;
	
	cout<<"Ingresar elementos de la mochila:"<<endl;
	for (int i=0;i<numero;i++)
	{

		cout<<"Valor: "<<i+1<<" :" ;elemento[i].valor=validarEntero();
		cout<<"\t ";
		cout<<"Peso: "<<i+1<<":"   ;elemento[i].peso=validarEntero();
		
		elemento[i].indice=elemento[i].valor/elemento[i].peso;
		cout<<endl;
	}
	
	for (int i=0;i<numero;i++)
	{for(int j=i+1;j<numero;j++)
	{if(elemento[i].indice < elemento[j].indice)
	{aux= elemento[i];
	elemento[i]= elemento[j];
	elemento[j]=aux;
	}
	}
	}
	cout<<" Indice Peso  Valor" <<endl;
	for (int i=0;i<numero;i++)
	{
		
		cout<<i+1<<":" ;
		cout<<elemento[i].indice<<" : ";
		cout<<elemento[i].peso<<" : ";
		cout<<elemento[i].valor<<endl;
		
	}
	
	cout<<endl;
	float wmax;
	float valmax=0;
	cout<<"Peso maximo de la mochila: \n";
	wmax=validarEntero();
	cout<<endl;
	int i=0;
	while(wmax>0)
	{ if(wmax>elemento[i].peso)
	{
		wmax= wmax-elemento[i].peso;
		valmax= valmax+elemento[i].valor;
		
	}
	else
	{
		valmax = valmax+(elemento[i].valor*(wmax/elemento[i].peso));
		wmax=0; 
	}
	i++;
		
	}
	
	cout<<"El valor maximo de la mochila es: "<<valmax<<endl;
	
}
char* Mochila::validarEnteros(char const *msj){
	char *dato = new char[0];
	char c;
	int i=0;
	cout<<msj;
	while((c = getch()) != 13){
		if((c >= '0' && c <= '9') ){
			cout<<c;
			dato[i++] = c;
		}else if(c == '\b'){
			i--;
			cout<<"\b \b";
		}
	}
	dato[i] = '\0';	
	return dato;
	
}

double Mochila::validarEntero(){
    char dato[10];
    float valorEntero;
    strcpy(dato, validarEnteros(" "));
    valorEntero = atof(dato);
    return valorEntero;
}