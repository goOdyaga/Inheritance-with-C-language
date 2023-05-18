#ifndef OYUN_H
#define OYUN_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "Koloni.h"

struct OYUN
{
    void (*kolonisavasi)(struct KOLONI *,struct KOLONI *);
};

typedef struct OYUN *Oyun;
// typedef struct KOLONI *Koloni;

Oyun oyunolustur();
void kolonisavasi(Koloni,Koloni);




#endif