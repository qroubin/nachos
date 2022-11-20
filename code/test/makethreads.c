#include "syscall.h"

void doSimplePutChar(int arg)
{
    PutChar('a');
    ThreadExit();
}

void testThreadCreateSimplePutChar()
{
    char c = 'a';
    ThreadCreate((void*) doSimplePutChar, (void*) c);
}

void doLoopPutChar(int arg)
{
    volatile int i = 0;
    for(i; i<5; i++){
        PutChar('a');
    }
    ThreadExit();
}

void testThreadCreateLoop()
{
    char c = 'a';
    ThreadCreate((void*) doLoopPutChar, (void*) c);
}

int main()
{
    // Les différents programmes de test. Décommentez-les individuellement pour les tester, et lancez-les avec 
    // ./nachos -x ../test/makethreads (éventuellement -d b pour voir les différents messages de DEBUG utilisés lors du développement)

    // programme test question I.7 :
    /*testThreadCreateSimplePutChar();*/

    // programme test question II.1 & II.2 (suite à cette question nachos se termine après la fin du dernier thread) :
    /*testThreadCreateSimplePutChar();
    PutChar('b');*/

    // programme test question II.3 (dans ce cas on teste en lançant 3 threads qui font chacun 5 affichages avec un for) :
    /*testThreadCreateLoop();
    testThreadCreateLoop();
    testThreadCreateLoop();
    PutChar('b');*/
    
    // programme test question II.4 :
    /*int x = 0;
    for(x=0; x<100;x++)
    {
        testThreadCreateLoop();
    }
    PutChar('b');*/
    
    ThreadExit();
}