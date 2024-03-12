#include "cDieselLok.h"

cDieselLok::cDieselLok(double trieb_in, double gew_in) : cLokomotive(trieb_in, gew_in) {}

/* Gibt die Tankmenge 2000.0 zurück */
double cDieselLok::tanken() {
	return 2000.0;
}

/* Zählt zum Parameter treibstoff das Ergebnis von tanken() dazu, nimmt das Ergebnis als Treibstoffmenge und ruft bereitstellen() der Basisklasse auf */
double cDieselLok::bereitstellen(double treibstoff) {
	return cLokomotive::bereitstellen(treibstoff + tanken());
}