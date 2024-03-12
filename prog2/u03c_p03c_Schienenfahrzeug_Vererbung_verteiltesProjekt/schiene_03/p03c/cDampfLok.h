#pragma once
#include "cLokomotive.h"
class cDampfLok:public cLokomotive {
private:
	double anheizen();
	
public:
	cDampfLok(double trieb_in = 6500.0, double gew_in = 50000.0);
	double bereitstellen(double kohlen);
};

