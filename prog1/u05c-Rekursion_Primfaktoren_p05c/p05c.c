//Name: Jason Volz
//Datum: 16.11.2022
//Beschreibung: Programm, welches Rekursiv eine Primzahl erkennen soll und Nicht primzahlen mit Primfaktoren zerlegen kann

#include <stdbool.h>
#include <stdio.h>


bool isPrim(int pruef){
    static int teiler = 2; //Static damit der wert nicht verloren geht bei neuaufruf
    if(teiler == pruef){
        teiler = 2;
        return true;
    }
    if(pruef % teiler == 0){
        teiler = 2;
        return false;
    }
    if(pruef > teiler){
        teiler++;
        return isPrim(pruef); 
    }
    return false;
}

void doPFZ(int zerleg,int zerleger){
    if(isPrim(zerleger)){
        if(zerleg % zerleger == 0){
            //Wir pruefen ob der Zerleger eine Primzahl ist und dann ob die Teilung restlos durch null teilbar ist, damit wir nur primzahl teilungen vornehmen, die Restlos sind.
            zerleg /= zerleger;
            printf("%i, ",zerleger);
            return doPFZ(zerleg,zerleger);
        }
        else{
            return doPFZ(zerleg,zerleger + 1); //return muss dazu geschrieben werden, damit das programm unsere Rekursion auch als rueckgabe wert annerkennt
        }
        if(zerleg == zerleger){
            return;
        }
    }
    if(zerleg == 1){
        return;
    }else{
        return doPFZ(zerleg,zerleger+1);
    }
}
int main(){
    int max = 0;
    printf("Geben sie eine Obergrenze ein: ");
    scanf("%i",&max);
    for(int i = 3;i<=max;i++){
        if(isPrim(i) == true){
            if(isPrim(i + 2) == true){
                printf("(%i %i)",i, i + 2);
            }
        }
    }
    //Aufgabenteil b)
    int eingabe = 0;
    printf("Geben sie eine Zahl fuer die Primfaktorenzerlegung ein: ");
    scanf("%i",&eingabe);
    printf("Die Zahl %i hat folgende Primfaktoren: ",eingabe);
    doPFZ(eingabe,2);
    return 0;
}