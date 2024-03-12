#pragma once
#include <iostream>
using namespace std;

class cQuadrat;
class cDreieck;
class cKreis
{
private:
	double radius;
public:
	cKreis(double = 0.0);
	void print();
	double flaeche()const;
	operator cQuadrat();
	operator cDreieck();
	friend ostream& operator <<(ostream&, const cKreis&);
};

