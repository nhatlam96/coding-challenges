#pragma once
#include "cLokomotive.h"

class cDieselLok:public cLokomotive {
public:
	cDieselLok(double trieb_in = 6500.0, double gew_in = 50000.0);
	double tanken();
	double bereitstellen(double treibstoff);
};

