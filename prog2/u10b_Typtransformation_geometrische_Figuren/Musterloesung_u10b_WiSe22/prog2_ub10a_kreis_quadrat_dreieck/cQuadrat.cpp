#include "cQuadrat.h"
#include "cKreis.h"
#include "cDreieck.h"
#define M_PI 3.1415
cQuadrat::cQuadrat(double seite_n): seite(seite_n){}

double cQuadrat::flaeche()const {
	double F = seite * seite;
	return F;
}

void cQuadrat::print() {
	cout << "SeiteLaenge: " << seite << endl << "Flaeche von dem Quadrat: " << flaeche() << endl;
}

// Operatoren..
// bei diese operator wird die flaeche nicht geendet werden.
// dewegen muss man bei der formel.
// flaeche von dem kreis = seite * seite  * PI
// die flaeche ziehen und Zurrueckgeben.
cQuadrat::operator cKreis() {
	return cKreis(sqrt(flaeche()/M_PI));
}

cQuadrat::operator cDreieck()
{
	double seite = sqrt(flaeche() / ((1.0 / 4.0) * sqrt(3.0)));
	return cDreieck();
}

ostream& operator <<(ostream& os, const cQuadrat& dr) {
	os << "Seitenlaenge: " << dr.seite << endl << "Flaeche von dem Quadrat: " << dr.flaeche() << endl;
	return os;
}
