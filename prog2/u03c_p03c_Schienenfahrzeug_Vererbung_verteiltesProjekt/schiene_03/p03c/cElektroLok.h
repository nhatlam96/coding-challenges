#pragma once
#include "cLokomotive.h"
class cElektroLok : public cLokomotive {
private:
	bool stromAn;
	void aufbuegeln();
public:
	cElektroLok(double trieb_in = 6500.0, double gew_in = 50000.0);
	~cElektroLok();

	

	double bereitstellen(int stunden);


};

