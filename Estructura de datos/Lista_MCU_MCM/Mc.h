#include "Nodo.h"
#include "Lista.cpp"

class Mc {
public:
	
   int getResultado(void);
   void setResultado(int newResultado);
   virtual void MinimoComun(Lista lis, int tam);
   virtual void Maximocomun(); 
private:
	int valor;
    int resultado;
    Nodo *primero;
  	Nodo *siguiente;
	Nodo *actual;
		bool listaVacia(){
			return (this->primero==NULL);
		}
};