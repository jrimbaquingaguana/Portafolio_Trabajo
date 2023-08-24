/*********
 * UFA - ESPE
 * Students:  Ronny Ibarra - José Imbaquinga
 * Created: jueves, 24 de febrero de 2023 19:00:40
 * Modified: viernes, 25 de febrero de 2023 2:02:48
 * Problem: Reina
 * Level: Level three
 * NRC: 7999
 *********/

#include <iostream>
#include <fstream>
#define DIMENSION 8
class Reina{
	private:
		bool **validar;
		char **tablero;
		std::fstream archivo;
		int contador;
		int n;
    public:
    	
        Reina(int n1);
		void encerarTablero();
        void crearArchivo();
        void bloquear(int x, int y);
        void mostrar();
        void quitarRelleno(int x,int y);
        void mostrarPantalla(int n);
        void mostrarEnConsola();
        void solucion(int x, int y, int n1);
        void solucionReinas();      
};
