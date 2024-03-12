/* 2015-10-13_u02a.c
* Beschreibung:	Aufgabe u02a - Schleifen und Summen
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
int main() {


	/* Variablen initialisieren */
	int zahl_current;
	int summe = 0;
	int zahl_max = 42;


	for(zahl_current = 1;zahl_current <= zahl_max;zahl_current++){

		summe += zahl_current;

	}

	printf("Die Summe der Zahlen 1 bis %i ist: %i\n", zahl_max, summe);

	do{
		/*Summe auf 0 setzen - wir verschwenden keine Variablen !!*/
		summe = 0;

		printf("Bitte Ganzzahl eingeben:\n");
		scanf("%i", &zahl_max);
		printf("Die vom Benutzer eingegebene Zahl lautet: %i \n", zahl_max);


		for(zahl_current = 0;zahl_current <= zahl_max;zahl_current++){

			summe += zahl_current;

		}

		printf("Die Summe der Zahlen 1 bis %i ist: %i\n", zahl_max, summe);

		/*Abbruch bei Eingabe von 0*/
	}while(zahl_max != 0);



	float ergebnis_multiplikation = 0.0;
	float eingabe_float = 0.0;
	do{

		printf("Bitte Gleitkommazahl eingeben:\n");
		scanf("%f", &eingabe_float);
		printf("Die vom Benutzer eingegebene Zahl lautet: %f \n", eingabe_float);

		ergebnis_multiplikation = eingabe_float * 1.19;


		printf("Das Ergebnis der Multiplikation von %f und 1.19 ist: %f\n", eingabe_float, ergebnis_multiplikation);

		/* Abbruch bei Eingabe von 0.0 */
	}while(eingabe_float != 0.0);

	

	
	return 0;
}
