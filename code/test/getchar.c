#include "syscall.h"

void print()
{
    int c = GetChar();
    PutChar(c);
}

int main()
{
    print();
    //Halt();
}