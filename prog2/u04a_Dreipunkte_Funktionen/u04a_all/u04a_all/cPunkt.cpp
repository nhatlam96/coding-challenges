#include "cPunkt.h"

/* Universal-Konstruktor */
cPunkt::cPunkt(double x_in, double y_in){
	x = x_in;
	y = y_in;
}

void cPunkt::ausgabe() {
	cout << x << "|" << y;
}

double cPunkt::getX() {
	return x;
}

double cPunkt::getY() {
	return y;
}