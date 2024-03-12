/* p11c.c
* Name: Eric Finger
* Datum: 04.01.23
* Beschreibung: Generiert aus einem via CLI-Parametern uebergebenen Satz ein Passwort,
*               indem es die erstes Buchstaben des Satzes ausgibt. Haertet das Passwort
*               optional wenn "-h" als Parameter uebergeben wird, indem es eine Ersetzung
*               von Buchstaben durchfuehrt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genPasswd(int argc, char *argv[], char *passphrase) {
    for(int i = 1; i < argc; i++) {
        // Den 1. Buchstaben der Woerter in passphrase speichern:
        *passphrase = argv[i][0];
        passphrase++;
    }
    *passphrase = '\0';
}

void hardenPasswd(char *passphrase) {
    for(int i = 0; i < strlen(passphrase); i++) {
        switch (passphrase[i]) {
            case 'S' : {
                passphrase[i] = '$';
            }break;

            case 'h' : {
                passphrase[i] = '#';
            }break;

            case 'i' : {
                passphrase[i] = '!';
            }break;

            case 'B' : {
                passphrase[i] = '8';
            }break;

            case 'x' : {
                passphrase[i] = '%';
            }break;

            case 'C' : {
                passphrase[i] = '(';
            }break;

            case 'e' : {
                passphrase[i] = '3';
            }break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Verwendung: %s <-h> [SATZ]\n", argv[0]);
        return 1;
    }

    char *passphrase = malloc(sizeof(char) * argc);

    if (strcmp(argv[1], "-h") == 0) {
        argv++;
        argc--;
    }

    genPasswd(argc, argv, passphrase);

    printf("Ihr eingegebenes Wort: ");
    
    for(int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    printf("\n");
    printf("Ihr Passwort: %s\n", passphrase);

    if (strcmp(argv[0], "-h") == 0) {
        hardenPasswd(passphrase);
        printf("Ihr gehaertetes Passwort: %s\n", passphrase);
    }

    free(passphrase);

    return 0;
}

