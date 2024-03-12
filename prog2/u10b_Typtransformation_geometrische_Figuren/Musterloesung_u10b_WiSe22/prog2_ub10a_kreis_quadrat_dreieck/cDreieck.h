#pragma once
#include <iostream>
using namespace std;
class cKreis;
class cQuadrat;
class cDreieck
{
private:
	double seite;
public:
	cDreieck(double = 1.0);
	void print();
	double flaeche() const;
	operator cKreis();
	operator cQuadrat();
	friend ostream& operator << (ostream& os, const cDreieck& dr);
};

