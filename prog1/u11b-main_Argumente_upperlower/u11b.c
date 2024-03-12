/* u11b.c
 * Name: Eric Finger
 * Datum: 21.12.2022
 * Beschreibung: Dieses Programm fuehrt, je nach Aufrufnamen, unterschiedliche Funktionen aus:
 *               upper: wandelt alle Parameter in Uppercase um
 *               lower: wandelt alle Parameter in Lowercase um
 *               generatePass: Generiert ein Passwort aus den Anfangsbuchstaben eines eingegebenen Satzes
 *               pali: Generiert ein Palindrom aus allen eingegebenen Woertern
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (!strcmp(argv[0], "./upper")) {
        // Fuer alle Parameter:
        for (int i = 1; i < argc; i++) {
            // Fuer alle character:
            for (int c = 0; c < strlen(argv[i]); c++) {
                putchar(toupper(argv[i][c]));
            }
            printf(" ");
        }
        
        printf("\n");
    }

    if (!strcmp(argv[0], "./lower")) {
        // Fuer alle Parameter:
        for (int i = 1; i < argc; i++) {
            // Fuer alle character:
            for (int c = 0; c < strlen(argv[i]); c++) {
                putchar(tolower(argv[i][c]));
            }
            printf(" ");
        }

        printf("\n");
    }

    if (!strcmp(argv[0], "./generatePass")) {
        // Fuer alle Parameter:
        for (int i = 1; i < argc; i++) {
            putchar(argv[i][0]);
        }

        printf("\n");
    }

    if (!strcmp(argv[0], "./pali")) {
        for (int i = 1; i < argc; i++) {
            // Das Wort vorwärts ausgeben:
            // (alternativ:)
            // printf("%s", argv[i]);
            for (int c = 0; c < strlen(argv[i]); c++) {
                putchar(argv[i][c]);
            }

            // Das Wort rueckwaerts ausgeben:
            for (int c = strlen(argv[i]) - 1; c >= 0; c--) {
                putchar(argv[i][c]);
            }


            printf(" ");
        }
        printf("\n");
    }

    return 0;
}

