#pragma once
#include <iostream>
using namespace std;
class cKreis;
class cDreieck;
class cQuadrat
{
private:
	double seite;
public:
	cQuadrat(double = 0.0);
	void print();
	double flaeche()const;
	operator cKreis();
	operator cDreieck();
	friend ostream& operator <<(ostream& os, const cQuadrat& dr);
};

