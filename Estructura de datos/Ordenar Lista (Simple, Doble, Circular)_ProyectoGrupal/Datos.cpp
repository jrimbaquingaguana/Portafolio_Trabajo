/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#include <iostream>
#include "ValidaDatos.cpp"

using namespace std;

class Datos
{
private:
    char cedula[11];
    char nombre[20];
    char apellido[20];
    bool registra;
    ValidaDatos * valida;

public:
    Datos();
    Datos(bool vacio);
    Datos(char * cedula,char * nombre,char * apellido);
    void imprimir();
    bool getRegistra();
    void getRegistraAdicionales();

    char * getCedula();
    char * getNombre();
    char * getApellido();

    void setCedula(char * cedula);
    void setNombre(char * nombre);


};

void Datos::setCedula(char * cedula){
    strcpy(this->cedula,cedula);
}

char * Datos::getCedula()
{
    return cedula;
}
void Datos::setNombre(char * nombre){
    strcpy(this->nombre,nombre);
}
char * Datos::getNombre()
{
    return nombre;
}
char * Datos::getApellido()
{
    return apellido;
}

bool Datos::getRegistra()
{
    return registra;
}

void Datos::imprimir()
{
    cout<<"-----------------------------------"<<endl;
    cout<<"Cedula:"<<cedula<<endl;
    cout<<"Nombre:"<<nombre<<endl;
    cout<<"Apellido:"<<apellido<<endl;
    cout<<"-----------------------------------"<<endl;
}

Datos::Datos(char * cedula,char * nombre,char * apellido)
{
    registra = true;
    strcpy(this->cedula,cedula);
    strcpy(this->nombre,nombre);
    strcpy(this->apellido,apellido);
}

Datos::Datos()
{
    valida = new ValidaDatos();
    registra = true;
    strcpy(cedula, valida->devuelveCharNumeros("Ingrese cedula:"));
    cout<<endl;
    if (valida->validarCedula(cedula) != 1)
    {
        registra = false;
    }
}

Datos::Datos(bool vacio){
}

void Datos::getRegistraAdicionales(){
    strcpy(nombre, valida->devuelveChar("Ingrese nombre:"));
    cout<<endl;
    strcpy(apellido, valida->devuelveChar("Ingrese apellido:"));
    cout<<endl;
}

