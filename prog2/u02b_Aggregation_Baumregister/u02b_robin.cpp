// Uebungsaufgabe u02b
// Robin Larisch
// 12.04.2016

#include <iostream>
#include <string>
using namespace std;

#define MAX 1000


class cBaum {
private: 

	string art;
	int insert = 0;
	double hoeh;
	double geob;
	double geol;
	double korrHoehe(double hoeh, double geob) {
		while (geob > 60 && hoeh > 6.5) {
			cout << "Unzulaessige Hoehe fuer diesen Breitengrad, die automatische Korrektur setzt die maximale Hoehe von 6.5m ein!" << endl;
			hoeh = 6.5;
		}
		while (geob > 30 && geob < 60 && hoeh > 36.5) {
			cout << "Unzulaessige Hoehe fuer diesen Breitengrad, die automatische Korrektur setzt die maximale Hoehe von 36.5m ein!" << endl;
			hoeh = 36.5;
		}
		while (geob >= 0 && hoeh > 66.5) {
			cout << "Unzulaessige Hoehe fuer diesen Breitengrad, die automatische Korrektur setzt die maximale Hoehe von 66.5m ein!" << endl;
			hoeh = 66.5;
		}

		return hoeh;
	}

public:
	cBaum() {
		art = "";
		hoeh = 10.0;
		geob = 48.79;
		geol = 8.17;
	}

	void eingabe() {
		cout << "Geben Sie die Art des Baumes ein: " << endl;
		cin >> art;
		cout << "Geben Sie die Hoehe des Baumes an: " << endl;
		cin >> hoeh;
		cout << "Geben Sie den Breitengrad an: " << endl;
		cin >> geob;
		cout << "Geben Sie den Laengengrad an " << endl;
		cin >> geol;
		hoeh = korrHoehe(hoeh, geob);
	}

	void ausgabe() {
		cout << art << " | ";
		cout << hoeh << " m | ";
		cout << geob << " Grad Breite | ";
		cout << geol << " Grad Laenge | " << endl;
	}
};

int main() {
	cBaum test[MAX];
	int menu = 0, i = 0, i2 = 0, i3 = 0;
	int insert = 0;

	while (menu != 3) {
		cout << "1 = Neuen Baum eintragen" << endl << "2 = Alle Baeume einsehen" << endl << "3 = Programm beenden" << endl;
		cin >> menu;

		switch (menu) {
			case 1:
				if (i2 == MAX) {
					cout << "Vorsicht! Ihre Datenbank ist voll!" << endl;
					break;
				}
				test[i++].eingabe();
				break;
			case 2:
				for (i2 = 0; i2 < i; i2++) {
					test[i2].ausgabe();
				}
				break;
			case 3:
				break;
		}
	}

	return 0;
}
