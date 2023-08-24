/***********************************************************************
 * UFA-ESPE
 * Autores: Ronny Ibarra-Jose Imbaquinga
 * Modificacion: Martes, 13 de noviembre 
 * Purpose: Listas, realizar el buscar, eliminar, inserta cola, mostrar cola
 *Nivel: Tercero           
 *NRC:7999
 ***********************************************************************/

#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		Nodo *primero;
		Nodo *actual;
		bool listaVacia(){
			return (this->primero==NULL);
		}
		int resultado;
	public:
		Lista();
		void insertar(int val);
		void buscar(int buscar);
		void mostrarLista();
		void eliminar(int elemento);
		void imprimirCola(Lista lis,int tam);
		void insertarCola(int num);
		void buscarElemento(int pos);	
		 int getResultado(void);
  		 void setResultado(int newResultado);
   		virtual void MinimoComun();
   		virtual void maxiComun(); 	
};
