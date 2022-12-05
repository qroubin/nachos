#include "syscall.h"

char* str = "abcd";

int main()
{
    int i = 0;
    for(i; i<4; ++i){
        PutChar(str[i]);
    }
    /*PutChar('c');
    PutChar('h');
    PutChar('a');
    PutChar('r');
    PutChar('\n');*/
}