#include "cClassArr.h"

cClassArr::cClassArr(int anz_in) {
	anz = anz_in < 0 ? 1 : anz_in;		// negative Werte abfangen

	if (!(p = new class cKinoPlatz[anz])) {	// Speicher holen fehlerhaft ?
		anz = 0;
	}
}

class cKinoPlatz& cClassArr::operator [] (const int& index) {
	if (index >= 0 && index < anz) {
		return p[index];
	}

	cerr << " ! Fehlindizierung: " << index << " (zulaessig: 0 bis " << anz - 1 << ")" << endl;

	if (p) {				// wenn Ressourcen belegt wurden
		delete[] p;			// sauber aufraeumen
		p = 0;
		anz = 0;
	}

	exit(1);
}

cClassArr::~cClassArr() {
	if (p) {				// wenn Ressourcen belegt wurden
		delete[] p;			// sauber aufraeumen
		p = 0;
		anz = 0;
	}
}