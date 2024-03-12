#include "cKreis.h"
#include "cQuadrat.h"
#include "cDreieck.h"
#include "math.h"
#define M_PI 3.1415
cKreis::cKreis(double radius_n): radius(radius_n) {

}

double cKreis::flaeche() const {
	double F = radius * radius * M_PI;
	return F;
}

void cKreis::print() {	// ausgabe fuer radius und flaeche.
	cout << "Radius: " << radius << endl << "Flaeche von dem Kreis :"<< flaeche() << endl;
}
// Operatoren
// bei diese operator wird die flaeche nicht geendet werden.
// dewegen muss man bei der formel.
// flaeche von dem kreis = seite * seite
// die flaeche ziehen und Zurrueckgeben.
cKreis::operator cQuadrat() {
	return cQuadrat(sqrt(flaeche()));
}

cKreis::operator cDreieck(){
	double seite = sqrt(flaeche() / ((1.0 / 4.0) * sqrt(3.0)));
	return cDreieck (seite);
}

ostream& operator <<(ostream& os, const cKreis& dr) {
	os << "Radius: " << dr.radius << endl << "Flaeche von dem Kreis :" << dr.flaeche() << endl;
	return os;
}