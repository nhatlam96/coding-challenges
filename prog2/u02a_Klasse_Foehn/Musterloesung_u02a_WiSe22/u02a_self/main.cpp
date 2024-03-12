/* Aufgabe u02a
 * 17.10.2022
 * Daniela Hei�
 * ( Nur In der Klausur: Matrikelnummer)
 * (Dies ist ein Kopfkommentar mit allen relevanten Informationen, bitte bei euren Abgaben dran denken! )
 */

#include <iostream>
#include <string>
using namespace std;

enum Farbe {schwarz, rot, blau, gelb, weiss}; //Verwendet bitte keine Umlaute, deshalb weiss mit zwei s

class cHaarfoehn {
private:	//nicht notwendig, da alles private ist, wenn es nicht als public deklariert wurde
	string bezeichnung;
	double watt;
	int schaltstufen;
	Farbe farbe;

public:
	cHaarfoehn(string bezeichnung_in = "unbestimmt", double watt_in = 0.0, int schaltstufen_in = 0, Farbe farbe_in = schwarz) {
		bezeichnung = bezeichnung_in;
		watt = watt_in;
		schaltstufen = schaltstufen_in;
		farbe = farbe_in;
	}

	~cHaarfoehn () {
		cout << "\nFoehn mit den Eigenschaften: " << endl;
		ausgabe();
		cout << "wurde destruiert\n" << endl;
	}

	void eingabe() {
		int enum_help;
		cout << "Eingabe:" << endl;

		cout << "Bezeichnung: ";
		cin >> bezeichnung; cout << endl;
		cout << "Watt: ";
		cin >> watt; cout << endl;
		cout << "Schaltstufen: ";
		cin >> schaltstufen; cout << endl;
		cout << "Farbe [0 = schwarz, 1 = rot, 2 = blau, 3 = gelb, 4 = weiss]: ";
		cin >> enum_help; cout << endl;

		if (enum_help >= 0 && enum_help <= 4) {
			farbe = static_cast <Farbe>(enum_help);
		}
		else {
			farbe = schwarz;
		}
	}

	void ausgabe() {
		cout << "Bezeichnung: " << bezeichnung << "\n" << "Watt: " << watt << "\n" << "Schaltstufen: " << schaltstufen << endl;
		switch (farbe) {
			case 0: cout << "Farbe: schwarz" << endl; break;
			case 1: cout << "Farbe: rot" << endl; break;
			case 2: cout << "Farbe: blau" << endl; break;
			case 3: cout << "Farbe: gelb" << endl; break;
			case 4: cout << "Farbe: weiss" << endl; break;
		}
	}
};

int main() {
	cHaarfoehn Foehn1;
	cHaarfoehn Foehn2("SuperFoehn", 200, 4, rot);
	cHaarfoehn Foehn3("SuperPlusFoehn", 400, 8, blau);

	cout << "Erste Ausgabe: \n" << endl;
	Foehn1.ausgabe(); cout << "----------------" << endl;
	Foehn2.ausgabe(); cout << "----------------" << endl;
	Foehn3.ausgabe(); cout << "----------------" << endl;

	cout << "Neu befuellen der Werte: \n" << endl;
	Foehn1.eingabe(); cout << "----------------" << endl;
	Foehn2.eingabe(); cout << "----------------" << endl;
	Foehn3.eingabe(); cout << "----------------" << endl;

	cout << "Ausgabe neuer Werte: \n" << endl;
	Foehn1.ausgabe(); cout << "----------------" << endl;
	Foehn2.ausgabe(); cout << "----------------" << endl;
	Foehn3.ausgabe(); cout << "----------------" << endl;

	cout << "\nBeginn der Destruktion" << endl;

	return 0;
}