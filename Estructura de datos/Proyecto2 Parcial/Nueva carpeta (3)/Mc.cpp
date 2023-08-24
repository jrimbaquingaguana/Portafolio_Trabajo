#include <iostream>
#include "Mc.h"


using namespace std;

int Mc::getResultado(void){
	return resultado;
}

void Mc::setResultado(int newResultado){
	resultado=newResultado;
}

void Mc::Maximocomun(){
	Nodo *tmp=this->primero;
	int casa,casa1,casa2;
	while(tmp){
		casa=tmp->valor;
		cout<<casa<<"-->";
		tmp=tmp->siguiente;
		casa1=tmp->valor;
		cout<<casa1<<endl;
		casa2=casa1+casa;
		cout<<"EL resultado es casa: "<<casa2<<endl;

		
	}
	cout<<"NULL";
}

void Mc::MinimoComun(Lista lis, int tam){
}