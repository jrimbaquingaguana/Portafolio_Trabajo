//#include "HashTable.cpp"
#include <iostream>
#include <list>
using namespace std;

class HashTable{
	private:
		static const int gruposHash = 10;
		list<pair<int, string>> tabla[gruposHash];
	
	public:
		bool estaVacio();
		int hashFuncion(int clave);
		void insertar(int clave, string valor);
		void eliminar(int clave);
		void buscar(int clave);
		void imprimir();
		char* validarEnteros(char const *msj);
   double validarEntero();
   char* ingresocaracteres(char *msj);
};

bool HashTable::estaVacio(){
	int sum{};
	for (int i{}; i < gruposHash; i++){
		sum += tabla[i].size();
	}
	
	if (!sum){
		return true;
	}
	return false;
}

int HashTable::hashFuncion(int clave){
	return clave % gruposHash;
}

void insertar(){};
void eliminar(){};
void buscar(){};
void imprimir(){};
