#ifndef BTAKTIK_H
#define BTAKTIK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "Taktik.h"

struct BTAKTIK
{
    
    struct TAKTIK * super;
    int (*degerDondurTB)(struct BTAKTIK *);
    void (*ByoketT)(struct BTAKTIK *);
};

typedef struct BTAKTIK *BTaktik;

BTaktik Btaktikolustur();
int degerDondurTB(BTaktik);
void ByoketT(BTaktik);




#endif