/*
 * Aufgabe: Schleifen-Buchstaben Quersumme
 *
 * Liest Buchstaben vom Eingabestrom ein
 * und zaelht die Anzahl der Zeichen in
 * verschiedenen Gruppen
 *
 *
 *
 * 22.10.18 -- Robin Eschbach
 *
 */

#include <stdio.h>

int quersumme(int quer, char zahl) {
  /* Ziffer in Zahl umkonvertieren */
  int z = zahl - '0';
  /* Zur Quersumme hinzufuegen und zurueckgeben */
  return quer + z;
}

int main() {
  /* Begruesst den Benutzer */
  printf("Guten Tag. Geben sie ein paar Buchstaben ein (Beendet wird mit EOF -> strg + D):\n");

  /* Deklarieren der 'buchstaben' Variable */
  char buchstabe;

  /* Deklarieren und Initialisieren der Zahlvariablen */
  int gross = 0;
  int klein = 0;
  int ziffer = 0;
  int steuer = 0;
  int andere = 0;

  /* Deklarieren und Initialisieren der Quersummenvariable */
  int quer = 0;

  /* Start der do-while Schleife */
  do {
    /* Liest ein Zeichen aus dem Eingabestrom in die 'buchstaben' Variable */
    buchstabe = (char) getchar();

    /* Abbruch falls EOF gefunden */
    if(buchstabe == EOF) {
      break;
    }

    /* Ueberpruefen der einzelnen Zaehlkonditionen */

    if(buchstabe >= 'A' && buchstabe <= 'Z') {  /* Grossbuchstaben */
      gross++;
    }
    else if(buchstabe >= 'a' && buchstabe <= 'z') { /* Kleinbuchstaben */
      klein++;
    } else if(buchstabe >= '0' && buchstabe <= '9') { /* Ziffernbuchstaben */
      ziffer++;

      /* Berechne die Quersumme */
      quer = quersumme(quer, buchstabe);
      if(quer >= 42) {  /* Abbrechen, wenn Quersumme >= 42 */
        printf("\n\nDie Quersumme ist %i\n", quer);
        break;
      }
    } else if(buchstabe < ' ') {  /* Steuerzeichen */
      steuer++;
    } else {  /* Andere Zeichen */
      andere++;
    }

    /* Ausgeben des Buchstabens */
    putchar(buchstabe);
    /* Failcheck: Beende die Schleife bei EOF */
  } while(buchstabe != EOF);

  /* Die Zahlervariablen ausgeben */
  printf("\n\nGezaehlt wurden:\n");
  printf("Grossbuchstaben: %i\nKleinbuchstaben: %i\nZiffernbuchstaben: %i\nSteuerzeichen: %i\nAndere Zeichen: %i\n", gross, klein, ziffer, steuer, andere);
}
