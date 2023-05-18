#ifndef BURETIM_H
#define BURETIM_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "Uretim.h"
struct BURETIM
{
    
    struct URETIM * super;
    int (*degerDondurUB)(struct BURETIM *);
    void (*ByoketU)(struct BURETIM *);
};

typedef struct BURETIM *Buretim;

Buretim Buretimolustur();
int degerDondurUB(Buretim);
void ByoketU(Buretim);



#endif