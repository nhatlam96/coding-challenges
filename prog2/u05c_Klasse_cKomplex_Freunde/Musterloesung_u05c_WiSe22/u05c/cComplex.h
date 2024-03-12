#pragma once
#include <iostream>
using namespace std;

class cComplex
{
private:
	double re;
	double im;
	double distanceNull();
public:
	cComplex(double = 0.0, double = 0.0);
	void printme();

	friend cComplex add(cComplex, cComplex);
	friend cComplex subt(cComplex, cComplex);
	friend cComplex mul(cComplex, cComplex);
	friend cComplex div(cComplex, cComplex);
	friend int complCompare(cComplex c1, cComplex c2);
};


