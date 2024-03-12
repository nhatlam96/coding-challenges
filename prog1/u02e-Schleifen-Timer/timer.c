/* Dateiname:    timer.c
 * Beschreibung: Timer - Console (Stunden, Minuten, Sekunden)
 * Datum:        29.10.2016
 * Ersteller:    Arthur Baer
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void timer(int stunden, int minuten, int sekunden){
    for (stunden = 0; stunden <= 23; stunden++){
        for (minuten = 0; minuten <= 59; minuten++){
            for (sekunden = 0; sekunden <= 59; sekunden++){
                system ("clear");
                printf ("Timer running..\n");
                printf ("%.2i:%.2i:%.2i\n", stunden, minuten, sekunden);
                sleep(1);
            }
        }
    }
}

int main(){
    int stunden = 0, minuten = 0, sekunden = 0;
    char c;
    
    system ("clear");
    printf ("Consolen - Timer\n");
    printf ("Um Timer zu starten, 'Enter' druecken!\n");
    scanf ("%c", &c);
    timer(stunden, minuten, sekunden);
    
    return 0;
}
