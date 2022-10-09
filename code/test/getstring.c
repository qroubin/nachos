#include "syscall.h"

void testGetString()
{
    char* s = "Hello world!";
    GetString(s, 13); //on récupère la chaine "Hello world!" et on définit la taille à 13 pour prendre en compte le \0
    PutString(s); //on affiche la chaine à l'écran
}

int main()
{
    testGetString();
    //Halt();
}