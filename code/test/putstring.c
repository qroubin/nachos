#include "syscall.h"

void testPutString(char* c)
{
    PutString(c);   //on affiche la chaine à l'écran
}

int main()
{
    testPutString("Hello world");   //on veut afficher "Hello world"
    //Halt();
}