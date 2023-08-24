#include "Lista.h"
using namespace std;
Lista::Lista(){
	this->primero=NULL;
	this->actual=NULL;
}

void Lista::insertarNodo(){
	nodo* nuevo = new nodo();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevo->dato;

	if(primero == NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	cout << "\n Nodo Ingresado\n\n";
}

void Lista::buscarNodo(){
	nodo* actual = new nodo();

	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar: ";
	cin >> nodoBuscado;
	if(primero != NULL){

		while(actual != NULL && encontrado != true){

			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado\n\n";
				encontrado = true;
			}

			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Lista::modificarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodoBuscado;
	if(primero != NULL){

		while(actual != NULL && encontrado != true){

			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado";
				cout << "\n Ingrese el Nuevo dato para este Nodo: ";
				cin >> actual->dato;
				encontrado = true;
			}

			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Lista::eliminarNodo(){
	nodo* actual = new nodo();
	actual = primero;
	nodo* anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado = 0;
	cout << " Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscado;
	if(primero != NULL){

		while(actual != NULL && encontrado != true){

			if(actual->dato == nodoBuscado){
				cout << "\n Nodo con el dato " << nodoBuscado << " Encontrado\n\n";

				if(actual == primero){
					primero = primero->siguiente;
				}else if(actual == ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
				}

				cout << "\n Nodo ELiminado con exito\n\n";

				encontrado = true;
			}

			anterior = actual;
			actual = actual->siguiente;
		}
		if(!encontrado){
			cout << "\n Nodo No Encontrado\n\n";
		}
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Lista::desplegarLista(){
	nodo* actual = new nodo();
	actual = primero;
	if(primero != NULL){

		while(actual != NULL){
			cout << " " << actual->dato  << endl;
			actual = actual->siguiente;
		}

	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Lista::busquedaSecuencial(){
    int valorObjetivo = 0;
    cout<<"Ingrese el valor a buscar:";
    cin>>valorObjetivo;

    nodo* actual = new nodo();
	actual = primero;
    if(primero != NULL){
        bool existe = false;
        int indice = -1;
		while(actual != NULL){
            indice++;
            if (actual->dato == valorObjetivo){
                existe = true;
                break;
            }
			actual = actual->siguiente;
		}

        if (existe){
            cout<<"Elemento encontrado posicion: "<<indice<<endl;
        }else{
            indice = -1;
            cout<<"Elemento no existe posicion: "<<indice<<endl;
        }
	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Lista::ordenamientoLista(){
    nodo* actual = new nodo();
	actual = primero;
	nodo* siguiente = new nodo();
	int auxiliar = -1;

	if(primero != NULL){

		while(actual != NULL){
            siguiente = actual->siguiente;
            while (siguiente != NULL){
                if (actual->dato > siguiente->dato){
                    auxiliar = actual->dato;
                    actual->dato = siguiente->dato;
                    siguiente->dato = auxiliar;
                }
                siguiente = siguiente->siguiente;
            }
			actual = actual->siguiente;
		}

	}else{
		cout  << "\n La Lista se Encuentra Vacia\n\n";
	}
}

void Lista::busquedaBinaria(){

    int valorObjetivo = 0;
    cout<<"Ingrese el valor a buscar:";
    cin>>valorObjetivo;

    nodo* actual = new nodo();
	actual = primero;
	nodo* ultimo = new nodo();

	while(actual != NULL){
        ultimo = actual;
	    actual = actual->siguiente;
	}

    ordenamientoLista();
    busqueda_binaria_recursiva(primero, ultimo, valorObjetivo);
}

void Lista::busqueda_binaria_recursiva(nodo *a, nodo *b, int valor_a_buscar)
{
    if (a->dato == valor_a_buscar)
    {
        cout<<"Elemento encontrado"<<a->dato<<endl;
    }
    else
    {
        int punto_medio = distancia(a, b) / 2;
        if (punto_medio)
        {
            nodo *mitad = a;
            avanza(mitad, punto_medio);

            cout<<"Mitad -> "<<mitad->dato<<endl;

            if (valor_a_buscar > mitad->dato)
            {
                busqueda_binaria_recursiva(mitad, b, valor_a_buscar);
            }
            else
            {
                busqueda_binaria_recursiva(a, mitad, valor_a_buscar);
            }
        }
        else{
            if (punto_medio == 0){
                if (b->dato == valor_a_buscar){
                    cout<<"Elemento encontrado"<<b->dato<<endl;
                }else{
                    cout<<"Elemento no existe"<<endl;
                }
            }
            else{
                busqueda_binaria_recursiva(b, b, valor_a_buscar);
            }
        }
    }
}



int Lista::distancia(nodo *a, nodo *b)
{
    int resultado = 0;
    for (; a && a != b; a = a->siguiente)
        ++resultado;
    if (a)
        return resultado;
    return -1;
}

void Lista::avanza(nodo *&p, int cantidad)
{
    for (; p && cantidad; --cantidad)
        p = p->siguiente;
}

