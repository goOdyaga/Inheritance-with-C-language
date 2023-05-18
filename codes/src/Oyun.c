#include "Oyun.h"

Oyun oyunolustur()
{
    Oyun this=(Oyun)malloc(sizeof(struct OYUN *));
    this->kolonisavasi=&kolonisavasi;
    return this;
}
void kolonisavasi(Koloni this,Koloni other)
{
    this->Savasyap(this,other);
}