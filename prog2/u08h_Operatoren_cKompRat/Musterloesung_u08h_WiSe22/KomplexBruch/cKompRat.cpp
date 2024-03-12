#include "cKompRat.h"

cKompRat::cKompRat(cBruch real_in, cBruch imag_in) : real(real_in), imag(imag_in) //Man kann ueber die Konstruktorenkaskade auch so Werte befuellen
{

}

int kompRatVergleich(cKompRat a, cKompRat b) {
	double betrag_a = sqrt(pow(a.real.getGleitkomma(), 2) + pow(a.imag.getGleitkomma(), 2));	//Betrag Z = sqrt(real^2 + imaginaer^2)
	double betrag_b = sqrt(pow(b.real.getGleitkomma(), 2) + pow(b.imag.getGleitkomma(), 2));	//Pythagoras, wir wollen die Laenge von der Hypotenuse

	if (betrag_a > betrag_b) {
		return 1;
	}
	else if (betrag_a == betrag_b) {
		return 0;
	}
	else {
		return -1;
	}
}

cKompRat cKompRat::operator + (cKompRat& k) {
	return cKompRat(add(real, k.real), add(imag, k.imag)); //Verwendung der in u05c definierten Rechenoperationen
}

cKompRat cKompRat::operator - (cKompRat& k) {
	return cKompRat(subt(real, k.real), subt(imag, k.imag));
}

cKompRat cKompRat::operator * (cKompRat& k) {
	return cKompRat(mul(real, k.real), mul(imag, k.imag));
}

cKompRat cKompRat::operator / (cKompRat& k) {
	return cKompRat(div(real, k.real), div(imag, k.imag));
}

bool cKompRat::operator < (cKompRat& k) {
	return real.getGleitkomma() + imag.getGleitkomma() < k.real.getGleitkomma() + k.real.getGleitkomma();
}

bool cKompRat::operator == (cKompRat& k) {
	return real.getGleitkomma() + imag.getGleitkomma() == k.real.getGleitkomma() + k.real.getGleitkomma();
}

bool cKompRat::operator > (cKompRat& k) {
	return real.getGleitkomma() + imag.getGleitkomma() > k.real.getGleitkomma() + k.real.getGleitkomma();
}

void cKompRat::operator ~ () {
	cBruch h = real;
	real = imag;
	imag = h;
}

ostream& operator << (ostream& o, cKompRat& c) {
	return o << "Reeller Teil: " << c.real << ", Imaginaerer Teil: " << c.imag;
}