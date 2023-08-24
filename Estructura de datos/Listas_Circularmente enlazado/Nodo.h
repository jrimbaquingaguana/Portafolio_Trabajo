/***********************************************************************
 * UFA-ESPE
 * Autores: Ronny Ibarra-Jose Imbaquimga
 * Modificacion: Martes, 08 de nombre de 2022 21:17:59
 * Purpose: Areas de las figuras
 *Nivel: Tercero           
 *NRC:7999
 ***********************************************************************/
#pragma once
#include <time.h>
class Nodo{
	private:
		int valor;
		Nodo *siguiente;
		Nodo *anterior;
	public:
		Nodo();
		Nodo(int val, Nodo *sig=NULL, Nodo *ant=NULL){
			this->valor=val;
			this->siguiente=sig;
			this->anterior=ant;
		}
	friend class ListaCircularDoble;
};
