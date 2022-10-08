#include "syscall.h"

void print()
{
    char* s = "Hello world!";
    GetString(s, 13);
    PutString(s);
}

int main()
{
    print();
    Halt();
}