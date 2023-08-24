#include "Matrices.cpp" 

int main(){
	
	Matrices<int> matriz;
	int contador;
	char datoEntero1[30],datoEntero2[30],datoEntero3[30],datoEntero4[30], *datoFlotante, *datoReal;
	int valorEntero1=0, valorEntero2=0, valorEntero3=0, valorEntero4=0;
	double valorReal=0.d;
	
	strcpy(datoEntero1,ingresarDatosEnteros("Escriba el numero de filas para A: "));
	valorEntero1=atoi(datoEntero1);
	matriz.setFa(valorEntero1);
	
	strcpy(datoEntero2,ingresarDatosEnteros("\nEscriba el numero de columnas para A: "));
	valorEntero2=atoi(datoEntero2);
	matriz.setCa(valorEntero2);
	
	matriz.setFb(valorEntero1);
	
	
	matriz.setCb(valorEntero2);
	
	matriz.encerarMatriz();
	
	
	

	if(matriz.getCa()==matriz.getFb()){	
	cout<<"\n Ingrese el numero de veces a multplicar"<<endl;
	cin>>contador;
		int i,j,k;
		int multiplicado=1;
	while(true){
	 if(j==0){
	 
		matriz.llenarMatrizA();
		
		
		matriz.setMat2(matriz.getMat1());
		
		//Realizamos el calculo
	
	//	matriz.multiplicacionMatrices(matriz.getMat1(),matriz.getMat2(),matriz.getMatR());
		matriz.multiplicacionRecursivaMatrizA(matriz.getMat1(),matriz.getMat2(),matriz.getMatR(),i);
		cout<<endl;                                                            
		//imprimimos la matriz resultante
		
		matriz.imprimirMatriz(matriz.getMatR(),"R");
		 
		j++;   
		multiplicado++;
}
	else if(j>0 && j<contador){
		cout <<"\n La matriz se multiplico "<<multiplicado<<" veces"<<endl;
		matriz.setMat1(matriz.getMat1());
		matriz.setMat2(matriz.getMatR());
		matriz.multiplicacionRecursivaMatrizA(matriz.getMat1(),matriz.getMat2(),matriz.getMatR(),i);

		cout<<endl;                                                            
		matriz.imprimirMatriz(matriz.getMatR(),"R");
		multiplicado++;


		j++;
		
	}
	else if(j==contador)
	break;
	}
	
	
}
	

	else{
		cout<<"\n No se puede multplicar"<<endl;
	}

	return 0;
}