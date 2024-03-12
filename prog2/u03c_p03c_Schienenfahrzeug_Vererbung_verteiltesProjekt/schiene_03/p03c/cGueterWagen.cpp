#include "cGueterWagen.h"
#include <iostream>

using namespace std;


cGueterWagen::cGueterWagen(double nutz_in, double gew_in) : cWaggon(gew_in) {
	this->nutzlast = nutz_in;
}

/*  lastplus wird auf nutzlast addiert, gibt neuen Wert der nutzlast zurück */
double cGueterWagen::zuladen(double lastplus) {
	return this->nutzlast += lastplus;
}

/* lastweg wird von nutzlast abgezogen, gibt neuen Wert der nutzlast zurück */
double cGueterWagen::abladen(double lastweg) {
	double neu = this->nutzlast - lastweg;
	if (neu >= 0.0)
		this->nutzlast = neu;
	else
		cout << "Es kann nicht mehr als " << this->nutzlast << " kg Nutzlast abgeladen werden!" << endl;
	return this->nutzlast;
}
/*  Ueberschreibt get_gewicht() des Schienenfahrzeugs, gibt den Wert gewicht + nutzlast zurueck */
double cGueterWagen::get_gewicht() {
	return this->nutzlast + cWaggon::get_gewicht();
}
