/* 2015-11-08_u06a.c
* Beschreibung:	Aufgabe u06a - Funktionen, Aufrufparameter, Rueckgabewerte
* !!ACHTUNG DAS IST KEINE GUTE LÖSUNG!!
* Name	      : pspzockerscene@jabber.ccc.de
*/

#include <stdio.h>
#include <math.h>

double u(double h, double winkela, double winkelb){

	double ergebnis = h * winkela / winkelb;
	return ergebnis;

}

double gradToBogen(double grad){

	/* Konstante initialisieren */
	const double pi = 3.141593;
	double ergebnis = (pi / 180) * grad;
	return ergebnis;

}

double phi(double winkela, double winkelb){

	double ergebnis = 180 - (winkela + winkelb);
	return ergebnis;

}

double hoehe(double laenge, double winkela, double winkelb){

	double varphi = phi(winkela, winkelb);
	//double winkela_bogen = gradToBogen(winkela);
	double ergebnis = u(laenge, winkela, winkelb) * sin(varphi);
	return ergebnis;

}


double bogenToGrad(double rad){

	/* Konstante initialisieren */
	const double pi = 3.141593;
	double ergebnis = (180 / pi) * rad;
	return ergebnis;

}

int main() {

	/* Variablen initialisieren */
	double laenge;
	double winkela;
	double winkelb;
	double varphi;
	double varhoehe;

	/* Benutzereingaben einlesen */
	printf("Laenge eingeben\n");
	scanf("%lf", &laenge);
	printf("Winkel alpha eingeben\n");
	scanf("%lf", &winkela);
	printf("Winkel beta eingeben\n");
	scanf("%lf", &winkelb);

	/* Berechnungen durchfuehren */
	varhoehe = hoehe(laenge, winkela, winkelb);
	varphi = phi(winkela, winkelb);
	//varphi_grad = bogenToGrad(varphi);

	/* Ergebnisse ausgeben */
	printf("Der Turm hat eine Hoehe von: %lf Metern.\n", varhoehe);
	printf("Die Strecke s betraegt %lf Meter.\n", laenge);
	printf("Der Winkel alpha betraegt %lf Grad.\n", winkela);
	printf("Der winkel betra betraegt %lf Grad.\n", winkelb);
	printf("Der Winkel phi betraegt %lf Grad.\n", varphi);

	


	printf("\nProgrammende\n");

	return 0;
}
