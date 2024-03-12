#include "cBruch.h"

cBruch::cBruch(int zaehler_in, int nenner_in)
{
	zaehler = zaehler_in;

	if (nenner_in == 0) {
		nenner = 1;
	}
	else if (nenner_in < 0) {
		nenner = nenner_in *-1;
		zaehler = zaehler_in * -1; //Um -1 erweitern, sodass Vorzeichen getauscht werden
	}
	else {
		nenner = nenner_in;
	}
}

cBruch::cBruch(const cBruch& b) { //Kopierkonstruktor
	zaehler = b.zaehler; 
	nenner = b.nenner;
}

void cBruch::ausgabe() {
	cout << zaehler << "/" << nenner << " (" << (double)zaehler / nenner << ")" << endl;
}

int cBruch::ggT(int x, int y) {
	if (y == 0)
		return x;
	else return ggT(y, x % y);
}

void cBruch::kuerzen() {
	int temp = ggT(zaehler, nenner);
	
	if (nenner != 0) {					//Abfangen von Nulldivision, hier ganz gut geeignet, da kuerzen immer bei Wertaenderungen aufgerufen wird
		zaehler = zaehler / temp;
		nenner = nenner / temp;
	}
	else {
		zaehler = 0;
		nenner = 1;
	}
}

double cBruch::getGleitkomma() {
	double gleitKomma = (double)zaehler / nenner;
	return gleitKomma;
}

//Freund-Funktionen

cBruch add(cBruch a, cBruch b) {
	cBruch c;

	c.zaehler = ((a.zaehler * b.nenner) + (b.zaehler * a.nenner));
	c.nenner = a.nenner * b.nenner;

	c.kuerzen();
	return c;
}

cBruch subt(cBruch a, cBruch b) {
	cBruch c;

	c.zaehler = ((a.zaehler * b.nenner) - (b.zaehler * a.nenner));
	c.nenner = a.nenner * b.nenner;

	c.kuerzen();
	return c;
}

cBruch mul(cBruch a, cBruch b) {
	cBruch c;

	c.zaehler = a.zaehler * b.zaehler;
	c.nenner = a.nenner * b.nenner;

	c.kuerzen();
	return c;
}

cBruch div(cBruch a, cBruch b) {
	cBruch c;

	c.zaehler = a.zaehler * b.nenner;
	c.nenner = a.nenner * b.zaehler;

	c.kuerzen();
	return c;
}

int vergleich(cBruch a, cBruch b) {
	if (a.getGleitkomma() < b.getGleitkomma()) {
		return -1;
	}
	else if (a.getGleitkomma() == b.getGleitkomma()) {
		return 0;
	}
	else { //Keine erneute if-Abfrage notwendig, Kleiner oder gleich bereits ausgeschlossen
		return 1;
	}
}

void tausch(cBruch& b1, cBruch& b2) { //Tauschen mit Referenzen
	cBruch b3 = b1;
	b1 = b2;
	b2 = b3;
}

void sortier(cBruch arr[]) {
	for (int n = 8; n > 1; n--) {
		for (int i = 0; i < n - 1; i++) {
			if (vergleich(arr[i], arr[i + 1]) == 1) { // Elemente vergleichen
				tausch(arr[i], arr[i + 1]); // Elemente tauschen
			}
		}
	}
}

ostream& operator << (ostream& o, cBruch& b) {
	return o << b.zaehler << " / " << b.nenner << ", (" << b.getGleitkomma() << ")";
}