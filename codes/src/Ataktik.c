#include "ATaktik.h"

ATaktik Ataktikolustur( )
{
    ATaktik this;
    this=(ATaktik)malloc(sizeof(struct ATAKTIK));
    this->super=Taktikolus();
    this->AyoketT=&AyoketT;
    this->super->degerdondurT=&degerDondurTA;
    return this;
}

int degerDondurTA(ATaktik this)
{
    int deger=this->super->Savas(this->super);
    this->super->degerdegistirT(this->super,deger+200);
    // printf("CONTROLLL\n");
    return deger+200;
}

void AyoketT(ATaktik this)
{
    if(this==NULL)  
        return;
    this->super->yoketT(this->super);
    free(this);
}
