#include "cDreieck.h"

/* globale Freundfunktion */
int dreieckVergleich(cDreieck d1, cDreieck d2) {
	if (d1.flaecheD() > d2.flaecheD()) return 1;
	if (d2.flaecheD() > d1.flaecheD()) return -1;
	return 0; 
}

int main() {
	cDreieck dreiecke[3] = {
		cDreieck(cPunkt(12.71, 1.78), cPunkt(1.64, 17.3), cPunkt(4.17, 5.42)),
		cDreieck(cPunkt(0.5, 1.0), cPunkt(1.5, 0.0), cPunkt(0.5, 0.0))
	};

	for each (cDreieck dreieck in dreiecke) {
		dreieck.ausgabe();
	}

	int vergleich = dreieckVergleich(dreiecke[0], dreiecke[1]);
	cout << "Dreieck 1 ist " << (vergleich == -1 ? "kleiner als" : vergleich ? "groesser als" : "gleich gross wie") << " (" << vergleich << ") Dreieck 2" << endl;

	vergleich = dreieckVergleich(dreiecke[1], dreiecke[2]);
	cout << "Dreieck 2 ist " << (vergleich == -1 ? "kleiner als" : vergleich ? "groesser als" : "gleich gross wie") << " (" << vergleich << ") Dreieck 3" << endl;

	return 0;
}