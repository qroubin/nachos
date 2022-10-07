#ifdef CHANGED

#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, NULL);
}
ConsoleDriver::~ConsoleDriver()
{
    delete console;
    delete writeDone;
    delete readAvail;
}
void ConsoleDriver::PutChar(int ch)
{
    console->TX (ch);   // echo it!
    writeDone->P ();    // wait for write to finish
}
int ConsoleDriver::GetChar()
{
    char ch;
    readAvail->P ();        // wait for character to arrive
    ch = console->RX ();
    return ch;
}
void ConsoleDriver::PutString(const char *s)
{
    while(s != NULL && *s != '\0'){
        PutChar((int) (*s));
        ++s;
    }
}
void ConsoleDriver::GetString(char *s, int n)
{
    // ...
}

unsigned copyStringFromMachine(int from, char *to, unsigned size)
{
    int res;
    unsigned cpt;
    for(cpt = 0; cpt<size; cpt++){
        machine->ReadMem(from, 1, &res);
        *(to+cpt) = (char) res;
        if (*(to+cpt) == '\0') break;
    }
    if (cpt >= size){
        *(to+cpt) = '\0';
    }
    return cpt;
}

#endif // CHANGED