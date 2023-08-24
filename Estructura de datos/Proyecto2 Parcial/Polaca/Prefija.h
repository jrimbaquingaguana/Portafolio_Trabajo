/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/
#include <iostream>
#include "Pila.cpp"
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Prefija
{
	typedef Prefija Pre;
	
	private:
		int posi;
		Pila pila;
		string *opera = new string[posi]; 
	public:
		string* inAPre(string);
		int getPosi();
		float resuelve(string);
		float suma(float,float);
		float resta(float,float);
		float multi(float,float);
		float divi(float,float);
		float pot(float,float);
		float sen(float);
		float cose(float);
		float tange(float);
		float arccose(float);
		float arcsen(float);
		float arctange(float);
		float senh(float);
		float coseh(float);
		float tangeh(float);
		int priorizar(string);
		
		float raiz(float);
}; typedef Prefija Pre;