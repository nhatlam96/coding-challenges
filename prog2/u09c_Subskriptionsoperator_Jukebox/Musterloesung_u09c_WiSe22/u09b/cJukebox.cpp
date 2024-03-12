#include "cJukebox.h"

cJukebox::cJukebox() 
{
	cout << "Konstruktion einer Jukebox!" << endl;
}

cJukebox::~cJukebox() {
	cout << "Irgendwer hat die Jukebox kaputt gemacht" << endl;
}

int cJukebox::operator[] (istream& input) {				

	int index;
	input >> index;

	if (index == 222) {									//Zuerst abfangen des Sonderfalles
		cout << "It's Time to say Goodbye" << endl;
		return -1;
	}
	else if (index >= 1 && index <= 100) {
		cout << "Lang leben Twist, Boogie, RocknRoll!" << endl;
		return index * 2;
	}
	else if (index >= 101 && index <= 200) {
		cout << "Traeumerisch schauen und gelegentlich seufzen" << endl;
		return index * 13 - 100;
	}
	else if (index >= 201 && index <= 300) {
		cout << "Raven bis zum Morgengrauen" << endl;
		return index * 717 % 11;
	}
	else {
		cout << "Eingabe eines ungueltigen Zeichens" << endl;
		return -1;
	}
}
