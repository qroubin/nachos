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
    int index = 0;
    char c;
    while(index < n-1){
        c = (int) GetChar();
        if (c == EOF){
            break;
        }
        *(s + index) = c;
        if (c == '\n'){
            index++;
            break;
        }
        index++;
    }
    *(s + index) = '\0';
}

void ConsoleDriver::PutInt(int n)
{
    char buffer[10];
    snprintf(buffer, 9, "%d", n);
    PutString(buffer);
}

void ConsoleDriver::GetInt(int* n)
{
    char buffer[10];
    GetString(buffer, 10);
    sscanf(buffer, "%d", n);
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

unsigned copyStringToMachine(char* from, int to, unsigned size)
{
    uint cpt = 0;
    for (uint i = 0; i < size; i++){
        if (from + i != NULL)
        {
            machine -> WriteMem(to, 1, *(from + i));
            if (*(from + i) == '\0') break;
        }
    }
    return cpt;
}

#endif // CHANGED