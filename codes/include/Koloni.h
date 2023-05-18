#ifndef KOLONI_H
#define KOLONI_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include "ATaktik.h"
#include "BTaktik.h"
#include "AUretim.h"
#include "BUretim.h"

struct KOLONI
{
    int kazanma;
    int kaybetme;
    int populasyon;
    char sembol;
    int stok;
    ATaktik atak;
    BTaktik batak;
    Auretim auret;
    Buretim BUret;
    int (* stokgetir)(struct KOLONI *);
    int ( * populasyongetir)(struct KOLONI *);
    char (*sembolgetir)(struct KOLONI *);
    void (*Uretimyap)(struct KOLONI *);
    int (*Savasyap)(struct KOLONI *,struct KOLONI *);
    void (*Populasyonduzenle)(struct KOLONI *,int);
    void (*stokDuzenle)(struct KOLONI *,int);
};

typedef struct KOLONI *Koloni;

Koloni koloniolustur(int ,char);

int stokgetir(Koloni);
int populasyongetir(Koloni);
char sembolgetir(Koloni);
void Uretimyap(Koloni);
int Savasyap(Koloni ,Koloni);
void Populasyonduzenle(Koloni,int);
void stokDuzenle(Koloni ,int a);

#endif