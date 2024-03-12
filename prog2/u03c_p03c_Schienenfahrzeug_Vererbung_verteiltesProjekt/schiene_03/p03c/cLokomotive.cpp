#include "cLokomotive.h"
#include <iostream>

using namespace std;

cLokomotive::cLokomotive(double triebkraft = 0.0, double gewicht = 0.0) : cSchienenFahrzeug(gewicht) {
	this->triebkraft = triebkraft;
}


/*  Gibt "ich zieh Euch alle" aus */
void cLokomotive::ankuppeln() {
	cout << "ich zieh Euch alle" << endl;
}

/* Gibt den "Power"-Wert der Lok ((gewicht + treibstoff) * triebkraft) geteilt durch 1000.0 zurueck */
double cLokomotive::bereitstellen(double treibstoff) {
	return ((get_gewicht() + treibstoff) * triebkraft) / 1000;

}
