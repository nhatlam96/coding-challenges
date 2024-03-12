#pragma once
#include "cBruch.h"
#include <iostream>
using namespace std;

class cKompRat
{
private:
	cBruch real;
	cBruch imag;
public:
	cKompRat(cBruch = { 0,1 }, cBruch = { 0,1 }); //Nenner mit 0 wird im cBruch Konstruktor abgefangen

	//Freundfunktionen
	friend int kompRatVergleich(cKompRat, cKompRat);

	//Ueberladungen
	friend ostream& operator << (ostream& o, cKompRat& c);
	cKompRat operator + (cKompRat&);
	cKompRat operator - (cKompRat&);
	cKompRat operator * (cKompRat&);
	cKompRat operator / (cKompRat&);
	bool operator < (cKompRat&);
	bool operator == (cKompRat&);
	bool operator > (cKompRat&);
	void operator ~ (void);
};
