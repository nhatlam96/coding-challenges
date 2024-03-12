#pragma once
#include "cWaggon.h"
class cPersonenWagen : public cWaggon {
private:
	int fahrgastzahl;
public:
	cPersonenWagen(int fahrg_in = 12, double gew_in = 50000.0);
	int einsteigen(int rein);
	int aussteigen(int raus);

};

