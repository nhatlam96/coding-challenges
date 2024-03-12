/* u07a.c
 * Name: Eric Finger
 * Datum: 23.11.2022
 * Beschreibung: Bildet aus einem vom Nutzer eingegebenem Wort ein Palindrom und gibt es aus.
 *               Danach kann der Nutzer ein weiteres Wort eingeben dass dann mit ROT13 
 *               ver-/entschluesselt und ausgegeben wird.
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

void rot13(char input[], char output[]) {
    int stelle = 0;
    while (input[stelle] != '\0') {
        char arbeit = input[stelle];

        if (arbeit >= 'a' && arbeit <= 'm') {
            // Die Zeichen von a - m werden fuer ROT13 um 13 Stellen nach oben geschoben
            output[stelle++] = arbeit + 13;
        } else if (arbeit >= 'n' && arbeit <= 'z') {
            // Die Zeichen von n - z werden fuer ROT13 um 13 Stellen nach unten geschoben
            output[stelle++] = arbeit - 13;
        } else {
            // Alle nicht-Kleinbuchstaben werden unveraendert uebernommen
            output[stelle++] = arbeit;
        }
    }

    output[stelle] = '\0';
}

int main() {
    char input[MAX_LENGTH + 1];
    char palindrom[MAX_LENGTH * 2 + 1];

    int laenge = 0;

    printf("Geben Sie ein Wort (maximal 20 Buchstaben) ein aus dem ein Palindrom gebildet werden soll: ");
    do {
        char in = getchar();

        if (in == '\n') {
            break;
        }

        input[laenge++] = in;
    } while (laenge < MAX_LENGTH);

    input[laenge] = '\0';
    printf("Ihr eingegenes Wort: '%s'\n", input);

    int input_len = strlen(input);
    strncpy(palindrom, input, MAX_LENGTH);

    // Wir kopieren das eingegebene Wort rueckwaerts an unseren input, 
    // sodass aus abcde -> abcdeedcba wird:
    for (int i = 0; i < input_len; i++) {
        palindrom[input_len + i] = input[input_len - 1 - i];
    }

    palindrom[input_len * 2] = '\0';

    printf("Ihr Palindrom: '%s'\n", palindrom);
    
    char inputRot13[MAX_LENGTH + 1];
    char outputRot13[MAX_LENGTH + 1] = {};
    printf("Geben Sie ein Wort ein das ROT13 ver-/entschlüsselt wird: ");
    scanf("%s", inputRot13);

    rot13(inputRot13, outputRot13);

    printf("Ihr eingegebenes Wort: %s\n", inputRot13);
    printf("Das Rot13 Ergebnis: %s\n", outputRot13);

    return 0;
}

