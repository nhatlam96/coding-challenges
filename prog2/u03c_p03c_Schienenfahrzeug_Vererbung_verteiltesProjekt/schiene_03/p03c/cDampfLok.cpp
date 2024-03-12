#include "cDampfLok.h"

cDampfLok::cDampfLok(double trieb_in, double gew_in):cLokomotive(trieb_in, gew_in) {}

/* Gibt den Energieverbrauch von 300.0 Kohlen zurück */
double cDampfLok::anheizen() {
	return 300.0;
}

/* Zieht vom Parameter kohlen das Resultat von anheizen() ab, rechnet das Ergebnis * 0.75 (Kohle hat eine
* geringere Energiedichte),nimmt diese Treibstoffmenge und ruft bereitstellen()der Basisklasse auf
*/
double cDampfLok::bereitstellen(double kohlen) {
	return cLokomotive::bereitstellen((kohlen - anheizen())*0.75);
}