/* Aufgabe u03d: Dreieck
 * Datum: 10.11.2022
 * Name: Daniela Heiﬂ
 * MTR: Nur in der Klausur angeben!!
 */

#include "cDreieck.h" //cPunkt und iostream bereits in cDreieck enthalten

int main() {
	cDreieck array [3] = { cDreieck(cPunkt(23.9, 3.13), cPunkt(5.24, -16.8), cPunkt(-6.72, 8.42)),
					       cDreieck(cPunkt(0.5, 1.0), cPunkt(1.5, 0.0), cPunkt(0.5, 0.0))};

	for (int i = 0; i < 3; i++) {
		cout << "Ausgabe Dreieck Nummer " << i + 1 << endl;
		array[i].ausgabe();
		cout << endl;
	}

	return 0;
}
