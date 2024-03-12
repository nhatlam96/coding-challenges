/*
* p03c.cpp
* Sebastian Fuhrmann
* 2016-04-28
*/

#include <iostream>
#include "cDieselLok.h"
#include "cDampfLok.h"
#include "cPersonenWagen.h"
#include "cGueterWagen.h"
#include "cElektroLok.h"
using namespace std;

int main() {
	cGueterWagen packdrauf;
	cPersonenWagen pullman;
	cDieselLok v200;
	cDampfLok br86;
	cElektroLok e03;

	// Mit den Objekten arbeiten:
	cout << "Startgewicht des Gueterwagens: " << packdrauf.get_gewicht() << endl;
	cout << "Startgewicht des Personenwagens: " << pullman.get_gewicht() << endl;
	cout << "Startgewicht der Diesellok: " << v200.get_gewicht() << endl;
	cout << "Startgewicht der Dampflok: " << br86.get_gewicht() << endl;
	cout << "br86 wird bereitgestellt: " << br86.bereitstellen(8) << endl;
	cout << "v200 wird bereitgestellt: " << v200.bereitstellen(6) << endl;
	cout << "e03 wird bereitgestellt: " << e03.bereitstellen(10) << endl;
	pullman.ankuppeln();
	packdrauf.ankuppeln();
	v200.ankuppeln();
	cout << "Ladung nach Aufladen 20000.0: " << packdrauf.zuladen(20000.0) << endl;
	cout << "Gewicht Gueterwagen danach: " << packdrauf.get_gewicht() << endl;
	cout << "Gaeste im Personanwagen nach Zusteigen 100: " <<
		pullman.einsteigen(100) << endl;
	cout << "Ende" << endl;

	return 0;
}