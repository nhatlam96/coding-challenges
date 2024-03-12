#include "cPersonenWagen.h"
#include <iostream>
using namespace std;
cPersonenWagen::cPersonenWagen(int fahrg_in, double gew_in) :cWaggon(gew_in) {
	this->fahrgastzahl = fahrg_in;
}


/*  Erhoeht die Anzahl der Fahrgaeste; Begrenzung auf <= 117; gibt neue Fahrgastzahl zurueck */
int cPersonenWagen::einsteigen(int rein) {
	int neu = fahrgastzahl + rein;

	if (neu <= 117) {
		this->fahrgastzahl = neu;
	}
	else {
		cout << "Der Wagen kann maximal 117 Personen transportieren!" << endl;
	}
	return this->fahrgastzahl;
}

/* Vermindert die Zahl der Fahrgaeste; Begrenzung auf >=0; gibt neue Fahrgastzahl zurueck */int cPersonenWagen::aussteigen(int raus) {
	int neu = this->fahrgastzahl - raus;
	if (neu >= 0) {
		this->fahrgastzahl = neu;
	}
	else {
		cout << "Es können nicht mehr als " << this->fahrgastzahl << " Leute(n) aussteigen!" << endl;
	}
	return this->fahrgastzahl;
}