#pragma once
#include "cWaggon.h"
class cGueterWagen : public cWaggon {
private:
	double nutzlast;
public:
	cGueterWagen(double nutz_in = 20000.0, double gew_in = 30000.0);
	double zuladen(double lastplus);
	double abladen(double lastweg);
	double get_gewicht();
};

