#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H

#include "bitmap.h"

class PageProvider{
    public:
    PageProvider(int nb);

    int GetEmptyPage();

    void ReleasePage(int nbEmptyPage);

    int NumAvailPage();

    private:
    BitMap* bitmap;
};

#endif // PAGEPROVIDER_H