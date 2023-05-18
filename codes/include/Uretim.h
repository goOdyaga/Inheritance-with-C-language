#ifndef URETIM_H
#define URETIM_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct URETIM
{
    int deger;
    void (*degerdegistirU)(struct URETIM *,int );
    int (*Uret)(struct URETIM *);
    void (*yoketU)(struct URETIM *);
    int (*degerdondurU)();
};

typedef struct URETIM *Uretim;

Uretim Uretimolustur();
void degerdegistirU(Uretim,int );
int Uret(Uretim);
void yoketU(Uretim);





#endif