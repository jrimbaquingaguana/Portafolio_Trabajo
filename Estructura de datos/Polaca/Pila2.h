/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/

#include <iostream>
#include <stdexcept>
#include "LDL.h"

using namespace std;

template<typename T>
class Pila2
{
public:
    Pila2()
    {

    }
    ~Pila2()
    {
        lista.clear();
    }

    bool empty() const;
    size_t size() const;
    const T& top() const;
    void push(const T& element);
    void pop();

private:
    LDL<T> lista;
};

template<typename T>
bool Pila2<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Pila2<T>::size() const
{
    return lista.size();
}

template<typename T>
const T& Pila2<T>::top() const
{
    if (empty())
    {
        throw runtime_error("Trying top() from empty stack.");
    }
    return lista.front();
}

template<typename T>
void Pila2<T>::push(const T& element)
{
    lista.push_front(element);
}

template<typename T>
void Pila2<T>::pop()
{
    if (empty())
    {
        throw runtime_error("Trying pop() from empty stack.");
    }
    lista.pop_front();
}

