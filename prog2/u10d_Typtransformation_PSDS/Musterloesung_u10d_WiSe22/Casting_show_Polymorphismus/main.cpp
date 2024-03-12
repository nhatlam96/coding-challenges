/*
Author: Junior Fomba Tagang
Datum: 20.12.2022
Aufgabe: Casting Show: Polymorphismus, Cast-Operator, virtuelle Methoden
Wichtig: Das Programm ist nicht kommentiert, aber wurde so geschrieden, 
			dass die Variablenamen bzw. Klassennamen bedeutungsvoll sind.
*/

#include "cKandidat.h"
#include "cSuperstar.h"
#include <string.h>


int main() {
	cKandidat suzanne;
	cSuperstar suzy;
	string choice;


	int stimmen = 0;
	int talent = suzanne.getTalent();

	suzanne.print();

	do {
		cout << "Ich bin die Suzanne. Bitte geben Sie mir Stimmen: ";
		cin >> stimmen;
		suzanne.werteTED(stimmen);
		suzanne.print();
	} while (suzanne.getPunkte() <= 100000);

	//cout << "Danke Leute. Ich bin Jetzt ein Superstar!!!!" << endl;
	cout << endl;
	suzy.print();
	suzy = (cSuperstar)suzanne;
	suzy.print();
	cout << endl;

	
	// wir wollen wieder eine Kandidatin werden
	do {
		
		cout << "Wollen Sie Hits erhöhen oder nicht?" << endl;
		cin >> choice;
		if (choice == "ja" || choice == "yes") {
			suzy.landeHit();
			suzy.print();
		}
		else if (choice == "exit") {
			break;
		}
		else
		{
			suzy.landeFlop();
			suzy.print();
		}
	} while (choice != "exit");
	
	if (suzy.getHits() > 2) {
		cout << "Suzy ist immer noch ein Superstar!" << endl;
	}
	else
	{
		cout << "Suzy ist kien Superstar mehr!" << endl << endl;
		suzanne = (cKandidat)suzy;
		suzanne.print();
	}

	return 0;
}