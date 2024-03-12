#include "cWaggon.h"

#include <iostream>

using namespace std;

cWaggon::cWaggon(double gew_in) : cSchienenFahrzeug(gew_in) {

}


/* Gibt "ich lass mich ziehen" aus */
void cWaggon::ankuppeln() {
	cout << "ich lass mich ziehen" << endl;
}
