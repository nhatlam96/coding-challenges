/* 2015-10-19_u03a.c
* Beschreibung:	Aufgabe u03a - Umgang mit Rechenoperationen
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
int main() {

	/* Konstante initialisieren */
	const double pi = 3.141593;
	/* Variablen initialisieren */
	double hoehe;
	double radius;
	double flaecheninhalt;
	double volumen_z;
	double volumen_k;


	/* Do-While Schleife in Verwendung, da Ende nicht absehbar. */
	do{
		/* Benutzereingaben entgegennehmen */
		printf("Radius eingeben:\n");
		scanf("%lf", &radius);

		printf("Hoehe eingeben:\n");
		scanf("%lf", &hoehe);

		/* Berechnungen durchführen */
		flaecheninhalt = pi * radius * radius;
		volumen_z = flaecheninhalt *  hoehe;
		volumen_k = (1.0/3) * flaecheninhalt * hoehe;

		/* Berechnete Werte ausgeben */
		printf("Kreis:\n");
		printf("Radius: 			       %lf\n", radius);
		printf("Flaecheninhalt: 		       %lf\n", flaecheninhalt);

		printf("======\n");
		printf("Zylinder:     \n");
		printf("Grundflaeche:			       %lf\n", flaecheninhalt);
		printf("Hoehe:				       %lf\n", hoehe);
		printf("Volumen:			       %lf\n", volumen_z);

		printf("======\n");
		printf("Kegel\n");
		printf("Volumen Zylinder:		       %lf\n", volumen_z);
		printf("Volumen Kegel:			       %lf\n", volumen_k);

		/* Abrechen bei 0-Eingaben */
	}while(radius != 0 && hoehe != 0);

	printf("Programmende");
	

	
	return 0;
}
