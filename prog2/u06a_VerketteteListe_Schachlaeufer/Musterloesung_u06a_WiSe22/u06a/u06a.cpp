/*	Schachlaeufer u06a - WiSe22 
 *  Daniela Heiß
 * 15.12.22
 */

#include "cSchachfeld.h"

int main() {

	cSchachfeld* p_act = new cSchachfeld('E', 7);
	cSchachfeld* p_ziel = new cSchachfeld('C', 1);

	while (vergleichPos(*p_act, *p_ziel) != 1) {
		p_act = p_act->springerZug();	//springerZug() statt laeuferZug(), da es eine abgewandelte Schachspringer Loesung ist
	}

	cout << "Das Ziel wurde erreicht!" << endl;
	cout << "Dies waren Ihre Zuege: " << endl;

	p_act->printSpiel();

	cout << "Spiel beenden..." << endl;

	delete p_act;
	delete p_ziel;

	return 0;
}