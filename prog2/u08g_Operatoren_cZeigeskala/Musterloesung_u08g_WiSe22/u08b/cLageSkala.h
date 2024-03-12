#pragma once
#include <iostream>
using namespace std;

#define SEGMENTS 42

class cLageSkala {
private:
	double unterGrenze;
	double oberGrenze;
	double aktVal;

	double getSegments() const;	//const fuer den Ausgabeoperator

public:
	cLageSkala(double unterGrenze_in = 0.0, double oberGrenze_in = 1.0, double aktVal_in = 0.5);
	void ausgabe();
	cLageSkala& operator ++(void);
	cLageSkala& operator --(void);

	friend ostream& operator << (ostream& out, const cLageSkala& obj);
	friend istream& operator >> (istream& in, cLageSkala& obj);
};