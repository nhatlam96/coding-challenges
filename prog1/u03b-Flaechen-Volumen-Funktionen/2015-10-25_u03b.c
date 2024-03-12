/* 2015-10-25_u03b.c
* Beschreibung:	Aufgabe u03b - Funktionen zum Rechnen mit geometrischen Figuren
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>


double eingabe(){
	/* Variable initialisieren */
	double eingabe_user;
	/* Benusereingabe entgegennehmen */
	scanf("%lf", &eingabe_user);
	return eingabe_user;
}


double zylinderVolumen(double flaecheninhalt, double hoehe){
	/* Berechnungen durchfuehren */
	double volumen_z_func = flaecheninhalt * hoehe;
	return volumen_z_func;
}


double kegelVolumen(double flaecheninhalt, double hoehe){
	/* Berechnungen durchfuehren */
	/* Ganzzahldivision korrekt ausfuehen */
	double volumen_k_func =  (1.0 / 3) * zylinderVolumen(flaecheninhalt, hoehe);
	return volumen_k_func;
}




double kreisFlaeche(double radius){
	/* Konstante initialisieren */
	const double pi = 3.141593;
	double flaecheninhalt = pi * radius * radius;
	/* Berechnungen durchfuehren */
	return flaecheninhalt;
}



int main() {

	/* Variablen initialisieren bzw vorab besetzen */
	double hoehe = 27.8;
	double radius = 7.2;
	double flaecheninhalt;
	double volumen_z;
	double volumen_k;


	/* Do-While Schleife in Verwendung, da Ende nicht absehbar. */
	do{

		/* Berechnungen per Funktionen durchfuehren - Benutzereingabe erst in Durchgang #2
		   abfragen, da hoehe und radius vorab schon Werte zugewiesen wurden. */
		flaecheninhalt = kreisFlaeche(radius);
		volumen_z = zylinderVolumen(flaecheninhalt, hoehe);
		volumen_k = kegelVolumen(flaecheninhalt, hoehe);

		/* Berechnete Werte ausgeben */
		printf("Kreis:\n");
		printf("Radius: 			       <%lf>\n", radius);
		printf("Flaecheninhalt: 		       <%lf>\n", flaecheninhalt);

		printf("======\n");
		printf("Zylinder:     \n");
		printf("Grundflaeche:			       <%lf>\n", flaecheninhalt);
		printf("Hoehe:				       <%lf>\n", hoehe);
		printf("Volumen:			       <%lf>\n", volumen_z);

		printf("======\n");
		printf("Kegel\n");
		printf("Volumen Zylinder:		       <%lf>\n", volumen_z);
		printf("Volumen Kegel:			       <%lf>\n", volumen_k);

		/* Benutzereingaben entgegennehmen - Erweiterung (b) */
		printf("Radius eingeben:\n");
		radius = eingabe();

		printf("Hoehe eingeben:\n");
		hoehe = eingabe();

		/* Abrechen bei '0'-Eingaben */
	}while(radius != 0 && hoehe != 0);

	printf("Programmende");
	

	
	return 0;
}
