/*********
UFA - ESPE
AUTORES: José Imbaquinga, Alexander Bedón, Ronny Ibarra
FECHA DE CREACIÓN: 14/01/2023
FECHA DE MODIFICACIÓN: 15/01/2023 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#pragma once
#include "Hash.h"
using namespace std;
void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    if (table[index].size()>=3){
        table[BUCKET].push_back(key);
    }else{
    table[index].push_back(key);
    }
}

void Hash::deleteItem(int key)
{

  int index = hashFunction(key);

  list <int> :: iterator i;
  for (i = table[index].begin();
           i != table[index].end(); i++) {
    if (*i == key)
      break;
  }

  if (i != table[index].end())
    table[index].erase(i);
}

void Hash::displayHash() {
  for (int i = 0; i < BUCKET+1; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;
    cout << endl;
  }
}

void Hash::BuscaHash(int val) {
  for (int i = 0; i < BUCKET+1; i++) {
    for (auto x : table[i])
      if(x==val){
        cout<<"Num: "<<x<<" Encontrado en: "<<i<<endl;
        break;
      }
  }
}


