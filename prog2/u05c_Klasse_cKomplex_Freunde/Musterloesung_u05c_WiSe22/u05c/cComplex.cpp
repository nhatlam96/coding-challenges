#include "cComplex.h"

cComplex::cComplex(double re_in, double im_in) {
	re = re_in;
	im = im_in;
}

void cComplex::printme() {
	cout << "Real: " << re << endl;
	cout << "Imaginaer: " << im << endl;
	cout << "Betrag: " << distanceNull() << endl;
}

double cComplex::distanceNull() {
	double distance = sqrt(pow(re, 2) + pow(im, 2));
	return distance;
}

cComplex add(cComplex a, cComplex b) {	//Ausfuehrliche Variante mit Hilfsobjekt
	cComplex ergebnis;
	ergebnis.re = a.re + b.re;
	ergebnis.im = a.im + b.im;
	return ergebnis;
}

cComplex subt(cComplex a, cComplex b) {			//Kompaktere Version
	return cComplex(a.re - b.re, a.im - b.im);
}

cComplex mul(cComplex a, cComplex b) {
	cComplex ergebnis;
	ergebnis.re = a.re * b.re;
	ergebnis.im = a.im * b.im;
	return ergebnis;
}

cComplex div(cComplex a, cComplex b) {
	cComplex ergebnis;
	if (b.re != 0 && b.im != 0) {
		ergebnis.re = a.re / b.re;
		ergebnis.im = a.im / b.im;
		return ergebnis;
	}
	else {
		cout << "Fehler: Nulldivision" << endl;
		return errno;
	}
}

int complCompare(cComplex c1, cComplex c2) {
	if (c1.distanceNull() > c2.distanceNull()) {
		return 1;
	}
	else if (c1.distanceNull() == c2.distanceNull()) {
		return 0;
	}
	else if (c1.distanceNull() < c2.distanceNull()) {
		return -1;
	}
}