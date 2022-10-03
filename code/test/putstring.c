#include "syscall.h"

void print()
{
    //char* string = "Hello world";
    PutString("Hello world");
    //PutChar('\n');
}

int main()
{
    print();
    Halt();
}