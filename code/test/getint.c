#include "syscall.h"

void testGetInt()
{
    int* n;
    GetInt(n); //on récupère la chaine du clavier
    PutInt(n); //on affiche la chaine à l'écran
}

int main()
{
    testGetInt();
    //Halt();
}