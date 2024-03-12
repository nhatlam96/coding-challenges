/* u02a.c
 * Name: Eric Finger
 * Datum: 19.10.2022
 * Beschreibung: Berechnet die Summe von 1-42. Danach wird die Summe ueber vom Nutzer eingegebene Ganzzahlen berechnet, 
 *               danach wird dann final die Summe ueber vom Nutzer eingegebene Gleitkommezahlen berechnet (nachdem ein 
 *               Faktor von 1.19 hinzugefuegt wird).
*/

#include <stdio.h>

int main() {
    // Aufgabenteil a):
    int summe = 0;
    for (int i = 1; i <= 42; i++) {
        summe += i;
    }

    printf("Die Summe der Zahlen von 1 - 42 ist: %d\n", summe);

    // Aufgabenteil b):
    int nutzerInput;
    int nutzerSumme = 0;

    do {
        printf("Geben Sie Ganzzahlen ein die addiert werden sollen (0 beendet die Eingabe): ");
        scanf("%d", &nutzerInput);
        nutzerSumme += nutzerInput;
        printf("Ihre Eingabe: %d\n", nutzerInput);
        printf("Die Zwischensumme ist: %d\n", nutzerSumme);
    } while (nutzerInput != 0); // Schleife laeuft bis Nutzer 0 eingibt

    printf("Die Endsumme ist: %d\n", nutzerSumme);

    // Aufgabenteil c):

    double nutzerFloatInput;
    double nutzerFloatSumme = 0;

    do {
        printf("Geben Sie Kommazahlen ein die addiert und mit 1.19 multipliziert werden sollen (0 beendet die Eingabe): ");
        scanf("%lf", &nutzerFloatInput);
        nutzerFloatInput *= 1.19;
        nutzerFloatSumme += nutzerFloatInput;
        printf("Ihre Eingabe * 1.19: %lf\n", nutzerFloatInput);
        printf("Die Zwischensumme ist: %lf\n", nutzerFloatSumme);
    } while (nutzerFloatInput != 0); // Schleife laeuft bis Nutzer 0 eingibt

    printf("Die Endsumme ist: %lf\n", nutzerFloatSumme);

    return 0;
}

