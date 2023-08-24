/*********
UFA - ESPE
AUTORES: José Imbaquinga, Alexander Bedón, Ronny Ibarra
FECHA DE CREACIÓN: 14/01/2023
FECHA DE MODIFICACIÓN: 15/01/2023 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#pragma once
#include<bits/stdc++.h>
using namespace std;
class Hash
{
    int BUCKET;
    list<int> *table;
public:
    Hash(int V);


    void insertItem(int x);


    void deleteItem(int key);


    int hashFunction(int x) {
        return (x % BUCKET);
    }

    void displayHash();

    void BuscaHash(int val);
};
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET+1];
}
