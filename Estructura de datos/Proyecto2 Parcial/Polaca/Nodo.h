/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Nodo{
	private:
		string valor;
		Nodo *siguiente;
		int index;
	public:
		Nodo(string _valor, Nodo *);
    	string getValor(void);
    	void setValor(string newValor);
    	int getIndex();
    	void setIndex(int);
    	Nodo *getSiguiente(void);
    	void setSiguiente(Nodo *newSiguiente);
		~Nodo();
	};
