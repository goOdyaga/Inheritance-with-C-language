#include "Uretim.h"

Uretim Uretimolustur()
{
    Uretim this=(Uretim)malloc(sizeof(struct URETIM));
    this->deger=0;
    this->degerdegistirU=&degerdegistirU;
    this->Uret=&Uret;
    this->yoketU=&yoketU;
    return this;
}
void degerdegistirU(Uretim this ,int a )
{
    this->deger=a;
}
int Uret(Uretim this)
{   
    srand(time(NULL));
    printf("DEGERRRRR\n");
    // Generate a random number between 0 and 9
    this->deger = (rand() % 10+1);
    return this->deger;
}
void yoketU(Uretim this)
{
    if(this==NULL)
        return;
    free(this);
}


