/*********
UFA - ESPE
AUTORES: Carlos Campoverde, Ronny Ibarra, José Imbaquinga, Alexander Bedón, César Loor, Josué Villavicencio, Samir Mideros.
FECHA DE CREACIÓN: 20/12/2022
FECHA DE MODIFICACIÓN: 20/12/2022 
GITHUB: Grupo-4-Estructura-de-datos-7999
 *********/

#include <iostream>
#include "Pila2.h"

using namespace std;

class Postfijo {
    private:
        static bool isOperator(char);
        static int precedence(char);
    public:
        Postfijo() = default;
        static string infijoAPostfijo(const string&);
};

string Postfijo::infijoAPostfijo(const string &cadena)
{
    
    string postfijo;
    Pila2<char> operadores;
    char operador;
  
    for(char c : cadena)
    {
        try
        {
            if(isOperator(c))
            {
                
                 while( !operadores.empty() &&
                        (operador = operadores.top()) != '(' &&
                        precedence(c) <= precedence(operador))
                 {
                     postfijo += operador;
                     operadores.pop();
                 }
                operadores.push(c);
            }
            else if(c == '(')
            {
                
                operadores.push(c);
            }
            else if(c == ')')
            {
                
                while((operador = operadores.top()) != '(')
                {
                    postfijo+=operador;
                    operadores.pop();
                }
                operadores.pop();

            }
            else
            {
                
                postfijo += c;
            }
        }
        catch(...)
        {
            cout << "La cadena no esta en el formato adecuado infijo" << endl;
            return "";
        }
    }
  
    while(!operadores.empty())
    {
        postfijo += operadores.top();
        operadores.pop();
    }
    return postfijo;
}

bool Postfijo::isOperator(char c)
{
    return precedence(c) != 0;
}

int Postfijo::precedence(char c)
{
    return (c == '+' || c == '-') ? 1 :
    (c == '*' || c == '/') ? 2 :
    (c == '^')? 3 : 0;
}


