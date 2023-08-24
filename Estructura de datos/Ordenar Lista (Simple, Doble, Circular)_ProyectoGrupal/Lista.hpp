/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#include<stdio.h>
#include<fstream>
#include<sstream>
#include "Nodo.cpp"
#include "ValidaDatos.cpp"
#include <iostream>

using namespace std;


//------------------
template<typename T>
class Lista
{
private:

    Nodo<T> * nodoRaiz;
    Nodo<T> * nodoActual;
    ValidaDatos * valida;

public:
    Lista();
    void insertar(T * nuevoDato);
    void listar();
    bool vacio();
    void borrar();
    void borrarInicial();
    bool buscarExistente(char * cedula);
    void shellSort(bool tipo);


    void leerArchivo();
    void escribirArchivo();

};

template<typename T>
void Lista<T>::shellSort(bool tipo)
{
    Nodo<T> * q;
    Nodo<T> * p;

    int cont = 0;
    T * aux;

    q = this->nodoRaiz;
    while (q != NULL)
    {
        q = q->getSiguiente();
        cont++;
    }

    int k = cont / 2;
    while (k > 0)
    {
        q = this->nodoRaiz;

        for (int i = 0; i < k; i++)
        {
            q = q->getSiguiente();
        }

        p = this->nodoRaiz;
        while (q != NULL)
        {
            bool intercambiar = false;
            if (tipo == true){
                if (strcmp(p->getDato()->getCedula(),q->getDato()->getCedula()) > 0){
                    intercambiar = true;
                }
            }else{
                if (strcmp(p->getDato()->getNombre(),q->getDato()->getNombre()) > 0){
                    intercambiar = true;
                }
            }

            if (intercambiar == true){
                aux = new T(false);
                aux->setCedula(p->getDato()->getCedula());
                aux->setNombre(p->getDato()->getNombre());

                p->getDato()->setCedula(q->getDato()->getCedula());
                p->getDato()->setNombre(q->getDato()->getNombre());

                q->getDato()->setCedula(aux->getCedula());
                q->getDato()->setNombre(aux->getNombre());
            }

            p = p->getSiguiente();
            q = q->getSiguiente();
        }
        k = k / 2;
    }

    if (tipo == true){
        cout<<"\nShell Sort por cedula ejecutado!!!"<<endl;
    }else{
        cout<<"\nShell Sort por nombre ejecutado!!!"<<endl;
    }

}

template<typename T>
bool Lista<T>::buscarExistente(char * cedula)
{
    bool respuesta = false;
    if (valida->validarCedula(cedula) == 1)
    {
        Nodo<T> * auxiliar = this->nodoRaiz;
        while(auxiliar != NULL)
        {
            if (strcmp(auxiliar->getDato()->getCedula(),cedula) == 0)
            {
                respuesta = true;
                break;
            }
            auxiliar = auxiliar->getSiguiente();
        }
    }
    return respuesta;
}

template<typename T>
void Lista<T>::borrar()
{
    char cedula[11];
    strcpy(cedula, valida->devuelveCharNumeros("Ingrese cedula:"));
    cout<<endl;

    Nodo<T> * auxiliar = this->nodoRaiz;
    Nodo<T> * auxiliarAnterior = NULL;
    while(auxiliar != NULL)
    {
        if (strcmp(auxiliar->getDato()->getCedula(),cedula) == 0)
        {
            if (auxiliar == this->nodoRaiz)
            {
                this->nodoRaiz = auxiliar->getSiguiente();
            }
            else
            {
                auxiliarAnterior->setSiguiente(auxiliar->getSiguiente());
            }
            cout<<"\nDato Eliminado!!!"<<endl;
            break;
        }
        auxiliarAnterior = auxiliar;
        auxiliar = auxiliar->getSiguiente();
    }
}

template<typename T>
void Lista<T>::borrarInicial()
{
    char inicial[1];
    strcpy(inicial, valida->devuelveUnSoloChar("Ingrese inicial apellido:"));
    cout<<endl;

    bool eliminados = false;
    Nodo<T> * auxiliar = this->nodoRaiz;
    Nodo<T> * auxiliarAnterior = NULL;
    while(auxiliar != NULL)
    {
        char apellido[20];
        strcpy(apellido,auxiliar->getDato()->getApellido());

        if (apellido[0] == inicial[0])
        {
            if (auxiliar == this->nodoRaiz)
            {
                this->nodoRaiz = auxiliar->getSiguiente();
            }
            else
            {
                auxiliarAnterior->setSiguiente(auxiliar->getSiguiente());
            }
            eliminados = true;
        }
        auxiliarAnterior = auxiliar;
        auxiliar = auxiliar->getSiguiente();
    }

    if (eliminados)
    {
        cout<<"\nDato Eliminado!!!"<<endl;
    }
}


template<typename T>
void Lista<T>::leerArchivo()
{
    ifstream archivo("Archivo.txt");
    if (archivo.is_open())
    {
        string linea;
        char delimitador = ';';

        while (getline(archivo, linea))
        {
            stringstream stream(linea);
            string cedula_, nombre_, apellido_;

            getline(stream, cedula_, delimitador);
            getline(stream, nombre_, delimitador);
            getline(stream, apellido_, delimitador);

            T * nuevoDato = new T(const_cast<char*>(cedula_.c_str()),const_cast<char*>(nombre_.c_str()),const_cast<char*>(apellido_.c_str()));
            insertar(nuevoDato);
        }
        archivo.close();
        cout<<"\nDatos Cargados!!!"<<endl;
    }
    else cout<<"\nError al abrir archivo"<<endl;
}

template<typename T>
void Lista<T>::escribirArchivo()
{
    ofstream archivo("Archivo.txt" );
    if (archivo.is_open())
    {
        Nodo<T> * auxiliar = this->nodoRaiz;
        while(auxiliar != NULL)
        {
            archivo<<auxiliar->getDato()->getCedula()<<";"<<auxiliar->getDato()->getNombre()<<";"<<auxiliar->getDato()->getApellido()<<endl;
            auxiliar = auxiliar->getSiguiente();
        }
        cout<<"\nSe ha escrito un Archivo.txt"<<endl;
    }
    else cout<<"\nError de apertura del archivo."<<endl;
}


template<typename T>
Lista<T>::Lista()
{
    this->nodoRaiz = NULL;
    this->nodoActual = NULL;
    this->valida = new ValidaDatos();
}

template<typename T>
bool Lista<T>::vacio()
{
    return (this->nodoRaiz == NULL);
}

template<typename T>
void Lista<T>::insertar(T * nuevoDato)
{
    bool adicionales = false;
    if (nuevoDato == NULL)
    {
        adicionales = true;
        nuevoDato = new T();
    }
    if (nuevoDato->getRegistra())
    {
        if (!buscarExistente(nuevoDato->getCedula()))
        {
            if (adicionales)
            {
                nuevoDato->getRegistraAdicionales();
            }
            Nodo<T> * nodo = new Nodo<T>(nuevoDato, NULL);
            if (vacio())
            {
                this->nodoRaiz = nodo;
            }
            else
            {
                this->nodoActual->setSiguiente(nodo);
            }
            this->nodoActual = nodo;
            if (adicionales)
            {
                cout<<"\nDatos Registrados!!!"<<endl;
            }
        }
        else
        {
            cout<<"\nNumero de Cedula Ya Existe!!"<<endl;
        }
    }
    else
    {
        cout<<"\nDatos No Registrados!!!"<<endl;
    }
}

template<typename T>
void Lista<T>::listar()
{
    Nodo<T> * auxiliar = this->nodoRaiz;
    while(auxiliar != NULL)
    {
        auxiliar->getDato()->imprimir();
        auxiliar = auxiliar->getSiguiente();
    }
}