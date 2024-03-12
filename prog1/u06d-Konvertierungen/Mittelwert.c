/*
 * Ein Programm, das Summe, Minimum,
 * Maximum und Mittelwert einer Argumentliste sucht
 *
 * 17.12.18 -- Robin Eschbach
 *
 */

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * args[]) {
	int anzahl = 0;
	double summe = 0;
	double mittelwert = 0;
	/* Jeder Wert ist <= dem Groessten Wert, den man eingeben kann */
	/* Um das Minimum zu suchen, sollten wir mit dem groessten Wert anfangen */
	double minimum = DBL_MAX;
	/* Gleiches Prinzip wie oben */
	double maximum = DBL_MIN;

	/* Platzhalter fuer Argument, Ende des Argumentes und Wert des Argumentes */
	char * arg;
	char * end;
	double val;

	/* Anfang bei 1, da 0. Element der Programmname ist */
	for(int i = 1; i < argc; i++) {
		arg = args[i];
		/* Konvertiert arg zu double und speichert, was hinten abfaellt */
		/* bsp: strod("123ende", &end) -> end = "ende" */
		val = strtod(arg, &end);
		/* Wenn in end etwas drinsteht, war es keine Zahl */
		if(strcmp(end, "") == 0) {
			anzahl++;
			summe += val;
			/* Ist val kleiner als Minimum, wurde ein neues Minimum gefunden */
			if(val < minimum) {
				minimum = val;
			}
			/* Das Selbe, wie oben */
			if(val > maximum) {
				maximum = val;
			}
		}
	}

	/* Standard Mittelwertrechnung */
	mittelwert = summe / anzahl;

	printf("\nAnzahl: %i\nSumme: %lf\nMittelwert: %lf\nMinimum: %lf\nMaximum: %lf\n", anzahl, summe, mittelwert, minimum, maximum);

	return 0;
}
