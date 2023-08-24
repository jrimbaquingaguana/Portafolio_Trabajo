/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/

#pragma once
#include "Nodo.cpp"
#include <iostream>
#include <string>
using namespace std;
class Pila{
	private:
		Nodo *primero;
		Nodo *actual;
		bool ListaVacia();		
	public:
	
		Pila();
		void setPrimero(Nodo *);
		void setActual(Nodo *);
		Nodo *getPrimero();
		Nodo *getActual();
		bool getPilaVacia();
		
		void push(string);
		void pop();
		void mostrar();
		void buscar(string);
		int contar();
	
};
