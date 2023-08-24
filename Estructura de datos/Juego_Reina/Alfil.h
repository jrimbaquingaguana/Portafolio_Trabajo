#include <iostream>
#define DIMENSION 8
class Alfil{
	public:
		bool validarMovimiento(int,int,int);
		bool solucionAlfil(int,int,int);
		Alfil();
		void encerar();
		int** getTableroAlfil();
		friend class menu;
		int **tableroAlfil;
	private:
		int nA;
};