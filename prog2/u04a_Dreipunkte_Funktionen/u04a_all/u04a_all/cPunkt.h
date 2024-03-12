#pragma once

#include <iostream>
using namespace std;

class cPunkt {
private:
	double x, y;
public:
	cPunkt(double x = 0.0, double y = 0.0);
	/*
		Standard-Konstruktor:
		cPunkt;

		Universal-Konstruktor:
		cPunkt(); oder cPunkt(1.0); oder cPunkt(1.0, 2.0);

		"Normaler" Konstruktor
		cPunkt(1.0, 2.0);
	*/
	void ausgabe();
	double getX();
	double getY();
};

