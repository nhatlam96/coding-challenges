/*
* Autor: Herve Mbatchou Njimi
* 13.12.2022
* uerberladung von operatoren bei der klasse.
*/
#include "cKreis.h"
#include "cDreieck.h"
#include "cQuadrat.h"
int main() {
	cKreis K1(12.18);
	cQuadrat Q1(18.12);
	cDreieck D1(23.72);
	cout << "ausgabe von K1, K2 und D1" << endl;
	cout << "----------Kreis--------------" << endl;
	K1.print();
	cout << "----------Quadrat--------------" << endl;
	Q1.print();
	cout << "----------Dreieck--------------" << endl;
	D1.print();

	cout << "--------Quadrat zu ein Kreis--------" << endl;
	K1 = (cKreis)Q1; // Quadrat zu ein Kreis
	K1.print();

	cout << "--------Kreis Objekt zu Quadrat-------" << endl;
	Q1 = (cQuadrat)K1; //Kreis objekt zu Quadrat
	Q1.print();

	cout << "-------Kreis zu Dreieck--------" << endl;
	D1 = (cDreieck)K1; // Kreis zu Dreieck
	D1.print();

	/*cout << endl << "ausgabe mit der ausgabe operatoren." << endl;
	cKreis K1(12.18);
	cQuadrat Q1(18.12);
	cDreieck D1(23.72);

	cout << K1 << endl;
	cout << Q1 << endl;
	cout << D1 << endl;

	K1 = (cKreis)Q1;
	cout << K1 << endl;
	Q1 = (cQuadrat)K1;
	cout << Q1 << endl;
	D1 = (cDreieck)K1;
	cout << D1 << endl;*/
	


	return 0;
}