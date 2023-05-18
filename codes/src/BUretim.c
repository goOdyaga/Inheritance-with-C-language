
#include "BUretim.h"
// Buretim BURETIMolustur();
// int degerDondur(Buretim);
// void Ayoket(Buretim);
Buretim Buretimolustur( )
{
    Buretim this;
    this=(Buretim)malloc(sizeof(struct BURETIM));
    this->super=Uretimolustur();
    // this->degerDondurUB=&degerDondurUB;
    this->ByoketU=&ByoketU;
    this->super->degerdondurU=&degerDondurUB;
    return this;
}

int degerDondurUB(Buretim this)
{
    int deger=this->super->Uret(this->super);
    this->super->degerdegistirU(this->super,deger-1);
    return deger-1;
}

void ByoketU(Buretim this)
{
    if(this==NULL)  
        return;
    this->super->yoketU(this->super);
    free(this);
}
