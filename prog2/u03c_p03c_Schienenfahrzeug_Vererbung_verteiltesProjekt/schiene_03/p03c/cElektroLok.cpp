#include "cElektroLok.h"



cElektroLok::cElektroLok(double trieb_in, double gew_in) : cLokomotive(trieb_in, gew_in) {
}


cElektroLok::~cElektroLok()
{
}
void cElektroLok::aufbuegeln() {
	this->stromAn = true;
}

double cElektroLok::bereitstellen(int stunden) {
	this->aufbuegeln();
	return cLokomotive::bereitstellen(stunden * 2 * (int)stromAn);
}