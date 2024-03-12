/*
* Autor: Herve Mbatchou Njimi
* 06.12.2022
* Freund funktion im Bruch
*/
#include"cBruch.h"
int main() {
	cBruch bruch[8] = {
		cBruch(3, 6),cBruch(21, -7),cBruch(8, -10), cBruch(-4, 3), cBruch(-8, 13), cBruch(4, 5), cBruch(21, 37)
	};

	cout << "---------------Bruch Array--------------" << endl;
	for (int i = 0; i < 7; i++) { // schleife um die werte von unsere Bruch objekt auszugeben
		bruch[i].ausgabe();
	}

	// zwei erste brueche addiren
	cout << endl << "---------------Addition von 2 brueche--------------" << endl;
	cBruch ergebnis = add (bruch[0], bruch[1]);
	ergebnis.ausgabe();

	cout << endl << "---------------Substrahiren von brueche--------------" << endl;
	ergebnis = sub(bruch[2], bruch[3]);
	ergebnis.ausgabe();

	cout << endl << "---------------Multiplizieren von brueche--------------" << endl;
	ergebnis = mult(bruch[4], bruch[5]);
	ergebnis.ausgabe();

	// unsere funktion sortieren um die werte von unsere Array zu sortieren
	cout << endl << "-----------sortierte funktion----------------------" << endl;
	sortier(bruch, 8);
	for (int i = 0; i < 7; i++) {
		bruch[i].ausgabe();
	}

	return 0;
}