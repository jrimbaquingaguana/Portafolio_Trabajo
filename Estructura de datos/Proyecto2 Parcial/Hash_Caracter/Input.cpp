#include "Input.h"
#include <iostream>
#include <conio.h>


int Input::integerNumber(const char *instructionMessage, int charAmount) {
    printf("\n%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    char *numbers = new char[charAmount + 1]{};
    char *iterator{numbers};
    char keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0') {

        if (keyPressed >= '0' && keyPressed <= '9') {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

char* Input::letters(const char *instructionMessage, int charAmount) {
    printf("\n%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[charAmount + 1]{};
    char *iterator{string};
    char keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' )  {

        if ((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z') || (keyPressed == SPACE_KEY && iterator <= string)) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

char  *ingresocaracteres(char *msj)
{
    char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msj);
	while ((c=getch())!=13){
		if((c>='a'&& c<='z') && i<1){
			printf("%c",c);
			dato[i++]=c;
		}else if(c==8){
			dato[i]=0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}
		
	}
	dato[i]='\0';//fin del while
	return dato;
}