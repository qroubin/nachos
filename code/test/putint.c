#include "syscall.h"

void testPutInt(int n)
{
    PutInt(n);
}

int main()
{
    testPutInt(14);   //on veut afficher 14
    //Halt();
}