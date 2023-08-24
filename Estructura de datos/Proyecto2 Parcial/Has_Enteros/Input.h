/*********
UFA - ESPE
AUTORES: José Imbaquinga, Alexander Bedón, Ronny Ibarra
FECHA DE CREACIÓN: 14/01/2023
FECHA DE MODIFICACIÓN: 15/01/2023 
GITHUB: Grupo-5-Estructura-de-datos-7999
 *********/
#ifndef INPUT_H
#define INPUT_H
#include <string>

class Input {

    public:
        int integerNumber(const char *instructionMessage, int charAmount);
        double realNumber(const char *instructionMessage, int charAmount);
        char *letters(const char *instructionMessage, int charAmount);
        char *claves(const char *instructionMessage, int charAmount);
        char *ET(const char *instructionMessage, int charAmount);
        static bool isValid(const std::string &idCard);
};

#endif
