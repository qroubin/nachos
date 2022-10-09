#include "syscall.h"

void testGetChar()
{
    int c = GetChar(); //on récupère le caractère de l'utilisateur
    PutChar(c); //on l'affiche à l'écran
}

int main()
{
    testGetChar();
    //Halt();
}