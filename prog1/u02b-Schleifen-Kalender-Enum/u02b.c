//Name: Jason Volz
//Datum: 26.10.22
//Beschreibung: Programm zur ausgabe eines Kalenders

//Zur leichteren Lesbarkeit der Switch Case marken
enum Monate {Januar = 1,Februar,Maerz,April,Mai,Juni,Juli,August,September,Oktober,November,Dezember};

#include <stdio.h>

int main(){
    int tage = 0;
    for(int monate = Januar; monate <= Dezember;monate++){
        //Wir Checken fuer jeden Monat, welcher Monat es ist und wie viele tage dieser monat hat
        switch(monate){
            case Januar:
                printf("Januar");
                tage = 31;
                break;
            case Februar:
                printf("Februar");
                tage = 28;
                break;
            case Maerz:
                printf("Maerz");
                tage = 31;
                break;
            case April:
                printf("April");
                tage = 30;
                break;
            case Mai:
                printf("Mai");
                tage = 31;
                break;
            case Juni:
                printf("Juni");
                tage = 30;
                break;
            case Juli:
                printf("Juli");
                tage = 31;
                break;
            case August:
                printf("August");
                tage = 31;
                break;
            case September:
                printf("September");
                tage = 30;
                break;
            case Oktober:
                printf("Oktober");
                tage = 31;
                break;
            case November:
                printf("November");
                tage = 30;
                break;
            case Dezember:
                printf("Dezember");
                tage = 31;
                break;
        }
        printf("\n");
        // Wir geben die Tage passend aus, das printf muss ueber dem if stehen, damit wir bei 7 und nicht 8 umbrechen
        for(int i = 1; i <= tage; i++){
            printf("%i\t",i);
            //Wir brechen fuer jeden 7. Tag aus.
            if((i % 7) == 0){
                printf("\n");
            }

        }
        printf("\n");
    }
    printf("\n");
    return 0;
}