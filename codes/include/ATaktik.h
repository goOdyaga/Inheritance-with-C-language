#ifndef ATAKTIK_H
#define ATAKTIK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "Taktik.h"
struct ATAKTIK
{
    
    struct TAKTIK * super;
    int (*degerDondurTA)(struct ATAKTIK *);
    void (*AyoketT)(struct ATAKTIK *);
};

typedef struct ATAKTIK *ATaktik;

ATaktik Ataktikolustur();
int degerDondurTA(ATaktik);
void AyoketT(ATaktik);



#endif