#include "Oyun.h"

#define MAX_SIZE 100
#define POOL_SIZE 94 // Number of printable ASCII characters (33 to 126)
int arraysembol[94]={};
int* splitStringToIntArray(const char* inputString, int* arraySize) {
    // Allocate memory for the integer array
    int* intArray = (int*)malloc(MAX_SIZE * sizeof(int));
    
    // Copy the input string to a temporary buffer
    char buffer[MAX_SIZE];
    strncpy(buffer, inputString, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';
    
    // Tokenize the string by spaces
    char* token = strtok(buffer, " ");
    int index = 0;
    
    while (token != NULL) {
        // Convert each token to an integer and store it in the array
        intArray[index++] = atoi(token);
        
        // Get the next token
        token = strtok(NULL, " ");
    }
    
    // Set the array size
    *arraySize = index;
    
    return intArray;
}


char getRandomCharacter() {
    // static char characterPool[POOL_SIZE]; // Pool of available characters
    // static int poolInitialized = 0; // Flag to check if the pool is initialized

    // if (!poolInitialized) {
    //     // Initialize the character pool with all printable ASCII characters
    //     for (int i = 0; i < POOL_SIZE; i++) {
    //         characterPool[i] = 33 + i; // Starting from ASCII value 33
    //     }
    //     poolInitialized = 1;
    // }

    // Generate a random index within the remaining character pool
    int randomIndex = rand() % 94;
    if(arraysembol[randomIndex]==1)
        return getRandomCharacter();
    // Get the random character from the pool at the generated index
    char randomChar = (char)(randomIndex+32);
    arraysembol[randomIndex]++;
    // Replace the selected character with the last character in the pool
    // characterPool[randomIndex] = characterPool[POOL_SIZE - 1];

    // Reduce the size of the pool by 1
    // POOL_SIZE--;

    return randomChar;
}

int checkgame(Koloni* kolon,int size)
{
    int i=0;
    int control=0;
    for(i=0;i<size;i++)
    {
        if(kolon[i]->stokgetir(kolon[i])<=0)
            control++;
    }
    if(control==size-1)
        return -1;
    return 1;
}
int main()
{
    char input[MAX_SIZE];
    printf("========================================================= \n");
    printf("Koloni populasyon sayilarini giriniz: ");
    fgets(input, sizeof(input), stdin);
    
    // Remove the trailing newline character from fgets
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';
    
    int arraySize = 0;
    int* intArray = splitStringToIntArray(input, &arraySize);
    
 
    Oyun oyunn=oyunolustur();
    Koloni *koloniarray=(Koloni* )malloc(sizeof(Koloni)*arraySize);
// arraySize++;
    for (int i = 0; i < arraySize; i++) {
        koloniarray[i]=koloniolustur(intArray[i],getRandomCharacter());
    }
int tursayisi=0;
while (checkgame(koloniarray,arraySize)==1)
{
    printf("---------------------------------------------------\n");
    printf("Tur sayisi : %d\n",tursayisi);
    printf("Koloni       Populasyon    Yemek stogu    Kazanma    Kaybetme\n");
    for(int h=0;h<arraySize;h++)
    {
        if(koloniarray[h]->stok<=0)
            printf("%c               -----             ----      ----      ---- \n",koloniarray[h]->sembol,koloniarray[h]->populasyon,koloniarray[h]->stok);
        else
        printf("%c                 %d               %d        %d           %d \n",koloniarray[h]->sembol,koloniarray[h]->populasyon,koloniarray[h]->stok,koloniarray[h]->kazanma,koloniarray[h]->kaybetme);
    }
    printf("---------------------------------------------------\n");
    for (int i=0;i<arraySize;i++)
    {
        for(int j=i+1;j<arraySize;j++)
        {
            if(koloniarray[i]->stok>=0&&koloniarray[j]->stok>=0)
            oyunn->kolonisavasi(koloniarray[i],koloniarray[j]);
        }
        
    }
    printf("---------------------------------------------------\n");
    printf("Tur sayisi : %d\n",tursayisi);
    printf("Koloni       Populasyon    Yemek stogu    Kazanma    Kaybetme\n");
    for(int h=0;h<arraySize;h++)
    {
        if(koloniarray[h]->stok<=0)
            printf("%c               -----             ----      ----      ---- \n",koloniarray[h]->sembol,koloniarray[h]->populasyon,koloniarray[h]->stok);
        else
        printf("%c                 %d               %d        %d           %d \n",koloniarray[h]->sembol,koloniarray[h]->populasyon,koloniarray[h]->stok,koloniarray[h]->kazanma,koloniarray[h]->kaybetme);
    }
    printf("---------------------------------------------------\n");

    tursayisi+=1;
}
    
    
}

