#include <iostream>
#include <list>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include "hashtable.h"

using namespace std;


void HashTable::insertar(int clave, string valor){
	int valorHash = hashFuncion(clave);
	auto& celda = tabla[valorHash];
	auto inicioItr = begin(celda);
	bool claveExiste = false;
	for (; inicioItr != end(celda); inicioItr++){
		if (inicioItr->first == clave){
			claveExiste = true;
			inicioItr->second = valor;
			cout<<"Adevertencia: Clave existe, valor reemplazado";
			break;
		}
	}
	
	if (!claveExiste){
		celda.emplace_back(clave, valor);
	}
	
	return;
}

void HashTable::eliminar(int clave){
	int valorHash = hashFuncion(clave);
	auto& celda = tabla[valorHash];
	auto inicioItr = begin(celda);
	bool claveExiste = false;
	for (; inicioItr != end(celda); inicioItr++){
		if (inicioItr->first == clave){
			claveExiste = true;
			inicioItr = celda.erase(inicioItr);			
			cout<<"Informacion: Item eliminado";
			break;
		}
	}
	
	if (!claveExiste){
		cout<<"Informacion: Clave no encontrada. Par no eliminado";		
	}
	
	return;
}

void HashTable::buscar(int clave){
	bool claveExiste = false;
	
	for (int i{} ; i < gruposHash; i++){
		if (tabla[i].size() == 0) continue;
		
		auto iterador = tabla[i].begin();
		for (; iterador != tabla[i].end(); iterador++){
			if (iterador->first == clave){
				claveExiste = true;
				cout<<"Informacion: Clave: "<<iterador->first<<" Valor: "<<iterador->second<<endl;
				break;
			}			
		}
	}
	
	if (!claveExiste){
		cout<<"Informacion: Clave no encontrada.";		
	}
}

void HashTable::imprimir(){
	for (int i{} ; i < gruposHash; i++){
		if (tabla[i].size() == 0) continue;
		
		auto iterador = tabla[i].begin();
		for (; iterador != tabla[i].end(); iterador++){
			cout<<"Informacion: Clave: "<<iterador->first<<" Valor: "<<iterador->second<<endl;
		}
	}
	return;	
}

char* HashTable::validarEnteros(char const *msj){
	char *dato = new char[0];
	char c;
	int i=0;
	cout<<msj;
	while((c = getch()) != 13){
		if(c >= '1' && c <= '9'){
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

double HashTable::validarEntero(){
    char dato[10];
    float valorEntero;
    strcpy(dato, validarEnteros("-> "));
    valorEntero = atof(dato);
    return valorEntero;
}

char* HashTable::ingresocaracteres(char *msj)
{
    char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while ((c=getch())!=13){
		if(c>='a'&& c<='z'){
			printf("%c",c);
			dato[i++]=c;
		}else if(c==8){
			dato[i]=0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}
		
	}
	dato[i]='\0';//fin del while
	return dato;
}
