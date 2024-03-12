/* u10a.c
Name: Eric Finger
Datum: 14.12.2022
Beschreibung: Programm zur Verwaltung eines Speed-Networking Events. Erfasst Teilnehmer und speichert
              sie in einer verketteten Liste. Bietet dem Nutzer ein Menue um alle Teilnehmer
              anzuzeigen, oder auch um die Teilnehmer nach Tischen sortiert anzuzeigen. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node {
    struct Teilnehmer *teilnehmer;
    struct Node *next;
};

struct Teilnehmer {
    char vorname[128];
    char nachname[128];
    char beruf[128];
    int tisch;
};

// Haengt ein neues Element der gegebenen verketteten Liste an
struct Node *newElement(char *vorname, char *nachname, char *beruf, struct Node *currentElement) {
    struct Teilnehmer *element = (struct Teilnehmer*)malloc(sizeof(struct Teilnehmer));
    strcpy(element->vorname, vorname);
    strcpy(element->nachname, nachname);
    strcpy(element->beruf, beruf);
    element->tisch = (rand() % 4) + 1;

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->teilnehmer = element;
    // Da wir ein neues letztes Element der Liste erzeugen legen wir next auf NULL um das Ende der Liste anzuzeigen
    new->next = NULL;
    currentElement->next = new;

    return new;
}

void ausgabeAlleTeilnehmer(struct Node *start) {
    struct Node *current = start;
    // Liste einmal durchlaufen und ausgeben:
    do {
        printf("Vorname: %s\n", current->teilnehmer->vorname);
        printf("Nachname: %s\n", current->teilnehmer->nachname);
        printf("Berufsbezeichnung: %s\n", current->teilnehmer->beruf);
        printf("Tisch: %d\n\n", current->teilnehmer->tisch);
        current = current->next;
    } while (current != NULL);
}

void ausabeNachTischen(struct Node *start) {
    struct Node *current = start;

    // Wir durchlaufen die Liste 4 mal und geben jeweils nur die Teilnehmer des Tisch's aus:
    for (int tisch = 1; tisch <= 4; tisch++) {
        printf("Tisch %d:\n", tisch);

        do {
            if (current->teilnehmer->tisch == tisch) {
                printf("\tVorname: %s\n", current->teilnehmer->vorname);
                printf("\tNachname: %s\n", current->teilnehmer->nachname);
                printf("\tBerufsbezeichnung: %s\n\n", current->teilnehmer->beruf);
            }

            current = current->next;
        } while (current != NULL);

        // Zuruecksetzen auf den Start der Liste:
        current = start;
    }
}

void aufloesen(struct Node *start) {
    struct Node *current = start;
    struct Node *next;

    do {
        free(current->teilnehmer);
        // next zwischen-Speichern:
        next = current->next;
        free(current);
        current = next;
    } while (current != NULL);
}

int main() {
    srand(time(NULL));

    struct Teilnehmer *start = (struct Teilnehmer*)malloc(sizeof(struct Teilnehmer));
    strcpy(start->vorname, "Heinz");
    strcpy(start->nachname, "Hose");
    strcpy(start->beruf, "Schneidermeister");
    start->tisch = (rand() % 4) + 1;
    
    struct Node *startListe = (struct Node *)malloc(sizeof(struct Node));
    startListe->teilnehmer = start;
    startListe->next = NULL;

    struct Node *letztesElement;

    letztesElement = newElement("Rudi", "Rohrbruch", "Wasserinstallateur", startListe);
    letztesElement = newElement("Petra", "Planlos", "Architektin", letztesElement);
    letztesElement = newElement("Armin", "Gips", "Stuntman", letztesElement);
    letztesElement = newElement("Nora", "Notfall", "Nachtschwester", letztesElement);
    letztesElement = newElement("Stella", "Standup", "Fitnesstrainerin", letztesElement);

    int wahl;

    while (1) {
        printf("Waehlen Sie eine Option:\n");
        printf("1 - Alle Teilnehmer anzeigen\n");
        printf("2 - Teilnehmer nach Tischen anzeigen\n");
        printf("0 - Programm beenden\n");
        scanf("%d", &wahl);

        switch (wahl) {
            case 0: {
                aufloesen(startListe);
                startListe = NULL;
                exit(0);
            }break;

            case 1: {
                ausgabeAlleTeilnehmer(startListe);
            }break;

            case 2: {
                ausabeNachTischen(startListe);
            }break;

            default: {
                printf("Option '%d' nicht erkannt\n\n", wahl);
            };
        }
    }

    // Unreachable:
    return 0;
}

