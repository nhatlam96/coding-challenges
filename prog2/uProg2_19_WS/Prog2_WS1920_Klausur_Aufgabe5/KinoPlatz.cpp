// Musterloesung Aufgabe 5 Klausur WS 2019/2020
// Reservierungssystem Kinositzplatze als sicheres Array aus Klassen

#include "cClassArr.h"

int main() {
	cClassArr Kino(30);			// Kino mit 30 Plaetzen

	for (int i = 0; i < 33; i++) {
		cout << "Platz Nummer " << i + 1 << ": " << Kino[i] << endl;
	}

	return 0;
}