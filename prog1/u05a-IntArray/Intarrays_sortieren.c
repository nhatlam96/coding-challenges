/*
 * Sortierungsfunktion fuer Integerarrays
 * Dabei ist das Array zufaellig generiert
 *
 * 26.11.12 -- Robin Eschbach
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ausgabe(int * intArr, int length) {
	for(int i = 0; i < length; i++) {
		/* %5i = auf 5 Stellen ausgeben */
		printf("%5i ", *(intArr + i));
		/* 10 Zahlen pro Reihe. 9 damit die erste Zahl nicht einsam ist. */
		if(i % 10 == 9) {
			printf("\n");
		}
	}
}

void init(int * intArr, int length) {
	for(int i = 0; i < length; i++) {
		/* Setzen der Zufallszahl */
		/* % 10000 + 1 fuer den Zahlenbereich */
		*(intArr + i) = (rand() % 10000) + 1;
	}
}

void tausche(int * pointer1, int * pointer2) {
	/* Tauschen der Werte ohne Hilfsvariable */
	/* bsp:
	 * a = 5
	 * b = 7
	 */
	*pointer1 = *pointer1 + *pointer2;	/* a = 5 + 7 = 12 */
	*pointer2 = *pointer1 - *pointer2;	/* b = 12 - 7 = 5 */
	*pointer1 = *pointer1 - *pointer2;	/* a = 12 - 5 = 7 */
}

void sortiere(int * intArr, int length) {
	int exchanged;
	/* Bubblesort Algorithmus aus der Aufgabe */
	for(int n = length; n > 1; n--) {
		exchanged = 0;
		for(int i = 0; i < n - 1; i++) {
			if(*(intArr + i) > *(intArr + i + 1)) {
				tausche(intArr + i, intArr + i + 1);
				exchanged++;
			}
		}
		/* Optimiert, wenn in einem Durchlauf keine groeßere gefunden */
		/* Dann kann abgebrochen werden, da es schon komplett sortiert ist */
		if(exchanged == 0) {
			break;
		}
	}
}

int main() {
	srand(time(NULL));

	int intArr[1000];
	init(intArr, 1000);
	ausgabe(intArr, 1000);
	printf("\n\n");
	sortiere(intArr, 1000);
	ausgabe(intArr, 1000);

  return 0;
}
