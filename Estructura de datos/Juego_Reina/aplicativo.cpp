/*********
 * UFA - ESPE
 * Students:  Ronny Ibarra - José Imbaquinga
 * Created: jueves, 24 de febrero de 2023 19:00:40
 * Modified: viernes, 25 de febrero de 2023 2:02:48
 * Problem: Reina
 * Level: Level three
 * NRC: 7999
 *********/

#include "menu.cpp"

int main(int argc, char **argv){
	system("cls");
				int n;
    			IngresoDatos in;
				n=8;
    			std::cout<<'\n';
				Reina *obj=new Reina(n);
				obj->solucionReinas();
    			//obj->mostrarPantalla(n);
    			obj->mostrarEnConsola();
				std::cout<<"\nSe creo el archivo txt"<<std::endl;
				system ("pause");
				
	return 0;
}
