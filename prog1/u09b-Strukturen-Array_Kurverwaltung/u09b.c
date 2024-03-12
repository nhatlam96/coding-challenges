/* u09b.c
 * Name: Eric Finger 
 * Datum: 07.12.2022
 * Beschreibung: Programm zur Statistik-Erfassung einer Kurverwaltung. Speichert in einer Struct die Anzahl
 *               der Gaeste, die durchschnittliche Temperatur und den Titel des wichtigsten Events des Monats ab.
 *               Gibt dann die Monate sortiert nach den verschiedenene Attributen aus. Danach wird ein Textmix
 *               durchgefuehrt bei dem o <-> a sowie O <-> A getauscht werden. Danach werden die Monate mit der
 *               kleinsten durchschnitts-Temperatur sowie der groessten Gaeste-Zahl bestimmt.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct monatsStatistik {
    int anzahlGaeste;
    double durchschnittsTemp;
    char eventTitel[256];
};

void ausgabeMonatsStatistik(struct monatsStatistik *monate, int laenge) {
    for (int i = 0; i < laenge; i++) {
        printf("Anzahl der Gaeste: %d\n", monate[i].anzahlGaeste);
        printf("Durschnitts-Temperatur: %lf\n", monate[i].durchschnittsTemp);
        printf("Titel des wichtigsten Events: %s\n", monate[i].eventTitel);
        printf("\n");
    }
}

bool vergleicheAnzahlGaeste(struct monatsStatistik a, struct monatsStatistik b) {
    return a.anzahlGaeste > b.anzahlGaeste;
}

bool vergleicheDurschnittsTemp(struct monatsStatistik a, struct monatsStatistik b) {
    return a.durchschnittsTemp > b.durchschnittsTemp;
}

bool vergleichEventTitel(struct monatsStatistik a, struct monatsStatistik b) {
    if (strcmp(a.eventTitel, b.eventTitel) <= 0) {
        return false;
    } else {
        return true;
    }
    // Is das gleiche wie:
    // return strcmp(a.eventTitel, b.eventTitel) > 0;
}

void tausche(struct monatsStatistik *a, struct monatsStatistik *b) {
    struct monatsStatistik tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortiere(struct monatsStatistik *monate, int anzahl, bool vergleich(struct monatsStatistik, struct monatsStatistik)) {
    for (int n = anzahl; n>1; n--) {
        for (int i = 0; i<n-1; i++) {
            if (vergleich(monate[i], monate[i + 1])) {
                tausche(&monate[i], &monate[i + 1]);
            }
        }
    }
}

void textmix(struct monatsStatistik *monate, int laenge) {
    for (int i = 0; i < laenge; i++) {
        for (int n = 0; n < strlen(monate[i].eventTitel); n++) {
            switch (monate[i].eventTitel[n]) {
                case 'a': {
                    monate[i].eventTitel[n] = 'o';
                }break;

                case 'o': {
                    monate[i].eventTitel[n] = 'a';
                }break;

                case 'A': {
                    monate[i].eventTitel[n] = 'O';
                }break;

                case 'O': {
                    monate[i].eventTitel[n] = 'A';
                }break;
            }
        }
    }
}

void minmax(struct monatsStatistik *monate, int laenge, struct monatsStatistik **pMin, struct monatsStatistik **pMax) {
    // Wir setzen den 1. Monat als Startwert:
    *pMin = &monate[0];
    *pMax = &monate[0];

    // i = 1 weil wir den 1. Monat nicht mit sich selbst vergleichen brauchen:
    for (int i = 1; i < laenge; i++) {
        if (monate[i].durchschnittsTemp < (*(*pMin)).durchschnittsTemp) {
            *pMin = &monate[i];
        }

        if (monate[i].anzahlGaeste > (*pMax)->anzahlGaeste) {
            *pMax = &monate[i];
        }
    }
}

int main() {
    struct monatsStatistik monate[12] = {
        {412, 2.34, "Holliday on Icecream"},
        {352, -11.32, "Skizirkus Graswandertoni"},
        {78, 3.72, "Haselnussbluete am Kroetenbrunnen"},
        {201, 5.68, "Rheingoldsuche mit Hagen"},
        {534, 11.11, "Siegfried und der Maidrache"},
        {478, 17.34, "Zauberfloete im Hochschul-Atrium"},
        {1267, 28.99, "Pfrimmschwimmen fuer Alle"},
        {1482, 24.02, "Heuschobernaechte rustikal"},
        {739, 19.44, "Indian Summer in der Pfalz"},
        {333, 10.55, "Weinlese im Weingut Oechsle"},
        {12, 6.66, "Eat what you can mit Martinsgans"},
        {856, -3.22, "Bratapfelwettbewerb im Heylshof"}
    };

    printf("Unsortierte Monate:\n");
    ausgabeMonatsStatistik(monate, 12);

    printf("\n\nMonate Sortiert nach Gaeste Anzahl:\n");
    sortiere(monate, 12, vergleicheAnzahlGaeste);
    ausgabeMonatsStatistik(monate, 12);

    printf("\n\nMonate Sortiert nach Druchschnittstemperatur:\n");
    sortiere(monate, 12, vergleicheDurschnittsTemp);
    ausgabeMonatsStatistik(monate, 12);

    printf("\n\nMonate alphabetisch sortiert nach Event-Titel:\n");
    sortiere(monate, 12, vergleichEventTitel);
    ausgabeMonatsStatistik(monate, 12);

    printf("\n\nMonate nach Textmix:\n");
    textmix(monate, 12);
    ausgabeMonatsStatistik(monate, 12);

    struct monatsStatistik *pMin;
    struct monatsStatistik *pMax;
    minmax(monate, 12, &pMin, &pMax);

    printf("\n\nMinimale Temperatur: %lf\nMaximale Gaeste: %d\n", pMin->durchschnittsTemp, pMax->anzahlGaeste);

    return 0;
}

