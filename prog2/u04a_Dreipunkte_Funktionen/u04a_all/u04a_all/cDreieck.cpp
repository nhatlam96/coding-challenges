#include "cDreieck.h"

/* Universal-Konstruktor für Dreieck */
cDreieck::cDreieck(cPunkt p1, cPunkt p2, cPunkt p3) {
	punkte[0] = p1; 
	punkte[1] = p2;
	punkte[2] = p3;
}

/* Berechnet die Länge einer Strecke zwischen zwei Punkten */
double cDreieck::lenS(cPunkt p1, cPunkt p2) {
	return sqrt(pow(p2.getX()-p1.getX(),2) + pow(p2.getY() - p1.getY(), 2));
}

/* Berechnet den Umfang eines Dreiecks */
double cDreieck::umfangD() {
	return lenS(punkte[0], punkte[1]) + lenS(punkte[1], punkte[2]) + lenS(punkte[2], punkte[0]);
}

double cDreieck::flaecheD() {
	double s = umfangD()/2; 
	double a = lenS(punkte[0], punkte[1]);
	double b = lenS(punkte[1], punkte[2]);
	double c = lenS(punkte[2], punkte[0]);
	return (sqrt(s*(s - a)*(s - b)*(s - c)));
}

void cDreieck::ausgabe() {
	cout << "==== DREIECK ====" << endl; 
	int i = 0; 

	for each (cPunkt punkt in punkte)	{
		cout << "Koordinaten von p" << ++i << ": ";	punkt.ausgabe(); cout << endl; 
	}
	cout << endl;

	cout << "L" << (char)132 << "nge p1 <-> p2: " << lenS(punkte[0], punkte[1]) << endl;
	cout << "L" << (char)132 << "nge p2 <-> p3: " << lenS(punkte[1], punkte[2]) << endl;
	cout << "L" << (char)132 << "nge p3 <-> p1: " << lenS(punkte[2], punkte[0]) << endl;
	cout << endl;
	cout << "Umfang: " << umfangD() << endl;
	cout << "Fl" << (char)132 << "che: " << flaecheD() << endl;
	cout << endl; 
}
