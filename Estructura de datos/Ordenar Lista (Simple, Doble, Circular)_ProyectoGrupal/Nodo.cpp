/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/

#include "Nodo.h"


template<typename T>
Nodo<T>::Nodo(T * dato, Nodo * siguiente)
{
    this->dato = dato;
    this->siguiente = siguiente;
}

template<typename T>
T * Nodo<T>::getDato()
{
    return this->dato;
}

template<typename T>
Nodo<T> * Nodo<T>::getSiguiente()
{
    return this->siguiente;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo<T> * siguiente)
{
    this->siguiente = siguiente;
}

