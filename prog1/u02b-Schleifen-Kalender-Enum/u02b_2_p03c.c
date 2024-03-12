/* p03c.c
 * Name: Eric Finger
 * Datum: 02.11.2022
 * Beschreibung: Gibt einen Kalender mit korrekter Wochentags-Darstellung aus. Nimmt an 
 *               dass das Jahr mit einem Montag beginnt und das es kein Schaltjahr ist.
*/

//Zur leichteren Lesbarkeit der Switch Case marken
enum monat { Januar = 1, Februar, Maerz, April, Mai, Juni, Juli, August, September, Oktober, November, Dezember };

#include <stdio.h>

int main() {
    int tage = 0;
    int tagImJahr = 0;

    for(int monat = Januar; monat <= Dezember; monat++) {
        //Wir Checken fuer jeden Monat, welcher Monat es ist und wie viele tage dieser monat hat
        switch(monat){
            case Januar: {
                printf("Januar");
                tage = 31;
            }break;

            case Februar: {
                printf("Februar");
                tage = 28;
            }break;

            case Maerz: {
                printf("Maerz");
                tage = 31;
            }break;

            case April: {
                printf("April");
                tage = 30;
            }break;

            case Mai: {
                printf("Mai");
                tage = 31;
            }break;

            case Juni: {
                printf("Juni");
                tage = 30;
            }break;

            case Juli: {
                printf("Juli");
                tage = 31;
            }break;

            case August: {
                printf("August");
                tage = 31;
            }break;

            case September: {
                printf("September");
                tage = 30;
            }break;

            case Oktober: {
                printf("Oktober");
                tage = 31;
            }break;

            case November: {
                printf("November");
                tage = 30;
            }break;

            case Dezember: {
                printf("Dezember");
                tage = 31;
            }break;
        }
        printf("\n");
        
        // Rueckt den Tag zu Anfang des Monats an die richtige Wochentags-Stelle:
        for (int i = 0; i < tagImJahr % 7; i++) {
            printf("\t");
        }
        // printf("Position: %d\n", tagImJahr);
        // printf("Position mod 7: %d\n", tagImJahr % 7);
        
        // Wir geben die Tage passend aus, das printf muss ueber dem if stehen, damit wir bei 7 und nicht 8 umbrechen
        for(int i = 1; i <= tage; i++) {
            printf("%i\t",i);
            tagImJahr++;

            //Wir brechen nach jedem Sonntag (jedem 7. Tag) aus
            if((tagImJahr % 7) == 0) {
                printf("\n");
            }

        }
        printf("\n\n");
    }
    printf("\n");
    return 0;
}

