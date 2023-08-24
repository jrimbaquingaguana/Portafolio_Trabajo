#include "Alfil.h"

void Alfil::encerar(){
	for(int i=0;i<DIMENSION;i++){
		tableroAlfil[i]=new int[DIMENSION];
		for(int j=0;j<DIMENSION;j++){
			*(*(tableroAlfil+i)+j)=0;
		}
	}
}

int** Alfil::getTableroAlfil(){
	return tableroAlfil;	
}

Alfil::Alfil(){
		//nA=n;
		tableroAlfil=new int *[DIMENSION];
		encerar();
}

bool Alfil::validarMovimiento(int x, int y, int n){
	
	for (int i = 0; i < x; i++)
    {
        if (*(*(tableroAlfil+i)+y) == 1)
        {
            return false;
        }
    }

    int i, j;
    for (i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (*(*(tableroAlfil+i)+j) == 1)
        {
            return false;
        }
    }

    for (i = x, j = y; i >= 0 && j < n; i--, j++)
    {
        if (*(*(tableroAlfil+i)+j) == 1)
        {
            return false;
        }
    }

    return true;
}

bool Alfil::solucionAlfil(int x, int n,int alfiles){
	nA=alfiles;
	if (nA == 0)
    {
        return true;
    }

    for (int y = 0; y < n; y++)
    {
        if (validarMovimiento(x, y, n))
        {  
            *(*(tableroAlfil+x)+y) = 1;
            if (solucionAlfil(x + 1, n, nA - 1))
            {
                return true;
            }
            *(*(tableroAlfil+x)+y) = 0;
        }
    }
    return false;
}