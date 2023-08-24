#include <iostream>
#include <graphics.h>
#include "Alfil.cpp"
#include <windows.h>
#pragma comment(lib,"graphics.lib")
using namespace std;
int main(){
	int filaAlfil,columnaAlfil;
	cout<<"Ingrese la posicion del arfil(fila):"<<endl;
	cin>>filaAlfil;
	cout<<"Ingrese la posicion del afil(columna):"<<endl;
	cin>>columnaAlfil;
	Alfil obj;
	obj.ModoGrafico(filaAlfil,columnaAlfil);
	return 0;

}
