#include "cDreieck.h"

double cDreieck::umfangD()
{
	return (getAB() + getBC() + getCA());
}

double cDreieck::flaecheD()
{
	double s = umfangD() / 2;

	return (sqrt(s * (s - getAB()) * (s - getBC()) * (s - getCA())));
}

double cDreieck::getAB()
{
	//Strecke AB
	 return (sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2)));
}

double cDreieck::getBC()
{
	//Strecke BC
	return (sqrt(pow(c.getX() - b.getX(), 2) + pow(c.getY() - b.getY(), 2)));
}

double cDreieck::getCA()
{
	//Strecke CA
	return (sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getY() - c.getY(), 2)));
}

cDreieck::cDreieck(cPunkt a_in, cPunkt b_in, cPunkt c_in) : a (a_in), b (b_in), c (c_in)	//Konstruktorenkaskade
{
}

void cDreieck::ausgabe()
{
	cout << "a: "; a.ausgabe(); cout << endl;
	cout << "b: "; b.ausgabe(); cout << endl;
	cout << "c: "; c.ausgabe(); cout << "\n" <<endl;

	cout << "Umfang: " << umfangD() << endl;
	cout << "Flaeche: " << flaecheD() << endl;
}

int dreieckVergleich(cDreieck d1, cDreieck d2) {
	if (d1.flaecheD() > d2.flaecheD()) {
		return 1;
	}
	else if (d1.flaecheD() == d2.flaecheD()) {
		return 0;
	}
	else if (d1.flaecheD() < d2.flaecheD()) {
		return -1;
	}
}
