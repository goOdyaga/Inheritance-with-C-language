
#include "AUretim.h"
// Auretim AURETIMolustur();
// int degerDondurU(Auretim);
// void Ayoket(Auretim);
Auretim Auretimolustur( )
{
    Auretim this;
    this=(Auretim)malloc(sizeof(struct AURETIM));
    this->super=Uretimolustur();
    // this->degerDondurUA=&degerDondurUA;
    this->AyoketU=&AyoketU;
    this->super->degerdondurU=&degerDondurUA;
    return this;
}

int degerDondurUA(Auretim this)
{
    int deger=this->super->Uret(this->super);
    this->super->degerdegistirU(this->super,deger+1);
    return deger+1;
}

void AyoketU(Auretim this)
{
    if(this==NULL)  
        return;
    this->super->yoketU(this->super);
    free(this);
}
