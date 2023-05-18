#include "Koloni.h"

Koloni koloniolustur(int pop ,char sym)
{
    Koloni this=(Koloni)malloc(sizeof(struct KOLONI));
    this->populasyon=pop;
    this->sembol=sym;
    this->stok=pop*pop;
    this->Populasyonduzenle=&Populasyonduzenle;
    this->populasyongetir=&populasyongetir;
    this->Savasyap=&Savasyap;
    this->sembolgetir=&sembolgetir;
    this->stokDuzenle=&stokDuzenle;
    this->stokgetir=&stokgetir;
    this->Uretimyap=&Uretimyap;
    this->atak=NULL;
    this->batak=NULL;
    this->auret=NULL;
    this->BUret=NULL;
    this->kazanma=0;
    this->kaybetme=0;
    srand(time(NULL));

    // Generate a random number between 0 and 9
    int deger = (rand() % 2);
    if (deger==1)
    {
        this->atak=Ataktikolustur();
        this->auret=Auretimolustur();
    }
    else
    {
        this->batak=Btaktikolustur();
        this->BUret=Buretimolustur();
   
    }
    return this;
    
}

void Populasyonduzenle(Koloni this ,int a)
{
    this->populasyon=a;
}
void stokDuzenle(Koloni this,int a)
{
    this->stok=a;
}
int stokgetir(Koloni this)
{
    return this->stok;
}
int populasyongetir(Koloni this)
{
    return this->populasyon;
}
char sembolgetir(Koloni this)
{
    return this->sembol;
}
void Uretimyap(Koloni this)
{
    if(this->auret!=NULL)
    this->stok+=this->auret->super->degerdondurU(this->auret);
    //     this->auret->degerDondurUA(this->auret,this->stok+this->auret->super->degerdondurU(this->auret));
    else
    this->stok+=this->BUret->super->degerdondurU(this->BUret);
        // this->BUret->degerDondurUB(this->BUret,this->stok+this->BUret->super->degerdondurU(this->BUret));
}
int Savasyap(Koloni this,Koloni other)
{
    int deger1,deger2;
    // printf("STEP2\n");
    int flag1=0;
    int flag2=0;
    if(this->atak!=NULL)
    {
        // printf("KONTROL1\n");
        flag1=1;
        deger1=this->atak->super->degerdondurT(this->atak);
        
    }
    else
    {
        // printf("KONTROL2\n");
        deger1=this->batak->super->degerdondurT(this->batak);
    }
    if(other->atak!=NULL)
    {
        // printf("KONTROL3\n");
        flag2=1;
        deger2=other->atak->super->degerdondurT(other->atak);
        
    }
    else
    {
        // printf("KONTROL4\n");
        deger2=other->batak->super->degerdondurT(other->batak);
    }

    // printf("FLAG1\n");
    int yuzde=(deger2-deger1)/10;
    if(yuzde==0)
        yuzde=10;
    // printf("deger1: %d deger2: %d\n",deger1,deger2);
    if(flag1==1)
    {
        if(flag2==1)
        {
            if(this->atak->super->degerkiyasla(this->atak->super,other->atak->super)==-1)
            {
                
                this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                other->kazanma+=1;
                this->kaybetme+=1;
                
            }
            else if(this->atak->super->degerkiyasla(this->atak->super,other->atak->super)==1)
            {
                int yuzde=(deger1-deger2)/10;
                other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                this->kazanma+=1;
                other->kaybetme+=1;  
            }
            else
            {
                // printf("FIRST CONTROL\n");
                if(this->populasyon>other->populasyon)
                {
                    
                    other->Populasyonduzenle(this,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                    this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                    other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                    this->kazanma+=1;
                other->kaybetme+=1;  

                }
                else if(this->populasyon<other->populasyon)
                {
                    // printf("SECOND CHECK\n");
                    
                    // printf("%f",)
                    this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                    other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                    this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                    other->kazanma+=1;
                this->kaybetme+=1;
                }
                else
                {
                    srand(time(NULL));
                    int deger = (rand() % 2);
                    if(deger==1)
                    {
                        
                        other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                        this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                        other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                        this->kazanma+=1;
                other->kaybetme+=1;  
                    }
                    else
                    {
                        
                        this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                        other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));   
                        this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));   
                        other->kazanma+=1;
                this->kaybetme+=1;
                    }
                }
            }
        }

        else
        {
            if(this->atak->super->degerkiyasla(this->atak->super,other->batak->super)==-1)
            {
                
                this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                other->kazanma+=1;
                this->kaybetme+=1;
            }
            else if(this->atak->super->degerkiyasla(this->atak->super,other->batak->super)==1)
            {
            
                other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                this->kazanma+=1;
                other->kaybetme+=1;  
            }
            else
            {
                if(this->populasyon>other->populasyon)
                {
                    
                    other->Populasyonduzenle(this,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                    this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                    other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);

                }
                else if(this->populasyon<other->populasyon)
                {
                    
                    this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                    other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                    this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                    other->kazanma+=1;
                this->kaybetme+=1;
                }
                else
                {
                    srand(time(NULL));
                    int deger = (rand() % 2);
                    if(deger==1)
                    {
                        
                        other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                        this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                        other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                        this->kazanma+=1;
                other->kaybetme+=1;  
                    }
                    else
                    {
                        
                        this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                        other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));   
                        this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));   
                        other->kazanma+=1;
                this->kaybetme+=1;
                    }
                }
            }
        }
    }
    else
    {
        if(flag2==1)
        {
            if(this->batak->super->degerkiyasla(this->batak->super,other->atak->super)==-1)
            {
                
                this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
               other->kazanma+=1;
                this->kaybetme+=1; 
            }
            else if(this->batak->super->degerkiyasla(this->batak->super,other->atak->super)==1)
            {
                other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                this->kazanma+=1;
                other->kaybetme+=1;  
            }
            else
            {
                if(this->populasyon>other->populasyon)
                {
                    
                    other->Populasyonduzenle(this,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                    this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                    other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                    this->kazanma+=1;
                other->kaybetme+=1;  
                }
                else if(this->populasyon<other->populasyon)
                {
                    
                    this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                    other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                    this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                    other->kazanma+=1;
                this->kaybetme+=1;
                }
                else
                {
                    srand(time(NULL));
                    int deger = (rand() % 2);
                    if(deger==1)
                    {
                        
                        other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                        this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                        other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                        this->kazanma+=1;
                other->kaybetme+=1;  
                    }
                    else
                    {
                        
                        this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                        other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));   
                        this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));   
                        other->kazanma+=1;
                this->kaybetme+=1;
                    }
                }
            }
        }
        else
        {
            if(this->batak->super->degerkiyasla(this->batak->super,other->batak->super)==-1)
            {
                
                this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                other->kazanma+=1;
                this->kaybetme+=1;  
            }
            else if(this->batak->super->degerkiyasla(this->batak->super,other->batak->super)==1)
            {
                other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                this->kazanma+=1;
                other->kaybetme+=1;  
            }
            else
            {
                if(this->populasyon>other->populasyon)
                {
                    
                    other->Populasyonduzenle(this,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                    this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                    other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                    this->kazanma+=1;
                other->kaybetme+=1;  
                }
                else if(this->populasyon<other->populasyon)
                {
                    
                    this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                    other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
                    this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
                    other->kazanma+=1;
                this->kaybetme+=1;
                }
                else
                {
                    srand(time(NULL));
                    int deger = (rand() % 2);
                    if(deger==1)
                    {
                        
                        other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
                        this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
                        other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
                        this->kazanma+=1;
                other->kaybetme+=1;  
                    }
                    else
                    {
                        
                        this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
                        other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));   
                        this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));   
                        other->kazanma+=1;
                this->kaybetme+=1;
                        }
                }
            }
        }
    }
    // deger1=this->taktik->degerdondurT(this->taktik);
    // deger2=other->taktik->degerdondurT(other->taktik);
    // if(a!=NULL)
    // if(this->atak->super->degerkiyasla(this->atak->super,other->atak->super)==-1)
    // {
    //     
    //     this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
    //     other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
    //     this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
        
    // }
    // else if(this->taktik->degerkiyasla(this->taktik,other->taktik)==1)
    // {
    //     int yuzde=(deger1-deger2)/10;
    //     other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
    //     this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
    //     other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
    // }
    // else
    // {
    //     if(this->populasyon>other->populasyon)
    //     {
    //         int yuzde=(deger1-deger2)/10;
    //         other->Populasyonduzenle(this,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
    //         this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
    //         other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
    //     }
    //     else if(this->populasyon<other->populasyon)
    //     {
    //         
    //         this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
    //         other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));
    //         this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));
    //     }
    //     else
    //     {
    //         srand(time(NULL));
    //         int deger = (rand() % 2);
    //         if(deger==1)
    //         {
    //             int yuzde=(deger1-deger2)/10;
    //             other->Populasyonduzenle(other,other->populasyongetir(other)-((other->populasyon)*yuzde)/100);
    //             this->stokDuzenle(this,(other->stokgetir(other)*yuzde)/100+this->stokgetir(this));
    //             other->stokDuzenle(other,(other->stokgetir(other)-other->stokgetir(other)*yuzde)/100);
    //         }
    //         else
    //         {
    //             
    //             this->Populasyonduzenle(this,this->populasyongetir(this)-((this->populasyon)*yuzde)/100);
    //             other->stokDuzenle(other,(this->stokgetir(this)*yuzde)/100+other->stokgetir(other));   
    //             this->stokDuzenle(this,(this->stokgetir(this)-(other->stokgetir(other)*yuzde)/100));   
    //         }
    //     }
    // }
    

}
