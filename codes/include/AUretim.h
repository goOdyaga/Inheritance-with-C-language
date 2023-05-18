#ifndef AURETIM_H
#define AURETIM_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "Uretim.h"
struct AURETIM
{
    
    struct URETIM * super;
    int (*degerDondurUA)(struct AURETIM *);
    void (*AyoketU)(struct AURETIM *);
};

typedef struct AURETIM *Auretim;

Auretim Auretimolustur();
int degerDondurUA(Auretim);
void AyoketU(Auretim);



#endif