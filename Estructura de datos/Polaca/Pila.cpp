/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/
#include "Pila.h"
#pragma once
Pila::Pila()
{
	this->primero=NULL;
	this->actual=NULL;
} 
bool Pila::getPilaVacia()
{
	return (this->primero==NULL);
}

void Pila::setPrimero(Nodo *first)
{
	primero = first;
}
void Pila::setActual(Nodo *now)
{
	actual = now;
}
Nodo *Pila::getPrimero()
{
	return primero;
}
Nodo *Pila::getActual()
{
	return actual;
}


void Pila::push(string valor)
{
	if(getPilaVacia())
	{
		Nodo *nuevo=new Nodo(valor,NULL);
		nuevo->setSiguiente(this->primero);
		setPrimero(nuevo);
		setActual(nuevo);
	}else
	{
		Nodo *nuevo=new Nodo(valor,NULL);
		nuevo->setSiguiente(this->primero);
		nuevo->setIndex(contar()+1);
		setPrimero(nuevo);
		
		
		
	
	}
	
}

void Pila::pop()
{
	if(getPilaVacia())
	{
		cout<<"\nNo se puede eliminar elementos de una pila sin objetos."<<endl;
	}
	else
	{
		Nodo *nodoAuxiliar = primero->getSiguiente();
		delete primero;
		setPrimero(nodoAuxiliar);
	}
}

void Pila::mostrar()
{
	Nodo *aux=this->primero;
	while(aux!=NULL)
	{
		cout<<"Pos "<<aux->getIndex()<<": "<<aux->getValor()<<endl;
		aux=aux->getSiguiente();
	}
}

void Pila::buscar(string n)
{
	Nodo *nodoAuxiliar = primero;
	bool encontrado=false;
	for(int x=0;x<=contar();x++)
    {
		if(nodoAuxiliar->getValor()==n)
		{
			encontrado=true;
			break;
		}
        nodoAuxiliar = nodoAuxiliar->getSiguiente();
    }
	if(encontrado)
	{
		cout<<"\nEl valor es: "<<nodoAuxiliar->getValor()<<endl;
		printf("\nEl indice del valor encontrado es: %d\n",nodoAuxiliar->getIndex());
	} else
	{
		cout<<"\nNo se ha encontrado el valor ingresado."<<endl;
	}
}

int Pila::contar()
{
	int i=0;
	Nodo *nodoAuxiliar = primero;
	while(nodoAuxiliar->getSiguiente()!=NULL)
    {
        nodoAuxiliar = nodoAuxiliar->getSiguiente();
		i++;
    }
	setActual(nodoAuxiliar);
	return i;
}
