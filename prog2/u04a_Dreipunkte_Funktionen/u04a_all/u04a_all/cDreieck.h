#pragma once
#include "cPunkt.h"

class cDreieck {
private:
	//cPunkt p1, p2, p3;
	cPunkt punkte[3];			/* durch ein Array kann man mit einer Schleife durch, durch Variablen nicht */
	double lenS(cPunkt p1, cPunkt p2);
	double umfangD();
	double flaecheD();

	friend int dreieckVergleich(cDreieck d1, cDreieck d2);
public:
	//cDreieck(double x1_in = 0.0, double y1_in = 1.0, double x2_in = 1.0, double y2_in = 0.0, double x3_in = 0.0, double y3_in = 0.0);
	cDreieck(cPunkt p1 = cPunkt(0.0, 1.0), cPunkt p2 = cPunkt(1.0, 0.0), cPunkt p3 = cPunkt(0.0, 0.0));
	void ausgabe();
};

