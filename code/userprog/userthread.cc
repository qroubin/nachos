#include "userthread.h"
#include "system.h"
#include "addrspace.h"

//créer struct avec f et arg
struct FArg
{
    int f;
    int arg;
};

static void StartUserThread(void *schmurtz)
{
    DEBUG ('b', "startuserthread\n");
    struct FArg* farg = (struct FArg*) schmurtz;

    int i;

    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    // Initial program counter -- must be location of "Start"
    int tmpPCReg = farg -> f;
    machine->WriteRegister (PCReg, tmpPCReg);
    DEBUG ('b', "Initializing PC register to 0x%x\n",
            tmpPCReg);

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    int tmpNextPCReg = machine->ReadRegister(PCReg) + 4;
    machine->WriteRegister (NextPCReg, tmpNextPCReg);
    DEBUG ('b', "Initializing Next PC register to 0x%x\n",
            tmpNextPCReg);
    
    int userStack = currentThread->space->AllocateUserStack();
    machine->WriteRegister (StackReg, userStack);
    DEBUG ('b', "Initializing stack register to 0x%x\n",
           userStack);

    machine->DumpMem("threads.svg");
    machine->Run();
}

int do_ThreadCreate(int f, int arg)
{
    Thread *t = new Thread ("forked thread");
    t->space = currentThread -> space;
    t->space->semNewThread();
    DEBUG ('b', "space = %d\n", t->space);
    
    struct FArg* farg = (struct FArg*) malloc(sizeof(struct FArg));
    DEBUG ('b', "f = %d\n", f);
    DEBUG ('b', "arg = %d\n", arg);
    farg -> f = f;
    farg -> arg = arg;
    t->Start (StartUserThread, (void*) farg);
    DEBUG ('b', "startuserthread lancé\n");
    // if(erreur) return -1;
    return 0;
}

void do_ThreadExit()
{
    DEBUG ('b', "nbThreads = %d\n", currentThread->space->getNbThreads());
    //libérer space
    if(currentThread->space->semRemThread() <= 0){
        interrupt->Powerdown();
    }
    currentThread->Finish();
}