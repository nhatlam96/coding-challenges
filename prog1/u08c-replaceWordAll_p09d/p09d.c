/* p09d.c
 * Name: Eric Finger 
 * Datum: 07.12.2022
 * Beschreibung: Findet eine Zeichenfolge in einem String und ersetzt diese durch eine Andere. Hierbei wird ein 
 *               Buffer-Overflow verhindert, und subst kann kleiner/groesser sein ohne andere Zeichen zu ueberschreiben.
 *               Die replaceWordAll-Funktion kann benutzt werden um ALLE vorkommnisse eines Wortes zu ersetzen.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void replaceWord(char *work, char *find, char *subst, int bufsiz) {
    bool foundFind = false;
    int indexFindInWork = 0;

    // Findet 'find' in found:
    for (int i = 0; i < strlen(work); i++) {
        if (work[i] == find[0]) {
            foundFind = true;
            // Wenn der erste Buchstabe stimmt die Restlichen vergleichen:
            for (int n = 1; n < strlen(find); n++) {
                if (work[i + n] != find[n]) {
                    foundFind = false;
                    break;
                }
            }
        }

        if (foundFind) {
            indexFindInWork = i;
            break;
        }
    }

    if (!foundFind) {
        printf("'%s' nicht in '%s' gefunden.\n", find, work);
        return;
    }

    char hilfe[1024];
    // Den "Rest" des work-arrays nach hilfe kopieren:
    strncpy(hilfe, work + indexFindInWork + strlen(find), 1024);

    // Den Rest des Arrays nullen (wichtig wenn subst kleiner ist als find).
    for (int i = indexFindInWork; i < bufsiz; i++) {
        work[i] = '\0';
    }

    // subst an die Stelle von find kopieren: 
    for (int i = 0; i < strlen(subst); i++) {
        if ((indexFindInWork + i) > bufsiz) {
            printf("Nicht genug Platz im work Array!\n");
            return;
        }
        
        work[indexFindInWork + i] = subst[i];
    }

    // Den Rest des Arrays wieder anhaengen:
    for (int i = 0; i < strlen(hilfe); i++) {
        if ((indexFindInWork + strlen(subst) + i) > bufsiz) {
            printf("Nicht genug Platz im work Array!\n");
            return;
        }

        work[indexFindInWork + strlen(subst) + i] = hilfe[i];
    }

    // Den String Null-Terminieren:
    work[indexFindInWork + strlen(subst) + strlen(hilfe) + 1] = '\0';
}

void replaceWordAll(char *work, char *find, char *subst, int bufsiz) {
    char *found = strstr(work, find);
    if (found == NULL) {
        // Wenn wir "find" nichtmehr in work finden sind wir fertig
        return;
    } else {
        // Buffersize korregieren (da wir alles bis "find" abschneiden):
        bufsiz = bufsiz - (found - work);
        replaceWord(found, find, subst, bufsiz);
        // Den Pointer auf die Stelle nach dem ersetzten Wort setzen (um Doppel-Ersetzungen zu vermeiden)
        found += strlen(subst);
        // Die Buffersize korregieren:
        bufsiz -= strlen(subst);
        replaceWordAll(found, find, subst, bufsiz);
    }
}

int main() {
    char testString[1024] = "Die Muf sieht mit Grufsen eine Pin mit Brufe durch die Klufe sufen";
    replaceWord(testString, "Pin", "Luf", 1024);
    printf("%s\n", testString);
    replaceWordAll(testString, "uf", "aus", 1024);
    printf("%s\n", testString);

    return 0;
}

