/*	Primzahl - u09a
 *	27.05.2022, editiert 16.12.2022
 *	Daniela Heiss
 */

#include "cPrimzahl.h"

int main() {
	cPrimzahl pz;
	char in = '-';
	int sub = 0;
	int i = 0;

	while (in != 'e') {
		cout << "Geben Sie eine Anweisung ein. Erlaubt sind die Zeichen: +, -, s und e: ";
		cin >> in; cout << endl;
		if (in == 'e') {
			break;
		}
		else if (in == '+') {
			++pz;
			cout << pz << endl;
		}
		else if (in == '-') {
			--pz;
			cout << pz << endl;
		}
		else if (in == 's') {
			cout << "Geben Sie eine Zahl fuer die Subskription ein: ";
			cin >> sub; cout << endl;
			i = pz[sub];
			cout << i << endl;
		}
	}

	return 0;
}