//Name: Jason Volz
//Datum: 09.11.2022
//Beschreibung: Programm zur Rekursiven erkennung und berechnung von Primzahlen

#include <stdio.h>
#include <stdbool.h>

bool isPrim(int pruef){
    static int teiler = 2;
    
    //Bricht ab wenn die Teilende Zahl gleichgross der Pruefenden zahl ist,  dann Primzahl
    if(teiler == pruef){
        teiler = 2;
        return true;
    }
    //Bricht ab wenn restlos teilbar, dann keine Primzahl
    if(pruef % teiler == 0){
        teiler = 2;
        return false;
    }

    if(teiler < pruef){
        teiler++;
        return isPrim(pruef);  
    }
    teiler = 2;
    return false;
}


int main(){
    int eingabe = 0;
    int max = 10000;
    printf("Geben sie die zu Pruefenden Primzahl ein: ");
    scanf("%i",&eingabe);
    if(isPrim(eingabe)){
        printf("Is eine Prim\n");
    }else{
        printf("Is keine Prim\n");
    }

    for(int i = 1;i <= max; i++){
        if(isPrim(i)){
            printf("%i ",i);
        }
    }
    return 0;   
}