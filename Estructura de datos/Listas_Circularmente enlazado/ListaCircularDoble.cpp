/***********************************************************************
 * UFA-ESPE
 * Autores: Ronny Ibarra-Jose Imbaquimga
 * Modificacion: Martes, 08 de nombre de 2022 21:17:59
 * Purpose: Areas de las figuras
 *Nivel: Tercero           
 *NRC:7999
 ***********************************************************************/
#include "ListaCircularDoble.h"
using namespace std;
ListaCircularDoble::ListaCircularDoble(){
	this->primero=NULL;
	this->ultimo=NULL;
}
void ListaCircularDoble::insertar(int val){
	Nodo *nuevo = new Nodo(val);
	if(listaVacia()){
		this->primero=nuevo;
		this->primero->siguiente=primero;
		this->primero->anterior=primero;
		this->ultimo=this->primero;
		
	}else{
		this->ultimo->siguiente=nuevo;
		nuevo->siguiente=this->primero;
		nuevo->anterior=this->ultimo;
		this->ultimo=nuevo;
		this->primero->anterior=ultimo;
	}
}
void ListaCircularDoble::mostrarLista(){
	Nodo *aux = this->primero;
	int posicion=1;
	if(this->primero !=NULL){
		do{
			cout<<posicion<<"-> "<<aux->valor<<"\t";
			aux = aux->siguiente;
			posicion++;
		}while(aux!=this->primero);
	}else{
		cout<<"La lista esta vacia\n";
	}
}
void ListaCircularDoble::buscar(int elementoBuscar){
	int cont=0, veces=0;

	bool afirmar=false;
	Nodo *actual;
	actual = this->primero;
	do{
		cont++;
		if(actual->valor==elementoBuscar){
			afirmar=true;
			veces++;
			cout<<"El elemento "<<elementoBuscar<<" Si se encuentra en la lista en la posicion: "<<cont<<endl;
		}
		actual=actual->siguiente;
		
	}while(actual !=this->primero&&afirmar!= true);
	if(afirmar==true){
		if(veces==1){
			cout<<"El numero se encontro  "<<veces<<" vez"<<endl;	
		}else{
			cout<<"El numero se encontro "<<veces<<" veces"<<endl;	
		}	
	}
	else {
		cout<<"El elemento que ingreso "<<elementoBuscar<<" No se encuentra en la lista"<<endl;
	}
	
	
}
void ListaCircularDoble::eliminar(int elementoBuscar){
bool afirmar=false;
	Nodo *actual;
	actual = this->primero;
	Nodo *antes;
	antes =  NULL;
	int cont=0;
	do{
		cont++;
		if(actual->valor==elementoBuscar){
			cout<<"\n El elemento que ingreso "<<elementoBuscar<<" \n Si se encuentra en la lista en la posicion: "<<cont<<endl;
			if(actual==this->primero){
				this->primero = this->primero->siguiente;
				this->primero->anterior = this->ultimo;
				this->ultimo->siguiente = this->primero;
			}else if(actual==this->ultimo){
				this->ultimo = antes;
				this->ultimo->siguiente=this->primero;
				this->primero->anterior=this->ultimo;
			}else{
				antes->siguiente = actual->siguiente;
				actual->siguiente->anterior = antes;
			}
			cout<<"\nElemento se a eliminado con exito\n";
			afirmar = true;
		}
		antes=actual;
		actual=actual->siguiente;
		
	}while(actual !=this->primero&&afirmar!= true);
	if(!afirmar){
		cout<<"\n Elemento no encontrado\n";
	}
}
void ListaCircularDoble::maxiComun(){
	Nodo *aux = this->primero;

	int primer_numero,segundo_numero,acumulador,veces;
	acumulador=1; 
	int mcd,residuo;     
	ListaCircularDoble list;  
	int i=1;
	
	
	if(this->primero !=NULL){
		do{
			primer_numero=aux->valor; 

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
			aux=aux->siguiente;
			i++;
			
		}while(aux!=this->primero);		
	   cout<<"El maximo comun divisor es:"<<mcd<<endl;

	}else{
		cout<<"La lista esta vacia\n";
	}

	   
	      
}
                   
void ListaCircularDoble::MinimoComun(){
		ListaCircularDoble list;  
		Nodo *aux=this->primero;
		int primero_numero;
		primero_numero=aux->valor;
		int i=1;
		int mcm,numero,producto,residuo;	
	if(this->primero !=NULL){
		do{
			primero_numero=aux->valor;
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
			aux = aux->siguiente;
			
		}while(aux!=this->primero);
		cout <<"El minimo comun multiplo es: "<<mcm<<endl;

	}
	else{
		cout<<"La lista esta vacia\n";	
}
}