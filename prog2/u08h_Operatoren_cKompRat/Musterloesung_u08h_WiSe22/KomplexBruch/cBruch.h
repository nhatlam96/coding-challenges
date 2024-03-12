#pragma once
#include <iostream>
using namespace std;

class cBruch
{
private:
	int zaehler;
	int nenner;

	void kuerzen();
	int ggT(int, int);

public:
	cBruch(int = 0, int = 1);	//Vorgabewerte so, dass Bruch Wert = 0 hat
	cBruch(const cBruch&);
	void ausgabe();
	double getGleitkomma(); //Hilfsfunktion um den Wert des Bruches zu berechnen

	//Freundfunktionen
	friend cBruch add(cBruch, cBruch);
	friend cBruch subt(cBruch, cBruch);
	friend cBruch mul(cBruch, cBruch);
	friend cBruch div(cBruch, cBruch);
	friend int vergleich(cBruch, cBruch);
	friend void tausch(cBruch&, cBruch&);
	friend void sortier(cBruch[]);

	//Ueberladung
	friend ostream& operator << (ostream&, cBruch&);
};
