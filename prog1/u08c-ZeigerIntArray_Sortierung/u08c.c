/* u08.c
 * Name: Eric Finger
 * Datum: 30.11.2022
 * Beschreibung: Fuellt ein Array mit Zufallszahlen und sortiert es dann mit dem Bubblesort Algorithmus.
 *               Danach wird das Array wieder mit zufaelligen Zahlen befuellt und anschliessend wird 
 *               das groesste und kleinste Element sowie der Median bestimmt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1001

// Fuellt das Array mit Zufallszahlen von 1 - 9999
void init(int *array, int anzahl) {
    for (int i = 0; i < anzahl; i++) {
        *(array + i) = (rand() % 9999) + 1;
    }
}

void ausgabe(int *array, int anzahl) {
    for (int i = 0; i < anzahl; i++) {
        printf("%5d ", *(array + i));
    }
    printf("\n");
}

void tausche(int *zahl1, int *zahl2) {
    int zwischenspeicher = *zahl1;
    *zahl1 = *zahl2;
    *zahl2 = zwischenspeicher;
}

void sortiere(int *array, int anzahl) {
    // Bubblesort:
    for (int n = anzahl; n > 1; n--) {
        for (int i = 0; i < n - 1; i++) {
            if (*(array + i) > *(array + i + 1)) {
                tausche(array + i, array + i + 1);
            }
        }
    }
}

int *mini(int *array, int anzahl) {
    int *mini = array; 
    for (int i = 1; i < anzahl; i++) {
        // Wir ueberspringen das 1. Element weil wir unseren Vergleich damit beginnen
        if (*(array + i) < *mini) {
            mini = array + i;
        }
    }

    return mini;
}

int *maxi(int *array, int anzahl) {
    int *maxi = array; 
    for (int i = 1; i < anzahl; i++) {
        // Wir ueberspringen das 1. Element weil wir unseren Vergleich damit beginnen
        if (*(array + i) > *maxi) {
            maxi = array + i;
        }
    }

    return maxi;
}

int *median(int *array, int anzahl) {
    sortiere(array, anzahl);
    return (array + anzahl / 2);
}

int main() {
    srand(time(NULL));
    int zahlen[ARRAY_SIZE];

    init(zahlen, ARRAY_SIZE);
    ausgabe(zahlen, ARRAY_SIZE);
    printf("\n\n");

    sortiere(zahlen, ARRAY_SIZE);
    ausgabe(zahlen, ARRAY_SIZE);
    printf("\n\n");

    init(zahlen, ARRAY_SIZE);
    ausgabe(zahlen, ARRAY_SIZE);

    int *min;
    int *max;

    min = mini(zahlen, ARRAY_SIZE);
    max = maxi(zahlen, ARRAY_SIZE);

    printf("Kleinestes Element: %d\n", *min);
    printf("Größtes Element: %d\n", *max);
    printf("Der Median Wert: %d\n", *median(zahlen, ARRAY_SIZE));

    return 0;
}

