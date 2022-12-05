#include "bitmap.h"
#include "machine.h"
#include "pageprovider.h"

PageProvider::PageProvider(int nb){
    bitmap = new BitMap(nb);
}

int PageProvider::GetEmptyPage(){
    int numEmpty = bitmap->Find();
    //TODO trouver comment récupérer l'adresse avec machine->mainMemory pour avoir le premier bit correspondant à la page numEmpty
    //if(numEmpty != -1)
        //memset((void *)numEmpty, 0, 1);
    return numEmpty;
 }

void PageProvider::ReleasePage(int nbEmptyPage){
    //if(nbEmptyPage == NULL) return;
    bitmap->Clear(nbEmptyPage);
}

int PageProvider::NumAvailPage(){
    return bitmap->NumClear();
}
