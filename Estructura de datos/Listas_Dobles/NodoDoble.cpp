#include "NodoDoble.h" //Llamo al archivo de cabecera NodoDoble.h para implementar los métodos de la clase NodoDoble
#include <iostream>
#include <conio.h>       
#include <stdio.h>  
using namespace std;

NodoDoble::NodoDoble() // Constructor por defecto de la clase NodoDoble.
{
	dato = 0;
	siguiente = NULL;
	anterior = NULL;
}
// Métodos setter y getter
// Setters
void NodoDoble::setDato(int dato)
{
	this->dato = dato;
}

void NodoDoble::setSiguiente(NodoDoble *siguiente)
{
	this->siguiente = siguiente;
}
void NodoDoble::setAnterior(NodoDoble *anterior)
{
	this->anterior = anterior;
}
// Getters
int NodoDoble::getDato()
{
	return dato;
}
NodoDoble *NodoDoble::getSiguiente()
{
	return siguiente;
}
NodoDoble *NodoDoble::getAnterior()
{
	return anterior;
}

// Métodos definidos por el usuario
void NodoDoble::generarNodoDoble(NodoDoble **nodoDoble, int dato, int &contarDatos) // Método en el cual se ingresan los datos a la lista doble
{
	NodoDoble *aux, *nuevo; // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doblemente enlazada.
	aux = *nodoDoble;		// Apunto aux a la lista doblemente enlazada
	int randomico = 0;

	for (int i = 0; i <= dato; i++)
	{
		randomico = 0;
		if (aux->getDato() == 0) // Si la lista doble esta vacia
		{
			randomico = 1 + rand() % 100;
			aux->setDato(randomico); // Envio como argumento el parámetro dato al método setDato() de la clase NodoDoble
									 // contarDatos++; //Aumento el contador de cuantos nodos  van ingresando a la lista doble.
		}
		else // Si la lista doble no esta vacia
		{
			randomico = 1 + rand() % 100;
			nuevo = new NodoDoble();		 // Reservo un espacio en memoria para el puntero nuevo que será un nuevo puntero.
			nuevo->setDato(randomico);		 // Envio como argumento el parámetro dato al método setDato() de la clase NodODoble
			nuevo->setSiguiente(*nodoDoble); // Apunto el nuevo nodo a NULL
			aux->setAnterior(nuevo);

			*nodoDoble = nuevo; // Apunto la lista doble al nuevo nodo creado,
			contarDatos++;		// Aumento el contador de cuantos nodos  van ingresando a la lista doble.
		}
	}
}

void NodoDoble::eliminarNodoDoble(NodoDoble **nodoDoble, int posicion, int &contarDatos) // Método en el cual se elimina el primer nodo de la lista doble
{
	NodoDoble *aux, *aux2; // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doblemente enlazada para no trabajar directamente con la lista doble,
						   // y declaro un aux2 para apuntar al elemento siguiente de la lista doble.
	aux = *nodoDoble;			// Apunto aux a la lista doble
	aux2 = aux->getSiguiente(); // Apunto aux2 al siguiente nodo de la lista doble.

	for (int i = 1; i <= posicion - 2; i++)
	{
		aux = aux->getSiguiente();
		aux2 = aux2->getSiguiente();
	}

	aux->setSiguiente(aux2->getSiguiente());
	aux2->setAnterior(aux);

	aux2->setSiguiente(NULL);

	contarDatos--; // Disminuyo´el número de nodos que hay en la pila
}

void NodoDoble::mostrarListaDoble(NodoDoble *nodoDoble, int contarDatos) // Método en el cual se muestra la lista doble
{
	NodoDoble *aux;	 // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doble.
	aux = nodoDoble; // Apunto aux a pila,
	int posicion = 1;
	if (aux == NULL) // Si la lista doble esta vacia, si aux apunta a NULL.
	{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
	}
	else
	{
		while (aux->getSiguiente() != NULL) // Recorremos la lista Doble, mientras no sea el último nodo de la lista doble.
		{
			cout << "-> " << posicion << "\t" << aux->getDato() << endl;
			posicion++;
			aux = aux->getSiguiente(); // Hago que se avance al siguiente nodo de la lista doble.
		}							   // Fin while()

		cout << "\nNumero de nodos en la lista doble: " << contarDatos << endl;
	}
}

void NodoDoble::maximoComun(NodoDoble *nodoDoble, int contarDatos){
	NodoDoble *aux;	 // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doble.
	aux = nodoDoble; // Apunto aux a pila,
	int mcd,primer_numero,residuo,i;	
	i=1;
	if (aux == NULL) // Si la lista doble esta vacia, si aux apunta a NULL.
	{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
	}
	else
	{
		while (aux->getSiguiente() != NULL) // Recorremos la lista Doble, mientras no sea el último nodo de la lista doble.
		{
			
			primer_numero=aux->getDato();

		if(i==1){
			mcd=primer_numero;
		}else{
			do{
				residuo=mcd%primer_numero;
				
				if(residuo !=0){
					mcd=primer_numero;
					primer_numero=residuo;
				}else{
					mcd=primer_numero;
				}
				
				
			}while(residuo != 0);
		}
		i++;
			aux = aux->getSiguiente(); // Hago que se avance al siguiente nodo de la lista doble.
		}							   // Fin while()
		cout <<"El maximo comun divisor es: "<<mcd<<endl;

		
	}
}
	void NodoDoble::MinimoComun(NodoDoble *nodoDoble, int contarDatos){
	NodoDoble *aux;	 // Declaro una variable puntero *aux de tipo NodoDoble que me va a servir para utilizarla como auxiiar que apunte a la lista doble para no trabajar directamente con la lista doble.
	aux = nodoDoble; // Apunto aux a pila,
	int mcm,primero_numero,residuo,i,producto;	
	i=1;
	if (aux == NULL) // Si la lista doble esta vacia, si aux apunta a NULL.
	{
		cout << "\nLista Doblemente Enlazada vacia." << endl;
	}
	else
	{
		while (aux->getSiguiente() != NULL) // Recorremos la lista Doble, mientras no sea el último nodo de la lista doble.
		{
			
			primero_numero=aux->getDato();
			if(i==1){
			mcm=primero_numero;
			producto=primero_numero;	
			}
			else{
				producto=mcm*primero_numero;
				do{
					residuo=mcm % primero_numero;
					mcm= primero_numero;
					primero_numero=residuo;
				}while(residuo !=0);
				mcm=producto/mcm;
			} 
			
			i++;
			aux = aux->getSiguiente(); // Hago que se avance al siguiente nodo de la lista doble.
		}							   // Fin while()
		cout <<"El minimo comun divisor es: "<<mcm<<endl;
}
	
	
}

	