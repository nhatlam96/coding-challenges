#include "cKinoPlatz.h"

#include <iostream>
using namespace std;

cKinoPlatz::cKinoPlatz() {
	static int zaehler = 0;

	art = ++zaehler <= 10 ? 2 : 1;	// die ersten 10 Plaetze sind Loge
	status = zaehler % 3 ? true : false;	// jeder dritte Platz ist belegt
}

ostream& operator << (ostream& o, const cKinoPlatz& kp) {
	o << (kp.art == 2 ? "Loge, " : "Parkett, ") << (kp.status == true ? "frei" : "belegt");
	return o;
}
