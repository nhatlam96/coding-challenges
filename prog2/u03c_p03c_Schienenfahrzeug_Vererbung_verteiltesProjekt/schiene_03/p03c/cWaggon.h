#pragma once
#include "cSchienenFahrzeug.h"
#include <iostream>

class cWaggon : public cSchienenFahrzeug {
public:
	cWaggon(double gew_in = 0.0);
	void ankuppeln();
};

