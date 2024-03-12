/*
 * Liest Buchstaben ein und wandelt sie
 * in eine Zahl um.
 * Dabei wird der Ueberlauf ignoriert.
 *
 * Robin -- 05.11.18
 *
 */

#include <stdio.h>


int fuegeCharZuIntHinzu(int zahl, char ziffer) {
  /* Fuegt die Ziffer hinten an die Zahl an */
  int erg = zahl * 10 + (ziffer - '0');

  /* Da bei einem Ueberlauf in den Minusbereich */
  /* gesprungen wird, koennen wir in so erkennen. */
  if(erg < 0) {
    return zahl;
  }
  return erg;
}

double fuegeCharZuDoubleHinzu(double zahl, char ziffer) {
  /* Fuegt die Ziffer hinten an die Zahl an */
  return zahl * 10 + (ziffer - '0');
}


int main() {
  char c;
  int ganzzahl = 0;
  double gleitkomma = 0;

  printf("Geben Sie eine Zahl im Textformat ein (Ende mit EOF - STRG + D): ");

  do {
    /* Liest einen Buchstaben ein */
    c = getchar();

    /* Ueberpruefen ob Buchstabe eine Ziffer ist */
    if(c >= '0' && c <= '9') {
      ganzzahl = fuegeCharZuIntHinzu(ganzzahl, c);
      gleitkomma = fuegeCharZuDoubleHinzu(gleitkomma, c);
    }

  } while(c != EOF);

  /* Ausgabe der Zahlen. %.18e Formatiert die Gleitkommazahl */
  /* In das Wissenschaftliche Format */
  printf("\nIhre Ganzzahl ist: %i\nIhre Gleitkommazahl ist: %.18E\n", ganzzahl, gleitkomma);
}
