/* Aufgabe u05d: Dreieck
 * Datum: 10.11.2022
 * Name: Daniela Heiﬂ
 * MTR: Nur in der Klausur angeben!!
 */

#include "cDreieck.h" //cPunkt und iostream bereits in cDreieck enthalten

int main() {
	cDreieck array [3] = { cDreieck(cPunkt(14.3, 2.14), cPunkt(1.24, 16.3), cPunkt(4.73, 6.42)),
					       cDreieck(cPunkt(0.5, 1.0), cPunkt(1.5, 0.0), cPunkt(0.5, 0.0))};

	for (int i = 0; i < 3; i++) {
		cout << "Ausgabe Dreieck Nummer " << i + 1 << endl;
		array[i].ausgabe();
		cout << endl;
	}

	cout << "Vergleich Dreieck 1 und 2: " << dreieckVergleich(array[0], array[1]) << endl;
	cout << "Vergleich Dreieck 2 und 3: " << dreieckVergleich(array[1], array[2]) << endl;

	return 0;
}
