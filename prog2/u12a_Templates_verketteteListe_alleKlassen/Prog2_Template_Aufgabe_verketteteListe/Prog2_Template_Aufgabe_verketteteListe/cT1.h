#pragma once

#include <iostream>
using namespace std;

class cT1
{
	double x;
public:
	cT1(double x_in = 0.1);
	cT1& operator * (const cT1&);
	friend ostream& operator << (ostream&, cT1&);
};
