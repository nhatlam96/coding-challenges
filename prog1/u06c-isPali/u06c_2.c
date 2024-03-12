/*
 * Ueberprueft, ob eine Zeichenkette ein Palindrome ist.
 *
 * 12.11.18 -- Robin Eschbach
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPali(char zeichenkette[]) {
  static int offset = 0;

  /* Abbruch wenn mehr als die Haelfte ueberprueft. */
  if(offset > strlen(zeichenkette) / 2) {
    offset = 0;
    return true;
  }

  /* Guckt, ob vorne und hinten das Zeichen */
  /* mit dem Offset counter gleich ist */
  if(zeichenkette[offset] == zeichenkette[strlen(zeichenkette) - offset - 1]) {
    offset++;
    /* Wenn ja, ueberpruefe mit einem Offset hoeher */
    return isPali(zeichenkette);
  } else {
    /* Wenn nein, Offset auf 0 und kein Palindrom */
    offset = 0;
    return false;
  }
}

int main() {
  char zeichenkette[21];

  printf("Geben Sie eine Zeichenkette ein(Max. 20 Zeichen, Ende mit strg+D): ");

  /* Einlesen einer Zeichenkette von max. 20 Zeichen */
  char c;
  int zaehler = 0;
  do {
    c = getchar();
    if(c != EOF) {
      zeichenkette[zaehler++] = c;
    }
  } while(c != EOF && zaehler < 20);
  /* Hinzufuegen des 0 Bytes */
  zeichenkette[zaehler] = '\0';

  /* Ausgabe, ob Palindrom oder nicht */
  if(isPali(zeichenkette)) {
    printf("\n%s ist ein Palindrom\n", zeichenkette);
  } else {
    printf("\n%s ist kein Palindrom\n", zeichenkette);
  }
}
