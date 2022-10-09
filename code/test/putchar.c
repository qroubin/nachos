#include "syscall.h"

void testPutChar(char c, int n)
{
    int i;
    for (i = 0; i < n; i++) {   //pour i de 0 à n, on affiche le caractère c + i, autrement dit on incrémente ce caractère avec l'ordre alphabétique
        PutChar(c + i);
    }
    PutChar('\n'); //saut de ligne
}

int main()
{
    testPutChar('a',4); //on souhaite afficher abcd
    //Halt();
}