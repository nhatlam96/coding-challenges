/* u02d.c
 * Name: Eric Finger
 * Datum: 26.10.22
 * Beschreibung: Gibt vom User eingegebene Zeichen aus und zaehlt die Anzahl der weichen und harten
 *               Konsonanten. Berechnet ausserdem die Quersumme ueber alle eingegebenen Zahlen.
*/

#include <stdio.h>

int main() {
    char userInput;
    int anzahlZeichen = 0;
    int anzahlWeicheKonsonanten = 0;
    int anzahlHarteKonsonanten = 0;
    int quersumme = 0;

    do {
        userInput = getchar();
        if (userInput != EOF) {
            putchar(userInput);
        }
        anzahlZeichen++;

        switch (userInput) {
            // Zaehlen der weichen Konsonanten:
            case 'B':
            case 'D':
            case 'G':
            case 'b':
            case 'd':
            case 'g': {
                anzahlWeicheKonsonanten++;
            }break;

            // Zaehlen der harten Konsonanten:
            case 'P':
            case 'T':
            case 'K':
            case 'p':
            case 't':
            case 'k': {
                anzahlHarteKonsonanten++;
            }break;

            case '0' ... '9': {
                // - '0' um den Zahlenwert der Eingabe zu erhalten
                quersumme += userInput - '0';
            }break;
        }
    } while (userInput != EOF);

    printf("Die Anzahl der eingegebenen Zeichen ist: %d\n", anzahlZeichen);
    printf("Die Anzahl der weichen Konsonanten ist: %d\n", anzahlWeicheKonsonanten);
    printf("Die Anzahl der harten Konsonanten ist: %d\n", anzahlHarteKonsonanten);
    printf("Die Quersumme aller eingegebenen Zahlen ist: %d\n", quersumme);

    return 0;
}

