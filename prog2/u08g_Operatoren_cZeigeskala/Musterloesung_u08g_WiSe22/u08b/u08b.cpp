/*	cZeigeskala - u08g
 *  23.06.2021, editiert am 16.12.2022
 *	Daniela Heiss
 */

#include "cLageSkala.h"

int main() {

	cLageSkala s1;
	s1.ausgabe();

	cout << s1 << endl;

	for (int i = 0; i < 2; i++) {
		++s1;
	}

	cout << "\n" << s1 << endl;

	cin >> s1;
	s1.ausgabe();

	cout << s1 << endl;

	--s1;
	cout << "\n" << s1 << endl;


	return 0;
}