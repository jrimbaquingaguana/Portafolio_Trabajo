#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		nodo *primero;
		nodo *actual;
		bool listaVacia(){
			return (this->primero==NULL);
		}
	public:
		Lista();
	void insertarNodo();
    void buscarNodo();
    void modificarNodo();
    void eliminarNodo();
    void desplegarLista();

    void busquedaSecuencial();
    void ordenamientoLista();
    void busquedaBinaria();

    void busqueda_binaria_recursiva(nodo *a, nodo *b, int valor_a_buscar);
    int distancia(nodo *a, nodo *b);
    void avanza(nodo *&p, int cantidad);

};
