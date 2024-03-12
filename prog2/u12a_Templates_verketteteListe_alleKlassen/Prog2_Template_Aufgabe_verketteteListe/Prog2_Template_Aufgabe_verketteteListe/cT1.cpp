#include "cT1.h"

cT1::cT1(double x_in) : x(x_in) {}		// Implementierung Konstruktor

cT1& cT1::operator * (const cT1& rhs) {
	static cT1 help;

	help.x = x * rhs.x;
	return help;
}

ostream& operator << (ostream& o, cT1& c1) {
	o << "x: " << c1.x;
	return o;
}
