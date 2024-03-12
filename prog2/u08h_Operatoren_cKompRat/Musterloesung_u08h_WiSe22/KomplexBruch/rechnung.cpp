/* Musterloesung zu u07a Bruch und u08h KompRat*/
/* 13.05.2022, editiert am 15.12.2022 */
/* Daniela Heiss */

#include "cBruch.h"
#include "cKompRat.h"

#include <iostream>
using namespace std;

int main() {

	//u07a
	//cBruch helpme;	//Hilfsvariable
	//cBruch cBArr[8] = { cBruch(3, 6),
	//					cBruch(21, -7),
	//					cBruch(8, -10),
	//					cBruch(-4, 3),
	//					cBruch(-8, 13),
	//					cBruch(4, 5),
	//					cBruch(21, 37)};

	//for (int i = 0; i < 8; i++) {
	//	cBArr[i].ausgabe();
	//}

	//helpme = add(cBArr[0], cBArr[1]);
	//cout << "Ergebnis Addition: "; helpme.ausgabe();

	//helpme = subt(cBArr[2], cBArr[3]);
	//cout << "Ergebnis Subtraktion: "; helpme.ausgabe();

	//helpme = mul(cBArr[4], cBArr[5]);
	//cout << "Ergebnis Multiplikation: "; helpme.ausgabe();

	//helpme = div(cBArr[6], cBArr[7]);
	//cout << "Ergebnis Division: "; helpme.ausgabe();

	//cout << "Vergleich Bruch 1 und Bruch 2: " << vergleich(cBArr[0], cBArr[1]) << endl;
	//cout << "Vergleich Bruch 3 und Bruch 4: " << vergleich(cBArr[2], cBArr[3]) << endl;
	//cout << "Vergleich Bruch 5 und Bruch 6: " << vergleich(cBArr[4], cBArr[5]) << endl;
	//cout << "Vergleich Bruch 7 und Bruch 8: " << vergleich(cBArr[6], cBArr[7]) << endl;

	//sortier(cBArr);
	//for (int i = 0; i < 8; i++) {
	//	cBArr[i].ausgabe();
	//}

	//u08h
	cKompRat test;

	cKompRat kompRatArr[4] = {	cKompRat(cBruch(21,56), cBruch(3,7)),
								cKompRat(cBruch(24, -6), cBruch(5,7)),
								cKompRat(cBruch(-8,13), cBruch(7, -11))};

	cout << "Ausgabe des Arrays:" << endl;

	for (int i = 0; i <= 3; i++) {
		cout << kompRatArr[i] << endl;
	}

	test = kompRatArr[0] + kompRatArr[1];
	cout << "\nErgebnis Addition 1 & 2: " << test << endl;

	test = kompRatArr[1] - kompRatArr[2];
	cout << "\nErgebnis Subtraktion 2 & 3: " << test << endl;

	test = kompRatArr[1] * kompRatArr[1];
	cout << "\nErgebnis Multiplikation 2 & 2: " << test << endl;

	test = kompRatArr[1] / kompRatArr[2];
	cout << "\nErgebnis Division 2 & 3: " << test << endl;

	//Weitere Testfunktionen fuer >, ==, > und ~ moeglich

	return 0;
}