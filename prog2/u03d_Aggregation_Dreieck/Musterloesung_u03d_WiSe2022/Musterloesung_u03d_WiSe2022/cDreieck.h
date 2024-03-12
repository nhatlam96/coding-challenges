#pragma once
#include "cPunkt.h"	//Da wir cPunkt.h inkludieren benoetigen wir ein erneutes include fuer iostream an dieser Stelle nicht

class cDreieck
{
private:
	cPunkt a;
	cPunkt b;
	cPunkt c;

	double umfangD();
	double flaecheD();

	double getAB();	//get-Funktionen der Berechnungen der Seitenlaengen
	double getBC();	//Wenn wir einen Wert mehr als einmal in einer anderen Methode benoetigen
	double getCA();	//macht das erstellen von privaten Hilsmethoden Sinn

public:
	cDreieck(cPunkt a_in = { 0.0, 1.0 }, cPunkt b_in = { 1.0, 0.0 }, cPunkt c_in = { 0.0, 0.0 });
	void ausgabe();
};

