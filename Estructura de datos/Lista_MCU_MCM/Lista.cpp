/***********************************************************************
 * UFA-ESPE
 * Autores: Ronny Ibarra-Jose Imbaquinga
 * Modificacion: Martes, 13 de noviembre 
 * Purpose: Listas, realizar el buscar, eliminar, inserta cola, mostrar cola
 *Nivel: Tercero           
 *NRC:7999
 ***********************************************************************/
#include "Lista.h"
using namespace std;
Lista::Lista(){
	this->primero=NULL;
	this->actual=NULL;
}

void Lista::insertar(int val){
	Nodo *nuevo=new Nodo(val);
	if (listaVacia()){
		this->primero=nuevo;
	}
	else{
		this->actual->siguiente=nuevo;
	}
	this->actual=nuevo;
}

void Lista::mostrarLista(){
	Nodo *tmp=this->primero;
	while(tmp){
		cout<<tmp->valor<<"-->";
		tmp=tmp->siguiente;
	}
	cout<<"NULL";
}

void Lista::buscar(int buscar){
	bool afirmar=false;
	Nodo *actual;
	actual = this->primero;
	int cont=0, veces=0;
	while(actual !=NULL){
		cont++;
		if(actual->valor==buscar){
			afirmar=true;
			cout<<"El elemento "<<buscar<<" Se encuentra en la lista en la posicion: "<<cont<<endl;
			veces++;

		}
		actual=actual->siguiente;
		
	}
	if(afirmar==true){
		if(veces==1){
			cout<<"El elemento que busca se encontro  "<<veces<<" vez"<<endl;	
		}else{
			cout<<"El elemento que busco se encontro  "<<veces<<" veces"<<endl;	
		}	
	}
	else {
		cout<<"El elemento que desea buscar "<<buscar<<" No se encuentra en la lista"<<endl;
	}
	
	
}
void Lista::eliminar(int elemento){
	
		Nodo *aux_borrar;
		Nodo *anterior =NULL;
		aux_borrar=this->primero;
		
		while (aux_borrar !=NULL && aux_borrar->valor !=elemento){
			anterior=aux_borrar;
			aux_borrar=aux_borrar->siguiente;
		}
		
		if(aux_borrar==NULL){
			cout<<"\nElemento no encontrado"<<endl;
		}else if (anterior==NULL){
			primero=primero->siguiente;
			delete aux_borrar;
		}else{
			anterior->siguiente=aux_borrar->siguiente;
			delete aux_borrar;
		}
	
}



void Lista::imprimirCola(Lista lis,int tam){
	Nodo *actual;
	actual = this->primero;
	cout<<"\nNULL-->";
	int cont=0;
	Lista list;
	while(cont<tam){
		lis.buscarElemento(tam);
		tam= tam-1;;
		
	}
	cout<<actual->valor<<" ";
}

void Lista::insertarCola(int num){
	
	Nodo *nuevo=new Nodo(num);
	
	nuevo->siguiente=NULL;
	if(listaVacia()){
		this->primero=nuevo;
	}
	else{
		Nodo *aux= this->primero;
		while(aux->siguiente !=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;
	}
	
}

void Lista::buscarElemento(int pos){
	Nodo *actual;
	bool afirmar=false;
	actual = this->primero;
	int cont=0;
	while(actual !=NULL  ){
		
		if(cont==pos){
			afirmar=true;
			cout<<actual->valor<<" --> ";
		}
		cont++;
		actual=actual->siguiente;	
	}
	
}

int Lista::getResultado(void){
	return resultado;
}

void Lista::setResultado(int newResultado){
	resultado=newResultado;
}

void Lista::maxiComun(){
	Nodo *tmp1=this->primero;
	int primer_numero,segundo_numero,acumulador,veces;
	acumulador=1; 
	int mcd,residuo;     
	primer_numero=tmp1->valor;   
	Lista list;  
	int i=1;
	while(tmp1){
	primer_numero=tmp1->valor;

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
		tmp1=tmp1->siguiente;
		i++;

	}
	   
	   cout<<"El maximo comun divisor es:"<<mcd<<endl;
}
                     
void Lista::MinimoComun(){
		Lista list;  
		Nodo *tmp1=this->primero;
		int primero_numero;
		primero_numero=tmp1->valor;
		int i=1;
		int mcm,numero,producto,residuo;
		while(tmp1){
			primero_numero=tmp1->valor;
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
			tmp1=tmp1->siguiente;
			
			i++;
		}
		cout <<"El minimo comun multiplo es: "<<mcm<<endl;
}
