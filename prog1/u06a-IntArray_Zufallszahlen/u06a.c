//Name: Jason Volz
//Datum: 16.11.2022
//Beschreibung:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init(int intArr[],int arrSize){
    for(int i = 0;i < arrSize;i++){
        //wir rechnen modulo plus eins um einen Bereich zwischen 1 und der Max zahl(hier 5000) zu erreichen
        intArr[i] = (rand() % 5000) + 1;
    }
}

void ausgabe(int intArr[],int arrSize){
    for(int i = 0; i < arrSize; i++){
        if(i % 10 == 0 && i != 0){
            printf("\n");
        }
        printf("%5i",intArr[i]);
    }
    printf("\n");
}

int suche(int intArr[], int arrSize,int gesucht){
    for(int i = 0; i < arrSize; i++){
        if(intArr[i] == gesucht){
            return i;
        }
    }
    return -1;
}

int main(){
    int size = 1000;
    int myArray[size];
    int suchende_Zahl;
    int find = 0;
    srand(time(NULL));
    init(myArray,size);
    ausgabe(myArray,size);
    printf("Geben sie die gesuchte Zahl ein: ");
    scanf("%i",&suchende_Zahl);
    if((find = suche(myArray,size,suchende_Zahl)) >= 0){ //wir geben den Return value an eine Variable um mehrfach aufruf zu verhindern
        printf("Die zahl %i ist an stelle %i\n",suchende_Zahl,find);
    }else{
        printf("Die Zahl ist nicht im Array, sadge\n");
    }
    return 0;
}
