#include "cSchienenFahrzeug.h"

cSchienenFahrzeug::cSchienenFahrzeug(double gewicht = 0.0) {
	this->gewicht = gewicht;
}


cSchienenFahrzeug::~cSchienenFahrzeug()
{
}

/* Gibt den Wert des Attributs "gewicht" als Returncode zurueck */
double cSchienenFahrzeug::get_gewicht() {
	return this->gewicht;
}