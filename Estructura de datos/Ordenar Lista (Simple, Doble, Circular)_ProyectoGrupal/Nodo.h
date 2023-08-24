/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/

template<typename T>
class Nodo
{
private:
    T * dato;
    Nodo<T> * siguiente;

public:

    Nodo(T * dato, Nodo * siguiente);
    T * getDato();
    Nodo<T> * getSiguiente();
    void setSiguiente(Nodo<T> * siguiente);

};