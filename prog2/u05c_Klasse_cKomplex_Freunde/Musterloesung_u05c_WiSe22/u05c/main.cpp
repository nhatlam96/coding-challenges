//Dani

#include "cComplex.h"

int main() {
	cout << "Testwerte: \n" << endl;
	cComplex c1(4.3, 2.6);
	cComplex c2(6.3, 7.2);

	c1.printme();
	c2.printme();

	cout << "\nVerrechnete Werte: " << endl;
	cComplex test;
	cout << "\nAddition" << endl;
	test = add(c1, c2);
	test.printme();
	cout << "\nSubtraktion" << endl;
	test = subt(c1, c2);
	test.printme();
	cout << "\nMultiplikation" << endl;
	test = mul(c1, c2);
	test.printme();
	cout << "\nDivision" << endl;
	test = div(c1, c2);
	test.printme();

	return 0;
}