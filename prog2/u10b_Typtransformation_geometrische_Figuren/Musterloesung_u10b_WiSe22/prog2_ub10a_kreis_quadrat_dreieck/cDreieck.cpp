#include "cDreieck.h"
#include "cKreis.h"
#include "cQuadrat.h"
#define M_PI 3.1415
cDreieck::cDreieck(double seite_n) : seite(seite_n) {

}

double cDreieck::flaeche() const {
	double F = 1.0 / 4.0 * sqrt(3.0) * seite * seite;
	return F;
}

void cDreieck::print() {
	cout << "Seitenlaenge: " << seite << endl << "Flaeche von dem Dreieck: " << flaeche() << endl;
}
// bei diese drei operator wird die flaeche nicht geendet werden.
// dewegen muss man bei der formel.
// flaeche von dem kreis = seite * seite * PI
// die flaeche ziehen und Zurrueckgeben.
cDreieck::operator cKreis() {
	return cKreis(sqrt(flaeche() / M_PI)); 
}

cDreieck::operator cQuadrat() {
	return cQuadrat(sqrt(flaeche()));
}

ostream& operator <<(ostream& os, const cDreieck& dr) {
	os << "Seitenlaenge: " << dr.seite << endl << "Flaeche von dem Dreieck: " << dr.flaeche() << endl;
	return os;
}