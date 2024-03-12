#pragma once
#include "cSchienenFahrzeug.h"
class cLokomotive : public cSchienenFahrzeug {
private:
	double triebkraft;
public:
	cLokomotive(double triebkraft, double gewicht);
	void ankuppeln();
	double bereitstellen(double treibstoff);

};

