#include "Taktik.h"

Taktik Taktikolus()
{
    
    Taktik this=(Taktik )malloc(sizeof(struct TAKTIK));
    this->Savas=&Savas;
    this->degerkiyasla=&degerkiyasla;
    this->degerdegistirT=&degerdegistirT;
    this->yoketT=&yoketT;
    return this;
}

void yoketT(Taktik this)
{
    if(this==NULL)
        return;
    free(this);
}   

int Savas(Taktik this)
{
    srand(time(NULL));

    // Generate a random number between 0 and 9
    int deger= (rand() % 10+1)*100;
    // this->deger =;
    this->deger=deger;
    return this->deger;
}
int degerkiyasla(Taktik this ,Taktik other )
{
    if(this->deger>other->deger)
        return 1;
    else if(this->deger<other->deger)
        return -1;
    return 0;
}
void degerdegistirT(Taktik this,int a)
{
    this->deger=a;
}

