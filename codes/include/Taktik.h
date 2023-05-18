#ifndef TAKTIK_H
#define TAKTIK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct TAKTIK
{
    int deger;
    void (*degerdegistirT)(struct TAKTIK *,int);
    int (*Savas)(struct TAKTIK *);
    int (*degerkiyasla)(struct TAKTIK *,struct TAKTIK *);
    void (*yoketT)(struct TAKTIK *);
    int (*degerdondurT)( );


};

typedef struct TAKTIK * Taktik;

void yoketT(Taktik);
Taktik Taktikolus();
int degerkiyasla(Taktik ,Taktik);
int Savas(Taktik);
void degerdegistirT(Taktik ,int );
// int degerdondurT






#endif