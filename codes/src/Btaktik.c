#include "BTaktik.h"

BTaktik Btaktikolustur( )
{
    BTaktik this;
    this=(BTaktik)malloc(sizeof(struct BTAKTIK));
    this->super=Taktikolus();
    // this->degerDondurTB=&degerDondurTB;
    this->ByoketT=&ByoketT;
    this->super->degerdondurT=&degerDondurTB;
    return this;
}

int degerDondurTB(BTaktik this)
{
    int deger=this->super->Savas(this->super);
    this->super->degerdegistirT(this->super,deger-100);
    // this->super->deger-100;
    return deger-100;
}


void ByoketT(BTaktik this)
{
    if(this==NULL)  
        return;
    this->super->yoketT(this->super);
    free(this);
}

